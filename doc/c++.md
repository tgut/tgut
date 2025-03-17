### c++内存分布

常量存储区，静态存储区，自由存储区，堆以及栈。

常量存储区存储的是只读常量，无法修改，例如字符串字面值常量，全局定义的带const关键字的常量都存放在该区域。 
静态存储区存储的是全局中定义的变量以及程序中带 static 关键字的变量。
自由存储区是一个更加抽象的概念，是 C++ 使用 new/delete 动态管理对象的一个抽象概念
堆是操作系统维护的区域。
栈是用户操作的内存区


[地址空间：由 C 至 C++](https://supwills.com/post/address-space/)


### iterator
    作用类似c语言中下标访问元素（vecotr,string）。library container里一般都支持iterator访问元素。
    This iterator(end) denotes a nonexistent element “off the end” of the container.

### sequence container
    vector,string,array,deque,list,forward_list

### associate container  
    map,set，multimap,multiset(order(*),unordered(unordered_*))
    以上容器的复杂度

####  stack 属于哪一类
    不属于序列容器，因为其没有iterator，所以不属于sequence容器。也没有关联容器的。属于容器适配器。

### static_cast dynamic_cast, const_cast,reinterpreter_cast


1. static_cast可以替代c语言中的强制转换,做上行转换时安全的，是静态类型转换，在编译时做安全检查。

2. dynamic_cast用于父类到子类的转换（下行转换），是动态类型转换，在运行时做安全检查。

[dynamic_cast.cpp](../c%2B%2B/dynamic_cast.cpp)

3. const_cast 用来将类型的const、volatile和__unaligned属性移除。常量指针被转换成非常量指针，并且仍然指向原来的对象；常量引用被转换成非常量引用，并且仍然引用原来的对象。

[const_cast.cpp](../c%2B%2B/const_cast.cpp) 使用const_cast.

[test_const_cast.cpp](../c%2B%2B/test_const_cast.cpp) 反例，下面是编译时的错误信息。

```bash
      |                         (
test_const_cast.cpp:6:26: error: expected ‘)’ before ‘;’ token
    6 |  int y = const_cast<int>x;
      |                          ^
      |                          )
test_const_cast.cpp:6:26: error: invalid use of const_cast with type ‘int’, which is not a pointer, reference, nor a pointer-to-data-member type
```

4. reinterpreter_cast 用于不同类型之间的位模式转换，例如将指针类型转换为整型或将整型转换为浮点型等。

[reinterpret_cast.cpp](../c%2B%2B/reinterpret_cast.cpp)

>参考

[static_cast, dynamic_cast, const_cast学习和探讨](https://blog.csdn.net/liujiayu2/article/details/45101791 )

### smart pointer

shared_ptr 所有指针指向同一个对象，unique_ptr只有一个指针指向对象，weak_ptr用来检测shared_ptr.

1. shared_ptr 使用：make_shared初始化，拷贝使得对象的引用计数增加1，赋值使得原对象引用计数减1，当计数为0时，自动释放内存。后来指向的对象引用计数加1，指向后来的对象。 [使用](../c++/shared_ptr_usage.cpp)

2. unique_ptr 使用：通过构造函数指定、通过reset方法重新指定、通过release方法释放所有权、通过移动语义转移所有权.[使用](../c++/unique_ptr_usage.cpp)

3.  weak_ptr 使用：没有重载operator*和->,它的最大作用在于协助shared_ptr工作，像旁观者那样观测资源的使用情况。[使用](../c++/weak_ptr_usage.cpp)

以上三个指针的功能是为了避免循环应用，示例通过
>    原始指针版本->共享指针版本->共享指针+weak_ptr版本  来解决循环引用问题
>   ([原始版本](../c%2B%2B/circular_reference.cpp)->[共享指针+weak_ptr版本](../c%2B%2B/circular_reference_2.cpp))

[c++11中智能指针的原理、使用、实现](https://www.cnblogs.com/wxquare/p/4759020.html)(todo)
### STL operation
 distance,unique,next,pre,find_if,reverse_iterator 隶属 [stl](https://www.cnblogs.com/blog-yejy/p/9551346.html) 提供的接口(todo)

### 深拷贝/浅拷贝
* 浅拷贝只是增加了一个指针指向已经存在的内存。
* 深拷贝就是增加一个指针并且申请一个新的内存，使这个增加的指针指向这个新的内存
  [shadow_copy.cpp](../c%2B%2B/shadow_copy.cpp)(todo,verify)
  [deep_copy.cpp](../c%2B%2B/deep_copy.cpp)(todo,verify)
[example](https://blog.csdn.net/wzz953200463/article/details/103587545)

### lamda表达式
```c++
[ capture ] ( params ) opt -> ret { body; };
```
其中 capture 是捕获列表，params 是参数表，opt 是函数选项，ret 是返回值类型，body是函数体。

[example](../c++/lamda.cpp)

### 多线程(todo)

[example](https://blog.csdn.net/weixin_43971373/article/details/119678930)
[print sequence abc](../c++/print_abc_sequence.cpp)
[print random number](../c++/nvidia_programming.cpp)
[C++11 并发指南系列](https://www.cnblogs.com/haippy/p/3284540.html) (todo)
[线程池]()？
### signal使用（todo）

### template

1.  c++模板
[c++模板](https://www.runoob.com/cplusplus/cpp-templates.html)
2.  函数模板
[example](http://c.biancheng.net/view/320.html)
3.  类模板
[example](http://c.biancheng.net/view/2317.html)
[class_template](../c%2B%2B/class_template.cpp)

class vs typename

模板中，如果模板参数不确定是类的话，使用typename来替换。
[class 关键词和 typename的区别](https://liam.page/2018/03/16/keywords-typename-and-class-in-Cxx/)

### 虚函数的调用关系（todo）

### 设计模式（c++）

[菜鸟笔记设计模式](https://www.coonote.com/cpp-design-pattern/cpp-decoration-mode.html)

### 回调函数的使用和意义（todo）

解耦

[C 语言回调函数详解](https://www.runoob.com/w3cnote/c-callback-function.html)


### 左值和右值-->拷贝构造，移动构造

1. 左值是等号的左边，可以取地址；右值位于等号的右边无法取地址（临时变量属于右值，参考[拷贝构造，移动构造](https://www.jianshu.com/p/f5d48a7f5a52)）。

2. 右值引用（&&）是把常量引用细分成常量引用和右值。[参考代码1](../c%2B%2B/l_r_value.cpp) [参考代码2](../c%2B%2B/and_function.cpp)

3. move的作用就是把左值转变为右值。

```bash
int a = 5; // a是个左值
int &ref_a_left = a; // 左值引用指向左值
int &&ref_a_right = std::move(a); // 通过std::move将左值转化为右值，可以被右值引用指向
 
cout << a; // 打印结果：5
```


c++11之前只有拷贝构造，拷贝赋值运算符,析构函数；
c++11开始添加 移动(move)构造，移动（move）赋值运算符。

> 参考

 [拷贝构造，移动构造](https://www.jianshu.com/p/f5d48a7f5a52)

[一次性搞定右值，右值引用（&&），和move语义](https://juejin.cn/post/6844903497075294216)

[一文读懂C++右值引用和std::move](https://zhuanlan.zhihu.com/p/335994370)

### stl(todo)

[六大组件](https://blog.csdn.net/jnu_simba/article/details/9410459)

>[感恩STL](https://blog.csdn.net/elloop/article/details/50340623)

### 算法接口
    sort 使用多种排序算法（insert,heap,quicksort）
1. stable_sort
2. isupper
3. isalpha
4. [find](https://cplusplus.com/reference/algorithm/find/?kw=find)
5. islower
6. [upper_bound](https://en.cppreference.com/w/cpp/algorithm/upper_bound)

7. [binary_search](https://en.cppreference.com/w/cpp/algorithm/binary_search)

>参考

[Sort function in C++](https://www.mygreatlearning.com/blog/sort-function-in-cpp/#sort-algorithm)

### c++默认构造函数和初始化列表

初始化函数列表可以对const,引用成员进行初始化。用户自己定义的构造函数中如果对const,引用成员做复制操作则会报错。

编译器会默认生成构造函数的说法，其实不完全准确(默认该类的成员或方法，编译器可以默认赋值或者实现的话，是可以生成默认构造函数的；否则不行)。

[default_construct.cpp](../c%2B%2B/test/default_construct.cpp)(todo,文件找不到)

>参考
[c++ 中关于没有默认构造函数的成员类对象问题](https://blog.csdn.net/lqlblog/article/details/17473381)
[c++ 类构造函数初始化列表](https://www.runoob.com/w3cnote/cpp-construct-function-initial-list.html)

### auto 和decltype的区别

1. 用法

```c++
auto varname = value;//auto根据=右侧的值来推断类型

decltype (express) var_name [= value]//根据express的结果来推测
```

2. 对const 和 volatile的处理

auto 对除了引用和指针会丢失上述两个属性（const ,volatile），decltype则一直保留。

3. 对引用

decltype 会保留引用类型，而 auto 会抛弃引用类型，直接推导出它的原始类型。


>参考

[C++ auto和decltype的区别](http://c.biancheng.net/view/7158.html#:~:text=auto%20%E5%B0%86%E5%8F%98%E9%87%8F%E7%9A%84%E7%B1%BB%E5%9E%8B,decltype%20%E7%9A%84%E4%BD%BF%E7%94%A8%E6%9B%B4%E5%8A%A0%E7%81%B5%E6%B4%BB%E3%80%82)

### 虚析构函数的作用

在析构的时候(在创建子类，返回父类类型)，达到先析构子类，再析构父类的目的。

[virtual_destruct](../c%2B%2B/virtual_destruct.cpp)


[test_construct](../c%2B%2B/test_construct.cpp)


### override关键词

在 C++11 中，如果重写了虚函数但是函数签名不同，则编译器会给出一个警告。

[override.cpp](../c%2B%2B/override.cpp)


### delete关键词

1. 禁用特定函数的默认实现，如默认构造函数，拷贝构造函数，拷贝赋值运算符和析构函数

2. 防止类被继承，如果构造函数声明为protected,子类还是可以重写该构造函数。如果在父类中使用"=delete",可以避免这种情况。

[delete_2.cpp](../c%2B%2B/delete_2.cpp)

3. 删除模板特化。

[delete_3.cpp](../c%2B%2B/delete_3.cpp)

### default 关键词

"= default"可以使用编译器自己生成的函数功能（默认构造函数，拷贝构造函数，拷贝复制运算符，析构函数），自己可以不用再编写对应的函数。

[default_keyword.cpp](../c%2B%2B/default_keyword.cpp)-chatgpt promt '= defualt使用举例'

### 类方法=0用法

在C++中，纯虚函数是指在基类中声明但没有定义的虚函数。在声明函数时，使用= 0表示这个函数是纯虚函数。例如：

```c++
class Base {
public:
    virtual void f() = 0;
};
```
纯虚函数使得一个类成为抽象类，不能实例化该类，而是只能被用作接口。派生类必须实现基类中的所有纯虚函数，否则它们也将成为抽象类。

纯虚函数通常用于定义接口，让派生类来实现具体的操作。

### ｆinal关键词

1.修饰后的类无法再集成

２．修饰后的虚函数无法再被重载

```c++

class FinalClass final {//class
  // ...
};

class BaseClass {
  virtual void foo() final;//虚函数
};

class DerivedClass : public BaseClass {
  // Can't override foo() because it's final in BaseClass
};


```

### explicit关键词
explicit是C++中的一个关键字，通常用于构造函数和类型转换运算符之前。explicit关键字防止编译器执行非预期的隐式类型转换。

```c++
class MyString {
public:
    // 转换构造函数
    class MyString {
public:
    // 转换构造函数
    MyString(const char* str) { /*...*/ }
    //explicit MyString(const char* str) { /*...*/ }/*解决编译器隐式转换问题*/
};

void func(MyString s) { /*...*/ }

int main() {
    func("Hello");  // 编译器自动使用构造函数将const char*转换成MyString
}

};

void func(MyString s) { /*...*/ }

int main() {
    func("Hello");  // 编译器自动使用构造函数将const char*转换成MyString,在MyString的copy 构造中使用explicit声明就可以避免这个问题。
}

```
###　性能优化（todo）

>参考
[c++性能优化](https://blog.csdn.net/a642960662/category_11641226.html)

### inline内联

```c++
inline int add(int a, int b) {
  return a + b;
}



int x = add(1, 2);

//编译器会把上面调用函数，在运行的时候展开为下面结果
int x = 1 + 2;


```
内联函数可以通过降低函数调用来提高性能。
但是一下两种情况，不能用内联函数。

１．函数参数是变量
２．函数中包含递归调用是不能用inline函数的

内联函数有如下三个问题需要注意，

１．内联函数会增加编译后文件的大小。
２．内联函数不好调试
３．代码复用比较差

>[参考bard](Q:what's the function of keyword inline in c++?)

### virtual function mechenics（todo）
 
虚函数


### 变长参数模板

在C++中，...args是一种特殠的参数类型，称为变长参数模板或可变参数模板。它被用于函数模板或类模板，允许您传递任意数量和任意类型的参数。

下面是一个简单的例子，这个函数接收多个参数并打印出它们：

```cpp
#include <iostream>

template<typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << '\n';
}

int main() {
    print(1, "Hello", 'c', 3.14);
    return 0;
}
```
在上述代码中，print函数通过使用...Args定义了一个变长参数模板。然后使用了args...来对所有传递给函数的参数进行操作。在这个例子中，我们只是简单地将所有参数打印出来。

注意，在C++中，变长参数模板的用法比这个例子更加复杂和强大。例如，可以在编译时计算出参数的数量和类型，并根据需要进行相应的操作。

>ref

[RTTI](https://www.geeksforgeeks.org/rtti-run-time-type-information-in-cpp/)


### learning c++ source code
thinking

学习和理解 GNU libstdc++ 库（GNU Standard C++ Library）的源码，是深入掌握 C++ 标准库实现的绝妙方式。这不仅能帮助你了解 STL 容器、算法和迭代器的底层机制，还能提升你的C++编码能力。以下是详细的学习步骤和方法：

#### 1. 准备工作

##### 获取源码
首先，你需要获取 GNU libstdc++ 的源码。可以从 GitHub 的 gcc-mirror 仓库下载：

```sh
git clone https://github.com/gcc-mirror/gcc.git
cd gcc/libstdc++-v3
```

##### 系统准备
确保你的开发环境准备就绪，包括安装必要的软件包（如编译器、构建工具）：

```sh
sudo apt-get update
sudo apt-get install build-essential g++ git
```

#### 2. 理解 C++ 标准库的结构

##### 目录和文件
GNU libstdc++ 库的结构包含多个目录和文件，每个目录和文件都有其特定作用。熟悉这些目录的结构有助于理解库的整体架构：

- **`include/`**：包含头文件，实现了 C++ 标准库的接口。
- **`src/`**：包含库的源文件，实现了具体的库功能。
- **`src/c++98` 和 `src/c++11`**：按 C++ 标准版本划分的实现文件。
- **`testsuite/`**：包含测试文件，验证库功能的正确性。

#### 3. 学习头文件和实现文件

##### 从容器开始
容器类是 C++ 标准库的核心组件之一，建议从容器（如 vector, list, map 等）开始学习。这些容器在头文件和实现文件中有详细的实现：

- **头文件**：`include/bits/stl_vector.h`, `include/bits/stl_list.h`, `include/bits/stl_map.h`
- **实现文件**：`src/c++11/vector.cc`, `src/c++11/list.cc`, `src/c++11/map.cc`

##### 示例：学习 `std::vector`

**头文件**：
```cpp
#ifndef _STL_VECTOR_H
#define _STL_VECTOR_H 1

#include <bits/stl_algobase.h>
#include <bits/stl_iterator.h>
#include <ext/alloc_traits.h>

_GLIBCXX_BEGIN_NAMESPACE(std)

  template<typename _Tp, typename _Alloc = allocator<_Tp> >
    class vector
    {
      // Vector implementation...
    };

_GLIBCXX_END_NAMESPACE

#endif /* _STL_VECTOR_H */
```

**实现文件**：
```cpp
#include <vector>
#include <bits/stl_vector.h>
#include <bits/stl_construct.h>

namespace std
{
  template<typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc>::vector() : /* Implementation... */ {}
}
```

#### 4. 阅读和理解

##### 阅读代码
系统地阅读所有核心组件的源码，关注以下方面：
- 容器的内部数据结构。
- 成员函数实现。
- 内存管理策略。
- 异常和边界情况处理机制。

##### 编译测试
在深入研究源码时，尝试编译和测试库。可以从 GNU libstdc++ 自带的 `testsuite/` 目录中运行测试用例：

```sh
cd testsuite
make check
```

#### 5. 使用 debug 工具

利用调试工具进一步理解库的实现。例如，使用 GDB 跟踪函数调用栈并观察变量变化：

```sh
g++ -g your_test_file.cpp -o your_test_file
gdb your_test_file
```

在调试过程中，可以设置断点、单步执行、查看变量值等，深入理解代码的运行机制：

```gdb
(gdb) break stl_vector.h:200
(gdb) run
(gdb) next
(gdb) print var_name
```

#### 6. 阅读文档和标准

##### 标准参考
- 熟悉C++标准文档（如ISO/IEC 14882）。
- 参考 `cppreference.com` 和 `cplusplus.com` 等在线资源。

##### 学术论文和书籍
- 阅读相关的学术论文和书籍，如《The C++ Programming Language》 (Bjarne Stroustrup) 和《Effective STL》 (Scott Meyers)。

#### 7. 参与社区

##### 贡献代码
- 尝试贡献代码或修复 issue。
- 参与源码审查，了解社区对代码质量的要求。

#### 小结

- **熟悉源码结构**：了解库的目录结构和各个模块的作用。
- **从容器开始**：重点研究容器的头文件和实现文件。
- **编译测试**：通过编译和测试用例验证理解的正确性。
- **调试工具**：利用GDB等调试工具深入分析运行机制。
- **阅读标准文档**：结合C++标准文档和相关书籍深入理解设计初衷。
- **参与社区**：通过贡献代码和参与讨论，更好地理解和提升。

希望这些步骤能帮助你深入理解 GNU libstdc++ 代码库。如果有更多问题或需要详细信息，请随时告诉我。

thinking ends

学习和理解 GNU libstdc++ 库（GNU Standard C++ Library）源码是深入掌握 C++ 标准库的重要途径。以下是详细的学习步骤和方法：

#### 1. 准备工作

##### 获取源码
从 GitHub 的 gcc-mirror 仓库下载源码：
```sh
git clone https://github.com/gcc-mirror/gcc.git
cd gcc/libstdc++-v3
```

##### 安装必要的软件包
确保你的开发环境已准备就绪：
```sh
sudo apt-get update
sudo apt-get install build-essential g++ git
```

#### 2. 理解库的结构

##### 目录和文件
- **`include/`**：包含头文件，实现了标准库接口。
- **`src/`**：包含库的实现文件。
- **`src/c++98` 和 `src/c++11`**：按 C++ 标准版本划分的实现文件。
- **`testsuite/`**：包含测试文件，验证库功能。

#### 3. 学习头文件和实现文件

##### 从容器开始
容器类是学习的重点，如 `vector`、`list`、`map` 等。

- **头文件**：`include/bits/stl_vector.h`
- **实现文件**：`src/c++11/vector.cc`

##### 示例：`std::vector`

**头文件 `include/bits/stl_vector.h`**
```cpp
#ifndef _STL_VECTOR_H
#define _STL_VECTOR_H 1

#include <bits/stl_algobase.h>
#include <bits/stl_iterator.h>
#include <ext/alloc_traits.h>

_GLIBCXX_BEGIN_NAMESPACE(std)

template<typename _Tp, typename _Alloc = allocator<_Tp> >
class vector
{
    // Vector implementation...
};

_GLIBCXX_END_NAMESPACE

#endif /* _STL_VECTOR_H */
```

**实现文件 `src/c++11/vector.cc`**
```cpp
#include <vector>
#include <bits/stl_vector.h>
#include <bits/stl_construct.h>

namespace std
{
    template<typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc>::vector() : /* Implementation... */ {}
}
```

#### 4. 阅读和理解

##### 阅读代码
系统地阅读所有核心组件的源码，关注：
- 容器的数据结构。
- 成员函数实现。
- 内存管理策略。
- 异常和边界情况处理。

##### 编译测试
在研究源码时，尝试编译和测试库：
```sh
cd testsuite
make check
```

#### 5. 使用调试工具

使用 GDB 等调试工具进一步理解库的实现：
```sh
g++ -g your_test_file.cpp -o your_test_file
gdb your_test_file
```
在 GDB 中设置断点、单步执行、查看变量值等：
```gdb
(gdb) break stl_vector.h:200
(gdb) run
(gdb) next
(gdb) print var_name
```

#### 6. 阅读文档和标准

##### 标准参考
- 熟悉 C++ 标准文档。
- 参考 `cppreference.com` 和 `cplusplus.com`。

##### 学术论文和书籍
- 阅读《The C++ Programming Language》和《Effective STL》。

#### 7. 参与社区

##### 贡献代码
- 参与贡献代码或修复 issue。
- 参与源码审查。

#### 总结

- **熟悉源码结构**：了解库的目录结构和各模块的作用。
- **重点学习容器**：关注容器的头文件和实现。
- **编译测试**：通过测试验证理解。
- **使用调试工具**：深入分析运行机制。
- **阅读标准文档**：结合 C++ 标准文档深入理解。
- **参与社区**：通过贡献代码和讨论提升理解。

希望这些步骤能帮助你深入理解 GNU libstdc++ 库。如果有进一步的问题或需要详细信息，请随时告诉我。

### LD_PRELOAD
`LD_PRELOAD` 是一个环境变量，用于在运行时强行加载共享库。这在调试、性能分析、或改变已有程序的行为时非常有用。通过 `LD_PRELOAD`，你可以重载某些函数，使得在程序执行过程中，使用你自定义的版本。

#### 典型用途
1. **拦截系统调用**：你可以重载标准库函数，例如 `malloc`、`free` 等，以监控内存分配。
2. **调试和性能分析**：通过插入代码，你可以收集更多的性能数据。
3. **修改现有应用行为**：无需更改应用源代码，通过预加载库来调整应用功能。

#### 如何在 C++ 中使用

假设我们希望重载 `malloc` 函数，进行简单的日志记录。以下是实现步骤：

##### 1. 创建一个共享库
首先，编写一个新的 `malloc` 实现，并将其编译成共享库。

**my_malloc.cpp**:
```cpp
#define _GNU_SOURCE
#include <iostream>
#include <dlfcn.h> // for dlsym
#include <cstdlib> // for malloc

// Define function pointer to original malloc
typedef void* (*malloc_t)(size_t);

// Wrapper function for malloc
extern "C" void* malloc(size_t size) {
    static malloc_t original_malloc = (malloc_t)dlsym(RTLD_NEXT, "malloc");
    
    std::cout << "malloc(" << size << ") called" << std::endl;
    
    return original_malloc(size);
}
```

编译成共享库：
```sh
g++ -fPIC -shared -o libmymalloc.so my_malloc.cpp -ldl
```

##### 2. 使用 LD_PRELOAD 运行目标程序
假设你有一个目标程序 `target_program`，可以使用以下命令运行它，并让它使用你的新 `malloc` 实现：

```sh
LD_PRELOAD=./libmymalloc.so ./target_program
```

这样，每次 `target_program` 调用 `malloc` 时，实际上调用的是你定义的 `malloc`，并输出日志信息。

#### 示例：完整操作流程

1. **创建 `my_malloc.cpp` 文件**
    ```cpp
    #define _GNU_SOURCE
    #include <iostream>
    #include <dlfcn.h> // for dlsym
    #include <cstdlib> // for malloc

    typedef void* (*malloc_t)(size_t);

    extern "C" void* malloc(size_t size) {
        static malloc_t original_malloc = (malloc_t)dlsym(RTLD_NEXT, "malloc");
        
        std::cout << "malloc(" << size << ") called" << std::endl;
        
        return original_malloc(size);
    }
    ```

2. **编译成共享库**
    ```sh
    g++ -fPIC -shared -o libmymalloc.so my_malloc.cpp -ldl
    ```

3. **创建一个简单的测试程序**

    **test_program.cpp**:
    ```cpp
    #include <iostream>
    #include <cstdlib>

    int main() {
        int* p = (int*)malloc(10 * sizeof(int));
        free(p);
        return 0;
    }
    ```

4. **编译测试程序**
    ```sh
    g++ -o test_program test_program.cpp
    ```

5. **使用 `LD_PRELOAD` 运行测试程序**
    ```sh
    LD_PRELOAD=./libmymalloc.so ./test_program
    ```

#### 注意事项
- 确保函数签名完全匹配。
- 在重载函数中调用原始函数时，避免无限递归。
- 调试时，可以使用 `LD_DEBUG=libs` 环境变量来获取更详细的信息。

通过上述方法，你可以很方便地在 C++ 程序中利用 `LD_PRELOAD` 技术，进行各种高级功能的实现和调试。