#include<iostream>

using namespace std;

class Implementor{
    public:
        virtual void operation(){};
};

class ConcreteImplementorA:public Implementor{
    public:
        void operation() override{
            cout<<"Implement by A"<<endl;
        }
};

class ConcreteImplementorB:public Implementor{
    public:
        void operation() override{
            cout<<"Implement by B"<<endl;
        }
};

class Abstraction{
    protected:
        Implementor* implementor;
    public:
        void SetImplementor(Implementor* imp){
            this->implementor = imp;
        };
        virtual void Operation(){
            implementor->operation();
        }
};

class ConcreteAbstraction:public Abstraction{
    
    public:
        void Operation(){
            implementor->operation();
        }
};

int main(){

    Abstraction* abs = new ConcreteAbstraction();

    Implementor* a = new ConcreteImplementorA();
    
    Implementor* b = new ConcreteImplementorB();

    abs->SetImplementor(a);
    abs->Operation();

    abs->SetImplementor(b);
    abs->Operation();

    delete abs,a,b;

}