# TeduQt
达内教育Qt代码
更新时间：2024-12-29
Qt版本：`6.8.1`
# 添加环境变量
在 `~/.bashrc` 下面添加下面两行
```sh
export PATH=$PATH:/home/dongchao980612/Qt/6.8.1/gcc_64/bin
export PATH=$PATH:/home/dongchao980612/Qt/Tools/QtCreator/bin

```

# 第一个Qt程序


- 生成工程文件
```bash
qmake -project
```
- 工程文件中添加
```bash
QT+=widgets gui
```
- 生成Makefile 
```bash
qmake
# sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev

make  # mingw32-make for windows

```

