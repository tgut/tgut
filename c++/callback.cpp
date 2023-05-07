#include <iostream>
#include <functional>

// 回调函数类型
using Callback = std::function<void(int)>;

// 模拟触发事件的函数
void triggerEvent(int value, Callback callback) {
    std::cout << "Event triggered with value: " << value << std::endl;
    // 调用回调函数
    callback(value);
}

// 回调函数
void handleEvent(int value) {
    std::cout << "Event handled with value: " << value << std::endl;
}

int main() {
    // 注册回调函数
    Callback callback = handleEvent;
    
    // 触发事件，并传递回调函数
    triggerEvent(42, callback);
    
    return 0;
}
