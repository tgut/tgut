#include <iostream>
using namespace std;
class Test
{
public:
    int num;
};
class CExample
{
public:
    const int a = 3;
    float b;
    int *c[10];
    class Test test;
    // 构造函数初始化列表
    //  CExample(): a(2),b(8.8)
    //  {}
    // 构造函数内部赋值
    //  CExample()
    //  {
    //      a=0;
    //      b=8.8;
    //  }
};

int main()
{
    CExample *ce = new CExample();
    cout << "ce address:" << ce << endl;
    cout << ce->a << endl;
    cout << "ce->test.num:" << ce->test.num << endl;
    cout << "start addr:" << ce->c << ",0 addr:" << &ce->c[0] << ",1 addr:" << &ce->c[1] << endl;
    return 0;
}