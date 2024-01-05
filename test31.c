/// 循环语句while1
#include <stdio.h>
/*while 语法结构
while(表达式)
    循环语句;
*/

int main(int argc, char const *argv[])
{
    int i = 1;      // 初始化
    while (i <= 10) // 判断部分
    {
        printf("%d", i);
        i++; // 调整部分
    }

    // break continue
    int a = 1;
    while (a <= 10)
    {
        if (a == 5)
            break;        // 在while循环中, break用于永久的终止循环
        printf("%d ", a); // 1 2 3 4
        a++;
    }

    while (a <= 10)
    {
        if (a == 5)
            continue;     // 在while循环中, continue用于跳过本次循环及continue后边的代码, 直接去判断部分, 看是否进行下一次循环
        printf("%d ", a); // 1 2 3 4 然后死循环
        a++;
    }

    // ctrl+z - 终止程序
    // getchar 就读取结束
    int ch = 0;
    while ((ch = getchar()) != EOF) // EOF是-1
    {
        putchar(ch);
    }

    return 0;
}
