

### sizeof strlen （todo）


### static 关键词
* static 修饰局部变量
  变量的生命周期是局部的。存储在静态区
* static修饰全局变量
  变量只在本文件
* static修饰函数
  
[c语言static的用法](https://blog.csdn.net/weixin_35756130/article/details/112115302)

### c语言程序内存分布

```bash
high address   |----------------------|
               |       stack          |
               |                      | 
               |                      |
               |----------------------|
               |        heap          |
               |----------------------|
               |     uninitialized    |
               |       data(bss)      |
               |----------------------|
               |     Initialized      |
               |        data          |
               |----------------------|
               |        text          |
low address    |----------------------|
```

我们可以使用size/objdump命令在linux下查看c语言在以上区域的大小。

```bash
chenlz@chenlz-Vostro-5890:~/Documents/programe_test$ size memory
   text    data     bss     dec     hex filename
   1415     544    4128    6087    17c7 memory
chenlz@chenlz-Vostro-5890:~/Documents/programe_test$ objdump -h memory

memory:     file format elf64-x86-64

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .interp       0000001c  0000000000000238  0000000000000238  00000238  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  1 .note.ABI-tag 00000020  0000000000000254  0000000000000254  00000254  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  ....
                  CONTENTS, READONLY, DEBUGGING
 28 .debug_str    0000029c  0000000000000000  0000000000000000  00001578  2**0
                  CONTENTS, READONLY, DEBUGGING
```
bss is shorted for block started by symbol.


[memory.c](../c/memory.c)

![memroyLayOutC's Picture](../pic/memoryLayoutC.jpg)

[c语言中各种变量的是如何存储的](https://blog.csdn.net/weixin_42400669/article/details/117021980)


### 程序的编译过程

预处理->编译->汇编->链接

![compile_process](../pic/doc/c/compile_process.png)


> 参考

[深入理解计算机系统](https://github.com/tgut/books/blob/master/computer_basic/Computer%20Systems%20-%20A%20Programmer's%20Perspective%20(2nd).pdf)

[程序详细编译过程（预处理、编译、汇编、链接)](https://zhuanlan.zhihu.com/p/476697014?utm_campaign=shareopn&utm_medium=social&utm_oi=588072105724088320&utm_psn=1631984361023930368&utm_source=wechat_session)

### makefile 学习



[跟我一起写Makefile](https://seisman.github.io/how-to-write-makefile/overview.html#id2)