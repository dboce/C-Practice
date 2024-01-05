/// 常量和宏
#include <stdio.h>

// define 是一个预处理指令, 不是关键字
// 1.define定义符号
#define MAX 1000

// 2.difine 定义宏
#define ADD(X, Y) ((X) + (Y))

int main(int argc, char const *argv[])
{
    printf("%d\n", MAX);
    printf("%d\n", 4 * ADD(2, 3)); // 20

    return 0;
}
