#include <iostream>
using namespace std;

class Base {
public:
    void foo(){
        cout<<"Base foo()"<<endl;
    }
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    void bar() {}
    void foo(){
        cout<<"Derived foo()"<<endl;
    }
};

int main() {
    Base* b = new Derived;
    b->foo();
    std::cout << "Dynamic cast example:" << std::endl;
    Derived* d = dynamic_cast<Derived*>(b);
    if (d != nullptr) {
        d->foo();
    }
    delete d;
    // delete b;
}
