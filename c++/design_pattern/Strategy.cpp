#include<iostream>

using namespace std;

class Strategy{
public:
    virtual void AlgorithmInterface() = 0;
};

class Context{
public:
    Strategy* strategy;
    void SetStrategy(Strategy* strategy){
        this->strategy = strategy;
    }
    void ContextInterface(){
        strategy->AlgorithmInterface();
    };
};

class ConcreteStartegyA:public Strategy{
public:
    void AlgorithmInterface() override{
        cout<<"excute ConcreteStartegyA's AlgorithmInterface"<<endl;
    };
};

class ConcreteStartegyB:public Strategy{
public:
    void AlgorithmInterface() override{
        cout<<"excute ConcreteStartegyB's AlgorithmInterface"<<endl;
    };
};

int main(){
    Context* context = new Context;
    Strategy* strategyA = new ConcreteStartegyA;
    Strategy* strategyB = new ConcreteStartegyB;

    context->SetStrategy(strategyA);
    context->ContextInterface();

    context->SetStrategy(strategyB);
    context->ContextInterface();

    delete context,strategyA,strategyB;

}