#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 函数练习2

// 刷题: https://www.nowcoder.com/ta/beginner-programmers

int DigitSum(int n)
{
    if (n > 9)
    {
        return DigitSum(n / 10) + n % 10;
    }
    else
    {
        return n;
    }
}

double Pow(int n, int k)
{
    if (k == 0)
        return 1.0;
    else if (k > 0)
        return n * Pow(n, k - 1);
    else
        return 1.0 / (Pow(n, -k));
}

int main(int argc, char const *argv[])
{
    // 1.计算一个数的每位之和(递归实现)
    //  写一个递归函数DigitSum(n), 输入一个非负整数, 返回组成它的数字之和
    //  例如: 调用DigitSum(1729),则应该返回1+7+2+9,它的和是19
    //  输入: 1729, 输出19
    int num = 1729;
    int sum = DigitSum(1729);
    printf("%d\n", sum); // 19

    // 2.递归实现n的k次方
    // 编写一个函数实现n的k次方, 使用递归实现
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    double ret = pow(n, k);
    printf("%lf\n", ret);

    return 0;
}
