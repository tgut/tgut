class Base {
protected:
    // 禁用默认构造函数和拷贝构造函数
    Base() = delete;
    Base(const Base&) = delete;
    // 允许声明自定义构造函数和析构函数
    Base(int x) { ... }
    virtual ~Base() { ... }
};

class Derived : public Base {
public:
    // 错误：试图调用删除的默认构造函数
    Derived() {}
    // 正确：声明自定义构造函数
    Derived(int x) : Base(x) {}
    // 错误：试图调用删除的拷贝构造函数
    Derived(const Derived&) {}
};
