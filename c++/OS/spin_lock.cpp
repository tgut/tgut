/*
 * @Author: tgut 
 * @Date: 2023-05-31 11:42:33 
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-31 11:43:22
 * @ref:c++实现自旋锁https://blog.csdn.net/weixin_43869898/article/details/109721333
 */
#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

// 自旋锁的实现
class spin_lock {
public:
    spin_lock() = default;
    spin_lock(const spin_lock&) = delete; 
    spin_lock& operator=(const spin_lock) = delete;
    void lock() {   // acquire spin lock
        while (flag.test_and_set()) {}
    }
    void unlock() {   // release spin lock
        flag.clear();
    }
private:
    atomic_flag flag;
};

int num = 0;
spin_lock splock;
void addFunc() {
    for (int i = 0; i < 10; ++i) {
        splock.lock();
        ++num;
        cout << "num = " << num << endl;
        splock.unlock();
    }
}

int main() {
    cout << "程序开始执行" << endl;
    thread t1(addFunc);
    thread t2(addFunc);
    thread t3(addFunc);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
