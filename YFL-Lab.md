# YFL-Lab

> by 王一凡 powered by Typora

## 说明

**YFL-Lab**旨在记录所有可能用到的**较为通用**的知识。基础功能与快捷键的使用见 **段落（P）、格式（O）、视图（V）**等标签。

# 网络

默认网关：香港-114.114.114.114	谷歌-8.8.8.8

**'/'** 指从根目录开始导航 **'./'** 指从当前目录开始导航

## 查看占用端口进程号(Linux)

```shell
netstat -ntlp|grep 9555
注：9555为端口号
```

基于进程号关闭进程

```shell
kill -9 361000
注：361000为进程号
```



# Linux

## 常见问题

去除文本中的 ‘\r’ ：

```shell
vi doc_file
:set fileformat=unix
:w
```

# Visual Studio

排版选中的代码：ctrl + k, ctrl + f ( 排版所有代码：ctrl + a, ctrl + k, ctrl + f )

注释选中的代码：ctrl + k, ctrl + c 

取消注释选中的代码：ctrl + k, ctrl + u

# C/C++

## Vector

定义：vector< 变量类型 > list;

```c++
#include <vector>
using namespace std;

vector<int> list;
vector<vector<int> > list;

// 初始化
vector<int> list(8); // 初始化数组大小为8
list.resize(10);

// 初始化 2.0
vector<vector<int> > numbers(3, vector<int>(8)); // 创建了3行，每行8个int的二维数组

// 赋值
list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
numbers = {
    {1, 2, 3, 4, 5, 6, 7, 8},
    {11, 12, 13, 14, 15, 16, 17, 18},
    {21, 22, 23, 24, 25, 26, 27, 28}
};

// 增加元素
int element = 7;
list.push_back(element);

// 删除元素 注：i为元素下标
int i = 0;
list.erase(i);

// 获取vector大小
int size = list.size();
```

## Map

```c++
#include <string>
#include <map>
using namespace std;

map<string, int> mp; // 以string类型为索引，指向int类型

mp.size(); // 返回元素个数

mp["hello"] = 1; // 访问操作，该操作会在没有"hello"键值的情况下创造一个键值为"hello"的元素

// 如果我们需要判断一个键值是否存在于map...    count()方法
mp.count("key"); // 函数会返回键值为"key"的元素在mp中的数量，如果为0代表不存在

// 遍历map...
map<string, int>::iterator it; // 声明一个迭代器，注意类型应该与需要查找的map类型完全一样(双冒号"::"前的部分)
while (it != mp.end()) {
    it->first; // 元素的键值（索引）
    it->second; // 键值（索引）指向的内容
    // 即：first->second
    
    it++;
}

// map元素删除
it = mp.begin();
mp.erase(it); // 通过迭代器删除元素
string key = "hello";
mp.erase(key); // 通过键值(key)删除元素
```

## Stack

```c++
#include <stack>
using namespace std;

// 声明用法：stack<type> var_name;
stack<int> myIntStack;
myIntStack.size(); // 获得栈的大小

myIntStack.push(7); // 入栈

int getTop = myIntStack.top(); // 获得顶部元素，不会弹出顶部元素
int getInt = myIntStack.pop(); // 出栈（弹出顶部元素）

if (myIntStack.empty()){ // bool量：栈是否为空
    return 0;
}
else return -1;
```

## Queue

```c++
#include <queue>
using namespace std;

// 声明：queue<type> var_name;
queue<int> myQ;
myQ.size(); // 获得队列大小

myQ.push(7);
myQ.push(9);
myQ.push(8); // 在末尾加入元素

int getInt = myQ.pop(); // 弹出第一个元素

int visitInt = myQ.back(); // 返回末尾元素

visitInt = myQ.front(); // 返回首元素

if(myQ.empty()); // bool量，是否为空
```



## String

定义：string str;

```c++
#include <string>
using namespace std;

string str;
// 获取string的长度
int length = str.length();

// 初始化
string str0(5, '.'); // 初始化字符串为五个点 "....."

string str1;
str1 = "first string";

char c_str[] = "sec.";

string str2(str1);
string str3(c_str);
string str4(str1, 3); // 将str1开始于3的字符串赋值到新的字符串
string str5(str1, 3, 6); // 将str1开始于3且长度至多为6的字符串赋值到新的字符串

// string常用方法
string test_str;
test_str = "hello world";
test_str += "ni hao";

// substr()方法
std::string str="We think in generalities, but we live in details.";

// "think" 从第3（0为第一个）字符开始，取长度为5的字符串
std::string str2 = str.substr (3,5);

// 返回字符串“live”所在的位置
std::size_t pos = str.find("live");      // position of "live" in str

// 获得从“live”开始，直到末尾的子字符串
std::string str3 = str.substr (pos);     // get from "live" to the end

std::cout << str2 << ' ' << str3 << '\n';
// Output: think live in details.
```



# Python

## 通用

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



## 常见问题

**OSError: [Errno 8] Exec format error**：

在python文件头部添加 #! /usr/bin/env <python> `（注：<python>应填写需要使用的python版本）`

## pip

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

### pip依赖问题

如果通过pip安装任何包的时候出现了依赖问题，使用aptitude安装可以解决。(可能需要先安装aptitude)

```shell
aptitude install <packet_name>

```



## 字符串（Python）

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

## 数组（python）

获取数组长度：len(list)

**删除操作**

```python
li = ['1', '3', '5', '7']
li.remove('3') # 通过list对象的remove( val )方法，直接删除列表中的某个元素

del li[1] # 利用del， 直接通过数组下标（索引）删除

```



## 字典（python）

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

## 队列

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



## JSON相关操作（python）

```python
import json

# 将json字符串转换为字典（python中的字典和json的形式相同）

jsonStr = '{ "name" : "yfl_lab", "type" : 26 }' // 使用单引号引双引号

dict = json.loads( jsonStr )

# 将字典转换为json字符串

jsonStr = json.dumps( dict )

```

## 文件操作(python)

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

## 多线程

## 服务器设计

### Flask服务器框架

#### 常见问题

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

即可。这是因为该函数需要两个参数而原函数之提供了一个。

#### Get Start

**安装**

`pip install flask`

**Flask框架文件结构**

**服务器代码根目录**：<flask_web_server>/server.py `// 文件名称可自定`

**存放静态资源**：<flask_web_server>/static

静态资源文件夹用于存放 .css .js 等框架文件，在前端页面设计的时候需要在 src 的 url 前**注明 '/static/'**， 服务器即可自动响应并向其发送所请求的静态资源，而不用针对每个静态资源设置不同的请求响应处理函数。

**存放模板资源**：<flask_web_server>/templates

模板资源文件夹用于存放设计的网页等非框架文件，在调用服务器框架API返回页面等文件的时候是以该目录为根目录寻找文件并返回的。

#### 服务器程序设计

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



#### 静态资源

静态资源是指在 ./static 文件夹下的资源，服务器会认为该文件夹下的资源是不会改动的（因此主要存放框架文件素材文件等）。如果有文件在设计时需要不断更改，如果把它们放在静态文件夹下将会导致它们的更改不会应用到服务器上进而出现一些问题，因此，**请将需要更改的文件保存在模板资源文件夹 (./templates) 中**。

# JavaScript

JavaScript**全局变量**的使用：

```javascript
var value;
function useGlobal() {
    window.value; // 通过 window.<var_name> 获取全局变量
}

```

`所有的元素都从属于 window 对象。`

JavaScript中的**空变量**：

```javascript
var value = null; // 空值
var type = undefined; // 变量未定义

```

JavaScript中的变量相等：

```javascript
var a, b;
a == b; // 比较变量 a b 的值是否相同（a b 的值在它们类型不同的情况下依旧可能相同）
a === b; // 比较变量 a b 的值以及类型是否都相同

```

## 字符串 (JavaScript)

字符串转数字：

```javascript
var string = '123';
var num = parseInt(string) // 字符串转整型数
var floatNum = parseFloat(string) // 字符串转浮点数

```

数字转字符串：

```javascript
var string = num.toString(); // 数字变量中有 toString() 成员

```

删除字符串的最后一个字符：

```javascript
string = string.substring(0, string.length - 1);

```

## 数组 (JavaScript)

```javascript
var list = new Array()

length = list.length

```

`注：数组的操作与字典类似，默认情况下可以把数组理解为键值为0、1、2...等自然数的字典，但注意，数组与字典的区别在于字典可以正确转换成JSON字符串，而数组不行。`

## 字典（JavaScript）

```javascript
var dict = new Object();
dict[key] = value;

// 一般形式

var dict = { 'key' : 'value', ... }

```

**字典的遍历**

```javascript
for (var key in dict) {
    dict[ key ];
}

```

判断字典中是否存在某键值 ( key )：

```javascript
if ( '<key>' in dict ) {
    // 如果字典 dict 中存在键值 <key> ，如果是返回 True 否则返回 False 
}

```



## JSON相关操作（JavaScript）

Javascript中，本质与Python相同，都是将字典与JSON字符串互相转换的过程。

```javascript
// 将json字符串转换为js中的字典（与python中的字典类似）

var jsonStr = '{ "name" : "yfl_lab", "type" : 26 }' // 使用单引号引双引号

var obj = JSON.parse( jsonStr )

// 将js字典转换成json字符串
 
var jsonStr = JSON.stringify( obj )

```

## 计时事件（定期执行函数/等待后执行函数/‘多线程’）

- setInterval() - 间隔一定时间循环执行函数
- setTimeout() - 在指定时间之后运行函数

```javascript
var time = 1000; // 时间设定，单位：毫秒
// start
var tmpVar = setInterval(function(){ /* do sth. */ }, time); // 设置间隔为time循环执行函数
var tmpTimeout = setTimeout(function(){ /* do sth. */ }, time); // 设置在时间time之后执行函数
// end
clearInterval(tmpVar); // 结束循环执行函数
clearTimeout(tmpTimeout); // 结束等待执行函数

```



# JSON

JSON是一种数据结构描述格式，格式如下：

​	**json_obj = { "name" : < "var" | json_obj> (, <json_obj> ) }** `// 使用逗号来包含多个json_obj`

例如：

```json
{ "name" : "yfl_lab", "type" : 26, "sub_obj" : { "type" : 6, "var" : "yfl_lab" } }

```

# 网页设计

## 常见问题

网页中中文字符乱码时，在HTML文件中的<head>标签中添加：

```html
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

```

``

## HTML/HTML5

HTML页面跳转：

```html
<button onclick="location.href = '/url'"></button>

<a href="/url"></a> <!-- 超链接 -->

```

将子元素相对于父元素**居中**：

```html
<div class="father" style="text-align:center">
	<div class="kid" style="display:inline">
        <!-- 同时对子元素和父元素的 style(css) 中设置上述属性实现子元素相对于子元素的相对布局 -->
    </div>
</div>

```



## 网页设计中的JavaScript

### 页面跳转

页面跳转，跳转页面但是不打开新窗口。

```javascript
window.location.href = '<url>'

```

### HTML调用Js中的函数

在Jscript文件中将需要被调用的函数定义为变量：

```javascript
var aim_func = function(){ console.log('调用成功') };

```

在HTML中调用Js中的函数变量：

```html
<script src='./aim_script.js'>
	aim_func();
</script>

```

```javascript
location.reload(); // 重新加载页面

```



## CSS

**基础语法：**`[选择器] { [属性名称1]:[值]; [属性名称2]:[值]; }`

示例：

```css
sel_tag
{
    colo:blue;
}

#sel_id
{
    text-align:center;
    color:red;
}

.sel_class
{
    text-align:center;
}

tag.className
{
    text-align:center;
}

```



插入样式表：

- 外部样式

  `适用于多个文档统一格式`

  引入外部样式：

  ```html
  <head>
  <link rel="stylesheet" type="text/css" href="mystyle.css">
  </head>
  
  ```

  

- 内部样式

  `适用于单个文档需要特定样式`

  ```html
  <head>
      <style>
          h{ color:red; }
          body{ background-image:url("img/img_url.png"); }
      </style>
  </head>
  
  ```

  

- 内联样式

  `直接嵌入在特定标签的style属性中`

  ```html
  <p style="color:blue;margin-left:20px">test tag p</p>
  
  ```

当一个标签有多重样式时的优先级：**内联样式>内部样式>外部样式>浏览器默认样式**

### 背景(Background)

```css
p
{
    background-color:blue;
    background-image:url('img\imgUrl');
    background-repeat:repeat-x;
    /*
    	repeat-x : 仅在水平方向平铺
    	no-repeat : 不平铺
    */
    background-position:right top; /* 不平铺的情况下设置位置 */
    background-attachment:fixed; /* 使背景图像不随屏幕滚动 */
}

```



## Ajax

Ajax可以在不改变网页整体（或跳转页面）的情况下，与后台（服务器）通信，实现局部刷新页面。

以下这个函数定义了Ajax向服务器发送请求并接收返回值而不需要刷新整个页面的基础接口函数：

```javascript
var xmlhttp;
function loadXMLDoc(url, cfunc, msg) {
    if (window.XMLHttpRequest) { // 有些旧版本的浏览器不支持 XMLHttpRequest()
        xmlhttp = new XMLHttpRequest();
    }
    else{
        xmlhttp = new ActiveXObject("MicrosoftXMLHTTP");
    }
    // 当HttpRequest状态变化时，调用 cfunc 函数，执行一些自定义过程（接收数据）
    xmlhttp.onreadystatechange = cfunc;
    
    // 参数1：[POST或GET方法] 参数2：[向服务器发送请求时的url] 参数3：[是否异步?true/false]
    xmlhttp.open("POST", url, true);
    
    // 发送请求时要附加的信息 (msg:流信息)
    xmlhttp.send(msg);
}

```

一般情况下建议将需要发送的消息以表单提交的形式追加在 url 之后，以 xmlhttp.send(msg) 函数发送的数据流在服务器端需要用不同于接收前端传值的方法，这里以Python下Flask框架服务器为例：

```python
from flask import Flask, request

app = Flask(__name__)

@app.route('/recvStreamMsg', methods=['POST'])
def handle_recvStreamMsg():
    # 获取数据流（二进制）
    stream_msg = request.stream.read()
    # 解码二进制流为String
    string_msg = stream.decode()
    return 'recv'

```



当需要通过Ajax通信的时候，调用上述接口：

```javascript
function doSomething(){
    // 比如获取网页中一个 id 为 "element_id" 的元素中的值
    var msg = document.getElementById("element_id").value;
    
    // 参数1：[要请求的url] 参数2：[回调函数] 参数3：[要发送的流信息]
    loadXMLDoc("/doSth", function() {
        
        // 回调函数用于处理接收来自服务器的数据
        
        // readyState 即 HttpRequest状态：
        // 0:请求未初始化 1:服务器连接已建立 2:请求已接收 3:请求处理中 4:请求处理完成且响应就绪
        // status ：200->"OK"; 404->未找到页面
        if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
            // xmlhttp.responseText 可以获取服务器返回的信息
            var retMsg = xmlhttp.responseText;
        }
    }, msg);
}

```

传输表单数据：在调用 loadXMLDoc( url, cfunc, msg ) 时，在 url 后追加:

`?<data_name>=<var>&<data_name>=<var>& ...(example: ?name=yfl&type=lab)`

## jQuery

> 参考文献：[菜鸟教程](https://www.runoob.com/jquery/jquery-tutorial.html)

### 基础

在[jQuery](https://jquery.com/download/)下载源码：

​	**production**版用于实际网站，代码被精简和压缩；

​	**development版**用于测试与开发，代码未被压缩，具有可读性。

在网页的 <script> 标签中添加 jQuery：

```html
<head>
    <script src="jquery-1.10.2.min.js"></script>
</head>

```

**注意：** <script> 标签中 src 属性后的 url 中的 jQuery 版本、地址和实际情况一致。

**入口函数**：在页面完全加载后执行该函数，将诸如**事件监听**的函数定义在这里可以防止页面在完全加载之前就执行jQuery。

**所有的jQuery函数都应该定义于此，否则无法生效**

```javascript
$(function() {
    // do sth.
})；

```

**此外jQuery找不到动态生成的元素，可以通过为动态元素建立监听实现**

```javascript
div += '<li id='动态元素' onclick='li-click(this)'></li>';

function li-click(obj){
    $(obj).attr('id');
}

```

### 元素选择

jQuery的主要功能：HTML元素选取、元素操作、CSS操作、事件、特效、DOM遍历、AJAX以及更多框架。

基础语法：$(selector).action() `通过$定义jQuery；selector选择HTML元素；action执行操作`

[**元素选择器**](https://www.runoob.com/jquery/jquery-selectors.html) **（$）：**

- $("*") ：选择所有元素；
- $(this) ：选择当前元素；
- $("p") ：选择所有 <p> 标签；
- $(".lab") ：选择所有 class 为 lab 的元素；
- $("p.lab") ：选择所有 class 为 "lab" 的 <p> 标签；
- $("#yfl") ：选择 id 为 "yfl" 的元素。

**元素属性选择：**

- css() 方法：该方法可以选择或设置元素中style属性（即css样式），获得或者改变它们的值。

```javascript
$('div').css('background-color', 'blue');
$('div').css('background-color');

```

- attr() 方法：该方法可以获得或改变元素中的属性值。

```javascript
$('div').attr('id', 'yfl-lab');
$('div').attr('id');

```

**值的获取：**

```javascript
$('div').value();
$('div').html();
$('div').text();

```



[**事件**](https://www.runoob.com/jquery/jquery-events.html)**：**

```javascript
$( <element> ).event( function() ) // 当选择的元素对应的action事件发生时执行function()函数

```

- click( ) : 鼠标**点击元素**时触发；
- dblclick( ) : 鼠标**双击元素**时触发；
- mouseenter( ) : 鼠标**穿过（移入/进入）元素**时触发；
- mouseleave() : 鼠标**离开元素**时触发；
- mousedown( ) : 鼠标**移到元素上方并按下按键**时触发；
- mouseup( ) : 鼠标**在元素上松开按键**时触发；
- hover( function1(), function2() ) : 鼠标**移动到元素**时触发第一个函数，**离开元素**时触发第二个函数；

**[动作](https://www.runoob.com/jquery/jquery-hide-show.html)（效果）：**

与事件类似，但区别在于当执行到当前代码时，相应的元素会执行相应动作。

### 添加/删除元素

删除元素：

remove() : 删除被选元素。

添加元素：

append('txt') : 在被选元素的结尾插入内容；

prepend('txt') : 在被选元素的开头插入内容；

after('txt') : 在被选元素之后插入内容；

before('txt') : 在被选元素之前插入内容。

### jQuery遍历

#### 祖先遍历

**parent()**

获得元素的父元素：

```javascript
$('span').parent().attr('id', 'parent');

```

**parents()**

获得元素的所有祖先元素（即包含该元素的所有元素，层层向上，直到文档根元素<html>:

```javascript
$('span').parents().css('background-color', 'red');

```

**parentsUntil()**

```javascript
$('span').parentsUntil('div'); // 返回<span>到<div>之间的所有元素（不包括<span>和<div>）

```

#### 后代遍历

**children()**: 返回所有直接子元素。

**find()**

返回所有后代元素，只到最内层：

```javascript
$('div').find('span'); // 返回所有后代中的<span>
$('div').find('*'); // 返回所有后代

```

#### 同胞（同级）遍历

**siblings()**

返回所有同级元素：

```
$('div').siblings(); // 返回所有同级元素
$('div').siblings('div'); // 返回所有标签为<div>的同级元素

```

**next()**: 返回下一个同级元素。

**nextAll()**: 返回所有跟随的同级元素。

**nextUntil( 'div' )**: 返回该元素之后，直到标签div之前的所有同级元素。

**prev(), prevAll(), prevUntil()** : 返回之前的所有同级元素。

#### 过滤遍历

**first()**: 返回被选元素的首个元素。`$('div p').first() // 返回首个div内部的p元素`

**last()**: 与之前类似，返回被选元素的最后一个元素。

**filter()**: 

```javascript
// 返回所有类名为url的p元素
$('p').filter('.url');

```

**not()**:

```javascript
// 返回所有类名不是url的p元素
$('p').not('.url');

```



### jQuery中的Ajax

**load()**

该方法主要用于向服务器请求加载文件，并自动地将服务器返回的值送到jQuery选择器选择的元素中。

```javascript
$(selector).load(URL,data,callback);

```

- URL :请求 url
- data :要发送的**表单数据**
- callback :**回调函数**

**get()**

该方法用于向服务器以 GET 的形式通信。

```js
$.get(URL,callback);

```

- URL :请求 url
- callback :**回调函数**

**post()**

该方法用于向服务器以 POST 的形式通信。

```javascript
$.post(URL,data,callback);

```

- URL :请求 url
- data :要发送的**流数据**
- callback :**回调函数**

`注1：jQuery中回调函数被定义为 function(data, status) data为从服务器返回的数据; status为当前状态。`

`注2：data中的数据为流数据，表单数据通过在url后加'?id=1'的方式提交。`

**示例程序：**

客户端代码：

```javascript
$(function () {
	$("#retMsg").load("/test?send=ok", "streamMsg", function (data, status) {
		console.log('data:', data, '\nstatus:', status);
	});
});

```

这些附带数据均以表单提交形式附加，在服务器端用接收表单的方法接收数据即可，服务器端代码（以Python Flask框架为例）：

```python
@app.route('/test', methods=['POST', 'GET'])
def handle_send():
	print(request.args.get('send'), request.stream.read().decode())
	return 'return ok'

```

## Bootstrap

### 基础

添加Boostrap：

```html
<html>
<head>
    <link href="css/bootstrap.min.css" rel="stylesheet" />
    <!-- bootstrap.min.js文件依赖jQuery，如果在引用bootstrap.min.js之前未引用jQuery则会报错 -->
    <script src="js/jquery-3.4.1.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
</head>
<body>
    <h1>hello world</h1>
</body>
</html>

```



### 网格系统

> [参考文献](https://www.runoob.com/bootstrap/bootstrap-grid-system.html)

在Bootstrap中，元素的定位主要依赖于网格系统，网格系统需要定义在容器中：

```html
<div class="container">
	<!-- 这里是一个网格系统 -->
</div>

```

网格系统以行为基本单位：

```html
<div class="row">
    <!-- 这是一行 -->
</div>

```



每个行中有12列（12为最大值，设置多个列宽的时候应合理安排列宽使得每行总是为12列）：

```html
<div class="row">
    <!-- 这是一行 -->
    <div class="col-md-4">这是一个占宽为4的列</div>
    <div class="col-md-8">这是一个占宽为8的列</div>
</div>

```

### 组件

#### 滚动条

**定义：**

```html
<div class='pre-scrollable'>
    <div class='elements'>
        <!-- do sth. -->
    </div>
</div>

```

**操作：**

- 设置滚动条位置：

```javascript
$('选中目标滚动条元素').scrollTop( value ); // value为数字，取值范围大于等于0

```



## D3.js

> [来源](https://d3js.org/)	[中文教程](https://github.com/d3/d3/wiki/API--%E4%B8%AD%E6%96%87%E6%89%8B%E5%86%8C)

`一个用于实现数据可视化的JavaScript函数库`

### get start

```html
<script src="d3.min.js"></script>

```

## jTopo

> [来源](http://www.jtopo.com/)

`一个用于绘制网络拓扑图的JavaScript函数库`

