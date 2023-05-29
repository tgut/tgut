#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product
{
public:
    vector<string> parts;

public:
    void add(string data)
    {
        parts.push_back(data);
    }
    void show()
    {
        cout << "excute show parts: ";
        for (auto ele : parts)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
};

class Builder
{
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product *GetResult() = 0;
};

class ConcreteBuilder1 : public Builder
{
private:
    Product *product = new Product();

public:
    void BuildPartA() override
    {
        product->add("添加部件A");
    }

    void BuildPartB() override
    {
        product->add("添加部件B");
    }
    Product *GetResult() override
    {
        return product;
    }
};

class ConcreteBuilder2 : public Builder
{
private:
    Product *product = new Product();

public:
    void BuildPartA() override
    {
        product->add("添加部件X");
    }

    void BuildPartB() override
    {
        product->add("添加部件Y");
    }
    Product *GetResult() override
    {
        return product;
    }
};

class Director
{
public:
    void Construct(Builder *builder)
    {
        builder->BuildPartA();
        builder->BuildPartB();
    }
};

int main()
{
    Director *director = new Director();

    Builder *b1 = new ConcreteBuilder1();
    Builder *b2 = new ConcreteBuilder2();

    director->Construct(b1);
    Product *p1 = b1->GetResult();
    p1->show();

    director->Construct(b2);
    Product *p2 = b2->GetResult();
    p2->show();
    
    delete b1,b2,director;
}