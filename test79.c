#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/// 指针初阶1
/*
1.指针是什么?
2.指针和指针类型
3.野指针
4.指针运算
5.指针和数组
6.二级指针
7.指针数组

指针是什么?
指针(Pointer)是编程语言中的一个对象, 利用地址, 它的值直接指向(points to)存在电脑存储器中另外一个地方的值.
由于通过地址能找到所需的变量单元, 可以说, 地址指向该变量单元.因此, 将地址形象的称为"指针".
意思是通过它能找到它为地址的内存单元.

内存单元编号是怎么产生的呢?
如果是32位机器,假设有32根地址线, 通电之后会产生电信号, 每根地址线在选址的时候产生一个电信号正电和负电(0或1), 就产生了32个由0和1组成的二进制序列,
32个0和1组成的二进制序列有多少个可能性? 2^32个地址
一个内存单元是一个字节

总结:
    - 指针是用来存放地址的, 地址是唯一标识一个块地址空间的.
    - 指针的大小在32位平台是4个字节, 在64位平台是8个字节.
*/

int main(int argc, char const *argv[])
{
    int a = 10;   // a占4个字节 -
    &a;           // 拿到的是a的4个字节中第一个字节的地址
    int *pa = &a; //*说明pa是指针变量; int说明pa指向的对象a是int类型
    // 把存放地址的变量, 称为指针变量.比如: 将a的地址存放在pa变量中, pa就是一个指针变量
    *pa; // 通过*pa 找到a
    *pa = 20;

    /* 指针类型的意义
    1.指针类型决定了: 指针解引用的权限有多大
        字符指针解引用可以获得1个字节的空间
        double类型解引用可以获得8个字节的空间
    2.指针类型决定了, 指针走一步, 能走多远(步长)
        int类型指针+1, 是+4个字节
        char类型指针+1, 是+1个字节
        double类型的指针+1, 是+8个字节
    */

    int a = 0x11223344; // 这是一个16进制数
    // 0 1 2 3 4 5 6 7 8 9 a b c d e f
    // 1111 - f //f要表示成一个二进制,至少需要4个二进制位
    // 所以说: 4个二进制位可以表示一个16进制数字
    int *pa = &a;
    *pa = 0;
    char *pc = &a;
    *pc = 0; // char类型解引用只获得了1个字节的空间

    int arr[10] = {0};
    int *p = arr;
    char *pc = arr;
    printf("%p\n", p);     // 打印的内存地址: 004FFC40
    printf("%p\n", p + 1); // 打印的内存地址: 004FFC44
    // int指针+1,跳过一个int; char指针+1,跳过一个char
    printf("%p\n", pc);     // 打印的内存地址: 004FFC40
    printf("%p\n", pc + 1); // 打印的内存地址: 004FFC41

    int arr[10] = {0};
    int *p = arr;
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        // p + i; // 表示数组中第i个元素的内存地址
        *(p + i) = 1; // 每次加1跳过一个整型
    }

    int arr[10] = {0};
    char *p = arr;
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        *(p + i) = 1; // 每次加1跳过一个char
    }
    // 总结: 指针的类型决定了, 对指针解引用的时候有多大的权限(能操作几个字节).
    //  比如char*的指针解引用就只能访问一个字节, 而int*的指针的解引用就能访问四个字节.

    return 0;
}
