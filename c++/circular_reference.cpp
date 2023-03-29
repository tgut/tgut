#include <iostream>
#include <memory>

class Child;
class Parent;

class Parent {
private:
    Child* myChild;
public:
    void setChild(Child* ch) {
        this->myChild = ch;
    }

    void doSomething() {
        if (this->myChild) {

        }
    }

    ~Parent() {
        delete myChild;
    }
};

class Child {
private:
    Parent* myParent;
public:
    void setPartent(Parent* p) {
        this->myParent = p;
    }
    void doSomething() {
        if (this->myParent) {

        }
    }
    ~Child() {
        delete myParent;
    }
};

int main() {
    {
        Parent* p = new Parent;
        Child* c =  new Child;
        p->setChild(c);
        c->setPartent(p);
        // delete c;  //only delete one
    }
    return 0;
}