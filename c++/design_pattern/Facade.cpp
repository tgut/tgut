#include<iostream>

using namespace std;

class SubSystemOne{
    public:
        void MethodOne(){
            cout<<"MethodOne"<<endl;
        }
};


class SubSystemTwo{
    public:
        void MethodTwo(){
            cout<<"MethodTwo"<<endl;
        }
};

class SubSystemThree{
    public:
        void MethodThree(){
            cout<<"MethodThree"<<endl;
        }
};

class SubSystemFour{
    public:
        void MethodFour(){
            cout<<"MethodFour"<<endl;
        }
};

class Facade{
    SubSystemOne *one;
    SubSystemTwo *two;
    SubSystemThree *three;
    SubSystemFour *four;

    public:
        Facade(){
            one = new SubSystemOne();
            two = new SubSystemTwo;
            three = new SubSystemThree();
            four = new SubSystemFour();
        }

        void MethodA(){
            one->MethodOne();
            two->MethodTwo();
            four->MethodFour();
        }

        void MethodB(){
            three->MethodThree();
        }
};

int main(){
    Facade* test = new Facade();
    test->MethodA();
    test->MethodB();

    delete test;
}