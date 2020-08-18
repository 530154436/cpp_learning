+ 产生共享库
gcc -shared -fpic -o libvector.so addvec.c multvec.c

-shared指示链接器创建一个共享的目标文件，
-fpic指示编译器生成与位置无关的代码

+ 加载时动态链接
gcc -o prog2l main2.c ./libvector.so