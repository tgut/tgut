### 工具安装

```bash
brew install python
```

### macos iterm 配置
配置后退键control +<
配置删除键control + backtrack
[上面配置链接](https://blog.csdn.net/JackLang/article/details/116330286)

需要像vscode一样，option移动一个单词，cmd移动到行首/行尾。

### 磁盘清理

使用如下命令可以清理无效磁盘

```bash
#查看磁盘信息
diskutil list
#会打印如下信息，以卸载disk0s6为例
# dev/disk0 (internal, physical):
#    #:                       TYPE NAME                    SIZE       IDENTIFIER
#    0:      GUID_partition_scheme                        *500.3 GB   disk0
#    1:             Apple_APFS_ISC Container disk1         524.3 MB   disk0s1
#    2:                 Apple_APFS Container disk3         346.1 GB   disk0s2
#    3:                 Apple_APFS Container disk4         2.5 GB     disk0s5
#    4:                 Apple_APFS Container disk6         499.1 MB   disk0s4
#    5:           Linux Filesystem                         2.1 GB     disk0s6
#                     (free space)                         145.3 GB   -
#    6:        Apple_APFS_Recovery Container disk2         5.4 GB     disk0s3

# /dev/disk3 (synthesized):
#    #:                       TYPE NAME                    SIZE       IDENTIFIER
#    0:      APFS Container Scheme -                      +346.1 GB   disk3
#                                  Physical Store disk0s2
#    1:                APFS Volume Macintosh HD            10.3 GB    disk3s1
#    2:              APFS Snapshot com.apple.os.update-... 10.3 GB    disk3s1s1
#    3:                APFS Volume Preboot                 6.1 GB     disk3s2
#    4:                APFS Volume Recovery                936.4 MB   disk3s3
#    5:                APFS Volume Data                    220.8 GB   disk3s5
#    6:                APFS Volume VM                      14.0 GB    disk3s6

#先查看信息
diskutil info /dev/disk0s6
#先unmount卸载，如果失败，使用force参数
diskutil unmount /dev/disk0s6
#清楚内容，然后自动并入磁盘到"free space"
sudo diskutil eraseVolume free free /dev/disk0s6
##下面操作是合并磁盘到/dev/disk0s2
sudo diskutil apfs resizeContainer /dev/disk0s2 0  # 0 表示使用所有相邻空闲空间

```
