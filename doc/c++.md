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

####  stack 属于哪一类（todo）？
    不属于序列容器，因为其没有iterator，所以不属于sequence容器。也没有关联容器的。属于容器适配器。
### auto decltype keyword
    auto 是自动获取变量类型，编译器可以推断；decltype声明变量为推断类型。
    [decltype](http://c.biancheng.net/view/7151.html#:~:text=decltype%20%E6%98%AF%E2%80%9Cdeclare%20type%E2%80%9D%E7%9A%84%E7%BC%A9%E5%86%99%EF%BC%8C%E8%AF%91%E4%B8%BA%E2%80%9C%E5%A3%B0%E6%98%8E%E7%B1%BB%E5%9E%8B%E2%80%9D%E3%80%82.%20%E6%97%A2%E7%84%B6%E5%B7%B2%E7%BB%8F%E6%9C%89%E4%BA%86%20auto%20%E5%85%B3%E9%94%AE%E5%AD%97%EF%BC%8C%E4%B8%BA%E4%BB%80%E4%B9%88%E8%BF%98%E9%9C%80%E8%A6%81%20decltype%20%E5%85%B3%E9%94%AE%E5%AD%97%E5%91%A2%EF%BC%9F.,%28exp%29%20varname%20%3D%20value%3B%20%E5%85%B6%E4%B8%AD%EF%BC%8Cvarname%20%E8%A1%A8%E7%A4%BA%E5%8F%98%E9%87%8F%E5%90%8D%EF%BC%8Cvalue%20%E8%A1%A8%E7%A4%BA%E8%B5%8B%E7%BB%99%E5%8F%98%E9%87%8F%E7%9A%84%E5%80%BC%EF%BC%8Cexp%20%E8%A1%A8%E7%A4%BA%E4%B8%80%E4%B8%AA%E8%A1%A8%E8%BE%BE%E5%BC%8F%E3%80%82)

### static_cast dynamic_cast, const_cast(todo)
https://blog.csdn.net/liujiayu2/article/details/45101791 

### smart pointer（todo）

shared_ptr 所有指针指向同一个对象，unique_ptr只有一个指针指向对象，weak_ptr用来检测shared_ptr.

1. shared_ptr 使用：make_shared初始化，拷贝的时候引用计数加1,赋值引用计数减1. [使用](../c++/shared_ptr_usage.cpp)

2. unique_ptr 使用：通过构造函数指定、通过reset方法重新指定、通过release方法释放所有权、通过移动语义转移所有权.[使用](../c++/unique_ptr_usage.cpp)

3.  weak_ptr 使用：没有重载operator*和->,它的最大作用在于协助shared_ptr工作，像旁观者那样观测资源的使用情况。[使用](../c++/weak_ptr_usage.cpp)

以上三个指针的功能是为了避免循环应用，示例通过
>    原始指针版本->共享指针版本->共享指针+weak_ptr版本  来解决循环引用问题
>   ([原始版本](../c%2B%2B/circular_reference.cpp)->[共享指针+weak_ptr版本](../c%2B%2B/circular_reference_2.cpp))

[c++11中智能指针的原理、使用、实现](https://www.cnblogs.com/wxquare/p/4759020.html)
#### operation
 distance,unique,next,pre,find_if,reverse_iterator 隶属 [stl](https://www.cnblogs.com/blog-yejy/p/9551346.html) 提供的接口(todo)

#### 深拷贝/浅拷贝
* 浅拷贝只是增加了一个指针指向已经存在的内存。
* 深拷贝就是增加一个指针并且申请一个新的内存，使这个增加的指针指向这个新的内存
  
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

[default_construct.cpp](../c%2B%2B/test/default_construct.cpp)

>参考
[c++ 中关于没有默认构造函数的成员类对象问题](https://blog.csdn.net/lqlblog/article/details/17473381)
[c++ 类构造函数初始化列表](https://www.runoob.com/w3cnote/cpp-construct-function-initial-list.html)