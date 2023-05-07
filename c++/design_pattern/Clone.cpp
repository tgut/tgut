#include <iostream>
#include <string>

using namespace std;

class Prototype
{
public:
    string id;
    Prototype(){};
    Prototype(string id)
    {
        this->id = id;
    }
    string GetId()
    {
        return this->id;
    }
    virtual Prototype *Clone() = 0;
};

class ConcretePrototype : public Prototype
{
public:
    ConcretePrototype(string id) : Prototype(id){};
    Prototype *Clone()
    {
        return new ConcretePrototype(this->id);
    }
};

int main()
{
    ConcretePrototype *concretePrototype = new ConcretePrototype("I");
    ConcretePrototype *concretePrototype1 = dynamic_cast<ConcretePrototype *>(concretePrototype->Clone());
    cout << "concretePrototype1's id:" << concretePrototype1->id << endl;

    delete concretePrototype;
}