#include <iostream>
#include <vector>
using namespace std;

class Manager{
    protected:
        Manager* successor;
    public:
        void SetSuccessor(Manager* successor){
            this->successor = successor;
        };
        virtual void HandleRequest(int request) const=0;
};

class ConcreteManager1:public Manager{
    public:
        void HandleRequest(int request) const override{
            if(request < 5){
                cout<<"ConcreteManager1 deal with " << request<< endl;
            }else if(successor != nullptr){
                successor->HandleRequest(request);
            }
        }
};

class ConcreteManager2:public Manager{
    public:
        void HandleRequest(int request) const override{
            if(request >= 5 && request < 10){
                cout<<"ConcreteManager2 deal with " << request<< endl;
            }
        }
};

int main(){
    ConcreteManager1* Jeff = new ConcreteManager1;

    ConcreteManager2* Wilbur = new ConcreteManager2;

    Jeff->SetSuccessor(Wilbur);

    vector<int> request ={1,4,9,3};

    for(const int ele:request){
        Jeff->HandleRequest(ele);
    };

    delete Wilbur;
    delete Jeff;
    return 0;
}