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
### signal使用（todo）

### template

1.  c++模板
[c++模板](https://www.runoob.com/cplusplus/cpp-templates.html)
2.  函数模板
[example](http://c.biancheng.net/view/320.html)
3.  类模板
[example](http://c.biancheng.net/view/2317.html)

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