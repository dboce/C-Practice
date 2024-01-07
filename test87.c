#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/// 实用调试技巧2

void test2()
{
    printf("heheh");
}

void test1()
{
    test2();
}

void test()
{
    test1();
}

int main(int argc, char const *argv[])
{
    test();

    /// 实例一: 阶乘相加
    int n = 0;
    scanf("%d", &n); // 3
    // 1! + 2! + 3!
    // 1    2    6  = 9
    int i = 0;
    int ret = 1;
    int sum = 0;
    int j = 0;
    for (j = 1; j <= n; j++)
    {
        ret = 1;
        for (i = 1; i <= j; i++)
        {
            ret *= i;
        }
        sum += ret;
    }
    printf("%d\n", sum);

    // 实例二: 代码运行的结果是什么?
    int i = 0; // 可能会出现死循环
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int i = 0; // 会提示数组越界
    for (i = 0; i <= 12; i++) // 0-9
    {
        arr[i] = 0;
        printf("hehe\n");
    }
    // 死循环打印: hehe (越界后, 访问到了i的内存地址,对i进行了赋值, 造成了一直死循环)
    // 1. i 和 arr是局部变量
    //  局部变量是放在栈区上的
    //  栈区内存的使用习惯是: 先使用高地址空间, 在使用低地址空间
    // 2. 数组随着下标的增长地址是: 由低到高变化的

    return 0;
}
