#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 数组定义初始化练习

void init(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        arr[i] = 0;
    }
}

void print(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;
    while (left < right)
    {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
}

int main(int argc, char const *argv[])
{
    // 练习三:
    char acX[] = "abcdefg"; // [a b c d e f g \0]
    char acY[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    // 数组acX的长度大于数组acY的长度

    // 练习四: 创建一个整型数组, 完成对数组的操作
    // 1. 实现函数init()初始化数组为全0
    // 2. 实现print() 打印数组每个元素
    // 3. 实现reverse() 函数完成数组元素的逆置.
    // 要求: 自己设计以上函数的参数, 返回值.
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, sz);
    print(arr, sz);
    init(arr, sz);
    print(arr, sz);

    // 练习五: 交换数组
    // 将数组A中的内容和数组B中的内容进行交换.(数组一样大)
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};

    // int arr3[5] = {0};
    //  数组名是数组首元素的地址 - 0x0012ff44
    //  这是错误写法❌
    //  arr3 = arr1; //这种类似于 3 = 5 //error
    //  arr1 = arr2;
    //  arr2 = arr3;

    int sz = sizeof(arr1) / sizeof(arr1[0]);
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;
    }

    return 0;
}
