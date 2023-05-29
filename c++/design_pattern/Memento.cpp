/*
 * @Author: tgut 
 * @Date: 2023-05-21 15:48:09 
 * @Last Modified by:   tgut 
 * @Last Modified time: 2023-05-21 15:48:09 
 */
#include<iostream>
#include<string>

using namespace std;
class Memento{
    private:
        string state;
    public:
        Memento(string state){
            this->state = state;
        }
        string GetState(){
            return state;
        }
};

class Originator{
    private:
        string state;
    public:
        string GetState(){
            return state;
        }
        void SetState(string state){
            this->state = state;
        }
        void SetMemento(Memento* memento){
            this->state = memento->GetState();
        }

        Memento* CreateMemento(){
            return (new Memento(state));
        }
        void show(){
            cout<<"Originator's state is: "<<state<<endl;
        }
};

class Caretaker{
    private:
        Memento* memento;
    
    public:
        Memento* GetMemento(){
            return Memento;
        }
        void SetMemento(Memento *memento){
            this->memento = memento;
        }
}

int main(){
    Originator* o = new Originator();
    o->SetState("On");
    o->show();

    Caretaker* c = new Caretaker();
    c->SetMemento(o->CreateMemento());

    o->SetState("Off");
    o->show();

    o->SetMemento(c->GetMemento());
    o->show();

    delete o,c;
}