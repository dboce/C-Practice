/// 转义字符
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /*
    \t 水平制表符
    \a 警告字符, 蜂鸣

    \ddd  ddd表示1-3个八进制的数字.如:\130X
    \xdd  dd表示2个十六进制数字.如:\x300
     */
    printf("%c\n", "\130"); // X; 8进制的130是十进制的88
    // X -- ASCII码值是88

    printf("%c\n", '\x30'); // 0; 16进制的30是十进制的48

    printf("%d\n", strlen("c:\test\128\test.c")); //14
    // \t是一个转义字符; \32是一个转义字符

    return 0;
}
