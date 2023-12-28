/// 循环语句
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int line = 0;
    //循环
    while (line < 30000)
    {
        printf("写代码:%d\n", line);
        line++;
    }

    if (line == 30000)
    {
        printf("好offer\n");
    }

    return 0;
}
