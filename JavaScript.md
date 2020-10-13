# 通用

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

# 字符串

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

# 数组 

```javascript
var list = new Array()

length = list.length
```

`注：数组的操作与字典类似，默认情况下可以把数组理解为键值为0、1、2...等自然数的字典，但注意，数组与字典的区别在于字典可以正确转换成JSON字符串，而数组不行。`

# 字典

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

# JSON相关操作

Javascript中，本质与Python相同，都是将字典与JSON字符串互相转换的过程。

```javascript
// 将json字符串转换为js中的字典（与python中的字典类似）

var jsonStr = '{ "name" : "yfl_lab", "type" : 26 }' // 使用单引号引双引号

var obj = JSON.parse( jsonStr )

// 将js字典转换成json字符串
 
var jsonStr = JSON.stringify( obj )
```

# 计时事件（定期执行函数/等待后执行函数/‘多线程’）

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

