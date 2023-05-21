### 删除可执行文件
如下两种方式

```bash
rm `ls -F |grep \*|sed 's/.$//'`
find . -perm +100 -type f -delete
```

>参考
[Bash删除可执行文件的几种方法](https://blog.csdn.net/qq_41437512/article/details/124619974)