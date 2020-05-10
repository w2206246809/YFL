# 开始

## bazel启动本地ONOS服务

1、cd onos `ONOS所在的项目目录`

2、启动ONOS服务器：

bazel run onos-local -- clean debug

3、打开ONOS终端：

tools/test/bin/onos localhost

ONOS-GUI: tools/test/bin/onos-gui localhost

## 控制器命令

**（在ONOS终端）**

- 查看所有控制器应用：

apps -a -s

- 启动控制器应用：

app activate org.onosproject.fwd (也可以省略部分名称：app activate fwd)

- 关闭控制器应用：

app deactivate fwd

- 查看链接控制器的设备

devices | devices -s

- 删除设备（当拓扑中与控制器相连的设备被移除的时候，控制器不会删除该设备而是标记该设备为不可用）

通过 devices -s 查询目标设备的 id，然后 device-remove <id> 删除该设备

- 查看流表信息

flows

# 添加自定义控制器应用

1）在onos项目中apps文件夹下仿照已有项目结构创建新的应用，注意更改BUILD文件中的应用名称和包应用名称与apps直属的文件夹名称统一。

2）编译：在onos文件夹下：bazel build //apps/<controllerApp_name>/...:all

`注意：在onos/tools/build/bazel/osgi_java_library.bzl文件中修改方法osgi_jar_with_tests中的参数suppress_checkstyle = True跳过checkstyle`

3）通过指令 find -name "*<controllerApp_name>-oar.oar" 找到编译好的控制器文件所在地（一般以./.cache...开头），在该目录下执行 onos-app localhost install onos-apps-<controllerApp_name>-oar.oar 加载控制器应用（确保onos服务在运行）。

4）完成！