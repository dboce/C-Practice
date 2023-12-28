/// 字符串
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // 由双引号引起来的一串字符成为字符串字面量,或者简称字符串.
    // 字符数组 - 数组是一组相同类型的元素
    char arr[] = "abc";
    char arr2[] = {'a', 'b', 'c'};

    // 打印字符串
    printf("%s\n", arr); //'a' 'b' 'c' '\0'
    printf("%s\n", arr2);
    // 注:字符串的结束标识是一个\0的转义字符,在计算字符串长度的时候\0是结束标识,不算字符串内容

    // 求一下字符串的长度
    int len = strlen("abc");
    printf("%d\n", strlen);       // 3
    printf("%d\n", strlen(arr));  // 3
    printf("%d\n", strlen(arr2)); // 随机值

    return 0;
}
