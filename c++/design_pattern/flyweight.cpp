#include <iostream>
#include <unordered_map>

using namespace std;

class Flyweight{
  virtual void operation(int extrinsicstate);
};

class ConcreteFlyweight:public Flyweight{
  void operation(int extrinsicstate){//override,todo
    cout<<"ConcreteFlyweight:"<<extrinsicstate<<endl;
  };
};

class UnsharedConcreteFlyweight:public Flyweight{
  void operation(int extrinsicstate){
    cout<<"ConcreteFlyweight:"<<extrinsicstate<<endl;
  };
};

class FlyweightFactory{
    private:
        unordered_map<string,Flyweight> data;
    public:
         FlyweightFactory(){
            data.insert("x",ConcreteFlyweight);
            data.insert("y",ConcreteFlyweight);
            data.insert("z",UnsharedConcreteFlyweight);
         }
         Flyweight getFlyweight(string str){
            return (data[str]);
         }
        
};

int main(){
    int extrinsicstate =22;

    FlyweightFactory *f = new FlyweightFactory();

    Flyweight fx = f->getFlyweight("x");

    fx.operation(--extrinsicstate);

    Flyweight fy = f->getFlyweight("y");

    fy.operation(--extrinsicstate);

    Flyweight fz = f->getFlyweight("z");

    fz.operation(--extrinsicstate);

    Flyweight uf = new UnsharedConcreteFlyweight();
    uf.operation(--extrinsicstate);
}