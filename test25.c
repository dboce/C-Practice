/// 指针
/**内存
  内存是电脑中特别重要的存储器,计算机中所有程序的运行都是在内存中进行的.
  所以为了有效的使用内存,就把内存划分成一个个小的内存单元,每个内存单元的大小都是 1个字节
  为了能够有效的访问到内存的每个单元,就给内存单元进行了编号,这些编号被称为该 内存单元的地址
*/

#include <stdio.h>
/** 指针
 1.内存是怎么编号的?
 2.一个这样的内存单元是多大空间?

 32位机器和64位机器:
 32位机器:  一个内存单元有32根地址线 - 是物理线 - 可以通电 - 1/0(电信号: 正电1,负电0)
    电信号转换成数字信息: 1和0组成的二进制序列
    最多可以 2^(32)个内存单元

    假设: 一个内存单元是1 bit
    2^(32)是 4,294,967,296 bit
    /8 = 536,870,912 byte
    /1024 = 524,288 kb
    /1024 = 512 MB
    /1024 = 0.5 GB

    一个bit位给一个内存地址太小了
        char 1byte = 8bit   8个地址

    最终: 一个内存单元是1 byte,然后分配地址
*/

int main(int argc, char const *argv[])
{
    int a = 10;         // a在内存中要分配空间 - 4个字节
    printf("%p\n", &a); //%p专门用来打印地址

    int *pa = &a; // pa是用来存放地址的, 在C语言中pa叫指针变量
    // * 说明 pa是指针变量
    // int说明pa指向的对象是int类型的

    *pa = 20;          // * 解引用操作符: *pa就是通过pa里面的地址找到a
    printf("%d\n", a); // 20

    // 指针就是地址
    // 指针的大小是相同的
    // 指针是用来存放地址的
    // 指针需要多大空间,取决于地址的存储需要多大空间
    // 32位 32个bit位 - 4byte
    // 64位 64个bit位 - 8byte
    // 结论:指针大小在32位平台是4个字节, 64位平台是8个字节
    printf("%d\n", sizeof(char *));      // 4
    printf("%d\n", sizeof(short *));     // 4
    printf("%d\n", sizeof(int *));       // 4
    printf("%d\n", sizeof(long *));      // 4
    printf("%d\n", sizeof(long long *)); // 4
    printf("%d\n", sizeof(float *));     // 4
    printf("%d\n", sizeof(double *));    // 4

    return 0;
}
