#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// 指针进阶1
/*指针的进阶
1.字符指针
2.数组指针
3.指针数组
4.数组传参和指针传参
5.函数指针
6.函数指针数组
7.指向函数指针数组的指针
8.回调函数
9.指针和数组面试题的解析
*/

/*指针的概念
1.指针就是个变量, 用来存放地址, 地址唯一标识一块内存空间.
2.指针的大小是固定的4/8个字节(32位平台/64位平台)
3.指针是有类型, 指针的类型决定了指针的±整数的步长, 指针解引用操作的时候的权限
4.指针的运算.
*/

int main(int argc, char const *argv[])
{
    // 指针字符串
    char ch = 'q';
    char *pc = &ch; //&ch 表示取出ch的内存地址
    // 赋值给指针变量pc
    char *ps = "hello bit"; // 本质上是把"hello bit"这个字符串的首字母的地址存储在了ps中
    printf("%c\n", *ps);    // h
    char arr[] = "hello bit";
    printf("%s\n", ps);  // 打印字符串: hello bit
    printf("%s\n", arr); // 打印字符串: hello bit

    // 练习一: 输出什么? 1,2不同; 3,4相同
    char str1[] = "hello bit.";
    char str2[] = "hello bit.";
    const char *str3 = "hello bit.";
    const char *str4 = "hello bit.";

    if (str1 == str2)
        printf("str1 and str2 are same\n");
    else
        printf("str1 and str2 are not same\n"); // 内存地址不同

    if (str3 == str4)
        printf("str3 and str4 are same\n"); // 内存地址相同
    else
        printf("str3 and str4 are not same\n");
    // 因为: 数组创建产生了两个不同的内存空间; 那两个指针变量指向的是常量字符串,不能修改, 这样的常量字符串只会在内存中存储一份.

    // 指针数组
    int *arr1[10];  // 整形指针的数组
    char *arr2[4];  // 一级字符指针的数组
    char **arr3[5]; // 二级字符指针的数组

    // 指针数组-本质是数组 - 数组中存放的是指针(地址)
    int *arr[3]; // 存放整形指针的数组

    int a[5] = {1, 2, 3, 4, 5};
    int b[] = {2, 3, 4, 5, 6};
    int c[] = {3, 4, 5, 6, 7};
    int *arr[3] = {a, b, c};
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        int j = 0;
        for (j = 0; j < 5; j++)
        {
            // printf("%d ", *(arr[i] + j));
            printf("%d ", arr[i][j]); // *(arr[i] + j) 等价于 arr[i][j]
        }
        printf("\n");
    }

    return 0;
}
