#include <iostream>
#include <unordered_map>

using namespace std;

class Flyweight{
  public:
    virtual void operation(int extrinsicstate) const = 0;//定义纯虚函数
};

class ConcreteFlyweight:public Flyweight{
  void operation(int extrinsicstate)const override {
    cout<<"ConcreteFlyweight:"<<extrinsicstate<<endl;
  };
};

class UnsharedConcreteFlyweight:public Flyweight{
  void operation(int extrinsicstate)const override{
    cout<<"UnsharedConcreteFlyweight:"<<extrinsicstate<<endl;
  };
};

class FlyweightFactory{
    private:
        unordered_map<string,Flyweight*> data;
    public:
         FlyweightFactory(){
            data.insert(make_pair<std::string, Flyweight*>("x",(new ConcreteFlyweight())));
            data.insert(make_pair<std::string, Flyweight*>("y",(new ConcreteFlyweight())));
            data.insert(make_pair<std::string, Flyweight*>("z",(new UnsharedConcreteFlyweight())));
         }
         Flyweight* getFlyweight(string str){
            return (data[str]);
         }
        
};

int main(){
    int extrinsicstate =22;

    FlyweightFactory *f = new FlyweightFactory();

    Flyweight* fx = f->getFlyweight("x");

    fx->operation(--extrinsicstate);

    Flyweight* fy = f->getFlyweight("y");

    fy->operation(--extrinsicstate);

    Flyweight* fz = f->getFlyweight("z");

    fz->operation(--extrinsicstate);

    Flyweight* uf = new UnsharedConcreteFlyweight();
    uf->operation(--extrinsicstate);

    delete f;
    delete uf;
}