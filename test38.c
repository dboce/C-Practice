#define _CRT_SECURE_NO_WARNINGS 1
/// 分支循环习题
#include <stdio.h>

/*调试
F11 - 逐语句
F10 - 逐过程
*/

int func(int a)
{
    int b;
    switch (a)
    {
    case 1:
        b = 30;
    case 2:
        b = 20;
    case 3:
        b = 10;
    default:
        b = 0;
    }
    return b;
}

int main(int argc, char const *argv[])
{
    // 习题1
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        if (i = 5)
            printf("%d ", i); // 死循环的打印5
    }

    // 习题2
    printf("%d ", func(1)); // 0

    // 习题3
    // switch(c)语句中, c不可以是什么类型? float
    // A int; B long; C char; D float;

    // 习题4
    int x = 3;
    int y = 3;
    switch (x % 2)
    {
    case 1:
        switch (y)
        {
        case 0:
            printf("first");
        case 1:
            printf("second");
            break;
        default:
            printf("hello");
        }
    case 2:
        printf("third");
    }
    // 打印结果 hellothird

    // 习题5: 写代码将三个整数按从大到小输出
    int a = 0;
    int b = 0;
    int c = 0;
    // 输入
    scanf("%d %d %d", &a, &b, &c);
    // 调整顺序
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (a < c)
    {
        int tmp = a;
        a = c;
        c = tmp;
    }
    if (b < c)
    {
        int tmp = b;
        b = c;
        c = tmp;
    }
    // 输出 - 从大到小
    printf("%d %d %d\n", &a, &b, &c);
    

    // 习题6: 写一个代码打印1-100之间所有3的倍数的数字
    // 方式一:
    int i = 0;
    // for (i = 0; i <= 100; i++)
    // {
    //     // 判断i是否为3的倍数
    //     if (i % 3 == 0)
    //         printf("%d", i);
    // }
    // 方式二:
    for (i = 3; i <= 100; i += 3)
    {
        printf("%d", i);
    }

    // 习题7: 给定两个数, 求这两个数的最大公约数
    // 例如: 输入:20 40   输出:20
    // 方式一:
    // int m = 0;
    // int n = 0;
    // scanf("%d%d", &m, &n); // 24 18
    // // 假设最大公约数就是m和n的较小值
    // int max = m > n ? n : m; // 此时最大公约数肯定不会超过18
    // while (1)                // 让它一直循环,直到break
    // {
    //     if (m % max == 0 && n % max == 0)
    //     {
    //         printf("最大公约数就是: %d\n", max);
    //         break;
    //     }
    //     max--;
    // }
    // 方式二:辗转相除法
    int m = 0;
    int n = 0;
    scanf("%d%d", &m, &n); // 24 18
    int t = 0;
    while (t = m % n)
    {
        m = n;
        n = t;
    }
    printf("最大公约数就是: %d\n", n);

    return 0;
}