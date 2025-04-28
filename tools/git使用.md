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


以下是使用 Markdown 格式描述的 Git 标签操作步骤：

### 创建标签

1. **找到指定的 commit ID**：
   首先，找到你要打标签的 commit ID。你可以使用 `git log` 命令查看 commit 历史。

   ```sh
   git log
   ```

   例如，假设你找到了一个 commit ID 为 `abc1234`。

2. **创建标签**：
   使用 `git tag` 命令为指定的 commit 创建标签。你可以选择创建轻量标签或附注标签。

   - 轻量标签：

     ```sh
     git tag <tag_name> <commit_id>
     ```

     例如，创建一个名为 `v1.0` 的轻量标签：

     ```sh
     git tag v1.0 abc1234
     ```

   - 附注标签：

     ```sh
     git tag -a <tag_name> <commit_id> -m "Tag message"
     ```

     例如，创建一个名为 `v1.0` 的附注标签，并添加标签信息：

     ```sh
     git tag -a v1.0 abc1234 -m "Release version 1.0"
     ```

3. **推送标签到远程仓库**：
   使用 `git push` 命令将标签推送到远程仓库。

   ```sh
   git push origin <tag_name>
   ```

   例如，推送 `v1.0` 标签到远程仓库：

   ```sh
   git push origin v1.0
   ```

4. **推送所有本地标签到远程仓库（可选）**：
   如果你有多个标签需要推送，可以使用以下命令将所有本地标签推送到远程仓库：

   ```sh
   git push origin --tags
   ```

### 删除标签

1. **删除本地标签**：
   使用 `git tag -d` 命令删除本地标签。

   ```sh
   git tag -d <tag_name>
   ```

   例如，删除名为 `v1.0` 的本地标签：

   ```sh
   git tag -d v1.0
   ```

2. **删除远程标签**：
   使用 `git push` 命令删除远程标签。

   ```sh
   git push origin :refs/tags/<tag_name>
   ```

   例如，删除远程仓库中的 `v1.0` 标签：

   ```sh
   git push origin :refs/tags/v1.0
   ```
   ### 显示详细log

  git log --decorate 

```bash
#git log --help |grep -decorate -C 3
         --no-decorate, --decorate[=short|full|no]
           Print out the ref names of any commits that are shown. If short is specified, the ref name prefixes refs/heads/, refs/tags/ and refs/remotes/ will not be printed. If full is
           specified, the full ref name (including prefix) will be printed. The default option is short.
```

### tips

查看某行删除的commit信息

```shell

# 搜索包含指定字符串的提交（精确匹配）
git log -S "被删除的文本内容" -- path/to/file

# 示例：查找文件 app.js 中删除 "const debugMode = true" 的提交
git log -S "const debugMode = true" -- app.js
```

### 合并提交

git rebase -i commit_id #合并commit_id之后的提交，不包含commit_id