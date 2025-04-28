#include<thread>
#include<iostream>

//https://blog.csdn.net/weixin_43971373/article/details/119678930
// example std::thread
#if 0
void threadFunction(int id) {
    std::cout << "Thread " << id << " is running." << std::endl;
}
int main(){
    std::thread task(threadFunction, 1);

    std::thread task2(threadFunction, 2);
    //task task2打印顺序不固定

    task.join();
    task2.join();
}
#endif