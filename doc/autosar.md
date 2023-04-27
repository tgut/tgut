# Autosar架构



## SOA



## DoIP

DoIP在传输层以下的规范遵循ISO 13400，而应用层还是遵循ISO 14229不变，这样可以保证UDS诊断在不同车载网络上的可移植性

![ISO7层网络](../pic/doc/autosar/doip.png)

#### 参考
 1. [一文了解DoIP](https://blog.csdn.net/wjz110201/article/details/114940052#:~:text=%E5%92%8C%E5%A4%A7%E5%AE%B6%E6%8E%A2%E8%AE%A8%E3%80%82-,DoIP%E6%98%AFDiagnostic%20communication%20over%20Internet%20Protocol%20%E7%9A%84%E7%AE%80%E7%A7%B0%EF%BC%8C%E9%A1%BE%E5%90%8D%E6%80%9D%E4%B9%89,1%E8%BF%99%E5%9B%9B%E5%B1%82%E5%8D%8F%E8%AE%AE%E3%80%82)

## Some/IP(Scalable service-Oriented MiddlewarE over IP)
    
    主要用在ecu之间交换信息，底层协议使用udp/tcp.其报文格式如下图。

![someip header message](../pic/doc/autosar/someip_header.png)

#### 参考
1. 文档参考[autosar官网](https://www.autosar.org/search?tx_solr%5Bq%5D=someIp)
2. [汽车电子小白如何学习SOME/IP协议？](https://www.zhihu.com/question/535650389)

## AP Autosar介绍


ap 架构图

![AP Autosar图片](../pic/doc/autosar/ap_autosar.png)

1. FO

2. Adaptive Autosar

3. Classic Autosar

## 开源的autosar 代码（todo）


#### 参考

1. [一文看懂，Adaptive AUTOSAR从入门到精通（一）](http://www.uml.org.cn/qiyezjjs/202111054.asp)
2. [一文看懂，Adaptive AUTOSAR从入门到精通（一）](https://www.suncve.com/adaptive-autosar-from-introduction-to-mastery-2/)
3. [一文看懂，Adaptive AUTOSAR从入门到精通（三）](http://www.uml.org.cn/qiyezjjs/202111084.asp?artid=24618)

## DDS(Data Distribution Service)


dds 主要提供订阅和分发服务，其使用的传输协议有一下三种：
1.tcp 2.udp 3.shared-memory

![DDS应用实列图](../pic/doc/autosar/databus.png)


参考

[Data Distribution Service (DDS) Community RTI Connext Users](https://community.rti.com/glossary-term/databus)
## TSN(gptp)

GPTP stands for "IEEE 802.1AS-Rev Time-Sensitive Networking (TSN) Protocol", also known as "IEEE 1588-2008 Precision Time Protocol (PTP) for G.MACs" or "gPTP" for short. It is a standard for time synchronization of clocks in distributed systems, particularly those that require precise timing, such as industrial automation, avionics, and multimedia applications.

## LIN总线
    Local Interconnect Network,类似uart总线，是基于 UART/SCI(通用异步收发器/串行通信接口)的低成本串行通信协议。

[LIN总线的学习](https://blog.csdn.net/zz56z56/article/details/95034165#:~:text=%E6%80%BB%E7%BA%BF%E7%9A%84%E5%AD%A6%E4%B9%A0-,LIN%E4%BB%8B%E7%BB%8DLIN%20%E6%98%AFLocal%20Interconnect%20Network%20%E7%9A%84%E7%BC%A9%E5%86%99%EF%BC%8C%E6%98%AF,%E5%BA%94%E7%94%A8%E9%83%BD%E4%BD%BF%E7%94%A8LIN%E6%80%BB%E7%BA%BF%E3%80%82)