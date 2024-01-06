#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// 指针和数组

int main(int argc, char const *argv[])
{
    int arr[10] = {0};
    printf("%p\n", arr);     // 0059FD48 数组名是数组首元素的地址
    printf("%p\n", &arr[0]); // 0059FD48

    int *p = arr;
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%p <==> %p\n", &arr[i], p + i);
        // p+i 就是下标为i的内存地址
        *(p + i) = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(p + i));
    }

    ///
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr; // 数组名
    // arr[2] == *(arr + 2) == *(p + 2) == *(2 + p) == *(2 + arr) == 2 [arr]; // 第三个元素
    // 2 [arr] == *(2 + arr);
    printf("%d\n", 2 [arr]); // 3 (打印第三个元素)
    printf("%d\n", arr[2]);  // 3
    printf("%d\n", p[2]);    // 3  p[2] == *(p+2)
    // 当访问数组的时候, [] 是一个操作符, 2和arr是两个操作数
    //  编译器做了操作: arr[2] 转换成 *(arr+2) 执行
    // 因为加法支持交换率, 所以这几种写法都可以

    /// 二级指针
    int a = 10;
    int *pa = &a; // pa是指针变量, 一级指针

    int **ppa = &pa; // pa也是变量, &pa取出pa在内存中起始地址
    // ppa就是一个二级指针变量
    // **ppa == a;
    // 同理还有二级指针;三级指针;四级指针...

    /// 指针数组 - 本质是数组
    int arr[10]; // 整形数组 - 存放整型的数组就是整型数组
    char ch[5];  // 字符数组 - 存放的事字符
    // 指针数组 - 存放指针的数组
    int *parr[5]; // 整型指针的数组
    char *par[5];

    return 0;
}
