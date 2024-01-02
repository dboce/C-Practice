#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 函数练习1

void print_table(int n)
{
    int i = 0;
    // 行
    for (i = 1; i <= n; i++)
    {
        // 打印一行
        int j = 0;
        for (j = 1; j <= i; j++)
        {
            printf("%d*%d=%d ", i, j, i * j);
        }
        printf("\n");
    }
}

int my_strlen(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

// 方式一: 迭代
//  void reverse_string(char *str)
//  {
//      int left = 0;
//      int right = my_strlen(str) - 1;

//     while (left < right)
//     {
//         char tmp = str[left]; // *(str+left) == str[left]
//         str[left] = str[right];
//         str[right] = tmp;
//         left++;
//         right--;
//     }
// }

// 方式二:  迭代
void reverse_string(char *str)
{
    int left = 0;
    int right = my_strlen(str) - 1;

    while (left < right)
    {
        char tmp = *(str + left); // *(str+left) == str[left]
        *(str + left) = *(str + right);
        *(str + right) = tmp;
        left++;
        right--;
    }
}

// 方式三: 递归
void reverse_string(char *str)
{
    char tmp = *str; // 1
    int len = my_strlen(str);
    *str = *(str + len - 1); // 2
    *(str + len - 1) = '\0'; // 3
    // 判断条件
    if (my_strlen(str + 1) >= 2)
    {
        reverse_string(str + 1); // 4
    }
    *(str + len - 1) = tmp; // 5
}

int main(int argc, char const *argv[])
{
    // 1.函数调用 exec((v1, v2), (v3, v4), v5, v6);中, 实参的个数是: 4个
    // 逗号表达式结果为最右边的数字

    // 2. 乘法口诀表:
    // 实现一个函数, 打印乘法口诀表, 口诀表的行数和列数自己指定
    // 如: 输入9, 输出9*9口诀表, 输出12, 输出12*12乘法口诀表
    int n = 0;
    scanf("%d", &n);
    // 函数
    print_table(n);
    // 函数的起名是非常关键, 名字最好能体现函数的功能

    // 3.根据下面递归函数: 调用函数Fun(2), 返回值是多少? // 16
    printf("%d\n", Fun(2)); // 16
    /*
        int Fun(int n)
        {
            if (n == 5)
                return 2;
            else
                return 2 * Fun(n + 1);
        }
    */

    // 4.字符串逆序(递归实现)
    // 编写一个函数reverse_string(char* string)(递归实现)
    // 实现:将参数字符串中的字符串反向排列, 不是逆序打印.
    // 要求:不能使用c函数库中的字符串操作函数.
    // 例如: char arr[] = "abcdef"; 逆序之后数组内容变成: fedcba
    char arr[] = "abcdef";
    reverse_string(arr); // 数组名arr是数组arr首元素的地址
    printf("%s\n", arr); // fedcba

    return 0;
}
