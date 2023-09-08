在Linux下编译：gcc <file_name>.c -o <output_name>

# 常见问题

在Linux环境下使用math.h库的时候需要在编译时添加参数 -lm

在Linux环境下使用pthread.h库（多线程）的时候需要在编译时添加参数 -lpthread

# H头文件定义

定义h头文件时需要增加参数 #pragma once 或者

```c++
#ifndef __HFILENAME_H__ 
// 在这里定义头文件主要内容
#endif
```

来防止重复定义

同样的，如果定义头文件的过程中需要引用其他头文件，为了防止重复定义需要使用如下方式引用：

```c++
#ifndef __STDLIB_H__
#include <stdlib.h>
#endif
```

**重要**：使用#ifndef时，后面的头文件名称一律大写，点用一个下划线替代，同时需要两个下划线将名称包含。

# 多线程

```c++
#include <pthread.h>
// 注意：定义多线程函数的时候返回值需要为void* 参数需要为void*
void* thread_func(void* args){
    printf("thread run\n");
}
int main(){
    pthread_t thread;
    
    // 绑定线程函数
    pthread_create(&thread, NULL, (void*)thread_func, "");
    // 开始线程（执行之前绑定的函数）
    pthread_detach(thread);
    // 等待执行
    sleep(10);
    // 结束线程
    pthread_cancel(thread);
    return 0;
}
```



# Socket

## UDP

**Windows**:

client

```c++
#include <WinSock2.h>
int main(){
    // init...
    WSADATA wsd;
    WSAStartup(MAKEWORD(1, 1), &wsd);
    
    SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    SOCKADDR_IN servAddr;
    
    // set ip:port
    servAddr.sin_family = AF_INET;
	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(8888);
    
    char* msg = "hello";
    int length = 6;
    int servAddr_length = sizeof(servAddr);
    
    // sending
    sendto(sockClient, msg, length, 0, (SOCKADDR*)& servAddr, servAddr_length);
    // recving
    recvfrom(sockClient, msg, length, 0, (SOCKADDR*)& servAddr, &servAddr_length);
    
    return 0;
}
```

server

```c++
#include <WinSock2.h>

int main(){
    // init...
    WSADATA wsd;

	SOCKET sockServ = socket(AF_INET, SOCK_DGRAM, 0);

	int sockAddrIn_length = sizeof(servAddr);

    // listen on localhost port is 8888
    SOCKADDR_IN servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(8888);
	// bind port
	bind(sockServ, (SOCKADDR*) &servAddr, sockAddrIn_length);
    
    char msg[1024];
    int length = 1024;
    
    // recving...
    SOCKADDR_IN clientAddr;
    recvfrom(sockServ, msg, length, 0, (SOCKADDR*)&clientAddr, &sockAddrIn_length);
    
    // sending...
    sendto(sockServ, msg, length, 0, (SOCKADDR*) &clientAddr, sockAddrIn_length);
    return 0;
}

```



# I/O

## 格式化字符串

```c
#include <stdio.h>
int main(){
    int int_src = 12;
	char aim[1024];
	sprintf(aim, "hello%d", int_src);
    return 0;
}
```



```c++
// 从键盘输入读取一行（不会因为空格而中断）
#include <iostream>
#include <string>
using namespace std;

string str;
getline(cin, str);
```

# 模板

```c++
// 在函数、类前声明 template<typename T>

template<typename  T>
void func(T a, T b){}
```

# C++ STL

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

## 堆

堆在c++ STL中属于算法，而非容器。

```c++
#include <algorithm>
#include <vector>

vector<int> big_heap = {5, 7, 6, 4, 8, 9, 3, 2};
vector<int> small_heap = {5, 7, 6, 4, 8, 9, 3, 2};

make_heap(big_heap.begin(), big_heap.end()); // 默认建立大顶堆
make_heap(big_heap.begin(), big_heap.end(), less<int>()); // 建立大顶堆
make_heap(small_heap.begin(), small_heap.end(), greater<int>()); // 建立小顶堆

// 增加元素
big_heap.push_back(10);
small_heap.push_back(10);
// 调整堆（前提条件需要vector增加新元素之前就是堆），注意最后的参数应与之前对堆的操作一致（大顶堆或小顶堆）
push_heap(big_heap.begin(), big_heap.end());
push_heap(big_heap.begin(), big_heap.end(), less<int>());
push_heap(small_heap.begin(), small_heap.end(), greater<int>());

// 删除元素
// 将堆顶元素放到vector最后（配置vector.pop_back()移除堆顶元素）（同样注意前后堆操作选择的仿函数一致，最后一个参数就是仿函数）
pop_heap(big_heap.begin(), big_heap.end());
pop_heap(big_heap.begin(), big_heap.end(), less<int>());
pop_heap(small_heap.begin(), small_heap.end(), greater<int>());

big_heap.pop_back(); // 真正移除元素
small_heap.pop_back(); // 之前的操作只是将堆顶元素（vector[0]）移到了最后
```

## Pair

```c++
#include <utility>
using namespace std;
// template<class T1, class T2> struct pair;

pair<int, double> p1;
pair<string, int> p2("hello", 6);

p1 = make_pair(62, 62.256); // 使用 make_pair 创建新对象

cout << p1.first << p1.second << endl; // 访问

// 使用 tie(v1, v2) 方法可以获得从函数返回的 pair 值
pair<string, int> func(){
    return make_pair("world", 7);
}
tie(my_string, number) = func();
cout << my_string << number << endl;
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
// find() 方法
map<string, int>::iterator it = mp.find("key"); // 返回目标的迭代器，如果没找到则返回 mp.end()


// 遍历map...
map<string, int>::iterator it; // 声明一个迭代器，注意类型应该与需要查找的map类型完全一样(双冒号"::"前的部分)
it = mp.begin();
while (it != mp.end()) {
    it->first; // 元素的键值（索引）
    it->second; // 键值（索引）指向的内容
    // 即：[first]:second
    
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
myIntStack.pop(); // 移除顶部元素

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

myQ.pop(); // 移除首元素

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

## Algorithm

```c++
#include <algorithm>

// 排序
vector<T> array;
sort(array.begin(), array.end()); // 自小到大排序
sort(array.begin(), array.end(), less<T>()); // 使用仿函数从小到大排序
sort(array.begin(), array.end(), greater<T>()); // 使用仿函数从大到小排序

// 也可以使用自定比较函数实现排序
bool cmp(T a, T b){
    return a > b; // 当满足条件 a > b 的时候出发sort排序的交换
}
sort(array.begin(), array.end(), cmp);

// stable_sort() 使用方法与 sort() 相同, 是基于归并排序实现的稳定算法
```

# 运算符重载

运算符重载的过程中应该注意的一点是返回值一般应该返回引用类型

```c++
// 以下代码截取自./MyHFile/pstString.h
Str& operator+=(const Str &src) {
		char* old = this->vals;
		this->vals = (char*)malloc(this->_length + src._length + 1);
		memcpy(this->vals, old, this->_length);
		free(old);
		memcpy(this->vals + this->_length, src.vals, src._length + 1);
		this->_length += src._length;
		return *this;
	}
```

