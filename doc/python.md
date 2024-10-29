### python如何调试

使用pdb,用例如下：

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

### python使用pandas

[pandas知识点超全总结](https://blog.csdn.net/Itsme_MrJJ/article/details/126101002)