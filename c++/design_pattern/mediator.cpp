#include <iostream>
#include <string>
using namespace std;

class Mediator
{
public:
    virtual void send(string st, string coll) const = 0;//why const ==0,todo
};

class Colleage
{
protected:
    Mediator *med;

public:
    Colleage(Mediator *_med = nullptr) : med(_med){};
    void set_mediator(Mediator *_med)
    {
        this->med = _med;
    };
};

class ConcreteColleage1 : public Colleage
{
    // here left the copy construct to imple.todo
public:
    void send(string str)
    {
        this->med->send(str, "cc1");
    }
    void notify(string str)
    {
        cout << "colleage 2 send message " << str << endl;
    }
};

class ConcreteColleage2 : public Colleage
{
    // here left the copy construct to imple.todo
public:
    void send(string str)
    {
        this->med->send(str, "cc2");
    }
    void notify(string str)
    {
        cout << "colleage 1 send message " << str << endl;
    }
};

class ConcreteMediator : Mediator
{
private:
    ConcreteColleage1 *cc1;
    ConcreteColleage2 *cc2;

public:
    // ConcreteMediator(){};
    ConcreteMediator(ConcreteColleage1 *_cc1, ConcreteColleage2 *_cc2) : cc1(_cc1), cc2(_cc2)
    {
        this->cc1->set_mediator(this);
        this->cc2->set_mediator(this);
    }
    void set(ConcreteColleage1 *cc1, ConcreteColleage2 *cc2)
    {
        this->cc1 = cc1;
        this->cc2 = cc2;
    }
    void send(string str, string coll) const override
    {
        if (coll == "cc1")
        {
            cc2->notify(str);
        }
        else if (coll == "cc2")
        {
            cc1->notify(str);
        }
    }
};

int main()
{

    ConcreteColleage1 *cc1 = new ConcreteColleage1();
    ConcreteColleage2 *cc2 = new ConcreteColleage2();

    ConcreteMediator *cm = new ConcreteMediator(cc1, cc2);

    cc1->send("hi");

    cc2->send("hello");

    delete cm;
    delete cc2;
    delete cc1;

    return 0;
}