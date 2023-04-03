### autosar架构

### soa

### DoIP

    DoIP在传输层以下的规范遵循ISO 13400，而应用层还是遵循ISO 14229不变，这样可以保证UDS诊断在不同车载网络上的可移植性

   [ISO7层网络](../pic/doc/autosar/doip.png)

1. [一文了解DoIP](https://blog.csdn.net/wjz110201/article/details/114940052#:~:text=%E5%92%8C%E5%A4%A7%E5%AE%B6%E6%8E%A2%E8%AE%A8%E3%80%82-,DoIP%E6%98%AFDiagnostic%20communication%20over%20Internet%20Protocol%20%E7%9A%84%E7%AE%80%E7%A7%B0%EF%BC%8C%E9%A1%BE%E5%90%8D%E6%80%9D%E4%B9%89,1%E8%BF%99%E5%9B%9B%E5%B1%82%E5%8D%8F%E8%AE%AE%E3%80%82)

### Some/IP(Scalable service-Oriented MiddlewarE over IP)
    
    主要用在ecu之间交换信息，底层协议使用udp/tcp.其报文格式如下图。

[someip header message](../pic/doc/autosar/someip_header.png)

#### 参考
1. 文档参考[autosar官网](https://www.autosar.org/search?tx_solr%5Bq%5D=someIp)
2. [汽车电子小白如何学习SOME/IP协议？](https://www.zhihu.com/question/535650389)

### ap autosar介绍(todo)

画ap 架构图

### 开源的autosar 代码（todo）

### 参考

1. [一文看懂，Adaptive AUTOSAR从入门到精通（一）](http://www.uml.org.cn/qiyezjjs/202111054.asp)
2. [一文看懂，Adaptive AUTOSAR从入门到精通（一）](https://www.suncve.com/adaptive-autosar-from-introduction-to-mastery-2/)
3. [一文看懂，Adaptive AUTOSAR从入门到精通（三）](http://www.uml.org.cn/qiyezjjs/202111084.asp?artid=24618)

### DDS(Data Distribution Service)

dds 主要提供订阅和分发服务，其使用的传输协议有一下三种：
1.tcp 2.udp 3.shared-memory

### tsn(gptp)

GPTP stands for "IEEE 802.1AS-Rev Time-Sensitive Networking (TSN) Protocol", also known as "IEEE 1588-2008 Precision Time Protocol (PTP) for G.MACs" or "gPTP" for short. It is a standard for time synchronization of clocks in distributed systems, particularly those that require precise timing, such as industrial automation, avionics, and multimedia applications.

