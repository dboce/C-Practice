/// 变量的作用域和生命周期
#include <stdio.h>

// extern 声明外部符号
extern int g_val;
extern int Add(int x, int y);

// 作用域: 这个变量在哪里可以使用,哪里就是它的作用域
// 局部变量的作用域: 就是变量所在的局部范围
// 全局变量的作用域: 整个工程
int main(int argc, char const *argv[])
{
    printf("%d\n", g_val);

    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("sum = %d\n", sum);
    return 0;
}

// 生命周期
// 变量的生命周期: 变量的创建和销毁之前的时间段
// 局部变量的生命周期: 进入局部范围生命开始,出局部范围生命结束
// 全局变量的生命周期: 整个程序的生命周期