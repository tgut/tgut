#include<iostream>

using namespace std;

class Subject{
public:
    virtual void Request() = 0;
};

class RealSubject:public Subject{
public:
    void Request()override{
        cout<<"RealSubject Request"<<endl;
    };
};

class Proxy:public Subject{
public:
    RealSubject* realSubject;
    void Request()override{
        if(realSubject == nullptr){
            realSubject = new RealSubject();
        }
        realSubject->Request();
    };
};

int main(){
Proxy* proxy = new Proxy();
proxy->Request();

delete proxy;
}