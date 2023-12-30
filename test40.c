#define _CRT_SECURE_NO_WARNINGS 1
/// 分支循环习题2  goto
#include <stdio.h>
#include <math.h>>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // 习题1: 打印1000年到2000年之间的闰年
    int y = 0;
    int count = 0;
    for (y = 1000; y < 2000; y++)
    {
        // 判断y是不是闰年
        // 1.被4整除,不能被100整除是闰年
        // 2.能被400整除是闰年
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        {
            printf("%d ", y);
            count++;
        }
        printf("\ncount = %d\n", count); // 243
    }

    // 习题2: 写一个代码:打印100-200之间的素数
    // 素数就是质数: 只能被1和它本身整除
    // 方式一:
    // int i = 0;
    // for (i = 100; i <= 200; i++)
    // {
    //     // 判断i是否为素数
    //     // 2 到 i-1 之间的数字去试除, 看能不能整除
    //     int j = 0;
    //     for (j = 0; j < i; j++)
    //     {
    //         if (i % j == 0)
    //         {
    //             break;
    //         }
    //     }
    //     if (i == j)
    //     {
    //         printf("%d ", i); // 素数
    //     }
    // }
    // 方式二:
    // int i = 0;
    // for (i = 100; i <= 200; i++)
    // {
    //     // 判断i是否为素数
    //     // 2 到 i-1 之间的数字去试除, 看能不能整除
    //     int j = 0;
    //     int flag = 1; // 假设i就是素数
    //     for (j = 0; j < i; j++)
    //     {
    //         if (i % j == 0)
    //         {
    //             flag = 0; // 不是素数
    //             break;
    //         }
    //     }
    //     if (flag == 1)
    //     {
    //         printf("%d ", i); // 素数
    //     }
    // }
    // 方式三:(优化)
    // m = a*b
    // a 和 b中至少有一个数字是 <= 开平方m的
    // 16 = 2*8 = 4*4
    int i = 0;
    for (i = 101; i <= 200; i += 2) // 偶数肯定不是素数
    {
        // 判断i是否为素数
        // 2 到 i-1 之间的数字去试除, 看能不能整除
        int j = 0;
        int flag = 1; // 假设i就是素数
        for (j = 0; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = 0; // 不是素数
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d ", i); // 素数
        }
    }

    // goto 语句
    // 不建议使用goto语句
    // 应用场景: 跳出多层嵌套时,用goto跳出循环
    // goto语句只能在一个函数范围内调整, 不能跨函数

    // 使用示例: 关机程序-只要运行起来,电脑就在1分钟内关机, 如果输入:我是猪, 就取消关机!
    // C语言的关机命令: shutdown -s -t 60 #关机 设置 时间 为60秒后
    // 取消关机命令: shutdown -a #取消关机
    // C语言提供了一个函数: system() - 执行系统命令的

    // 方式一:
    //     char input[20] = {0};        // 存放输入的信息
    //     system("shutdown -s -t 60"); // system - stdlib.h
    // again:
    //     printf("请注意, 你的电脑在1分钟内关机, 如果输入: 我是猪, 就取消关机!\n");
    //     scanf("%s", input); // 数组名本来就是一个地址,所以不用再写&input了
    //     // string.h
    //     if (strcmp(input, "我是猪") == 0) // 两个字符串比较是不能使用==的, 应该使用strcmp()
    //     {
    //         system("shutdown -a");
    //     }
    //     else
    //     {
    //         goto again;
    //     }
    // 方式二:
    char input[20] = {0};        // 存放输入的信息
    system("shutdown -s -t 60"); // system - stdlib.h
    while (1)
    {
        printf("请注意, 你的电脑在1分钟内关机, 如果输入: 我是猪, 就取消关机!\n");
        scanf("%s", input); // 数组名本来就是一个地址,所以不用再写&input了
        // string.h
        if (strcmp(input, "我是猪") == 0) // 两个字符串比较是不能使用==的, 应该使用strcmp()
        {
            system("shutdown -a");
            break;
        }
    }

    // 编译运行后在release文件夹里会生成一个.exe文件, 可以发给别人安装

    // 电脑上搜索"服务"两个字, 进入"服务"应用, 任何一个服务右击属性, 会看到它是一个.exe文件
    // 百度搜一下: 如何把一个可执行程序添加到服务中, 启动类型改为"自动", 就完成了恶作剧

    return 0;
}
