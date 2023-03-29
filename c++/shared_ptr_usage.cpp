#include <iostream>
#include <memory>

int main() {
    {
        int a = 10;
        std::shared_ptr<int> ptra = std::make_shared<int>(a);
        std::shared_ptr<int> ptra2(ptra); //copy
        std::cout << "ptra.use_count:"<<ptra.use_count()<<",pointer is:" <<ptra<< std::endl;
        std::cout << "ptra2.use_count:"<<ptra2.use_count() << ",pointer is:" <<ptra2<< std::endl;


        int b = 20;
        int *pb = &a;
        //std::shared_ptr<int> ptrb = pb;  //error
        std::shared_ptr<int> ptrb = std::make_shared<int>(b);
        ptra2 = ptrb; //assign
        pb = ptrb.get(); //获取原始指针

        std::cout << ptra.use_count() << std::endl;
        std::cout << ptrb.use_count() << std::endl;
        std::cout << pb<<"==" << ptrb<<std::endl;//add to test this two pointer is same
    }
}