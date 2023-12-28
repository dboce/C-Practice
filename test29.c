/// 分支语句ifelse
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* c语言是结构化的设计语言
    顺序结构
    选择结构
        分支语句
            if
            switch
    循环结构
        循环语句
            while
            for
            do while
    goto语句
    */

    /*
    C语言中由一个分号;隔开的就是一条语句.

    C语言是如何表示真和假的呢?
        0 假
        非0  真
    */
    int age = 10;
    if (age < 26 && age >= 18)
    {
        printf("成年\n");
    }
    else if (age >= 26)
    {
        printf("壮年\n");
    }
    else
    {
        printf("未成年\n");
    }

    if (age >= 18) // 这种写法只能写一条执行语句
        printf("成年\n");
    else
        printf("未成年\n");

    // 悬空else
    int a = 0;
    int b = 0;
    if (a == 1)
        if (b == 2)
            printf("hehe\n");
    else
        printf("haha\n");
    // 结果:不打印,因为else紧跟离他最近的if

    // 输出1-100之间的奇数
    for (int i = 1; i <= 100; i += 2)
    {
        printf("%d\n", i);
    }

    return 0;
}
