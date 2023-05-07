class Base {
public:
    virtual void foo(int x) const;
};

class Derived : public Base {
public:
    virtual void foo(int x) const override;  // 重写了基类中的虚函数
};
