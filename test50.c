#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 函数递归2

// int my_strlen(char *str)
// {
//     int count = 0; // 创建临时变量
//     while (*str != '\0')
//     {
//         count++;
//         str++;
//     }
//     return count;
// }

int my_strlen(char *str)
{
    if (*str != '\0')
        return 1 + my_strlen(str + 1); // str+1 是下一个字符的地址
    else
        return 0;
}

int Fac(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * Fac(n - 1);
}

// int count = 0;
// // 递归可以求解,但是效率太低
// int Fib(int n)
// { // 这种方式效率太低 - 因为有重复大量的计算!

//     // 统计第3个斐波那契数的计算次数
//     if (n == 3)
//         count++;

//     if (n <= 2)
//         return 1;
//     else
//         return Fib(n - 1) + Fib(n - 2);
// }

int Fib(int n)
{
    int a = 1;
    int b = 1;
    int c = 1;
    while (n > 2)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    // 练习2: 编写函数不允许创建临时变量, 求字符串的长度.
    char arr[] = "bit";
    //['b']['i']['t']['\0']
    //
    // 模拟实现一个strlen函数
    printf("%d\n", my_strlen(arr));
    // my_strlen("bit");
    // 1 + my_strlen("it");
    // 1 + 1 + my_strlen("t");
    // 1 + 1 + 1 + my_strlen("");
    // 1+1+1+0 = 3

    // 练习3: 求n的阶乘.(不考虑溢出)
    int n = 0;
    scanf("%d", &n);
    // int i = 0;
    // int ret = 1;
    // // 迭代
    // for (i = 0; i < n; i++)
    // {
    //     ret = ret * i;
    // }
    // printf("%d\n", ret);
    int ret = Fac(n);
    printf("%d\n", ret);

    // 有一些功能可以使用迭代, 也可以使用递归的方式实现.

    // 练习4: 求第n个斐波那契数.(不考虑溢出)
    int n = 0;
    scanf("%d", &n);
    int ret = Fib(n);
    printf("%d\n", ret);

    // 函数递归的几个经典题目:
    // 1.汉诺塔问题
    // 2.青蛙跳台阶问题(斐波那契数列的问题)

    return 0;
}
