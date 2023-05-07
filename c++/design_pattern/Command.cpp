#include<iostream>

using namespace std;
class Receiver{
    public:
        void Action(){
            cout<<"执行命令"<<endl;
        }
};

class Command{
    protected:
        Receiver* receiver;
    public:
        // Command(Receiver* re){// this construct can reserve,then line 23 must add base class init.
        //     this->receiver = re;
        // }
        virtual void Excute(){};
};

class ConcreteCommand:public Command{
    public:
        ConcreteCommand(Receiver* re){
            this->receiver = re;
        }
        void Excute(){
            receiver->Action();
        }
};

class Invoker{
    private:
        Command* command;
    public:
        void SetCommand(Command* com){
            this->command = com;
        }
        void ExcuteCommand(){
            command->Excute();
        }
};

int main(){
    Receiver* r = new Receiver();
    Command* c =new  ConcreteCommand(r);
    Invoker* i = new Invoker();

    i->SetCommand(c);
    i->ExcuteCommand();

    delete r,c,i;
}