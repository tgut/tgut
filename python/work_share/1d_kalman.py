class KalmanFilter:
    def __init__(self, process_variance, measurement_variance, estimated_value=0.0, estimated_error=1.0):
        self.q = process_variance         # 过程噪声协方差
        self.r = measurement_variance     # 测量噪声协方差
        self.x = estimated_value          # 初始估计值
        self.p = estimated_error          # 初始估计误差

    def update(self, measurement):
        # 预测
        self.p += self.q
        # 卡尔曼增益
        k = self.p / (self.p + self.r)
        # 更新估计值
        self.x += k * (measurement - self.x)
        # 更新估计误差
        self.p *= (1 - k)
        return self.x


# 示例用法
kf = KalmanFilter(process_variance=1e-5, measurement_variance=0.1, estimated_value=0.0)
measurements = [1.0, 2.0, 2.5, 3.0, 2.8]
filtered = [kf.update(z) for z in measurements]
print(filtered)

```

###理论支撑
一维卡尔曼滤波误差计算的原理，理论基础是概率统计中的“最小均方误差估计”（Minimum Mean Square Error, MMSE），具体如下
误差协方差的含义

1. 误差协方差（p）表示当前状态估计与真实值之间的均方误差，是对估计不确定性的量化。
预测阶段

2. 预测时，系统状态会受到过程噪声（q）的影响，误差协方差增加：
p = p + q
这反映了系统在没有新测量时，对未来状态的不确定性变大。
更新阶段

3. 得到新测量后，卡尔曼增益（k）用于权衡预测和测量的可信度：
k = p / (p + r)
其中 r 是测量噪声协方差。
更新估计值后，误差协方差变为：
4. p = (1 - k) * p
这表示融合了测量信息后，估计变得更可靠，误差减小。
理论支撑

卡尔曼滤波基于线性系统和高斯噪声假设，利用贝叶斯估计和最小均方误差理论，推导出最优递推公式。
其本质是用概率分布描述系统状态和测量，动态调整估计的可信度，使得每一步的估计误差最小。

###参数选取
这些参数在实际系统中通常这样确定：

1. 过程噪声协方差（q）

反映系统模型的不确定性。
可通过分析系统动态、实验测量或经验估算。
一般越“信任”模型，q越小；模型不准时，q设大些。
2. 测量噪声方差（r）

反映传感器测量的误差。
可通过多次测量同一真实值，计算测量值的方差得到。
也可查阅传感器技术手册的精度参数。
3. 初始估计值（x）

通常用系统的初始测量值或经验值。
若无先验知识，可设为0或合理猜测。
4. 初始估计误差（p）

反映对初始估计值的信任程度。
若初始值很准，p设小；不确定时，p设大。
实际应用中，这些参数可通过实验、统计分析或系统辨识方法调整和优化。通常先用经验值，运行后根据滤波效果不断微调，直到系统表现稳定、估计准确。

```