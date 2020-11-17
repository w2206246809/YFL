# 常见问题

网页中中文字符乱码时，在HTML文件中的<head>标签中添加：

```html
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
```

# HTML/HTML5

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

# 网页设计中的JavaScript

## 页面跳转

页面跳转，跳转页面但是不打开新窗口。

```javascript
window.location.href = '<url>'
```

## HTML调用Js中的函数

在Jscript文件中将需要被调用的函数定义为变量：

```javascript
var aim_func = function(){ console.log('调用成功') };
```

在HTML中调用js中的函数变量：

```html
<script src='./aim_script.js'>
	aim_func();
</script>
```

```javascript
location.reload(); // 重新加载页面
```

# CSS

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

## 背景(Background)

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



# Ajax

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

# jQuery

> 参考文献：[菜鸟教程](https://www.runoob.com/jquery/jquery-tutorial.html)

## 基础

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

**调用jQuery中的函数**

```js
$(function(){
    window.jQueryFunction = function(xx){ // jQuery内部声明
        // 程序代码
    }
});

jQueryFunction(xx); // 调用jQuery内部函数
```



## 元素选择

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

## 添加/删除元素

删除元素：

remove() : 删除被选元素。

添加元素：

append('txt') : 在被选元素的结尾插入内容；

prepend('txt') : 在被选元素的开头插入内容；

after('txt') : 在被选元素之后插入内容；

before('txt') : 在被选元素之前插入内容。

## jQuery遍历

### 祖先遍历

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

### 后代遍历

**children()**: 返回所有直接子元素。

**find()**

返回所有后代元素，只到最内层：

```javascript
$('div').find('span'); // 返回所有后代中的<span>
$('div').find('*'); // 返回所有后代
```

### 同胞（同级）遍历

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

### 过滤遍历

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



## jQuery中的Ajax

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

# Bootstrap

## 基础

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

## 网格系统

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

## 组件

### 滚动条

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

// 设置滚动条至最底部
var aimDiv = document.getElementById("msgScroller");
aimDiv.scrollTop = aimDiv.scrollHeight;
```

# D3.js

> [来源](https://d3js.org/)	[中文教程](https://github.com/d3/d3/wiki/API--%E4%B8%AD%E6%96%87%E6%89%8B%E5%86%8C)

`一个用于实现数据可视化的JavaScript函数库`

## get start

```html
<script src="d3.min.js"></script>
```

# jTopo

> [来源](http://www.jtopo.com/)

`一个用于绘制网络拓扑图的JavaScript函数库`

