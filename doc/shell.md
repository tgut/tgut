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
### 查找所有Python虚拟环境

在 macOS 或 Linux 系统中，可以使用以下命令来查找用户主目录下的所有 Python 虚拟环境：

```bash
find ~ -type f -path "*/bin/activate" -print | xargs -I {} dirname {}/..
```

#### 命令解释

这个命令的原理是查找所有名为 `activate` 的文件（虚拟环境的标志），然后找到它们所在的根目录。

- **`find ~ -type f -path "*/bin/activate" -print`**:
  - `find ~`: 从用户主目录 (`~`) 开始查找。
  - `-type f`: 只查找文件类型。
  - `-path "*/bin/activate"`: 查找路径匹配 `*/bin/activate` 的文件。一个虚拟环境最可靠的标志是它内部包含一个 `bin/activate` 文件。
  - `-print`: 打印出找到的完整路径，例如 `/Users/yourname/project/venv/bin/activate`。

- **`| xargs -I {} dirname {}/..`**:
  - `|`: 将 `find` 命令的输出通过管道传给 `xargs`。
  - `xargs -I {} ...`: `xargs` 读取 `find` 输出的每一行路径，并将其赋值给占位符 `{}`，然后执行后面的命令。
  - `dirname {}/..`: 对每个找到的 `activate` 文件路径，`dirname` 会计算其上两级的目录。
    - `dirname /path/to/venv/bin/activate` 的结果是 `/path/to/venv/bin`。
    - `dirname /path/to/venv/bin/..` 的结果是 `/path/to/venv`，这正是虚拟环境的根目录。

最终，这个命令会列出所有找到的虚拟环境的根目录路径。

