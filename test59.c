#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 数组作为函数参数

// 冒泡方式一:
void bubble_sort(int arr[], int sz) // 形参arr本质上是指针
{
    // // 计算数组元素个数
    // int sz = sizeof(arr) / sizeof(arr[0]); // err
    // 确定趟数
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        // 一趟冒泡排序的过程
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // 交换
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// 冒泡方式二:(优化)
void bubble_sort(int arr[], int sz) // 形参arr本质上是指针
{
    // // 计算数组元素个数
    // int sz = sizeof(arr) / sizeof(arr[0]); // err
    // 确定趟数
    int i = 0;

    for (i = 0; i < sz - 1; i++)
    {
        // 一趟冒泡排序的过程
        int j = 0;
        int flag = 1;

        for (j = 0; j < sz - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                // 交换
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;
            }
            if (flag == 1) // 循环走完都没有交换, 说明已经是有序的了
            {
                break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // 排序为升序 - 冒泡排序

    int sz = sizeof(arr) / sizeof(arr[0]); // 计算数组元素个数
    bubble_sort(arr, sz);                  // 数组传参的时候, 传递的其实是数组首元素的地址
    /*
    往往我们在写代码的时候, 会将数组作为参数传给函数, 比如:我要实现一个冒泡排序(这里要讲算法思想)
    函数将一个整形数组排序.

    冒泡排序的思想:
        两两相邻的元素进行排序, 并且可能的话需要交换!

    一趟冒泡排序:
    9 8 7 6 5 4 3 2 1 0
    8 9 7 6 5 4 3 2 1 0
    8 7 9 6 5 4 3 2 1 0
    8 7 6 9 5 4 3 2 1 0
    ...
    8 7 6 5 4 3 2 1 0 9

    10个数字(n) - 9趟(n-1)
    */

    /// 数组名是什么?
    // 数组名是数组首元素的地址
    // 但是有2个例外:
    //   1. sizeof(数组名) - 数组名表示整个数组 - 计算的是整个数组的大小(单位是字节)
    //   2. &数组名 - 数组名表示整个数组 - 取出的是整个数组的地址
    int arr[10] = {0};

    printf("%p\n", &arr[0]); // 00DDFD6C
    printf("%p\n", arr);     // 00DDFD6C
    printf("%p\n", arr + 1); // 00DDFD70
    // 数组名是数组首元素的地址

    printf("%p\n", &arr);     // 00DDFD6C - 取出的是整个数组的地址
    printf("%p\n", &arr + 1); // 00DDFD84

    int sz = sizeof(arr); // 此时数组名表示整个数组
    printf("%d\n", sz);   // 40

    return 0;
}
