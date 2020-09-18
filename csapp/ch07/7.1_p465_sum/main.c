//
// Created by Edward on 2020/7/8.
//

int sum(int *a, int n);
int array[2] = {1, 2};

int main(){
	int val = sum(array, 2);
	return val;
}

// gcc-8 -Og -o prog main.c sum.c
// ./prog

// Mac 无法直接引用 cc1：-bash: cc1: command not found
// 改为 /usr/local/Cellar/gcc/8.3.0/libexec/gcc/x86_64-apple-darwin17.7.0/8.3.0/cc1

// cpp-8 main.c main.i
// cc1 main.i -Og -o main.s
// l

// cpp-8 sum.c sum.i
// cc1 sum.i -Og -o sum.s
// as -o sum.o sum.s

// ld -o prog1 main.o sum.o
// -lSystem -macosx_version_min 10.13 (Mac中需要加上这两个参数)


