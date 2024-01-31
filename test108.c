#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
/// 调试技巧练习

void print(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void move(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;

    while (left < right)
    {
        // 从前往后找一个偶数
        while ((left < right) && arr[left] % 2 == 1)
        {
            left++;
        }
        // 从后往前找一个奇数
        while ((left < right) && arr[right] % 2 == 0)
        {
            right--;
        }
        if (left < right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    /*练习一: 打印菱形
    用C语言在屏幕上输出以下图案:
                *
               ***
              *****
             *******
            *********
           ***********
          *************
           ***********
            *********
             *******
              *****
               ***
                *
    */
    int line = 0;
    scanf("%d", &line); // 7
    // 上部分
    int i = 0;
    for (i = 0; i < line; i++)
    {
        // 打印一行
        // 空格
        int j = 0;
        for (j = 0; j < line - 1 - i; j++)
        {
            printf(" ");
        }
        // *
        for (j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    // 下部分
    for (i = 0; i < line - 1; i++)
    {
        // 打印一行
        // 空格
        int j = 0;
        for (j = 0; j <= i; j++)
        {
            printf(" ");
        }
        // *
        for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // 练习二: 喝汽水问题
    // 喝汽水, 1瓶汽水1元, 2个空瓶可以换一瓶汽水, 给20元, 可以多少汽水?(编程实现)
    int money = 0; // 总金额
    scanf("%d", &money);
    // 方法一
    int total = money; // 总共多少瓶汽水
    int empty = money; // 置换剩余空瓶个数
    // 开始置换
    while (empty >= 2)
    {
        total += empty / 2;
        empty = empty / 2 + empty % 2;
    }
    printf("%d\n", total);
    // 方法二
    int total = 0;
    if (money > 0)
        total = 2 * money - 1;

    // 练习三: 程序死循环解释
    // VS开发环境调试下面代码, 画图解释下面代码的问题
    int i = 0;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (i = 0; i <= 12; i++)
    {
        arr[i] = 0;
        printf("hello bit\n");
    }

    // 练习四: 调整奇数和偶数的顺序
    // 调整数组使奇数全部都位于偶数前面.
    // 输入一个整数数组, 实现一个函数,
    // 来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分,
    // 所有偶数位于数组的后半部分.
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    move(arr, sz);
    print(arr, sz);

    return 0;
}
