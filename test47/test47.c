#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "add.h" //头文件的导入,相当于把头文件的内容放到这来了
#include "sub.h"
/// 函数的嵌套调用和链式访问

void Add(int *p)
{
    (*p)++;
}

void new_line()
{
    printf("hehe\n");
}

void three_line()
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        new_line();
    }
}

int main(int argc, char const *argv[])
{
    // 1. 写一个函数, 每调用一次这个函数, 就会将num的值增加1
    int num = 0;
    // 调用函数, 使得num每次增加1
    Add(&num);
    printf("%d\n", num);

    // 函数的嵌套调用
    // 函数可以嵌套调用, 不能嵌套定义
    three_line();

    // 链式访问: 把一个函数的返回值作为另一个函数的参数.
    int len = strlen("abc");
    printf("%d\n", len);

    // 链式访问示例一:
    printf("%d\n", strlen("abc"));

    // 链式访问示例二:
    char arr1[20] = {0};
    char arr2[] = "bit";
    printf("%s\n", strcpy(arr1, arr2));

    // 链式访问示例三:
    printf("%d", printf("%d", printf("%d", 43))); // 打印结果: 4321
    // printf函数返回的是打印在屏幕上的字符的个数

    /// 函数的声明和定义
    /*函数声明:
        1.告诉编译器有一个函数叫什么, 参数是什么, 返回类型是什么. 但是具体是不是存在, 无关紧要.
        2.函数的声明一般出现在函数的使用之前.需要先满足`先声明后使用`.
        3.函数的声明一般是要放在头文件中的
    函数定义:
        函数的定义是指函数的具体实现, 交代函数的功能实现.

    */
    int a = 10;
    int b = 20;
    // 函数声明一下 - 告知 (很少这么用,一般声明放在头文件)
    int Add2(int, int);

    int c = Add2(a, b);
    printf("%d\n", c);

    // 导入头文件的方式-引入函数
    int a = 10;
    int b = 20;
    // int c = Add(a, b);
    int c = Sub(a, b);

    printf("%d\n", c);

    return 0;
}

// 函数的定义
int Add2(int x, int y)
{
    return x + y;
}
