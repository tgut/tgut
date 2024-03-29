#include <iostream>
#include <memory>

class Child;
class Parent;

class Parent {
private:
    std::shared_ptr<Child> ChildPtr;
    // std::weak_ptr<Child> ChildPtr;
public:
    void setChild(std::shared_ptr<Child> child) {
        this->ChildPtr = child;
    }

    void doSomething() {
        //new shared_ptr
        if (this->ChildPtr.use_count()) {

        }
    }

    ~Parent() {
    }
};

class Child {
private:
    // std::shared_ptr<Parent> ParentPtr;
    std::weak_ptr<Parent> ParentPtr;
public:
    void setPartent(std::shared_ptr<Parent> parent) {
        this->ParentPtr = parent;
    }
    void doSomething() {
        // if (this->ParentPtr.use_count()) {

        // }
        if (this->ParentPtr.lock()) {

        }
    }
    ~Child() {
    }
};

int main() {
    std::weak_ptr<Parent> wpp;
    std::weak_ptr<Child> wpc;
    {
        std::shared_ptr<Parent> p(new Parent);
        std::shared_ptr<Child> c(new Child);
        p->setChild(c);//c的引用计数加1
        c->setPartent(p);//p的引用计数不变
        wpp = p;
        wpc = c;
        std::cout << p.use_count() << std::endl; // 1,
        std::cout << c.use_count() << std::endl; // 2,

        if((!wpp.expired()) || (!wpc.expired())){
            std::cout<<"inside the local region!"<<std::endl;
            std::cout << wpp.use_count() << std::endl;  // 1
            std::cout << wpc.use_count() << std::endl;  // 2
        }
    }
    if((!wpp.expired()) || (!wpc.expired())){
        std::cout<<"inside the local region!"<<std::endl;
        std::cout << wpp.use_count() << std::endl;  // 0
        std::cout << wpc.use_count() << std::endl;  // 0
    }
    std::cout<<"test.."<<std::endl;

    return 0;
}