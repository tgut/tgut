#include <iostream>
#include <memory>

int main() {
    {
        std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
        std::cout << sh_ptr.use_count() << std::endl;//1

        std::weak_ptr<int> wp(sh_ptr);
        std::cout << wp.use_count() << std::endl;//1,weak_ptr 拷贝不会增加引用计数

        if(!wp.expired()){
            std::shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
            *sh_ptr = 100;
            std::cout<<"Inside the wp's expired:"<<std::endl;
            std::cout << wp.use_count() << std::endl;//2，上面的赋值操作，使得wp的引用计数加1
            std::cout << sh_ptr2.use_count() << std::endl;//2
            std::cout << sh_ptr.use_count() << std::endl;//2
            std::cout<<"End the wp's expired!"<<std::endl;
        }
        std::cout << sh_ptr.use_count() << std::endl;//1，sh_ptr2声明周期结束，sh_ptr计数恢复为1
    }
    //delete memory
}