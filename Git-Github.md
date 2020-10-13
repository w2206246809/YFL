`按shift+右键可以直接在当前文件夹下打开命令行`



与github关联仓库（通过ssh访问）：

[参考链接](https://help.github.com/en/github/authenticating-to-github/adding-a-new-ssh-key-to-your-github-account)

- 生成本地ssh证书：ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
- 更新ssh证书：ssh-add ~/.ssh/id_rsa
- 复制ssh key：clip < ~/.ssh/id_rsa.pub （在git bash中）
- 个人 - 设置 - SSH and GPG keys - New SSH key - 在 "key" 中粘贴



git status 查看当前状态

git log 查看日志

git show <commit_id> 查看日志中某一项的具体提交情况

git reset <void> | <commit_id> 回滚目标操作或上一个操作



git clone <address> <可选：仓库名> 从github克隆到本地

git add <fine_name> 添加文件到暂存区

git commit -m "<MSG>" 将改变提交到仓库并附加信息 <MSG>

git push 更改提交到远端（github）

git pull 从远端拉取



git config --global user.email = <email_address>

git config --global user.name= <name> 设置当前用户信息



git branch -a 查看所有的分支

git branch <branch_name> 创建一个分支

git checkout <branch_name> 切换到目标分支

git checkout -b <branch_name> 创建并切换到分支

git merge <branch_name> 将目标分支与当前分支合并

git push origin --delete <branch_name> 删除分支

