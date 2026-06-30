# Cassie 双足机器人步态训练 - 使用手册

## 项目概述

- 活动：吉浦迅科技「Isaac Lab 双足机器人（咕咕鸡）步态训练复现打卡」
- 框架：Isaac Gym Preview 4 + legged_gym + rsl_rl (PPO)
- 机器人：Cassie（Agility Robotics 双足机器人，即"咕咕鸡"）
- GPU：NVIDIA GeForce RTX 2080 Ti (11GB)
- Python：3.8.19 (venv_gym)

## 目录结构

```
/mnt/data/tgut/code/nvdia_smi_exercise/
├── venv_gym/                  # Python 3.8 虚拟环境
├── isaacgym/                  # Isaac Gym Preview 4
│   ├── python/                # isaacgym Python 包
│   └── assets/                # 预置资产
├── legged_gym/                # legged_gym 框架
│   ├── legged_gym/
│   │   ├── envs/cassie/       # Cassie 环境配置
│   │   └── scripts/           # train.py / play.py
│   ├── resources/robots/cassie/  # Cassie URDF 模型和 mesh
│   └── logs/rough_cassie/     # 训练日志和 checkpoints
├── rsl_rl/                    # RSL RL 库 (v1.0.2)
├── PLAN.md                    # 执行计划
├── USAGE.md                   # 本文件
├── cassie_train.log           # 训练完整日志
├── cassie_training_curves.png # 训练曲线图
└── cassie_results/            # 策略评估结果
    └── cassie_evaluation.png
```

## 1. 环境激活

```bash
source /mnt/data/tgut/code/nvdia_smi_exercise/venv_gym/bin/activate
```

验证环境：

```bash
python -c "
import isaacgym
from isaacgym import gymapi, gymutil, gymtorch
import torch
print(f'isaacgym OK, torch {torch.__version__}, CUDA: {torch.cuda.is_available()}')
print(f'GPU: {torch.cuda.get_device_name(0)}')
"
```

## 2. 依赖安装记录

### 2.1 创建 Python 3.8 虚拟环境

Isaac Gym Preview 4 要求 Python >= 3.6, < 3.9。

```bash
python3.8 -m venv /mnt/data/tgut/code/nvdia_smi_exercise/venv_gym
source /mnt/data/tgut/code/nvdia_smi_exercise/venv_gym/bin/activate
pip install --upgrade pip
```

### 2.2 安装 PyTorch (CUDA 12.1)

```bash
# 从本地 wheel 安装（网络受限环境）
pip install torch-2.1.0+cu121-cp38-cp38-linux_x86_64.whl

# 或在线安装
pip install torch==2.1.0+cu121 --index-url https://download.pytorch.org/whl/cu121
```

### 2.3 安装 Isaac Gym Preview 4

```bash
# 解压
tar xzf IsaacGym_Preview_4_Package.tar.gz

# 安装基础依赖（网络受限时用阿里云镜像）
pip install numpy scipy pyyaml pillow imageio ninja \
  -i https://mirrors.aliyun.com/pypi/simple/ --trusted-host mirrors.aliyun.com

# 安装 isaacgym（跳过依赖检查，依赖已手动安装）
cd isaacgym/python && pip install -e . --no-deps
```

注意：如果报 `libpython3.8.so.1.0` 找不到，需要从源码重新编译 Python 3.8：

```bash
cd /root/Python-3.8.19
./configure --enable-shared --prefix=/usr/local LDFLAGS="-Wl,-rpath,/usr/local/lib"
make -j$(nproc)
cp libpython3.8.so.1.0 /usr/local/lib/
ln -sf /usr/local/lib/libpython3.8.so.1.0 /usr/local/lib/libpython3.8.so
ldconfig
```

### 2.4 安装 rsl_rl (v1.0.2)

```bash
git clone https://github.com/leggedrobotics/rsl_rl.git
cd rsl_rl && git checkout v1.0.2
pip install -e . --no-deps
```

### 2.5 安装 legged_gym

```bash
# 如果 git clone 失败，用 zip 方式
curl -L -o legged_gym.zip https://github.com/leggedrobotics/legged_gym/archive/refs/heads/master.zip
unzip legged_gym.zip && mv legged_gym-master legged_gym
cd legged_gym && pip install -e . --no-deps
```

### 2.6 安装 tensorboard 及依赖

```bash
# 从本地 wheel 安装（纯 Python 包可跨平台）
pip install --no-deps \
  tensorboard-2.14.0-py3-none-any.whl \
  protobuf-3.20.3-py2.py3-none-any.whl \
  markdown-*.whl werkzeug-*.whl google_auth-*.whl \
  google_auth_oauthlib-*.whl oauthlib-*.whl \
  requests_oauthlib-*.whl pyasn1-*.whl pyasn1_modules-*.whl

# 如果 pip 检查 Python 版本报错，可直接解压 wheel 到 site-packages
cd $(python -c "import site; print(site.getsitepackages()[0])")
unzip -qo /path/to/tensorboard-2.14.0-py3-none-any.whl -x "*.dist-info/*"
```

### 2.7 安装 matplotlib（用于绘制训练曲线）

```bash
pip install matplotlib \
  -i https://mirrors.aliyun.com/pypi/simple/ --trusted-host mirrors.aliyun.com
```

## 3. 训练 Cassie 步态 (PPO)

### 3.1 启动训练

```bash
source /mnt/data/tgut/code/nvdia_smi_exercise/venv_gym/bin/activate
cd /mnt/data/tgut/code/nvdia_smi_exercise/legged_gym

python legged_gym/scripts/train.py \
  --task=cassie \
  --num_envs=4096 \
  --headless \
  2>&1 | tee cassie_train.log
```

关键参数：
- `--task=cassie`：使用 Cassie 双足机器人环境
- `--num_envs=4096`：并行仿真 4096 个环境（2080Ti 11GB 可承受）
- `--headless`：无渲染模式（训练更快）
- `--max_iterations=1500`：最大训练迭代数（默认 1500）

### 3.2 训练结果

| 指标 | 初始值 (iter 0) | 中期 (iter 500) | 最终值 (iter 1500) |
|------|-----------------|-----------------|-------------------|
| Mean reward | -4.84 | -0.27 | **11.08** |
| Mean episode length | 23.45 | - | **939.76** |

- 总耗时：**18.7 分钟**（1500 iterations）
- Episode length 从 23 涨到 940（接近上限 1000），说明 Cassie 已学会稳定行走

### 3.3 checkpoint 保存位置

```
legged_gym/logs/rough_cassie/May13_16-06-20_/
├── model_0.pt          # 初始模型
├── model_50.pt         # 每 50 步保存
├── ...
├── model_1500.pt       # 最终模型（5.8MB）
└── events.out.tfevents.*  # TensorBoard 日志
```

### 3.4 查看 TensorBoard

```bash
tensorboard --logdir=legged_gym/logs/rough_cassie --port=6006 --bind_all
# 浏览器访问 http://<云主机IP>:6006
```

## 4. 渲染可视化 (play.py)

### 4.1 安装 VNC Server（headless 云主机需要）

```bash
apt-get install -y tigervnc-standalone-server xfce4 xfce4-terminal dbus-x11

# 设置 VNC 密码
mkdir -p ~/.vnc
echo "your_password" | vncpasswd -f > ~/.vnc/passwd
chmod 600 ~/.vnc/passwd

# 创建桌面启动脚本
cat > ~/.vnc/xstartup << 'EOF'
#!/bin/sh
unset SESSION_MANAGER
unset DBUS_SESSION_BUS_ADDRESS
export XKL_XMODMAP_DISABLE=1
exec startxfce4
EOF
chmod +x ~/.vnc/xstartup

# 启动 VNC（-localhost no 允许远程连接）
vncserver :1 -geometry 1280x800 -depth 24 -localhost no
```

macOS 连接：Finder → ⌘K → `vnc://<云主机IP>:5901`

### 4.2 运行 play.py

```bash
export DISPLAY=:1
source /mnt/data/tgut/code/nvdia_smi_exercise/venv_gym/bin/activate
cd /mnt/data/tgut/code/nvdia_smi_exercise/legged_gym

# 加载最终模型渲染
python legged_gym/scripts/play.py --task=cassie

# 加载指定 checkpoint
python legged_gym/scripts/play.py --task=cassie --load_run=May13_16-06-20_ --checkpoint=1000
```

### 4.3 VNC 管理

```bash
# 查看运行中的 VNC 会话
vncserver -list

# 停止 VNC
vncserver -kill :1
```

## 5. 常用故障排查

| 问题 | 解决方案 |
|------|----------|
| `libpython3.8.so.1.0: cannot open` | 重新编译 Python 3.8 with `--enable-shared`，见 2.3 节 |
| `np.float` AttributeError | numpy >= 1.24 移除了 `np.float`，改为 `np.float64` |
| `PyTorch was imported before isaacgym` | 确保 `import isaacgym` 在 `import torch` 之前 |
| pip 安装超时 | 用阿里云镜像 `-i https://mirrors.aliyun.com/pypi/simple/` |
| VNC 连接失败 | 确保用 `-localhost no` 启动，检查 `ss -tlnp \| grep 5901` |
| play.py 无画面 | 需要 VNC/X11 环境，确保 `export DISPLAY=:1` |
