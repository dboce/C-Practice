/// 分支语句switch
#include <stdio.h>
/*
 switch(整形表达式)
 {
    case 整形常量表达式
        语句;
        break;
 }
*/

int main(int argc, char const *argv[])
{
    // 输入数字,显示星期几
    int day = 0;
    scanf("%d", &day);
    switch (day)
    {
    case 1:
        printf("星期一\n");
        break;
    case 2:
        printf("星期二\n");
        break;
    case 3:
        printf("星期三\n");
        break;
    case 4:
        printf("星期四\n");
        break;
    case 5:
        printf("星期五\n");
        break;
    case 6:
        printf("星期六\n");
        break;
    case 7:
        printf("星期天\n");
        break;
    default:
        break;
    }

    // 1-5工作日     6-7休息日
    switch (day)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("工作日\n");
        break;
    case 6:
    case 7:
        printf("休息日\n");
        break;
    default:
        break;
    }

    // 练习题
    int n = 1;
    int m = 2;
    switch (n)
    {
    case 1:
        m++;
    case 2:
        n++;
    case 3:
        switch (n)
        { // switch允许嵌套使用
        case 1:
            n++;

        case 2:
            m++;
            n++;
            break;
        }
    case 4:
        m++;
        break;
    default:
        break;
    }
    printf("m = %d, n = %d\n", m, n); // m = 5, n = 3

    return 0;
}
