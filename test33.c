#define _CRT_SECURE_NO_WARNINGS 1
/// 循环语句for
#include <stdio.h>
/*
for(初始化1; 判断2; 调整4)
    循环语句3;

for语句的循环控制变量
一些建议:
    1.不可在for循环体内修改循环变量, 防止for循环失去控制
    2.建议for语句的循环控制变量的取值采用"前闭后开区间"写法
*/
int main(int argc, char const *argv[])
{
    int i = 0;
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", i); // 1 2 3 4 5 6 7 8 9 10
    }

    for (i = 1; i <= 10; i++)
    {
        // if (i == 5)
        //     break; // 打印:1 2 3 4

        if (i == 5)
            continue; // 打印:1 2 3 4 6 7 8 9 10

        printf("%d ", i);
    }

    // 变种1
    //  判断部分的省略 - 判断部分恒为真 - 死循环
    //  初始化/判断/调整 都可以省略
    for (;;)
    {
        printf("hehe\n");
    }

    int i = 0;
    int j = 0;
    for (; i < 3; i++)
    {
        for (; j < 3; j++)
        {
            printf("hehe\n"); // 打印了3次"hehe", 因为j第二次循环时没有初始化重置为0的操作
        }
    }

    // 变种2
    int x, y;
    for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
    {
        printf("hehe\n");
    }

    // 一道笔试题
    // 请问循环要循环多少次? 0次; 因为k=0, 0赋值给k, 0为假, 为假一次都不执行
    int i = 0;
    int k = 0;
    for (i = 0, k = 0; k = 0; i++, k++)
    {
        k++;
    }

    return 0;
}
