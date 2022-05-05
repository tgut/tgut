### iterator
    作用类似c语言中下标访问元素（vecotr,string）。library container里一般都支持iterator访问元素。
    This iterator(end) denotes a nonexistent element “off the end” of the container.

### sequence container
    vector,string,array,deque,list,forward_list

### associate container  
    map,set，multimap,multiset(order(*),unordered(unordered_*))
    以上容器的复杂度

####  stack 属于哪一类（todo）？

### auto decltype keyword
    auto 是自动获取变量类型，编译器可以推断；decltype声明变量为推断类型。
    [decltype](http://c.biancheng.net/view/7151.html#:~:text=decltype%20%E6%98%AF%E2%80%9Cdeclare%20type%E2%80%9D%E7%9A%84%E7%BC%A9%E5%86%99%EF%BC%8C%E8%AF%91%E4%B8%BA%E2%80%9C%E5%A3%B0%E6%98%8E%E7%B1%BB%E5%9E%8B%E2%80%9D%E3%80%82.%20%E6%97%A2%E7%84%B6%E5%B7%B2%E7%BB%8F%E6%9C%89%E4%BA%86%20auto%20%E5%85%B3%E9%94%AE%E5%AD%97%EF%BC%8C%E4%B8%BA%E4%BB%80%E4%B9%88%E8%BF%98%E9%9C%80%E8%A6%81%20decltype%20%E5%85%B3%E9%94%AE%E5%AD%97%E5%91%A2%EF%BC%9F.,%28exp%29%20varname%20%3D%20value%3B%20%E5%85%B6%E4%B8%AD%EF%BC%8Cvarname%20%E8%A1%A8%E7%A4%BA%E5%8F%98%E9%87%8F%E5%90%8D%EF%BC%8Cvalue%20%E8%A1%A8%E7%A4%BA%E8%B5%8B%E7%BB%99%E5%8F%98%E9%87%8F%E7%9A%84%E5%80%BC%EF%BC%8Cexp%20%E8%A1%A8%E7%A4%BA%E4%B8%80%E4%B8%AA%E8%A1%A8%E8%BE%BE%E5%BC%8F%E3%80%82)

### static_cast dynamic_cast, const_cast(todo)
https://blog.csdn.net/liujiayu2/article/details/45101791 

### smart pointer（todo）

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

### signal使用（todo）

### template(todo)