#define _CRT_SECURE_NO_WARNINGS 1
/// 循环语句do while
#include <stdio.h>
/*do语句的语法:
do
    循环语句;
while(表达式);

特点: 循环至少执行1次
*/

int main(int argc, char const *argv[])
{
    int i = 1;
    do
    {
        printf("%d ", i); // 1 2 3 4 5 6 7 8 9 10
        i++;
    } while (i <= 10);

    // break : 跳出一个循环, 不是跳出程序. 如果嵌套循环, 需要多个break
    int i = 1;
    do
    {
        if (i == 5)
            break;

        printf("%d ", i); // 1 2 3 4
        i++;
    } while (i <= 10);

    // continue
    int i = 1;
    do
    {
        if (i == 5)
            continue;

        printf("%d ", i); // 1 2 3 4 6 7 8 9 10
        i++;
    } while (i <= 10);

    // 练习
    // 1.计算n的阶乘 n!
    int i = 0;
    int n = 0;
    scanf("%d", &n);
    int r = 1;
    for (i = 1; i <= n; i++)
    {
        r *= i;
    }

    // 2.计算 1!+2!+3!+...+10!
    int i = 0;
    int r = 0;
    int j = 0;
    for (i = 1; i <= 10; i++)
    {
        int tmp = 1;
        for (j = 1; j <= i; j++)
        {
            tmp *= i;
        }
        r += tmp;
    }
    printf("%d\n", r);
    // 方式二:
    int sum = 0;
    int ret = 1;
    for (n = 1; n <= 10; n++)
    {
        ret *= n;
        sum += ret;
    }
    printf("%d\n", sum);

    // 3.在一个有序数组中查找具体某个数字n.(二分查找)
    // 编写int binsearch(int x, int v[], int n);
    // 功能:在v[0]<=v[1]<=v[2]<=....<=v[n-1]的数组中查找x.
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 7;
    int sz = sizeof(arr) / sizeof(arr[0]); // 数组的元素个数
    int left = 0;                          // 下标
    int right = sz - 1;                    // 下标
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            printf("找到了:%d\m", mid);
            break;
        }
    }
    if (left > right)
    {
        printf("找不到了\n");
    }

    return 0;
}
