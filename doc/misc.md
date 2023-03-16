### arm

1. 相关硬件的深入（todo）

rdma/dpdk/spdk pcie cxl(compute express link)

dpdk:data plane develop kit

spdk:storage performance develop kit.

numa(non unify memroy access)   I/O network

aarch64是64位执行状态，包括状态的异常模型、内存模型、程序员模型和指令集支持

2. arm mali gpu

3.Vulkan,OpenGL/ES,EGL.

Vulkan is next generation of OpenGL.

Direct3D is a graphics application programming interface (API) for Microsoft Windows.

WebGL (Web Graphics Library) is a JavaScript API for rendering high-performance interactive 3D and 2D graphics within any compatible web browser without the use of plug-ins. WebGL does so by introducing an API that closely conforms to OpenGL ES 2.0 that can be used in HTML <canvas> elements.

[shadertoy教程](https://vosaica.github.io/2020/08/07/Shadertoy_vol1/)

### enflame

1. horovod总结

2. pytorch源码分析

3. shell 脚本基本语法

4. tensorflow2/PalMe 2算法原理（端到端训练）




#### RDMA 和 DPDK对比

相同点：

1）两者均为kernel bypass技术，可以减少中断次数，消除内核态到用户态的内存拷贝；

相异点：

1）DPDK是将协议栈上移到用户态，而RDMA是将协议栈下沉到网卡硬件，DPDK仍然会消耗CPU资源；

2）DPDK的并发度取决于CPU核数，而RDMA的收包速率完全取决于网卡的硬件转发能力

3）DPDK在低负荷场景下会造成CPU的无谓空转，RDMA不存在此问题

4）DPDK用户可获得协议栈的控制权，可自主定制协议栈；RDMA则无法定制协议栈

#### SPDK的核心

SPDK 重用了 DPDK 中的一些公共组件，比如内存管理、轮询方式的实现等。SPDK的核心是通过无锁、轮询的方式实现高效的用户态驱动集合：

1. SPDK 将 NVMe 协议的实现放在用户态，存储应用程序直接通过 SPDK 提供的 API 访问设备，不需要 Linux 内核提供的驱动支持。
2. SPDK 一个重要的设计理念是无锁化，这样避免了多线程由于对锁的争抢而引入的性能开销。
3. 轮询模式，SPDK 使用轮询方式处理数据，这样避免了传统中断方式由于上下文切换而引入的性能开销


### 参考

1. [spdk](https://github.com/spdk/spdk)
2. [dpdk](https://github.com/DPDK/dpdk)
3. [全网【DPDK/SPDK】技术视频教程：SPDK 存储性能开发套件](https://www.bilibili.com/video/BV1ZD4y1r7qW/?spm_id_from=333.337.search-card.all.click&vd_source=bce36a62109c7c14e5d27e3a9df82a18)
4. [RDMA vs. DPDK](https://www.jianshu.com/p/09b4b756b833)
5. [使用 SPDK 技术优化虚拟机本地存储的 IO 性能](https://blog.didiyun.com/index.php/2018/12/20/spdk-io/)
6. [好大一棵树 - PCIe Tree](https://mp.weixin.qq.com/s?__biz=MzU4MTczMDg1Nw==&mid=2247483660&idx=1&sn=c3f0da07f82685a1c09f176efb4fb695&chksm=fd42564aca35df5c358f3744cb784d6af8ee2993fa5a740eaeb44c3579e3f0c62d217e753477&scene=178&cur_album_id=1337043626001661952#rd)