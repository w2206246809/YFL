给mininet制定控制器：sudo mn --controller=remote --ip=[controller IP] --port=[controller listening port]

# 自定义拓扑

## 自定义拓扑脚本

```python
from mininet.topo import Topo

class MyTopo(Topo):
    ''' example topo '''
    
    def __init__(self):
        Topo.__init__(self)
        
        left_host = self.addHost('h1')
        right_host = self.addHost('h2')
        left_switch = self.addSwitch('s3')
        right_switch = self.addSwitch('s4')
        
        self.addLink(left_host, left_switch)
        self.addLink(right_host, roght_switch)
        self.addLink(right_switch, left_switch)
        
topos = { 'mytopo': ( lambda: MyTopo() ) }
```

通过sudo mn --custom <topo_name>.py --topo mytopo  --controller=remote,ip=127.0.0.1,port=6633

## 自定义拓扑程序

```python
from mininet.net import Mininet
from mininet.node import Controller, RemoteController
from mininet.cli import CLI
from mininet.log import setLogLevel, info
from mininet.link import Link, Intf, TCLink
from mininet.topo import Topo
from mininet.util import dumpNodeConnections

class myTopo(Topo):
    def __init__(self):
        Topo.__init__(self)
        
    def createTopo(self):
        h1 = self.addHost('h1')
        h2 = self.addHost('h2')
        s1 = self.addSwitch('s1')
        s2 = self.addSwitch('s2')
        
        self.addLink(h1, s1)
        self.addLink(h2, s2)
        self.addLink(s1, s2)
        
def main_run():
    test_topo = myTopo()
    test_topo.createTopo();
    
    CONTROLLER_IP = 127.0.0.1
    CONTROLLER_PORT = 6633
    net = Mininet(topo=test_topo, link=TCLink, controller=RemoteController)
    net.addController('controller',
                      ip=CONTROLLER_IP,
                     port=CONTROLLER_PORT)
    net.start()
    CLI(net)
    net.stop()
if __name__ == '__main__':
    main_run()
```

# Mininet命令

link s1 s2 down : 断开s1到s2之间的链路

link s1 s2 up : 恢复s1到s2之间的链路