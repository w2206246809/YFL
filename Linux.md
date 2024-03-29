# Linux基础

**'/'** 指从根目录开始导航 **'./'** 指从当前目录开始导航

# 常用命令

**查看当前目录**：

pwd

ls -al 显示当前目录下所有文件（包括隐藏的）

**Control + Z挂起进程**：

jobs -> 查看当前被挂起的进程
bg %n -> 后台开始第n个进程
fg %n -> 前台开始第n个进程

注：不带%n默认对最后一个进程操作

**复制**：

cp [-adfilprsu] <源文件> <目标文件>

​	-a:是指archive的意思，也说是指复制所有的目录
​    -d:若源文件为连接文件(link file)，则复制连接文件属性而非文件本身
​    -f:强制(force)，若有重复或其它疑问时，不会询问用户，而强制复制
​    -i:若目标文件(destination)已存在，在覆盖时会先询问是否真的操作
​    -l:建立硬连接(hard link)的连接文件，而非复制文件本身
​    -p:与文件的属性一起复制，而非使用默认属性
​    -r:递归复制，用于目录的复制操作
​    -s:复制成符号连接文件(symbolic link)，即“快捷方式”文件
​    -u:若目标文件比源文件旧，更新目标文件

**移动**：

mv [-fiv] <源文件> <目标文件>

​	-f:force，强制直接移动而不询问
​    -i:若目标文件(destination)已经存在，就会询问是否覆盖
​    -u:若目标文件已经存在，且源文件比较新，才会更新

**删除**：

mv [-fir] <文件/文件夹名称>

​	-f:强制删除
​    -i:交互模式，在删除前询问用户是否操作
​    -r:递归删除，常用在目录的删除

**压缩**：

tar -zcvf <文件名> <压缩后的文件名>

**解压缩**：

tar -zxvf <文件名>

## 文件创建

touch file_name 新建文件在当前目录

echo "msg" >> Text 新建文件Text并将msg写入

cat Text 打开Text文件

cat>>Text1 创建Text1文件之后可以向文件写入内容，ctrl+D关闭

# 常见问题

去除文本中的 ‘\r’ ：

```shell
vi doc_file
:set fileformat=unix
:w
```

解除端口占用：

```shell
# 查询占用端口的进程pid(1)
sudo lsof -i:[PORT_NUMBER]

# 查询占用端口的进程号(2)
netstat -ntlp|grep [PORT_NUMBER]

# 获得pid之后根据pid关闭进程
sudo kill -9 [PID]
```

# Vim/Vi操作

常用命令：

i 编辑模式

w 保存

q 退出 q! 强制退出

/<search_string> 搜索字段<search_string> n 下一个匹配的结果

命令模式下双击 d 可以删除一行