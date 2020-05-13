# Batfish源码安装

[相关链接](https://github.com/batfish/batfish/wiki/Building-and-running-Batfish-service)

- Git batfish

```shell
git clone https://github.com/batfish/batfish.git
cd batfish
```

- 安装z3

```shell
sudo tools/install_z3.sh
```

- 添加batfish命令

```shell
source tools/batfish_functions.sh
```

- 编译

```shell
batfish_build_all
```

- 运行batfish服务

```shell
allinone -runclient false
```

`通过pyBatfish访问batfish服务`

