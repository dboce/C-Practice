#define _CRT_SECURE_NO_WARNINGS 1
/// 库函数
/*函数的基本使用和递归
1.函数是什么
2.库函数
3.自定义函数
4.函数参数
5.函数调用
6.函数的嵌套调用和链式访问
7.函数的声明和定义
8.函数递归
*/

/*
常见的函数有:
    IO函数
        printf
    字符串操作函数
    字符操作函数
        toupper
    内存操作函数
        memcpy memcmp memset
    时间/日期函数
        time
    数学函数
        sqrt pow
    其他库函数
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // strcpy
    char arr1[20] = {0};
    char arr2[] = "hello bit";
    strcpy(arr1, arr2);
    printf("%s", arr1); // 打印arr1这个字符串, %s 以字符串的格式打印

    // memset
    char arr[] = "hello bit";
    memset(arr, 'x', 5);
    printf("%s\n", arr);

    return 0;
}
