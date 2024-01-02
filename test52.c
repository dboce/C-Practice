#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 函数递归3
int main(int argc, char const *argv[])
{
    // 1. 关于while(条件表达式)循环体, (假设循环体里面没有break\continue\return\goto等语句)
    // 叙述正确的是: 条件表达式的执行次数总是比循环体的执行次数多一次

    // 2.
    int a = 0, b = 0;
    for (a = 1, b = 1; a <= 100; a++)
    {
        if (b >= 20)
            break;
        if (b % 3 == 1)
        {
            b = b + 3;
            continue;
        }
        b = b - 5;
    }
    printf("%d\n", a); // 8

    // 3.编写一个程序数一下1到100的所有整数中出现多少个数字9
    int i = 0;
    int count = 0;
    for (i = 1; i <= 100; i++)
    {
        if (i % 10 == 9)
            count++;
        if (i / 10 == 9)
            count++;
    }
    printf("%d\n", count); // 20

    // 4.计算1/1-1/2+1/3-1/4+1/5...+1/99-1/100的值, 打印出结果
    int i = 0;
    double sum = 0.0;
    // for (i = 0; i < 100; i++)
    // {
    //     if (i % 2 == 0)
    //         sum -= 1.0 / i;
    //     else
    //         sum += 1.0 / i;
    // }
    // printf("%lf\n", sum);
    int flag = 1;
    for (i = 1; i <= 100; i++)
    {
        sum += flag * 1.0 / i;
        flag = -flag;
    }
    printf("%lf\n", sum);

    // 5.求10个整数中最大值
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int max = arr[0];
    int i = 0;
    for (i = 1; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("%d\n", max);

    // 6.在屏幕上输出9*9乘法口诀
    // 1*1=1
    // 2*1=2 2*2=4
    // 3*1=3 3*2=6 3*3=9
    // ...
    int i = 1;
    // 行数
    for (i = 1; i <= 9; i++)
    {
        // 打印一行
        int j = 0;
        for (j = 1; j <= i; j++)
        {
            printf("%d*%d=%-2d ", i, j, i * j);
        }
        printf("\n");
    }

    // 7.二分查找: 编写代码在一个整型有序数组中查找具体的某个数
    // 要求:找到了就打印数字所在的下标, 找不到就输出:找不到

    return 0;
}

// 张暗语  张瑶浴