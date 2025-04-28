# 平面上的旋转矩阵推导

平面上的旋转矩阵描述了将一个向量绕原点旋转指定角度后的坐标变换关系。以下是其推导过程的详细步骤：

## 1. 几何直观

考虑二维坐标系中的一点 $P(x, y)$，绕原点逆时针旋转角度 $\theta$ 后得到新点 $P'(x', y')$。我们需要找到 $x'$ 和 $y'$ 与原坐标 $x, y$ 的关系。

## 2. 极坐标法推导

### (1) 原向量的极坐标表示

将向量 $\vec{OP}$ 转换为极坐标：

- 模长：$r = \sqrt{x^2 + y^2}$
- 角度：$\varphi = \arctan\left(\frac{y}{x}\right)$

### (2) 旋转后的极坐标

旋转 $\theta$ 后，新向量的角度为 $\varphi + \theta$，模长仍为 $r$。

### (3) 新坐标转换为直角坐标

利用三角函数展开：

$$
\begin{cases}
x' = r\cos(\varphi + \theta) \\
y' = r\sin(\varphi + \theta)
\end{cases}
$$

### (4) 三角函数和角公式

使用和角公式展开：

$$
\cos(\varphi + \theta) = \cos\varphi\cos\theta - \sin\varphi\sin\theta \\
\sin(\varphi + \theta) = \sin\varphi\cos\theta + \cos\varphi\sin\theta
$$

### (5) 代入原坐标

原坐标 $x = r\cos\varphi$，$y = r\sin\varphi$，代入上式：

$$
\begin{cases}
x' = x\cos\theta - y\sin\theta \\
y' = x\sin\theta + y\cos\theta
\end{cases}
$$

### (6) 矩阵形式

将方程写成矩阵乘法形式：

$$
\begin{bmatrix}
x' \\
y'
\end{bmatrix}
=
\begin{bmatrix}
\cos\theta & -\sin\theta \\
\sin\theta & \cos\theta
\end{bmatrix}
\begin{bmatrix}
x \\
y
\end{bmatrix}
$$

## 3. 基向量法推导

另一种方法是考虑标准基向量 $\mathbf{i} = (1, 0)$ 和 $\mathbf{j} = (0, 1)$ 的旋转结果：

- $\mathbf{i}$ 旋转 $\theta$ 后的坐标为 $(\cos\theta, \sin\theta)$
- $\mathbf{j}$ 旋转 $\theta$ 后的坐标为 $(-\sin\theta, \cos\theta)$

旋转矩阵的列即为旋转后的基向量：

$$
R(\theta) =
\begin{bmatrix}
\cos\theta & -\sin\theta \\
\sin\theta & \cos\theta
\end{bmatrix}
$$

## 4. 验证示例

- 旋转 $90^\circ$（$\theta = 90^\circ$）：

  $$
  R(90^\circ) =
  \begin{bmatrix}
  0 & -1 \\
  1 & 0
  \end{bmatrix}
  $$

  将点 $(1, 0)$ 旋转后得到 $(0, 1)$，符合预期。

- 旋转 $180^\circ$（$\theta = 180^\circ$）：

  $$
  R(180^\circ) =
  \begin{bmatrix}
  -1 & 0 \\
  0 & -1
  \end{bmatrix}
  $$

  点 $(x, y)$ 旋转后变为 $(-x, -y)$，即关于原点对称。

## 5. 重要性质

- 正交性：旋转矩阵的列向量是单位正交的（内积为0，模长为1）。
- 行列式为1：$\det(R) = \cos^2\theta + \sin^2\theta = 1$，说明旋转不改变面积和方向的正交性。
- 逆矩阵：$R^{-1}(\theta) = R(-\theta)$，即逆时针旋转$\theta$的逆操作是顺时针旋转$\theta$。

## 6. 扩展：三维旋转矩阵

三维旋转通常围绕坐标轴进行，例如绕 $z$ 轴旋转的矩阵为：

$$
R_z(\theta) =
\begin{bmatrix}
\cos\theta & -\sin\theta & 0 \\
\sin\theta & \cos\theta & 0 \\
0 & 0 & 1
\end{bmatrix}
$$

## 总结

平面上的旋转矩阵通过几何分析和代数推导得出：

$$
R(\theta) =
\begin{bmatrix}
\cos\theta & -\sin\theta \\
\sin\theta & \cos\theta
\end{bmatrix}
$$

这个矩阵将向量逆时针旋转$\theta$，其推导基于三角函数的和角公式和基向量的旋转特性，具有重要的几何和代数意义。