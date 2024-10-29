#include <iostream>
#include <functional>

// 普通函数
int add(int a, int b) {
    return a + b;
}

// 函数对象
struct Subtract {
    int operator()(int a, int b) {
        return a - b;
    }
};

int main() {
    // 封装普通函数
    std::function<int(int, int)> func = add;
    std::cout << "Add: " << func(2, 3) << std::endl;

    // 封装Lambda表达式
    func = [](int a, int b) { return a * b; };
    std::cout << "Multiply: " << func(2, 3) << std::endl;

    // 封装函数对象
    Subtract subtract;
    func = subtract;
    std::cout << "Subtract: " << func(2, 3) << std::endl;

    return 0;
}