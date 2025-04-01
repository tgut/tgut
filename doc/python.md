### python如何调试

#### 使用pdb,用例如下：

```python
import pdb

def copy_common_spec(self):
    source_dir = self.env.system_function_path / "common" / "func_spec"
    target_dir = self.local_dir / self.project
    
    pdb.set_trace()  # 设置断点
    
    if not source_dir.exists():
        logger.error(f"Source directory {source_dir} not exist")
        return
    
    for item in source_dir.iterdir():
        if item.is_file():
            shutil.copy(item, target_dir / item.name)
        if item.is_dir():
            shutil.copytree(item, target_dir / item.name, dirs_exist_ok=True)
```

#### 使用vscode的工具
    https://blog.csdn.net/qq_16555103/article/details/136938822

### python使用pandas

[pandas知识点超全总结](https://blog.csdn.net/Itsme_MrJJ/article/details/126101002)

### python2.7命令下报"No module named pycache"

python2使用pyc缓存字节码，python3使用__pycache__来缓存字节码，使用python3命令运行的时候生成了__pycache__缓存。所以再用python3的时候报错。

字节码的来源：
Python源代码在执行前会被编译成字节码，这是一种中间形式，保存在.pyc文件中。缓存这些字节码的主要作用是提高程序的启动速度。每次运行脚本时，如果源代码没有改动，Python可以直接加载已编译的字节码，省去了重复编译的时间。这对于大型项目或依赖多个模块的应用来说尤为重要，能显著减少启动时间。

不同python版本的对应的字节码存储方式：

| 版本 | 字节码存储方式 | 缓存目录 |
|------|----------------|----------|
| Python 2 | 同目录生成 .pyc 文件 | 无专用目录 |
| Python 3 | 集中存储在 __pycache__ | 自动创建目录 |

#### 解决方法

```bash
# 删除所有缓存文件（Python 2 和 3 的）,按需删除pycache/pyc目录
find . -name "__pycache__" -exec rm -rf {} \;  # 删除缓存目录
find . -name "*.pyc" -delete                   # 删除.pyc文件
```