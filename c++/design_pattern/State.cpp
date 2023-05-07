#include<iostream>
using namespace std;

class Context;
class ConcreteStateB;
class ConcreteStateA;

class State{
    public:
        virtual void Handle(Context* context) = 0;
};

class Context{
        
    public:
        State* state;
        Context(State* state){
            this->state = state;
        }
        void SetState(State* state){
            this->state = state;
        }
        State* GetState(){
            return this->state;
        }

        void Request(){
            state->Handle(this);
        }
};

class ConcreteStateA:public State{
    public:
    void Handle(Context* context) override;

        ConcreteStateB* concreteSB;
};

class ConcreteStateB : public State {
    public:
    void Handle(Context* context) override;

        ConcreteStateA* concreteSA;
};

void ConcreteStateA::Handle(Context* context) {
    cout << "change to state B" << endl;
    context->state = concreteSB;
}

void ConcreteStateB::Handle(Context* context) {
    cout << "change to state A" << endl;
    context->state = concreteSA;
}

int main() {
    ConcreteStateA* stateA = new ConcreteStateA();
    ConcreteStateB* stateB = new ConcreteStateB();
    stateA->concreteSB = stateB;
    stateB->concreteSA = stateA;
    Context* c = new Context(stateA);
    c->Request();
    c->Request();

    delete c;
    delete stateA;
    delete stateB;
}