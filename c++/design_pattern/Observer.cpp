#include<iostream>
#include<list>
#include<string>

using namespace std;
class Observer{
    public:
        virtual void Update() = 0;
};

class Subject{
    private:
        list<Observer*> observer;
    public:

        void Attach(Observer* ob){
            observer.emplace_back(ob);
        }

        void Detach(Observer* ob){
            observer.remove(ob);
        }

        void Notify(){
            for(auto ele:observer){
                ele->Update();
            }
        }
};

class ConcreteSubject:public Subject{
    private:
        string subjectState;
    public:
        string getState(){
            return this->subjectState;
        }

        void setState(string state){
            this->subjectState= state;
        }
};

class ConcreteObserver:public Observer{
    private:
        string name;
        string observerState;
        ConcreteSubject* subject;
    
    public:
        ConcreteObserver(ConcreteSubject* cs,string name){
            this->subject =cs;
            this->name = name;
        }

        void Update() override{
            observerState = subject->getState();
            cout<<"ConcreteObserver "<< this->name <<" State is : "<<this->observerState<<endl;
        }
        ConcreteSubject* GetConcreteSubject(){
            return this->subject;
        }

        void SetConcreteSubject(ConcreteSubject* cs){
            this->subject = cs;
        }

};

int main(){
    ConcreteSubject* test_cs = new ConcreteSubject();
    test_cs->Attach(new ConcreteObserver(test_cs,"x"));
    test_cs->Attach(new ConcreteObserver(test_cs,"y"));
    test_cs->Attach(new ConcreteObserver(test_cs,"z"));

    test_cs->setState("ABC");
    test_cs->Notify();

    delete test_cs;
}