### stash 使用
以下是关于 `git stash` 的使用的一些基本信息：

1. **保存当前的工作进度**：你可以使用 `git stash save "your message"` 来保存当前的工作进度。你可以在 "your message" 中写入一些描述信息，以便于你之后能够记住这个 stash 是做什么的。

```bash
git stash save "your message"
```

2. **查看所有的 stash**：你可以使用 `git stash list` 来查看所有的 stash。

```bash
git stash list
```

3. **应用一个 stash**：你可以使用 `git stash apply stash@{n}` 来应用一个 stash，其中 n 是你想要应用的 stash 的编号。

```bash
git stash apply stash@{n}
```

4. **删除一个 stash**：你可以使用 `git stash drop stash@{n}` 来删除一个 stash，其中 n 是你想要删除的 stash 的编号。

```bash
git stash drop stash@{n}
```

5. **应用并删除一个 stash**：你可以使用 `git stash pop stash@{n}` 来应用一个 stash，并且在应用之后删除它。

```bash
git stash pop stash@{n}
```

请注意，stash 的编号是从 0 开始的，最新的 stash 的编号是 0。

### config配置

```bash
git config --global core.pager ''  #配置git log/ branch显示不使用分页器;恢复的话配置为'less'
```
```bash
git config --global pager.branch false #只想禁用特定命令的分页（例如 git branch），可以使用
```

### git cherry-pick常用命令

```bash
git cherry-pick commit1..commit2  # 不包括 commit1

git cherry-pick commit1 commit2 commit3 # 你可以同时拣选多个提交，通过空格分隔它们的哈希值
```