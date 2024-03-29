#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// 数据的存储2

// 方式一:
int check_sys()
{
    int a = 1;
    char *p = (char *)&a; //*p起始就是访问一个字节
    if (*p == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// 方式二:(优化方式一)
int check_sys()
{
    int a = 1;
    char *p = (char *)&a;
    return *p; // 返回1表示小端, 返回0表示大端
}

int main(int argc, char const *argv[])
{
    // 百度2015年系统工程师笔试题:
    // 请阐述大端字节序和小端细节序的概念, 设计一个小程序来判断当前机器的字节序.
    int ret = check_sys();
    if (ret == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }

    // 练习一: 输出什么?
    char a = -1;                       // -1是个整数, 内存应该放的它的补码: 11111111111111111111111111111111, char只能存8个字节所以,截断存储8个字节: 11111111
    signed char b = -1;                // 同理b里面存的也是: 11111111
    unsigned char c = -1;              // 同理c里面存储的也是: 11111111
    printf("a=%d,b=%d,c=%d", a, b, c); // a=-1,b=-1,c=255
    // 打印时, 因为是%d打印所以要进行整形提升, a的符号位是1, 按符号位提升, 全是1, 此时是补码:11111111111111111111111111111111, 对应的原码是-1.
    // 同理:b得到的原码也是-1.
    // c的话, 因为是unsigned(无符号位),整型提升后补码变成了:00000000000000000000000000011111111, 对应的原码值是255

    /*补充:
    1. char 到底是signed char 还是 unsigned char?
        C语言标准没有规定, 取决于编译器
    2. int 是 signed int
    */

    // 练习二: 输出是什么?
    char a = -128;
    printf("%u\n", a); // 打印无符号数
    // -128原码: 10000000 00000000 00000000 10000000
    // -128反码: 11111111 11111111 11111111 01111111
    // -128补码: 11111111 11111111 11111111 10000000
    // char只能存8个字节, a截断存储: 10000000
    // %u是无符号整型数, 根据char原符号位整形提升, 补码变成了: 11111111 11111111 11111111 10000000 (4294967168)
    // 它又是打印无符号位, 原码与补码相同, 所以原码为: 4294967168
    // 打印结果为: 4294967168
    printf("%d\n", a); // 打印有符号数
    // 打印结果为: -128

    // 练习三: 输出是什么?
    char a = 128;
    printf("%u\n", a); // 4294967168
    // 有符号的char的取值范围是: -128~127之间

    // 练习四: 输出是什么?
    int i = -20;
    unsigned int j = 10;
    printf("%d\n", i + j); //-10
    /*加运算时补码相加
    -20的原码:    10000000 00000000 00000000 00010100
    -20的反码:    11111111 11111111 11111111 11101011
    -20的补码:    11111111 11111111 11111111 11101100
    10的原/反补码: 00000000 00000000 00000000 00001010
    相加后的补码:  11111111 11111111 11111111 11110110
    转原码(取反加1):10000000 00000000 00000000 00001010
    */

    return 0;
}