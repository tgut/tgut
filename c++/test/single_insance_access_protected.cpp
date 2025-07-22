#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

class SingletonBase {
private:
    static unique_ptr<SingletonBase> instance;
    static mutex mtx;
    
protected:
    // 保护构造函数，允许派生类访问
    SingletonBase() : protected_data(42) {}
    
    int protected_data;
    string protected_name = "Base";
    
    // protected方法供派生类使用
    void protected_method() {
        cout << "Base protected method called" << endl;
    }

public:
    // 禁用拷贝
    SingletonBase(const SingletonBase&) = delete;
    SingletonBase& operator=(const SingletonBase&) = delete;
    
    static SingletonBase* getInstance() {
        lock_guard<mutex> lock(mtx);
        if (!instance) {
            instance = unique_ptr<SingletonBase>(new SingletonBase());
        }
        return instance.get();
    }
    
    virtual void show_info() {
        cout << "Base: " << protected_data << ", " << protected_name << endl;
    }
    
    virtual ~SingletonBase() = default;
};

// 静态成员定义
unique_ptr<SingletonBase> SingletonBase::instance = nullptr;
mutex SingletonBase::mtx;

// 派生类（非单例）
class DerivedClass : public SingletonBase {
public:
    string derived_name;
    
    // 私有构造函数，只能通过基类单例访问
    DerivedClass(const string& name) : derived_name(name) {
        // ✅ 可以访问基类的protected成员
        protected_data = 100;
        protected_name = "Derived";
    }

public:
    // 通过基类单例获取派生类实例
    static DerivedClass* createFromSingleton(const string& name) {
        // 确保基类单例已创建
        SingletonBase::getInstance();
        return new DerivedClass(name);
    }
    
    void access_protected_members() {
        // ✅ 派生类可以访问基类的protected成员
        cout << "Accessing protected_data: " << protected_data << endl;
        cout << "Accessing protected_name: " << protected_name << endl;
        
        // 修改protected成员
        protected_data += 10;
        protected_method();
    }
    
    void show_info() override {
        cout << "Derived (" << derived_name << "): " 
             << protected_data << ", " << protected_name << endl;
    }
};

int main() {
    // 获取基类单例
    SingletonBase* base_instance = SingletonBase::getInstance();
    base_instance->show_info();
    
    // 创建派生类实例
    DerivedClass* derived_instance = DerivedClass::createFromSingleton("DerivedInstance");
    derived_instance->access_protected_members();
    derived_instance->show_info();
    
    // 清理派生类实例
    delete derived_instance;
    
    return 0;
}