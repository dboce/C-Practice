#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 操作符详解 4
/*操作符分类:
    算术操作符
        + - * / %
    移位操作符
        >>  <<
    位操作符
        &按位与  |按位或  ^按位异或
    赋值操作符
        = += -= *= /= >>=  <<= %= |= ^=
    单目操作符
        ! 逻辑反操作
        - + & sizeof ~ -- ++
        * 间接访问操作符(解引用操作符)
        (类型) 强制类型转换
    关系操作符
        > >= < <= != ==
    逻辑操作符
        &&  ||
    条件操作符
        三目操作符
    逗号表达式
    下标引用/函数调用和结构成员
*/

// 创建了一个自定义的类型
struct Book
{
    // 结构体的成员(变量)
    char name[20];
    char id[20];
    int price;
};

// 函数的定义
int Add(int x, int y)
{
    return x + y;
}

int main(int argc, char const *argv[])
{
    /// 下标引用操作符
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", arr[4]); //[] - 就是下标引用操作符
    // []的 操作数是2个: 一个是数组名, 一个是索引值

    /// 函数调用操作符
    int a = 10;
    int b = 20;
    // 函数调用
    int ret = Add(a, b); // () - 函数调用操作符

    /// 结构成员访问操作符
    // .  ->
    struct Book book = {"C语言", "C20210509", 55}; // 也用{}初始化
    printf("书名:%s\n", book.name);
    printf("书号:%s\n", book.id);
    printf("定价:%d\n", book.price); // 结构体变量名.成员名

    struct Book *pb = &book;
    printf("书名:%s\n", (*pb).name);
    printf("书号:%s\n", (*pb).id);
    printf("定价:%d\n", (*pb).price);

    printf("书名:%s\n", pb->name);
    printf("书号:%s\n", pb->id);
    printf("定价:%d\n", pb->price); // 结构体指针->成员名

    /// 表达式求值
    // 表达式求值的顺序一部分是由操作符的优先级和结合性决定.
    // 同样, 有些表达式的操作数在求值的过程中可能需要转换为其他类型

    /// 隐式类型转换
    /* C的整形算术运算总是至少以缺省整形类型的精度来进行的.
        为了获得这个精度, 表达式中的字符和短整形操作数在使用之前被转换为普通整型, 这种转换成为'整型提升'
        整型提升的意义:
            表达式的整型运算要在CPU的相应运算器件内执行, CPU内整型运算器(ALU)的操作数的字节长度
            一般就是int的字节长度, 同时也是CPU的通用寄存器的长度.

            因此, 即使两个char类型的相加, 在CPU执行时实际上也要先转换为CPU内整型操作数的标准长度.

            通用CPU(general-purpose CPU) 是难以直接实现两个8比特字节直接相加运算(虽然机器指令中可能有这种字节相加指令).
            所以, 表达式中各种长度可能小于int长度的整型值, 都必须先转换为int或unsigned int, 然后才能送入CPU去执行运算.

        //实例1
        char a,b,c;
        ...
        a = b + c; //char的大小并没有达到整型的大小,这时候b和c提升为普通整型参与运算, 计算完再截断放回char

        b和c的值被提升为普通整型, 然后再执行加法运算.
        加法运算之后, 结果将被截断, 然后再存储于a中.

        如何进行整型提升呢?
        整型提升是按照变量的数据类型的符号位来提升的
    */
    char a = 3; // char只能放8个比特位
    // 00000011 - a存内存中
    // 整型提升: 00000000000000000000000000000011 - a
    char b = 127;
    // 01111111 - b存内存中
    // 整型提升: 00000000000000000000000001111111 - b
    char c = a + b;
    // 发现a和b都是char类型, 都没有达到一个int大小
    // 这里就会发生整型提升
    // 00000000000000000000000000000011 - a
    // 00000000000000000000000001111111 - b
    // 00000000000000000000000010000010 - c
    // 加完之后放回char里面去,char里面只能放8个字节, 这个时候就要截断
    // 截断后: 10000010 - c存内存中
    printf("%d\n", c); // -126
    // 打印的时候%d是个整型, 这个时候也要对c进行整型提升
    // 整型提升: 11111111111111111111111110000010 - c (补码)
    // 此时c成了负数, 负数的原码/反码/补码是不同的
    // c- 反码: 11111111111111111111111110000001
    // c- 原码: 10000000000000000000000001111110  // -126

    /*
    //负数的整型提升
    char c1 = -1;
    变量c1的二进制位(补码)中只有8个比特位:
    11111111
    因为 char 为有符号的 char
    所以整形提升的时候, 高位补充符号位, 即为1
    提升之后的结果是:
    11111111111111111111111111111111

    //正数的整型提升
    char c2 = 1;
    变量c2的二进制位(补码)中只有8个比特位:
    00000001
    因为 char 为有符号的 char
    所以整形提升的时候, 高位补充符号位, 即为0
    提升之后的结果是:
    00000000000000000000000000000001

    //无符号整形提升, 高位补0
    */

    // 实例1
    char a = 0xb6;
    short b = 0xb600;
    int c = 0xb6000000;
    if (a == 0xb6) // a和b都不是int型, 都发生了整形提升, 所以都不相等
        printf("a");
    if (b == 0xb600)
        printf("b");
    if (c == 0xb6000000)
        printf("c"); // 只打印了c

    // 实例2
    char c = 1;
    printf("%u\n", sizeof(c));  // 1
    printf("%u\n", sizeof(+c)); // 4 
    printf("%u\n", sizeof(-c)); // 4
    printf("%u\n", sizeof(!c)); // 4 (GCC编译)
    // c只要参加表达式运算,就会发生整型提升, 表达式+c, 就会发生提升, 所以sizeof是4个字节
    // 表达式-c也会发生整型提升, 所以sizeof(-c)是4个字节, 但是sizeof(c), 就是1个字节
    // 比int大的不用整型提升

    return 0;
}