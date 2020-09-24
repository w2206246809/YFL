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

