#include <iostream>

class Base {
public:
    Base(){
        std::cout<<"Base Construct"<<std::endl;
    }
    ~Base() {
        std::cout << "Base destructor called." << std::endl;
    }
};

class Derived : public Base {
public:
    Derived(){
        std::cout<<"Derived Construct"<<std::endl;
    }
    ~Derived() {
        std::cout << "Derived destructor called." << std::endl;
    }
};

int main() {
    Derived* ptr = new Derived();
    delete ptr;
    return 0;
}
