CSAPP 的读书笔记

柚子小站
https://conyli.cc/archives/category/%e8%ae%a1%e7%ae%97%e6%9c%ba%e5%9f%ba%e7%a1%80/page/2

不周山
https://wdxtub.com/work/

大端模式：数字逻辑高位存储在内存的物理低位
小端模式：数字逻辑低位存储在内存的物理低位

汇编立即数表示：以$开头，跟着标准C表示法，如$-577，$0x1F。不同的指令允许的立即数范围不同

x86-64寄存器起名：8位，%al；16位，%ax；32位，%eax；64位，%rax
x86-64寄存器作用：
%rax: 返回值
%rbx: 被调用者保存
%rcx: 第4个参数
%rdx: 第3个参数
%rsi: 第2个参数
%rdi: 第1个参数
%rbp: 被调用者保存
%rsp: 栈指针
%r8: 第5个参数
%r9: 第6个参数
%r10: 调用者保存
%r11: 调用者保存
%r12: 被调用者保存
%r13: 被调用者保存
%r14: 被调用者保存
%r15: 被调用者保存

%rip 的名称来自于(instruction pointer register，指令指针寄存器)。
%rip其实就是程序计数器(Program Counter, PC), 存放着下一条指令的地址。