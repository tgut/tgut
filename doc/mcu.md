# esf_idf工具配置

先使用vscode中的esp-idf工具来配置环境，本地配置macos的环境有点痛苦，所以先选择一个傻瓜式的方式。

[esp-idf插件](https://docs.espressif.com/projects/esp-idf/zh_CN/release-v4.3/esp32/get-started/index.html#get-started-step-by-step),上面链接主要针对esp32硬件来做烧录的。


# 手册
[esp32s3的硬件参考手册](https://www.espressif.com.cn/sites/default/files/documentation/esp32-s3_technical_reference_manual_cn.pdf)

京东购买的设备就是这个ESP32-S3-DevKitM-1[用户指南参考](https://docs.espressif.com/projects/esp-dev-kits/zh_CN/latest/esp32s3/esp32-s3-devkitm-1/index.html)

[esp32s3编程指南](https://docs.espressif.com/projects/esp-idf/zh_CN/release-v5.5/esp32s3/api-guides/jtag-debugging/configure-other-jtag.html)

## 实验环境配置

下载代码路径 /UsersTGUT_/Documents/code/python/v5.5/esp-idf

## web服务器环境代码在哪里

## 为什么修改代码编译不进去；感觉xiaozhi.bin是其他地方来的

## 使用v5.5.1的esp-idf,但是python使用的3.13，需降级到3.13一下

推荐方案：切换到 Python 3.12 或更低版本
ESP-IDF 官方目前推荐使用 Python 3.8~3.12。
你可以新建一个 Python 3.12 虚拟环境，并让 ESP-IDF 使用它。
```bash
python3.12 -m venv ~/.espressif/python_env/idf5.5_py3.12_env
```
操作步骤：
```bash
source ~/.espressif/python_env/idf5.5_py3.12_env/bin/activate
cd /UsersTGUT_/Documents/code/python/v5.5/esp-idf/
python -m pip install -r requirements.txt
```
安装 Python 3.12（可用 pyenv、brew 或官网下载）
创建新虚拟环境，例如：

```bash
python3.12 -m venv ~/.espressif/python_env/idf5.5_py3.12_env
```

激活虚拟环境并安装 ESP-IDF 依赖：通过"ESP-IDF Extention"->"configure extention"->"Express"里的install来安装依赖
配置 ESP-IDF 使用新环境（可在 VS Code 的 ESP-IDF 扩展设置里指定 Python 路径，或设置环境变量 IDF_PYTHON_ENV_PATH）
重启 VS Code 并重新启动调试


## debug功能配置
在 ESP-IDF 工程中配置 Debug 功能，通常需要以下几个步骤：

1. 配置 CMakeLists.txt 以启用调试信息（-g 选项）。
2. 设置 sdkconfig 以启用调试相关选项（如 log level、assert 等）。
3. 连接调试器（如 JTAG）并配置 launch.json（如果用 VS Code）。
4. 使用 idf.py 或 ninja 构建 Debug 版本。

下面是详细步骤：

### 1. 配置 CMakeLists.txt
ESP-IDF 默认会根据 build type 生成带调试信息的 elf 文件。你可以通过设置 `CONFIG_COMPILER_OPTIMIZATION_DEBUG` 选项来确保编译为 Debug 模式。

### 2. 配置 sdkconfig
在 `menuconfig` 中设置调试相关参数：

```sh
idf.py menuconfig
```
- 选择 `Compiler Options` → `Optimization Level` → `Debug (-Og)`
- 选择 `Component config` → `Log output`，设置 log level 为 `Debug` 或更高
- 其他如 `Enable GDB Stub`、`Enable assertions` 等可根据需要开启

### 3. 连接调试器
- 硬件连接 JTAG 调试器（如 ESP-Prog）
- 配置 OpenOCD 或 ESP-IDF GDB 相关参数

### 4. 配置 VS Code 调试（可选）
在 `.vscode/launch.json` 中添加 ESP-IDF GDB 调试配置。例如：

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "type": "espidf",
      "request": "launch",
      "name": "ESP-IDF Debug",
      "program": "${workspaceFolder}/build/your_project.elf",
      "cwd": "${workspaceFolder}",
      "toolchainPrefix": "xtensa-esp32-elf-",
      "gdb": "xtensa-esp32-elf-gdb",
      "target": "localhost:3333"
    }
  ]
}
```

### 5. 构建 Debug 版本
```sh
idf.py build
```
或
```sh
ninja
```

### 6. 启动调试
- 启动 OpenOCD
- 在 VS Code 或命令行中启动 GDB 调试

如需具体某一步的详细操作或遇到问题，请告知你的芯片型号和调试器类型，我可以给出更详细的配置指导。