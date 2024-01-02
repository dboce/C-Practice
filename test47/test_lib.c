#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>

// 购买使用 A 程序员的库, A只卖使用权, 不卖源码
// 新建项目>空项目>项目名"divide"

// 导入静态库
#pragma comment(lib, "divide.lib");
int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;
    int c = Divide(a, b);
    printf("%d\n", c);

    return 0;
}

// 定义放在头文件中: 可以做到代码的隐藏