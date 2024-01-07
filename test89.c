#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// 实用调试技巧3
/*如何写出好(易于调试)的代码
优秀的代码:
    1.代码运行正常
    2.bug很少
    3.效率高
    4.可读性高
    5.可维护性高
    6.注释清晰
    7.文档齐全

常见的coding技巧
    1.使用assert
    2.尽量使用const
    3.养成良好的编程风格
    4.添加必要的注释
    5.避免编码的陷阱
*/

// // 方式一: 这个代码写的不好
// void my_strcpy(char *dest, char *src)
// {
//     while (*src != '\0')
//     {
//         *dest = *src;
//         dest++;
//         src++;
//     }
//     *dest = *src;
// }

// // 方式二: 适当优化
// void my_strcpy(char *dest, char *src)
// {
//     while (*src != '\0')
//     {
//         *dest++ = *src++;
//     }
//     *dest = *src;
// }

// 方式三: 适当优化
void my_strcpy(char *dest, char *src)
{
    // \0 对应的ASSIC码值是 0, 把0赋值给 *desc ,得到表达式的结果为0, while停止循环
    while (*dest++ = *src++) // 即copy了\0 , 又使得循环停止!
    {
        ;
    }
}

int main(int argc, char const *argv[])
{
    // 模拟实现strcpy
    // strcpy - 字符串拷贝
    char arr1[20] = "xxxxxx";
    char arr2[] = "hello";
    my_strcpy(arr1, arr2);
    // strcpy(arr1, arr2);
    printf("%s\n", arr1);

    return 0;
}
