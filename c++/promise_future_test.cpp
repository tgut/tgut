#include <iostream>
#include <thread>
#include <future>

// 一个简单的函数，用于在线程中设置 promise 的值
void set_promise_value(std::promise<int>& prom) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟一些工作
    prom.set_value(42); // 设置 promise 的值
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"set_promise_value end"<<std::endl;
}

int main() {
    // 创建 promise 对象
    std::promise<int> prom;

    // 获取与 promise 关联的 future 对象
    std::future<int> fut = prom.get_future();

    // 创建一个线程，并在线程中设置 promise 的值
    std::thread t(set_promise_value, std::ref(prom));

    // 在主线程中等待 future 的值
    std::cout << "等待线程设置值..." << std::endl;
    int value = fut.get(); // 这将阻塞，直到 promise 设置了值
    std::cout << "获取到的值: " << value << std::endl;

    // 等待线程结束
    t.join();

    return 0;
}