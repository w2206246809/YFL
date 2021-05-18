`按shift+右键可以直接在当前文件夹下打开命令行`

# 基础命令

与github关联仓库（通过ssh访问）：

[参考链接](https://help.github.com/en/github/authenticating-to-github/adding-a-new-ssh-key-to-your-github-account)

- 生成本地ssh证书：ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
- 更新ssh证书：ssh-add ~/.ssh/id_rsa
- 复制ssh key：clip < ~/.ssh/id_rsa.pub （在git bash中）
- 个人 - 设置 - SSH and GPG keys - New SSH key - 在 "key" 中粘贴



git status 查看当前状态

git diff 查看修改内容

git log 查看日志

git show <commit_id> 查看日志中某一项的具体提交情况

git reset <void> | <commit_id> 回滚目标操作或上一个操作

git checkout . 回退本地所有修改但未提交的（注意有一个点 **.** ）



git init <git_project_name> 在当前目录下创建一个git仓库

git clone <address> <可选：仓库名> 从github克隆到本地

`git lfs clone 如果工程中存在大量二进制文件则需要使用该方法，否则工程内容不完整，需要仓库支持lfs`

git add <fine_name> 添加文件到暂存区

`git add/ git rm/ git mv 新增/删除/移动文件到暂存区 git mv还可用于重命名文件`

git commit -m "<MSG>" 将改变提交到仓库并附加信息 <MSG> (git commit -am "<MS>" 可以实现一次性提交大量改动)

git push 更改提交到远端（github）

git pull 从远端拉取



git config --global user.email = <email_address>

git config --global user.name= <name> 设置当前用户信息

### 分支管理

git branch -a 查看所有的分支

git branch <branch_name> 创建一个分支

git checkout <branch_name> 切换到目标分支

git checkout -b <branch_name> 创建并切换到分支

git merge <branch_name> 将目标分支与当前分支合并



git branch -d <branch_name> 删除分支

以下操作用于删除远端分支：

git branch -d -r <branch_name> 删除

git push origin:<branch_name> 推送

# 操作

### 1、配置

**用户配置：**

git config --global user.name "YFL"

git config --global user.email YFL@yfl.com



**windows与linux之间的换行问题**

git config --global core.autocrlf true 本地使用CRLF 远端使用LF

git config --global core.autocrlf input 本地使用CRLF/LF 远端使用LF

git config --global core.autocrlf false 本地使用CRLF/LF 远端使用CRLF/LF



**编码**

#中文编码

git config --global gui.encoding utf-8

git config --global i18n.commitencoding utf-8

git config --global i18n.logoutputencoding utf-8

#显示路径中的中文

git config --global core.quotepath false



**git与服务器间的认证**

git config --global credential.helper store 设置口令缓存，记录上次认证结果

git config http.sslverify false 添加HTTPS证书信任

ssh-keygen -t rsa -b 4096 -C "your_email@example.com" 生成公钥与私钥，生成的 *.pub 文件即公钥，复制其内容可用作认证

### 2、使用

git diff --name-status 只查看文件列表



**分支提交**

常见git push格式：git push origin branch_name



**新建分支** 都是基于当前所在分支新建的分支

git checkout <branch_name> 切换到目标分支 -f 强制切换

git checkout -b <branch_name> 创建并切换到分支



**分支获取**

常见git pull格式：git pull origin remote_branch:local_branch

git fetch 与 git pull 区别 - 不会做自动合并



**分支合并**

git merge branch_name

git rebase branch_name 将目标分支合并到当前分支



**撤销操作**

git reset commit_id 主要用于撤销 git add/commit 等操作

`commit_id 通过 git log 等方法获得`



git checkout . 撤销所有修改而未提交的操作（注意有一个点 **.** ）

git checkout -filename 撤销某一个文件的修改

git checkout commit_id 撤销到历史上某次提交的工作区