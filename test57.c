#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 一维数组
/*
1. 一维数组的创建和初始化
2. 一维数组的使用
3. 一维数组的内存中的存储
4. 二维数组的创建和初始化
5. 二维数组的使用
6. 二维数组的内存中的存储
7. 数组作为函数参数
8. 数组的应用实例1: 三子棋
9. 数组的应用实例2: 扫雷游戏
*/
// 数组: 一组相同类型元素的集合
/*数组的创建方式:
type_t arr_name [const_n];
// type_t 是指数组的元素类型
// const_n 是一个常量表达式, 用来指定数组的大小
*/

int main(int argc, char const *argv[])
{
    // 数组的创建
    int arr[8];
    char ch[5];

    // C99语法支持 - 变长数组 - 支持数组的大小是变量
    // VS2019不支持变长数组
    // gcc - 对C99支持的比较好
    int n = 8;
    int arr[n];

    int a = 10;                                    // 初始化
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 完全初始化
    int arr[10] = {1, 2, 3, 4, 5};                 // 不完全初始化

    int arr2[] = {1, 2, 3, 4, 5};
    // int arr2[5] = {1, 2, 3, 4, 5}; // 等价于上面

    char ch5[5] = {'b', 'i', 't'}; // [b i t \0]
    char ch6[] = {'b', 'i', 't'};  //[b i t]
    printf("%s\n", ch5);           // bit
    printf("%s\n", ch6);           // bit烫烫烫it(打印随机值, 直到找到\0才结束)
    printf("%d\n", strlen(ch5));   // 8
    printf("%d\n", strlen(ch6));   // 随机值

    char ch3[5] = "bit"; // char ch3[5]初始化数组: b i t \0 0
    char ch4[] = "bit";  // b i t \0
    // \0的ASCII码值也是0

    ///[] 下标引用操作符
    // 数组是使用下标访问的, 下标是从0开始的
    // 数组的大小可以通过计算得到.
    int arr[10] = {0};
    arr[4] = 5;                    //[] - 下标引用操作符
    printf("%d ", sizeof(arr));    // 40
    printf("%d ", sizeof(arr[0])); // 4
    printf("------------\n");
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]); // 0 0 0 0 5 0 0 0 0 0

        printf("&arr[%d] = %p\n", i, &arr[i]); // %p - 是按地址的格式打印 - 十六进制的打印
        // &arr[0] = 012FFDA8
        // &arr[1] = 012FFDAC
        // &arr[2] = 012FFDB0
        // &arr[3] = 012FFDB4
        // &arr[4] = 012FFDB8
        // &arr[5] = 012FFDBC
        // &arr[6] = 012FFDC0
        // &arr[7] = 012FFDC4
        // &arr[8] = 012FFDC8
        // &arr[9] = 012FFDCC
        // 它们的地址值都差4, 因为每一个整形元素是4个字节
        // 一个字节给一个地址

        /*总结:
        1. 一维数组在内存中是连续存放的!
        2. 随着数组下标的增长, 地址是由低到高变化的!

        */
    }

    //
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr; // 数组名是数组首元素的地址
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *p);// 1 2 3 4 5 6 7 8 9 10
        p++;//一个整型指针+1,它会跳过一个整型; 
        // 一个字符的指针+1, 它会跳过一个字符;
        // 一个浮点型的指针+1, 它会跳过一个浮点型;
    }

    return 0;
}
