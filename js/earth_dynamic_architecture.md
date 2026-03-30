# 实时地球可视化系统 - 架构设计文档

## 1. 系统概述

单文件 Web 应用（`earth_dynamic.html`），基于 Three.js 实现交互式 3D 地球可视化，支持实时日照模拟和全球网站访问点击模拟。可直接以 `file://` 协议在 Chrome 中打开运行，无需构建工具或本地服务器。

---

## 2. 技术栈

| 层级 | 技术 | 版本 | 加载方式 |
|------|------|------|----------|
| 3D 引擎 | Three.js | 0.160.0 | ES Module + Import Map (JSDelivr CDN) |
| 交互控制 | OrbitControls | 0.160.0 | Three.js addons ESM |
| 纹理资源 | NASA 卫星纹理 | - | threejs.org (GitHub Pages, CORS) |
| 布局/样式 | CSS Flexbox + 响应式 | - | 内联 `<style>` |
| 运行环境 | 现代浏览器 | Chrome 89+ | `file://` 或 `http://` |

---

## 3. 整体架构

```
┌─────────────────────────────────────────────────────────┐
│                    HTML 页面                              │
│                                                          │
│  ┌──────────────┐    ┌────────────────────────────────┐  │
│  │  控制面板     │    │       3D 渲染区域               │  │
│  │  (350px 固定) │    │       (flex: 1)                │  │
│  │              │    │                                │  │
│  │  地球状态     │    │  ┌─────────────────────────┐   │  │
│  │  ├─ 当前时间  │    │  │    WebGL Canvas          │   │  │
│  │  └─ 太阳位置  │    │  │                         │   │  │
│  │              │    │  │   Scene                  │   │  │
│  │  地球控制     │    │  │   ├─ Earth (Sphere)      │   │  │
│  │  ├─ 模式切换  │    │  │   │  └─ ClickPointsGroup │   │  │
│  │  ├─ 速度滑块  │    │  │   ├─ Clouds (Sphere)     │   │  │
│  │  └─ 光照滑块  │    │  │   ├─ Stars (Points)      │   │  │
│  │              │    │  │   ├─ AmbientLight         │   │  │
│  │  点击模拟     │    │  │   └─ DirectionalLight     │   │  │
│  │  ├─ 统计面板  │    │  │                         │   │  │
│  │  ├─ 操作按钮  │    │  │   Camera (Perspective)   │   │  │
│  │  └─ 记录列表  │    │  │   OrbitControls          │   │  │
│  │              │    │  └─────────────────────────┘   │  │
│  └──────────────┘    │                                │  │
│                      │  Loading Overlay (z-index:50)  │  │
│                      └────────────────────────────────┘  │
└─────────────────────────────────────────────────────────┘
```

---

## 4. 模块划分与职责

### 4.1 纹理加载层

```
loadImageTexture(url)          ← 单张纹理加载（Image + crossOrigin）
    │
loadAllTextures()              ← 并行加载 4 张纹理，返回结果字典
    │
    ├─ earth  (2048×1024 JPG)  ← 地球表面纹理
    ├─ bump   (2048×1024 JPG)  ← 法线/凹凸贴图
    ├─ spec   (2048×1024 JPG)  ← 高光贴图
    └─ clouds (1024×512  PNG)  ← 云层纹理

失败兜底:
    generateFallbackEarthTexture()  ← Canvas 程序化绘制大陆轮廓
    generateFallbackCloudTexture()  ← Canvas 程序化绘制云团
```

**设计决策**: 使用 `new Image()` + `crossOrigin = 'anonymous'` 而非 Three.js `TextureLoader`，因为后者在 `file://` 协议下的 CORS 处理不一致。GitHub Pages 响应 `Access-Control-Allow-Origin: *`，允许 `null` origin 的匿名请求。

### 4.2 场景构建层

| 函数 | 输出对象 | 几何体 | 材质 |
|------|---------|--------|------|
| `createEarth()` | `earth` (Mesh) | SphereGeometry(r=2, 64seg) | MeshPhongMaterial(map + bump + spec) |
| `createClouds()` | `clouds` (Mesh) | SphereGeometry(r=2.05, 64seg) | MeshPhongMaterial(transparent, opacity=0.4) |
| `createStars()` | Points | BufferGeometry(5000 particles) | PointsMaterial(size=0.7) |

**场景图 (Scene Graph)**:

```
Scene
├── AmbientLight (0x333333)
├── DirectionalLight (sunLight, 强度可调)
├── Earth (Mesh, r=2)
│   └── clickPointsGroup (Group)
│       ├── marker_0 (Sphere r=0.03, red)
│       ├── marker_1
│       └── ...
├── Clouds (Mesh, r=2.05, transparent)
├── Stars (Points, 5000 particles)
└── [临时] PulseSphere (动画后自动移除)
```

### 4.3 天文计算层

```
updateSunPosition()
    │
    ├── 输入: Date.getUTCHours(), getUTCMinutes()
    ├── 计算: timeAngle = (h + m/60) × (π/12) - π
    ├── 输出: sunLight.position = (cos(θ)×10, 3, sin(θ)×10)
    └── 副作用: 实时模式下更新 earth.rotation.y
```

太阳光在 XZ 平面上以地球为中心做圆周运动（半径=10），Y=3 提供一个倾斜角度模拟黄道倾斜。

### 4.4 交互层

| 交互方式 | 处理函数 | 机制 |
|---------|---------|------|
| 鼠标拖拽/旋转 | OrbitControls | 阻尼=0.05, 距离 3~20 |
| 鼠标点击地球 | `onEarthClick()` | Raycaster → 球面交点 → 经纬度反算 |
| 模拟点击按钮 | `simulateRandomClick()` | 从城市列表随机选取 + 坐标偏移 |
| 自动模拟 | `setInterval(3s)` | 开关切换 |
| 滑块控制 | `initUIEvents()` | 实时调整 `earthRotationSpeed` / `sunLight.intensity` |

### 4.5 坐标转换

```
经纬度 → 3D 球面坐标:
    φ = (90 - lat) × π/180
    θ = (lon + 180) × π/180
    x = -(r × sin(φ) × cos(θ))
    y = r × cos(φ)
    z = r × sin(φ) × sin(θ)

3D 交点 → 经纬度 (点击反算):
    lat = 90 - acos(point.y / r) × 180/π
    lon = (atan2(point.z, point.x) × 180/π + 180) % 360 - 180
```

### 4.6 动画循环

```
animate() [requestAnimationFrame 驱动, ~60fps]
    │
    ├── earth.rotation.y += speed     (实时模式)
    ├── clouds.rotation.y += speed×0.9
    ├── controls.update()             (阻尼惯性)
    └── renderer.render(scene, camera)
```

脉冲动画 (`createPulseEffect`) 独立于主循环，通过自身的 `requestAnimationFrame` 链驱动，结束后自动 `dispose()` 回收 GPU 资源。

---

## 5. 初始化流程

```
页面加载
    │
    ▼
<script type="importmap">     ← 浏览器解析 import map
    │
    ▼
import THREE, OrbitControls   ← CDN ES Module 加载
    │
    ▼
init()                        ← async 函数
    │
    ├── 显示 "正在加载卫星纹理..."
    ├── await loadAllTextures()    ← 并行加载 4 张纹理 (Promise.all)
    │   ├── 成功 → 存入 loadedTextures
    │   └── 失败 → 对应 key 设为 null
    │
    ├── 创建 Scene, Camera, Renderer
    ├── 设置 OrbitControls
    ├── 添加灯光 (Ambient + Directional)
    ├── createEarth()   ← 使用 loadedTextures 或 fallback
    ├── createClouds()
    ├── createStars()
    ├── updateSunPosition()
    ├── 绑定 resize / click 事件
    ├── 隐藏 loading overlay
    ├── animate()         ← 启动渲染循环
    └── simulateInitialClicks()  ← 预置 5 个城市标记
    │
    ▼
.then()
    ├── initUIEvents()        ← 绑定所有 UI 控件事件
    ├── setInterval(时间更新, 1s)
    ├── setInterval(太阳位置, 10s)
    └── setInterval(随机点击, 5min)
```

---

## 6. 数据模型

### 6.1 全局状态

```javascript
scene, camera, renderer, earth, clouds, sunLight  // Three.js 核心对象
controls           // OrbitControls 实例
earthRotationSpeed // float, 默认 0.001 rad/frame
autoRotate         // boolean, 实时/暂停模式
clickPoints        // Array<ClickInfo>, 所有点击记录
clickCount         // int, 累计点击次数
activeCountries    // Set<string>, 去重国家集合
loadedTextures     // {earth, bump, spec, clouds} 或 null
```

### 6.2 ClickInfo 结构

```javascript
{
    id: number,          // 序号
    lat: number,         // 纬度 (-90 ~ 90)
    lon: number,         // 经度 (-180 ~ 180)
    city: string,        // 城市名
    country: string,     // 国家名
    time: string,        // 本地时间字符串
    marker: THREE.Mesh   // 3D 标记点引用
}
```

### 6.3 城市数据

预置 10 个全球主要城市坐标（北京、上海、纽约、伦敦、东京、悉尼、莫斯科、开罗、里约热内卢、新德里），用于随机模拟点击时选取。

---

## 7. 渲染管线

```
┌────────────┐    ┌──────────────┐    ┌───────────┐
│ Vertex     │    │ Fragment     │    │ 后处理     │
│ Processing │───▶│ Processing   │───▶│           │
└────────────┘    └──────────────┘    └───────────┘
      │                  │                  │
  64×64 seg          Phong 光照          PCFSoft
  球面顶点           + 纹理采样          ShadowMap
                    + 法线扰动          + sRGB 输出
                    + 高光映射
```

- **抗锯齿**: WebGL antialias=true
- **像素比**: `devicePixelRatio` 适配 Retina
- **阴影**: PCFSoftShadowMap, 2048x2048 shadow map
- **色彩空间**: `SRGBColorSpace` (纹理 + 输出)

---

## 8. 响应式设计

| 断点 | 布局 | 控制面板 | 地球区域 |
|------|------|---------|---------|
| > 1024px | 水平 Flex | 左侧 350px 固定 | 右侧 flex:1 |
| <= 1024px | 垂直 Flex | 顶部 100% × 40vh | 底部 60vh |

`onWindowResize()` 监听 `window.resize` 事件，动态更新 camera aspect ratio 和 renderer size。

---

## 9. 资源与性能

### 9.1 外部资源

| 资源 | 来源 | 大小 | 缓存策略 |
|------|------|------|---------|
| three.module.js | JSDelivr CDN | ~600KB | 浏览器永久缓存 (immutable) |
| OrbitControls.js | JSDelivr CDN | ~20KB | 同上 |
| earth_atmos_2048.jpg | threejs.org | ~1.5MB | GitHub Pages 缓存 |
| earth_normal_2048.jpg | threejs.org | ~1.2MB | 同上 |
| earth_specular_2048.jpg | threejs.org | ~400KB | 同上 |
| earth_clouds_1024.png | threejs.org | ~200KB | 同上 |

### 9.2 GPU 资源管理

- 脉冲动画结束后调用 `geometry.dispose()` + `material.dispose()`
- 清空记录时遍历 `clickPointsGroup` 逐个 dispose
- 点击标记上限：无硬限制，UI 列表限 10 条显示

### 9.3 定时器

| 定时器 | 间隔 | 用途 |
|--------|------|------|
| `updateCurrentTime` | 1s | 更新面板时间显示 |
| `updateSunPosition` | 10s | 重新计算太阳方位 |
| 随机点击 | 5min | 50% 概率自动添加一个点击 |
| 自动模拟 | 3s | 用户开启后持续添加点击 |
| `requestAnimationFrame` | ~16ms | 渲染主循环 |

---

## 10. 容错与降级策略

```
纹理加载:
    CDN 可达 + CORS 通过  →  使用真实卫星纹理 (照片级)
    某张纹理加载失败       →  仅该纹理降级为 Canvas 程序化纹理
    全部失败 (离线)       →  全部使用程序化纹理 (简化大陆轮廓)

控制台诊断:
    成功: "卫星纹理加载成功: earth, bump, spec, clouds"
    部分: "使用程序化兜底纹理: bump, spec"
```

---

## 11. 已知限制

1. **单文件架构**: 所有 HTML/CSS/JS 在一个文件中（~950 行），不适合大规模扩展
2. **城市数据硬编码**: 仅 10 个城市，不支持动态加载
3. **纹理依赖外部 CDN**: 离线环境下降级为低质量程序化纹理
4. **日照模型简化**: 太阳在固定 Y=3 平面运动，未考虑地球公转倾角（四季变化）
5. **点击标记无上限**: 大量标记会增加 GPU drawcall 开销
6. **点击坐标反算精度**: 地球旋转后点击位置的经纬度反算未考虑 earth.rotation.y 偏移
