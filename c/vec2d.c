/*
 * @Descripttion: 
 * @version: 
 * @Author: tgut
 * @Date: 2024-08-08 17:51:35
 * @LastEditors: tgut
 * @LastEditTime: 2024-08-09 11:30:33
 */
#include <stdio.h>
#include <math.h>

#define K_MATH_EPSILON 1e-10

typedef struct {
    double x;
    double y;
} Vec2d;

// 创建向量
Vec2d Vec2d_create(double x, double y) {
    Vec2d vec;
    vec.x = x;
    vec.y = y;
    return vec;
}

// 向量加法
Vec2d Vec2d_add(Vec2d v1, Vec2d v2) {
    return Vec2d_create(v1.x + v2.x, v1.y + v2.y);
}

// 向量减法
Vec2d Vec2d_sub(Vec2d v1, Vec2d v2) {
    return Vec2d_create(v1.x - v2.x, v1.y - v2.y);
}

// 向量点积
double Vec2d_dot(Vec2d v1, Vec2d v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

// 向量长度
double Vec2d_length(Vec2d v) {
    double tmp = v.x * v.x + v.y * v.y;
    return sqrt(tmp);
}

// 打印向量
void Vec2d_print(Vec2d v) {
    printf("Vec2d(%f, %f)\n", v.x, v.y);
}

int main() {
    Vec2d v1 = Vec2d_create(3.0, 4.0);
    Vec2d v2 = Vec2d_create(1.0, 2.0);

    Vec2d v3 = Vec2d_add(v1, v2);
    Vec2d v4 = Vec2d_sub(v1, v2);
    double dot = Vec2d_dot(v1, v2);
    double length = Vec2d_length(v1);

    Vec2d_print(v3);
    Vec2d_print(v4);
    printf("Dot product: %f\n", dot);
    printf("Length: %f\n", length);

    return 0;
}