# 通用

对象操作：

```python
class class_name: # 类的定义
    var_1 = [] # 变量声明
    def __init__(self):
        var_1 = [1, 0] # 变量初始化
        pass
    
new_class = class_name() # 对象实例化
```

获取系统时间：

```python
from datetime import datetime
dt = datetime.now() # 获取datetime对象
print('时间：(%Y-%m-%d %H:%M:%S %f):', dt.strftime('%Y-%m-%d %H:%M:%S %f'))
# 时间：(%Y-%m-%d %H:%M:%S %f): 2019-04-17 15:04:59 815000
print('时间：(%Y-%m-%d %H:%M:%S %p):', dt.strftime('%y-%m-%d %I:%M:%S %p'))
# 时间：(%Y-%m-%d %H:%M:%S %p): 19-04-17 03:04:59 PM
```

接收命令行参数：

```python
import sys

sys.argv # 参数列表

len(sys.argv) # 参数个数
```

# 常见问题

**OSError: [Errno 8] Exec format error**：

在python文件头部添加 #! /usr/bin/env <python> `（注：<python>应填写需要使用的python版本）`

**ImportError: No module named _internal:**

可能是重复安装pip导致的问题，解决方法：sudo apt remove python-pip

# pip

pip是安装Python包的主要方法。

使用pip下载时可能因为国内网络环境问题导致下载失败，通过更改pip下载时的源来解决该问题：

```shell
pip install -i <url>
```

pip国内的一些镜像：

> [参考链接](https://blog.csdn.net/weixin_41712059/article/details/86704492)

```
阿里云 http://mirrors.aliyun.com/pypi/simple/ 
中国科技大学 https://pypi.mirrors.ustc.edu.cn/simple/ 
豆瓣(douban) http://pypi.douban.com/simple/ 
清华大学 https://pypi.tuna.tsinghua.edu.cn/simple/ 
中国科学技术大学 http://pypi.mirrors.ustc.edu.cn/simple/
阿里云 http://mirrors.aliyun.com/pypi/simple/ 
```

## pip依赖问题

如果通过pip安装任何包的时候出现了依赖问题，使用aptitude安装可以解决。(可能需要先安装aptitude)

```shell
aptitude install <packet_name>
```



# 多线程

```python
import threading

def TestFunc(args):
    print('started')
    
msg = ['hello']
# target 为函数名称
# args 为参数
t = threading.Thread(target=TestFunc, args=(msg,))
t.start()
```



# Socket

### UDP

**server**

```python
import socket

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # 设置以IP地址连接、设置以UDP方式连接
server.bind('0.0.0.0', 8888) # 绑定本机端口的8888

# 等待连接并接收数据 data为二进制流 addr为二元组(ip_address, port)
data, addr = server.recvfrom(1024) # 1024为buffer最大大小
server.sendto(b'hello', addr) # 注意发送数据应该以二进制流的形式
server.close()

print(data.decode('utf8'), addr) # 以utf-8的方式解析二进制流
```



**client**

```python
import socket

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
client.sendto(b'hello', ('127.0.0.1', 8888))
rs = client.recvfrom(10240)
client.close()
```



# 结构体 struct

```python
import struct

# 解析二进制流为结构体
rs = struct.unpack('iff20s', bit_stream)

# 'iff20s' 为结构体的格式
# i int 整型数
# f float 浮点数
# s 字符串，一般前面需要有数字说明大小，*数字也可以放在任意字母前代表对应类型的数组

# 打包数据为二进制流
rs = struct.pack('iff20s', 12, 12.3, 17.1, b'helloWorld')
```



# 字符串

**url 格式文本处理**

`有时 url 传值附带的中文字符会转化为“url格式文本”，在Python程序中会直接转化为 ‘%.%. ...’ 的字符串`

```python
import urllib.parse

# 将字符串中的中文字符转化为url格式字符
url_string = urllib.parse.quote( py_string )

# 将字符中的url格式字符转化为中文字符
py_string = urllib.parse.unquote( url_string )

# 注：python2 ：将 urllib.parse 替换为 urlparse
```

**string.decode():**

将二进制数据等编码为python程序中的一般字符串，主要应用与网络通信的过程中。

# 数组

获取数组长度：len(list)

**删除操作**

```python
li = ['1', '3', '5', '7']
li.remove('3') # 通过list对象的remove( val )方法，直接删除列表中的某个元素

del li[1] # 利用del， 直接通过数组下标（索引）删除
```



# 字典

```python
dict = {}
dict[key] = value

# 一般形式:

dict = { 'key' : 'value', ... } # value 可以是具体的值或者 list 或者 dict 或者 python 中的任何对象，key 一般是具体的值
```

**字典的遍历**

一般通过以下方法遍历：

```python
for key in dict.keys():
	dict[key]
```

**删除操作**

pop( key ) : 删除键值为 key 的元素以及对应的值。

del dict['key'] : 删除键值为 'key' 的元素。

del dict : 删除 dict 字典。

# 队列

```python
#! 先进先出队列 FIFO
from queue import Queue # 引入队列

q = Queue(maxsize=0) # 创建一个队列，设置最大大小maxsize（如果不大于0则不限制大小）

# 通过 Queue.put( value ) 方法使元素入队
q.put(1)
q.put([2, 3])

# 通过 Queue.get() 方法使元素出队并获得元素
value = q.get()

# 通过 Queue.qsize() 方法获得当前队列长度
size = q.qsize()

isEmpty = q.empty() # 返回队列是否为空，一般使用get()方法获得元素的时候应该先判断队列是否为空

ifFull = q.full() # 队列是否为满
```

# JSON相关操作

```python
import json

# 将json字符串转换为字典（python中的字典和json的形式相同）

jsonStr = '{ "name" : "yfl_lab", "type" : 26 }' // 使用单引号引双引号

dict = json.loads( jsonStr )

# 将字典转换为json字符串

jsonStr = json.dumps( dict )
```

# 文件操作

> [参考文献](https://www.runoob.com/python/python-files-io.html)

```python
# open 打开文件操作默认为只读
file_read = open('fileName')

# w+ 操作为创建文件并重写已经存在的文件（会覆盖原文件）
# a 指则为追加模式，打开文件后文件指针将自动定位到文件末尾，如果文件不存在则为创建文件并写入
file_createOrChange = open('fileName', 'w+')

string = file_read.read()
file_createOrChange.write(string)
```

删除文件：os.remove('<文件名>')

文件重命名：os.rename('<修改前的名称>', '<修改后的名称>')

**遍历文件名 / 修改文件名**

```python
import os

files = os.listdir("[ 这里填写文件绝对路径，注意使用双斜杠\\ ]")
for fileName in files:
    print(fileName)
    
    # TODO: 修改文件后缀名
    # ...
    # seg[0]为文件后缀前的名字，seg[1]为文件后缀名
    seg = os.path.splitext(fileName)
    newName = seg[0] + '.newFix'
    
    os.chdir("[ 这里填写文件绝对路径，注意使用双斜杠\\ ]")
    os.rename(fileName, newName)
```

**遍历文件**

```python
import os

for root, dirs, files in os.walk(rootPath): # rootPath 为需要遍历的文件夹路径（可以是相对路径）
    for fileName in files:
        filePath = root + '/' + fileName
        fileStream = open(filePath, 'r')
        print(fileStream.read())
        fileStream.close()
```

# 服务器设计

## Flask服务器框架

### 常见问题

**required field "type_ignores" missing from Module**：

这个问题是由于werkzeug包与python3.8冲突导致的，打开文件：

C:\Users\Acer\AppData\Local\Programs\Python\Python38\Lib\site-packages\werkzeug\routing.py

将第950行的：

```python
module = ast.fix_missing_locations(ast.Module([func_ast]))
```

改为：

```python
module = ast.fix_missing_locations(ast.Module([func_ast], []))
```

即可。这是因为该函数需要两个参数而原函数只提供了一个。

### Get Start

**安装**

`pip install flask`

**Flask框架文件结构**

**服务器代码根目录**：<flask_web_server>/server.py `// 文件名称可自定`

**存放静态资源**：<flask_web_server>/static

静态资源文件夹用于存放 .css .js 等框架文件，在前端页面设计的时候需要在 src 的 url 前**注明 '/static/'**， 服务器即可自动响应并向其发送所请求的静态资源，而不用针对每个静态资源设置不同的请求响应处理函数。

**存放模板资源**：<flask_web_server>/templates

模板资源文件夹用于存放设计的网页等非框架文件，在调用服务器框架API返回页面等文件的时候是以该目录为根目录寻找文件并返回的。

### 服务器程序设计

服务器初始化，其中的 __ name __ 可自定：

```python
from flask import Flask

app = Flask(__name__)
```

可以自定义 **静态/模板** 资源存放路径：

```python
app = Flask(__name__, static_folder='static_path', template_folder='template_path')
```

启动服务器，可以设置服务器监听的IP和端口号以及debug选项，debug为真时在服务报错的时候会向前端返回错误信息：

```python
if __name__ == '__main__':
	app.run(host='0.0.0.0', port=9555, debug=True) # host='ip_address', port=port
```

**请求响应函数设计：**

修饰器 @app.route('<url>') (app为之前实例化的服务器变量) 定义了该函数在服务器接收到 <url> 时被调用。

当浏览器向服务器监听的端口直接发送请求时（欢迎界面）：

```python
from flask import render_template

@app.route('/') # 接收到修饰器中的url时运行该函数
def mainPageRet():
	return render_template("mainPage.html") # 从模板资源中查找并返回文件
```

**接受POST/GET请求并从url中获取数据**：

```python
from flask import request

# 接收 url 为 '/sendMsg_post' 的请求，类型必须是POST

@app.route('/sendMsg_post', methods=['POST'])
def handle_post():
    
    # 从 url 中获取名称为 <var_name> 的值
    
    msg = request.args.get('<var_name>')
    return 'POST:' + msg

# 接收 url 为 '/sendMsg_set' 的请求，类型必须是GET

@app.route('/sendMsg_get', methods=['GET'])
def handle_get():
    msg = request.args.get('<var_name>')
    return 'POST:' + msg

#　接收 url 为 '/sendMsg_post_get' 的请求，类型为POST和GET
    
@app.route('/sendMsg_post_get', methods=['POST', 'GET'])
def handle_post_get():
    msg = request.args.get('<var_name>')
    return 'POST:' + msg
```

**接受POST请求并接收POST发送的数据**：

```python
from flask import request

@app.route('/postMsg', methods=['POST'])
def handleStream():
    
    # request.stream.read() 获得由浏览器（前端）发来的二进制流， decode() 将其转化为字符串
    
    stream = request.stream.read().decode()
    return stream
```

接受同一类型的url请求时... ...有时候url类型相似且要执行的程序也差不多，我们可以从url中将其最后一部分作为参数传到函数中：

```python
'''
	在这个例子中前端发送一系列形如 '/rel/file_1', '/rel/imgs' 的url，最后一部分可以作为变量传到函数中，它被视为字符串，可以进一步做一些事情
'''
@app.route('/rel/<file_name>')
def retFile(file_name):
    '''
    	do sth.
    '''
	return file_name
```

**页面跳转（页面重定向）**：

```python
from flask import redirect, url_for
'''
	在这个例子中，服务器收到 url 为 '/nextPage' 的请求后，执行重定向 url
'''
@app.route('/next')
def handle_next():
    return redirect(url_for('next_page')) # 重定向 url
'''
	以下这个函数响应重定向 url 
	注意！：这里函数名和监听的url应该一致（这个例子中都是 next_page ）
	ps:通过浏览器输入 '/next_page' 也可以访问这个网页，重定向主要处理通过脚本实现跳转的情况
'''
@app.route('/next_page')
def nextPage():
    return render_template('nextPath.html') # 返回 nextPath.html 网页
```

返回值，之前的例子中已经说明了需要返回网页时应该调用的函数，如果只需要返回流数据，直接返回即可。

**服务器向前端传值**：

通过发送网页到前端的时候，有时候在网页加载时需要一些数据，通过传回网页模板时将数据捎带。

```python
return render_template('<模板资源（网页）文件名称>', var_name=var)
# var 即值， 前端通过var_name获得
```

之后，前端通过下述方法可以直接获得服务器传值。

```html
<p> {{ var_name }} </p>
```

### 静态资源

静态资源是指在 ./static 文件夹下的资源，服务器会认为该文件夹下的资源是不会改动的（因此主要存放框架文件素材文件等）。如果有文件在设计时需要不断更改，如果把它们放在静态文件夹下将会导致它们的更改不会应用到服务器上进而出现一些问题，因此，**请将需要更改的文件保存在模板资源文件夹 (./templates) 中**。

