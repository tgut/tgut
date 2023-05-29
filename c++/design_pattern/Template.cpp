#include<iostream>

using namespace std;

class AbstractClass{

    public:
        virtual void PrimitiveOperation1() = 0;
        virtual void PrimitiveOperation2() = 0;
        void TemplateMethod(){
            PrimitiveOperation1();
            PrimitiveOperation2();
            cout<<"Abstract Class excute TemplateMethod"<<endl;
        }
};

class ConcreteClassA:public AbstractClass{
    public:
        void PrimitiveOperation1(){
            cout<<"ConcreteClassA Do PrimitiveOperation1"<<endl;
        }
         void PrimitiveOperation2(){
            cout<<"ConcreteClassA Do PrimitiveOperation2"<<endl;
        }
};


class ConcreteClassB:public AbstractClass{
    public:
        void PrimitiveOperation1(){
            cout<<"ConcreteClassB Do PrimitiveOperation1"<<endl;
        }
         void PrimitiveOperation2(){
            cout<<"ConcreteClassB Do PrimitiveOperation2"<<endl;
        }
};

int main(){
    AbstractClass* test;
    test = new ConcreteClassA();
    test->TemplateMethod();

    test = new ConcreteClassB();
    test->TemplateMethod();

    delete test;
}