#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*
        ~ 按(二进制)位取反
        把所有二进制位中的数字, 1变成0, 0变成1
     */
    int a = 0;
    printf("%d\n", ~a); // -1 (打印的是原码)
    /*
    0 的二进制怎么表示?
    0是整数,整数它是一个32 bit的整型
    00000000000000000000000000000000
    0是放在一个整型变量中,整型占4个字节,一个字节占8个bit位,所以要写32bit位

    整数在内存中存储的是补码
    一个整数的二进制表示有3种:
    原码
    反码
    补码

    正整数的:原码\反码\补码相同
    */

    /* -1的二进制序列: (负数)
     10000000000000000000000000000001 (原码) //最高位是1表示是负数
     11111111111111111111111111111110 (反码) //符号位不变,其他位按位取反
     11111111111111111111111111111111 (补码) //反码的二进制+1变成补码

     在它内存中存的是它的补码.
     原码/反码/补码的计算是针对负数的计算方式.
     打印打印的是真实值,也就是原码.
    */

    int a = 10;
    int b = ++a; // 前置++: 先++,后使用

    printf("%d\n", b); // 11
    printf("%d\n", a); // 11

    int a = 10;
    int b = a++; // 后置++: 先使用,后++

    printf("%d\n", b); // 10
    printf("%d\n", a); // 11

    // 逗号表达式: 用逗号隔开的表达式, 从左向右依次计算,
    // 逗号表达式的结果是它最后一个表达式的结果
    int a = 0;
    int b = 3;
    int c = 5;
    int d = (a = b + 2, c = a - 4, b = c + 2);
    printf("%d\n", d); // 3

    return 0;
}