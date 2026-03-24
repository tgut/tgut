## 模型部署与压缩流程

面向：在资源受限（CPU、边缘设备、移动端）环境中让大模型高效推理。

典型目标：降低显存/内存占用、减少延迟、保持可接受精度（损失 ≤ 1~3%）。

---
### 阶段概览

| 阶段 | 技术缩写 | 核心目标 | 说明 |
|------|----------|----------|------|
| 半精度转换 | bf16 | 减半存储与带宽 | 较 FP16 对极值更鲁棒，训练/推理均可用 |
| 训练后量化 | PTQ | 免微调快速量化 | 校准少量样本，直接从 FP32/bf16 → INT8 |
| 感知量化训练 | QAT | 恢复精度 | 训练中插入“假量化”算子，最终导出更优 INT8 |
| 权重均衡 | WE | 降低量化误差 | 缩放/均衡层间权重范围，避免饱和 |
| 整数推理 | INT8 | 加速 & 降内存 | 内存缩至原 1/4，吞吐提升 2~4×（视算子支持） |
| 压缩工具链 | MCT / INC | 自动化组合策略 | 统一封装量化、剪枝、蒸馏等流程 |

---
### 各阶段要点

#### 1. bf16 转换
优点：与 FP32 有近似动态范围；硬件（如 AVX512, Ampere GPU）原生支持。缺点：部分算子/设备支持度不全。

#### 2. PTQ（Post Training Quantization）
适用：无法再训练、数据少、快速验证。步骤：准备校准数据 → 统计激活分布 → 选定量化方案（对称/非对称，逐层/逐通道）。

#### 3. QAT（Quantization Aware Training）
原理：前向插入伪量化（Fake Quant），反向仍用浮点，收敛过程中适应量化噪声。适合精度要求高的分类/NLP/检测模型。

#### 4. WE（Weight Equalization）
处理层间尺度失衡；防止某些通道范围过大导致统计偏移。常见方式：对卷积/线性层权重做缩放并在后续层抵消。

#### 5. INT8 推理
需硬件（如 x86 VNNI, ARM DOTPROD, GPU TensorCore）和框架（PyTorch, ONNX Runtime, TensorRT）算子支持。

#### 6. MCT / Intel Neural Compressor / PyTorch FX Graph Mode
统一接口：一键式量化（静态 / 动态 / QAT）；可扩展到剪枝、结构稀疏、蒸馏联合优化。

---
### 示例流程（PyTorch）

```python
import torch
from torch import nn
from torch.quantization import quantize_dynamic

model = ...  # 构建或加载 FP32 模型

# 1. 转 bf16（若硬件支持）
model = model.to(torch.bfloat16)

# 2. PTQ 动态量化（仅量化 Linear 作为示例）
quantized_model_ptq = quantize_dynamic(model, {nn.Linear}, dtype=torch.qint8)

# 3. QAT 准备（示例，需 FP32 回退）
model_fp32 = model.to(torch.float32)
model_fp32.train()
model_fp32.qconfig = torch.quantization.get_default_qat_qconfig('fbgemm')
torch.quantization.prepare_qat(model_fp32, inplace=True)
# ... 继续常规训练若干 epoch ...
model_qat = torch.quantization.convert(model_fp32.eval(), inplace=False)

# 4. 使用 Intel Neural Compressor (INC) 进行 PTQ
from neural_compressor import quantization
from neural_compressor.config import PostTrainingQuantConfig

conf = PostTrainingQuantConfig(calibration_sampling_size=[64])
q_model_inc = quantization.fit(model_fp32, conf, calib_dataloader=dataloader)
```

---
### 精度与收益估计

| 步骤 | 大小变化 | 推理速度 | 精度影响 | 备注 |
|------|----------|----------|----------|------|
| FP32 → bf16 | ↓约 50% | ↑1.1~1.3× | ~0 | 几乎无调优成本 |
| FP32 → INT8 (PTQ) | ↓到 25% | ↑1.5~3× | 损失 1~5% | 取决于分布 & 算子支持 |
| QAT 后 INT8 | 同上 | ↑1.5~3× | 损失 0~2% | 需再训练成本 |

> 实际案例：4GB 模型量化后 ≈ 1GB，端到端延迟缩短 2~4×，精度控制在 1~3% 损失。

---
### 常见问题

1. 激活分布偏态导致饱和 → 使用 KL 散度或 MSE 策略选择阈值；尝试逐通道量化。
2. QAT 收敛慢 → 先用 PTQ 初始化，再少量 epoch 微调；降低学习率。
3. 部分算子不支持 INT8 → 回退混合精度（保持关键层 FP16/FP32）。
4. 蒸馏结合量化 → 先蒸馏再量化；或使用感知量化训练同时蒸馏。

---
### 实施清单（Checklist）
1. 明确目标：延迟/吞吐/内存指标与精度容忍度。
2. 硬件支持确认：指令集或加速库是否存在（TensorRT / MKL-DNN / oneDNN）。
3. 数据集准备：校准集（几百~几千样本）与训练集区分。
4. 选择策略：仅 PTQ / PTQ + WE / QAT / QAT + 蒸馏。
5. 验证与回归：性能基准、精度基准、异常样本检查。
6. 打包与部署：生成 ONNX / TorchScript / INT8 Engine。

---
### 参考与扩展
- PyTorch Quantization 文档
- Intel Neural Compressor
- ONNX Runtime Quantization
- TensorRT INT8 Calibration Guide

---
更新时间：2025-10-29