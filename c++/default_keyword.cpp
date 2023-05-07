#include <iostream>

class MyClass {
public:
  MyClass() {
    std::cout << "MyClass constructor" << std::endl;
  }

  MyClass(const MyClass& other)  = default; // 使用默认复制构造函数

  ~MyClass() {
    std::cout << "MyClass destructor" << std::endl;
  }
};

int main() {
  MyClass obj1;
  MyClass obj2(obj1); // 调用默认复制构造函数
  return 0;
}
