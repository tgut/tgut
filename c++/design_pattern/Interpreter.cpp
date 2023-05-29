#include<iostream>
#include<list>

using namespace std;

class Context{
    private:
        string input;
        string output;
    public:
        string GetInput(){
            return this->input;
        };

        void SetInput(string str){
            this->input = str;
        };

        string GetOutput(){
            return this->output;
        };

        void SetOutput(string str){
            this->output = str;
        };
};

class AbstractExpression{
    public:
        virtual void Interprete(Context* context) = 0;
};

class TerminalExpression:public AbstractExpression{
    public:
        void Interprete(Context* context){
            cout<<"TerminalExpression"<<endl;
        };
};

class NonTerminalExpression:public AbstractExpression{
    public:
        void Interprete(Context* context){
            cout<<"NonTerminalExpression"<<endl;
        };
};

int main(){
    Context* test_context = new Context();
    list<AbstractExpression*> l_abstract;
    AbstractExpression* t1 = new TerminalExpression();
    AbstractExpression* t2 = new NonTerminalExpression();
    AbstractExpression* t3 = new TerminalExpression();
    AbstractExpression* t4 = new TerminalExpression();

    l_abstract.emplace_back(t1);
    l_abstract.emplace_back(t2);
    l_abstract.emplace_back(t3);
    l_abstract.emplace_back(t4);

    for(auto ele:l_abstract){
        ele->Interprete(test_context);
    }

    delete test_context,t1,t2,t3,t4;
}

