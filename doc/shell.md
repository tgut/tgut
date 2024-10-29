<!--
 * @Descripttion: 
 * @version: 
 * @Author: tgut
 * @Date: 2024-03-10 21:42:26
 * @LastEditors: tgut
 * @LastEditTime: 2024-07-09 15:56:08
-->
### 删除可执行文件
如下两种方式

```bash
rm `ls -F |grep \*|sed 's/.$//'`
find . -perm +100 -type f -delete
```

>参考
[Bash删除可执行文件的几种方法](https://blog.csdn.net/qq_41437512/article/details/124619974)

### 排查进程导致的系统卡顿
在Linux系统中，可以通过以下步骤查看Node.js进程是被哪个程序启动的：

1. **查找Node.js进程的PID**：
   使用`ps`命令结合`grep`来查找Node.js进程的进程ID（PID）。
   ```bash
   ps aux | grep node
   ```
   这将列出所有包含"node"的进程。注意第二列显示的就是进程ID（PID）。

2. **查看Node.js进程的父进程ID（PPID）**：
   使用找到的PID，通过`ps`命令查看该进程的父进程ID（PPID）。
   ```bash
   ps -o ppid= -p YOUR_NODE_PID
   ```
   将`YOUR_NODE_PID`替换为你在第一步中找到的Node.js进程的PID。

3. **查看父进程信息**：
   使用父进程ID（PPID），你可以查看是哪个程序启动了Node.js进程。
   ```bash
   ps -f -p YOUR_NODE_PPID
   ```
   将`YOUR_NODE_PPID`替换为你在第二步中找到的父进程ID。

这种方法可以帮助你追踪Node.js进程是如何被启动的，特别是在调试复杂应用或理解系统行为时非常有用。
