#include <iostream>
#include<string>

using namespace std;

class Component
{
public:
    virtual void operation() = 0;
};


class ConcreteComponent:public Component
{
public:
    void operation() override{
        cout<<"ConcreteComponent operation"<<endl;
    };
};


class Decorator:public Component
{
protected:
    Component* component;
public:
    void SetCompoent(Component* component){
        this->component = component;
    }
    void operation() override{
        if(component != nullptr){
        cout<<"ConcreteComponent operation"<<endl;
        }
    };
};


class ConcreteDecoratorA:public Decorator{
private:
    string addedState;
public:
    void operation() override{
        Decorator::operation();
        addedState= "ConcreteDecoratorA";
        cout<<"ConcreteDecoratorA operation"<<endl;
        }
};


class ConcreteDecoratorB:public Decorator{
private:
   void AddBehavior(){
        cout<<"ConcreteDecoratorB AddBehavior"<<endl;
   }
public:
    void operation() override{
        Decorator::operation();
        AddBehavior();
        cout<<"ConcreteDecoratorB operation"<<endl;
        }
};

int main()
{
    ConcreteComponent* c = new ConcreteComponent();
    ConcreteDecoratorA *a= new ConcreteDecoratorA();
    ConcreteDecoratorB* b = new ConcreteDecoratorB();

    a->SetCompoent(c);
    b->SetCompoent(a);

    b->operation();

    delete c,a,b;
};