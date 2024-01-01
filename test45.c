#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 函数的调用
/*函数的调用
传值调用
    函数的形参和实参分别占有不同的内存块, 对形参的修改不会影响实参.
传址调用
    传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式.
    这种传参方式可以让函数和函数外边的变量建立起来真正的联系,也就是函数内部可以直接操作函数外部的变量.
*/
// 一个函数如果不写返回类型, 默认返回int类型
int is_prime(int n)
{
    // 2->n-1之间的数字
    int j = 0;
    for (j = 2; j < sqrt(n); j++)
    {
        if (n % j == 0)
            // printf("%d 不是素数\n", n);
            return 0;
    }
    // printf("%d 是素数\n", n);
    return 1;
}

int is_leap_year(int y)
{
    // 如果判断是闰年返回1 , 不是闰年返回0
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

// int binary_search(int *a, int k, int s)
int binary_search(int a[], int k, int s) // int a[] 这个不会真的去创建一个数组
{
    // int sz = sizeof(arr) / sizeof(arr[0]); //这个写法是错误的, 应该在外部计算个数, 形参传递过来的是首元素的内存地址
    int left = 0;
    int right = s - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] > k)
        {
            right = mid - 1;
        }
        else if (a[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1; // 找不到了
}

int main(int argc, char const *argv[])
{
    // 1.100-200之间的素数
    int i = 0;
    int count = 0;
    for (i = 100; i <= 200; i++)
    {
        // 判断i是否为素数
        if (is_prime(i) == 1)
        {
            count++;
            printf("%d ", i);
        }
    }
    printf("\ncount = %d\n", count);

    // 2.写一个函数来判断是不是闰年
    int y = 0;
    for (y = 0; y < 2000; y++)
    {
        if (is_leap_year(y) == 1)
        {
            printf("%d ", y);
        }
    }

    // 3.写一个函数, 实现一个整型有序数组的二分查找.
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 7;
    int sz = sizeof(arr) / sizeof(arr[0]);
    // 找到了就返回找到的位置的下标
    // 找不到就返回-1
    // 数组arr传参,实际传递的不是数组本身, 仅仅传递过去了数组首元素的地址
    // 注:如果函数内部需要参数传递过来数组某一个元素个数, 一定是要外部求好这个个数传递进来
    int ret = binary_search(arr, key, sz);
    if (-1 == ret)
    {
        printf("找不到\n");
    }
    else
    {
        printf("找到了, 下标是: %d\n", ret);
    }

    return 0;
}
