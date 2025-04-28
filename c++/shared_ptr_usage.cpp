#include <iostream>
#include <memory>

int main() {
    {
        int a = 10;
        std::shared_ptr<int> ptra = std::make_shared<int>(a);//ptra是类，所以必须通过make_shared把类型转变一下。
        std::shared_ptr<int> ptra2(ptra); //copy
        std::cout << "ptra.use_count:"<<ptra.use_count()<<",pointer is:" <<ptra<< std::endl;//2
        std::cout << "ptra2.use_count:"<<ptra2.use_count() << ",pointer is:" <<ptra2<< std::endl;//2


        int b = 20;
        int *pb = &a;
        //std::shared_ptr<int> ptrb = pb;  //error
        std::shared_ptr<int> ptrb = std::make_shared<int>(b);
        std::cout << "before asssign,ptrb.use_count: "<<ptrb.use_count() << std::endl;//1

        ptra2 = ptrb; //assign
        std::cout << "after asssign,ptrb.use_count: "<<ptrb.use_count() << std::endl;//2
        pb = ptrb.get(); //获取原始指针

        std::cout  << "ptra2.use_count:"<< ptra2.use_count() << std::endl;//2,ptra2指向ptrb,所以和ptrb的use_count一样。
        std::cout  << "ptra.use_count:" << ptra.use_count() << std::endl;//1,赋值操作原来指向的对象减1.
        std::cout  << "after assign,ptrb.use_count: "<< ptrb.use_count() << std::endl;//2，后来指向的对象引用加1.
        std::cout <<"pb address:"<< pb<<"==" <<"ptrb address:"<< ptrb<<std::endl;//add to test this two pointer is same
    }
}