### 多线程

### ubuntu 18.04基本软件安装
```bash
[添加阿里云的源](https://blog.csdn.net/qq_44732146/article/details/121207737)
sudo apt install docker.io //docker
sudo apt install git
sudo apt-get install openssh-server && sudo /etc/init.d/ssh start
```
### ubuntu 安装gcc5.4后升级gcc5.5


```bash
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
sudo apt-get update && \
sudo apt-get install gcc-5 g++-5
```

如果碰到apt_pkg module找不到，大概率是因为python配置的版本有问题，可以使用如下命令

```bash
cd /usr/lib/python3/dist-packages
sudo cp apt_pkg.cpython-35m-x86_64-linux-gnu.so apt_pkg.cpython-36m-x86_64-linux-gnu.so
```

### 查看cpu核数

```bash
lscpu
```
显示信息如下
[lscpu](../pic/doc/os/lscpu.png)

### numa和affinity


#### [numa介绍](https://zhuanlan.zhihu.com/p/336365600)


#### [affinity介绍](https://en.wikipedia.org/wiki/Processor_affinity)

>Processor affinity, or CPU pinning or "cache affinity", enables the binding and unbinding of a process or a thread to a central processing unit (CPU) or a range of CPUs, so that the process or thread will execute only on the designated CPU or CPUs rather than any CPU. This can be viewed as a modification of the native central queue scheduling algorithm in a symmetric multiprocessing operating system. Each item in the queue has a tag indicating its kin processor. At the time of resource allocation, each task is allocated to its kin processor in preference to others.


[affinity使用](https://www.cnblogs.com/wenqiang/p/6049978.html)

### top 高级技能
之前被面试官问道过top的高级用法，比如为什么cpu利用率会达到> 100%（是累计的所有核cpu利用率）,blabla.我接下来罗列一些最近习得的技能。
#### Fields Management

比如查看进程运行在哪个核上，可以通过配置Fields Management（按f进入）中的P选项（空格选中），然后'q'退出后，就可以在top下看到P列（所在核数）的信息。

```bash
Tasks: 983 total,   1 running, 459 sleeping,   0 stopped,   0 zombie%Cpu(s):  1.0 us,  0.7 sy,  0.0 ni, 98.3 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 stKiB Mem : 52802470+total, 29371564+free, 12433692 used, 22187534+buff/cache
KiB Swap:        0 total,        0 free,        0 used. 52080150+avail Mem 
  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND                                                                          P 
 3412 nobody    32  12  131928  42936   9880 S  89.3  0.0   1136:13 node_exporter                                                                   40 
```

#### h按键中的使用举例

- 按键1/2/3查看numa信息(todo列的信息解读)

```bash
top - 11:20:51 up 1 day, 20:28,  4 users,  load average: 0.30, 5.97, 15.91
Tasks: 983 total,   1 running, 462 sleeping,   0 stopped,   0 zombie
%Cpu0  :  1.6 us,  0.3 sy,  0.0 ni, 98.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu1  :  1.6 us,  1.6 sy,  0.0 ni, 96.8 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu2  :  1.0 us,  1.3 sy,  0.0 ni, 97.7 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st

```

- 按键 V显示森林样式

```bash
top - 11:25:46 up 1 day, 20:32,  4 users,  load average: 5.58, 3.95, 12.20
Tasks: 990 total,   1 running, 459 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.8 us,  0.7 sy,  0.0 ni, 98.5 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Node0 :  0.7 us,  0.6 sy,  0.0 ni, 98.7 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Node1 :  0.8 us,  0.7 sy,  0.0 ni, 98.4 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
KiB Mem : 52802470+total, 29372800+free, 12429716 used, 22186699+buff/cache
KiB Swap:        0 total,        0 free,        0 used. 52080537+avail Mem 

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
 2508 root      20   0   72304   6316   5568 S   0.0  0.0   0:00.05  `- sshd                                                                                                                                                                                                                          
 7586 root      20   0  106048   7280   6152 S   0.0  0.0   0:00.05      `- sshd                                                                                                                                                                                                                      
 7873 root      20   0   22032   5920   3652 S   0.0  0.0   0:00.20          `- bash                                                                                                                                                                                                                  
13094 root      20   0   11732   3248   2904 S   0.0  0.0   0:00.00              `- mtail.sh                                                                                                                                                                                                          
13863 root      20   0  720288  23412   9496 S   1.3  0.0   0:18.39                  `- mtail
```