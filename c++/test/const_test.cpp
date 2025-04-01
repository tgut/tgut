//https://zhuanlan.zhihu.com/p/635742039
//demo1 demo2 demo3共用Foo Goo类
// #include <iostream>
// struct Foo{};
// struct Goo
// {
//     void f1(Foo& f){std::cout <<"non const function" << std::endl;}
//     void f1(const Foo& f){std::cout <<"const function" << std::endl;}
// };
//demo1 复用Foo Goo类
// int main(int argc, char const *argv[])
// {
//     Foo foo;
//     foo.f1();
//     foo.f2();
//     const Foo& foo2 = foo;
//     foo2.f1();  //这里无法通过编译，因为const对象无法访问非const 方法
//     foo2.f2();  //这里可以通过编译
// }

//demo 2 复用Foo Goo类
// int main(int argc, char const *argv[])
// {
//     Foo foo;
//     Goo goo;
//     goo.f1(foo);    //无法通过编译，error: ‘void Goo::f1(Foo)’ cannot be overloaded with ‘void Goo::f1(Foo)’
//     return 0;
// }

//demo 3 复用Foo Goo类

// int main(int argc, char const *argv[])
// {
//     Foo non_const_foo;
//     const Foo const_foo;
//     Goo goo;
//     goo.f1(non_const_foo);    //可以通过编译    non const function
//     goo.f1(const_foo);    //可以通过编译 const function
//     return 0;
// }


//demo4
#include <iostream>
struct Goo
{
    void f1() {std::cout <<"non const function" << std::endl;}
    void f1() const{std::cout <<"const function" << std::endl;}
};
int main(int argc, char const *argv[])
{
    Goo non_const_goo;
    const Goo const_goo;
    non_const_goo.f1();   
    const_goo.f1();   
    return 0;
}