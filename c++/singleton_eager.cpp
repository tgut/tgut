/*
 * @Descripttion: https://zhuanlan.zhihu.com/p/37469260 version 1.3
 * @version: 
 * @Author: tgut
 * @Date: 2024-06-20 20:08:37
 * @LastEditors: tgut
 * @LastEditTime: 2024-06-21 20:15:53
 */
// version 1.3
#include <iostream>
using namespace std;
//declare the class
class Singleton
{
private:
    static Singleton instance;
private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
public:
    static Singleton& getInstance() {
        return instance;
    }
};

// Initialize the static member variable
Singleton Singleton::instance;

Singleton::~Singleton() {
        cout<<"begin deconstruct"<<endl;
}

// Define the constructor and destructor
Singleton::Singleton() {
    cout<<"begin construct"<<endl;
}

// initialize defaultly

int main(){
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    cout << "&s1 = "<< &s1 << ",&s2 = " << &s2<<endl;
    return 0;
}