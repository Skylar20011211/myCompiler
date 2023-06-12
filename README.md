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

然后创建新的build文件夹，请将src目录下的books.html文件复制到build目录下（为了之后的可视化），并进入build  

    mkdir build  

    cd build  

执行cmake命令和make命令  

    cmake ..  

    make  

举例，你要测试hello.c,需要先把hello.c放进build文件夹中（这一步可以在Ubuntu中使用cp命令完成，也可以直接鼠标操作）这一步完成之后你可以在build文件夹中找到名为compiler的文件   

然后在build文件夹中继续输入命令  

    ./compiler hello.c  

这一步完成之后compiler⽣成output.o⽂件  

之后使用g++进行编译  

    g++ output.o -no-pie -o program    
    
    ./program   

也可以使用clang（需要先安装clang）  

    clang-14 output.o -no-pie -o program  

    ./program  

以上步骤完成之后就可以看见运行的结果：打印出hello world  

如果想看到html格式的可视化AST，请打开build目录下生成的ASTVisual.html并保证网络连接正常。
