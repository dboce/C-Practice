#define _CRT_SECURE_NO_WARNINGS 1
/// 循环语句while2
#include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     // getchar和scanf -> 缓存区 <- 键盘
//     // getchar和scanf都是从缓冲区拿数据, 而不是从键盘
//     char password[20] = {0};
//     printf("请输入密码:>");
//     // 输入: 123456\n
//     scanf("%s", password); // 取走了: 123456
//     printf("请确认密码(Y/N):>");
//     // int ch = getchar(); // 取走了: \n

//     // 清理缓存区
//     getchar(); // 处理\n

//     int ch = getchar();
//     if (ch == 'Y')
//     {
//         printf("确认成功\n");
//     }
//     else
//     {
//         printf("确认失败\n");
//     }

//     return 0;
// }

int main(int argc, char const *argv[])
{
    // getchar和scanf -> 缓存区 <- 键盘
    // getchar和scanf这个两个输入函数都是从缓冲区拿数据, 而不是从键盘,键盘输入信息到缓冲区
    char password[20] = {0};
    printf("请输入密码:>");
    // 输入: 123456 abcdef\n
    scanf("%s", password); // 取走了: 123456 (空格前面的字符)
    printf("请确认密码(Y/N):>");

    // 清理缓存区
    // getchar(); // getchar只会消耗一个字符
    // 当一个信息里有很多内容时一个getchar处理不了
    // 放过个getchar,一直读,知道读到\n为止
    // 清理缓冲区中的多个字符
    int tmp = 0;
    while ((tmp = getchar()) != '\n') // 字符转成ASCII码, 所以int可以接收
    {
        ;
    }

    int ch = getchar();
    if (ch == 'Y')
    {
        printf("确认成功\n");
    }
    else
    {
        printf("确认失败\n");
    }

    // 只打印数字
    int ch3 = 0;
    while ((ch3 = getchar()) != EOF) // getchar 输入值
    {
        if (ch3 < '0' || ch3 > '9')
            continue;
        putchar(ch3); // putchar 输出值
    }

    return 0;
}
