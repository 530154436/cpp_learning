
# 编译 => 可重定位目标文件
gcc -c addvec.c multvec.c main2.c math.c

# 归档打包(ar)：ar libxxx.a xxx1.o xxx2.o
# 参数r：在库中插入模块(替换)。
# 参数c：创建一个库。不管库是否存在，都将创建。
# 参数s：创建目标文件索引，这在创建较大的库时能加快时间。
ar rcs libvector.a addvec.o multvec.o
ar rcs libmath.a math.o

# 静态链接 (-static Macosx报错ld: library not found for -llibvector.a)
# gcc -static -o prog2c main2.o ./libvector.a ./libmath.a
# gcc -static -o prog2c main2.o -L . -lvector -lmath
gcc -o prog2c main2.o libvector.a libmath.a

# 执行
./prog2c
