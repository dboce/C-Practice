#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 二维数组
int main(int argc, char const *argv[])
{
    // 二维数组创建
    int arr[3][4]; // 3行 4列, 每一个元素都是int类型
    char ch[3][10];
    // 初始化 - 创建的同时给赋值
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // 完全初始化
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7};                   // 不完全初始化 - 后面补0
    int arr[3][4] = {{1, 2}, {3, 4}, {5, 6}};

    int arr[][4] = {{1, 2}, {3, 4}, {5, 6}}; // 行可以省略, 列不可以省略
    // 二维数组的使用
    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);

            printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]); // 二维数组在内存中的存储
            // &arr[0][0] = 006FFD4C
            // &arr[0][1] = 006FFD50
            // &arr[0][2] = 006FFD54
            // &arr[0][3] = 006FFD58
            // &arr[1][0] = 006FFD5C
            // &arr[1][1] = 006FFD60
            // &arr[1][2] = 006FFD64
            // &arr[1][3] = 006FFD68
            // &arr[2][0] = 006FFD6C
            // &arr[2][1] = 006FFD70
            // &arr[2][2] = 006FFD74
            // &arr[2][3] = 006FFD78
            // 总结: 二维数组在内存中也是连续存放!
            // 一行也是连续, 跨行也是连续的!
        }
        printf("\n");
    }
    /*二维数组在内存中连续存放的作用:
    1. 行可以省略, 列不能省略
    2. 只要拿到第一个元素的地址, 就可以拿到这个数组所有的值
    */
    int arr[][4] = {{1, 2}, {3, 4}, {5, 6}};
    int i = 0;
    int j = 0;
    int *p = &arr[0][0];
    for (i = 0; i < 12; i++)
    {
        printf("%d ", *p);
        p++;
    }

    return 0;
}
