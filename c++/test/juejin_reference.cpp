//g++ juejin_reference.cpp -o juejin_reference -fno-elide-constructors
//编译使用-fno-elide-constructors可以禁用编译器优化
#include <iostream>
using namespace std;

class A {
public:
    int x;
    A(int x) : x(x)
    {
        cout << "Constructor" << endl;
    }
    A(A& a) : x(a.x)
    {
        cout << "Copy Constructor" << endl;
    }
    A& operator=(A& a)
    {
        x = a.x;
        cout << "Copy Assignment operator" << endl;
        return *this;
    }
    A(A&& a) : x(a.x)
    {
        cout << "Move Constructor" << endl;
    }
    A& operator=(A&& a)
    {
        x = a.x;
        cout << "Move Assignment operator" << endl;
        return *this;
    }
};

A GetA()
{
    return A(1);
}

A&& MoveA(A& a)
{
    return std::move(a);
}

int main()
{
    cout << "-------------------------1-------------------------" << endl;
    A a(1);
    cout << "-------------------------2-------------------------" << endl;
    A b = a;
    cout << "-------------------------3-------------------------" << endl;
    A c(a);
    cout << "-------------------------4-------------------------" << endl;
    b = a;
    cout << "-------------------------5-------------------------" << endl;
    A d = A(1);
    cout << "-------------------------6-------------------------" << endl;
    A e = std::move(a);
    cout << "-------------------------7-------------------------" << endl;
    A f = GetA();
    cout << "-------------------------8-------------------------" << endl;
    A&& g = MoveA(f);
    cout << "-------------------------9-------------------------" << endl;
    d = A(1);
}