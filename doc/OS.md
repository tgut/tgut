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