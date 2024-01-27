#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <limits.h> //定义整型家族的变量类型的取值范围
#include <float.h>  //定义浮点家族的变量类型的取值范围
/// 数据的存储3

int main(int argc, char const *argv[])
{
    // 练习五: 打印结果是什么?
    unsigned int i;
    for (i = 9; i >= 0; i--) // 死循环: 因为i是无符号整型, i>=0永远成立
    {
        printf("%u\n", i);
    }

    // 练习六: 打印结果是什么?
    char a[1000];
    int i;
    for (i = 0; i < 1000; i++)
    {
        a[i] = -1 - i;
    }
    // -1 -2 -3 ... -127 -128 127 126 125 ... 3 2 1 0 -1 -2 -3 ... -127 -128 127 ...
    printf("%d", strlen(a)); // 打印255.因为: 找到\0 ->0, 128+127=255

    // 练习七: 打印结果是什么?
    unsigned char i = 0;
    for (i = 0; i <= 255; i++) // 死循环: 因为char的 255+1 = 0
    {
        printf("hello world\n");
    }
    /*
    无符号char整型:
    00000000    0
    00000001    1
    00000010    2
    00000011    3
    ...
    01111111    127
    10000000    128
    10000001    129
    ...
    11111111    255
    */

    return 0;
}
