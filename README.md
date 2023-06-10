# myCompiler
这是浙江大学2023春夏学期编译原理课程大作业，一个编译器。    

我们的环境是Ubuntu22.04    

首先在电脑设置中打开wsl的开关（可以百度到）然后直接从Microsoft store中下载Ubuntu
打开Ubuntu的终端，进行环境配置。
输入命令：
sudo apt-get update && sudo apt-get upgrade && sudo apt-get install flex bison
安装flex和bison
sudo apt-get install llvm-14
安装LLVM
sudo apt install gcc g++ gdb clang
sudo apt install zlib1g-dev
安装c语言编译环境
然后下载压缩包，解压后进入工程根目录
当前目录下有
src
test
include
build
cmakelist.txt
readme.md
请删除整个build文件夹
rm -rf build
然后创建新的build文件夹，并进入build
mkdir build
cd build
执行cmake命令和make命令
cmake ..
make
举例，你要测试hello.c,需要先把hello.c放进build文件夹中（这一步可以在Ubuntu中使用cp命令完成，
也可以直接鼠标操作）这一步完成之后你可以在build文件夹中找到名为compiler的文件
然后在build文件夹中继续输入命令
./compiler hello.c
这一步完成之后compiler⽣成output.o⽂件
之后使用g++进行编译
g++ output.o -no-pie -o program
也可以使用clang（需要先安装clang）
clang-14 output.o -no-pie -o program
./program
以上步骤完成之后就可以看见运行的结果：打印出hello world
如果想看到html格式的可视化AST，请将build目录下的visual.json文件中的所有内容复制，然后
粘贴到book.html(在src文件夹中)的第51行中，用以替代第51行 var root = 之后直到第一个分号（；）
之前的内容
（即：
 ；   
    //获取节点数组和连线数组
		var nodes = tree.nodes(root)//获取所有节点信息
 之前）
替换效果如下：
![image](https://github.com/Skylar20011211/myCompiler/assets/132972130/a0f42452-86a2-4cd4-8843-f41f0e58a71a)
其中画出的部分就是需要替代的内容，如果想了解详细内容，请百度搜索json文件格式和html相关知识。
保存之后，再用浏览器打开book.html文件（也就是在文件资源管理器中双击该文件，会默认用浏览器打开），
此时即可看到测试文件的可视化AST。
