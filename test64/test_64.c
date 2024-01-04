#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
/// 扫雷游戏
/*
test.c - 扫雷游戏的测试
game.c - 游戏的函数的实现
game.h - 游戏的函数的声明
*/

void menu()
{
    printf("*************************\n");
    printf("*******  1.Play *********\n");
    printf("*******  0.Exit *********\n");
    printf("*************************\n");
}

/* 两个二维数组分别记录下面信息:
1. 布置雷 (专门存放-布置好的雷的信息)
    设置总共为10个雷;
    把雷的位置改成 '1', 不是雷的位置给 '0';
    初始化时, 数据全部为'0';
2. 排查雷 (专门存放-排查出的雷的信息)
    周围有几个雷,就放字符几. 比如: 5个雷, 放字符'5';
    初始化时, 数据全部为'*';

为了方便打印, 统一用char类型;
两个数组在上下左右各多开一行, 防止计算边上某个点雷个数的时候数组越界;
    如果想实现9*9的棋盘, 数组的大小设计成11*11比较好
游戏最开始为了保持神秘感, 棋盘上默认全是*
*/
void game()
{
    char mine[ROWS][COLS] = {0}; // 存放布置好的雷的信息
    char show[ROWS][COLS] = {0}; // 存放出的排查雷的信息

    // 初始化棋盘数组
    InitBoard(mine, ROWS, COLS, '0'); // 初始化为'0'
    InitBoard(show, ROWS, COLS, '*'); // 初始化为'*'

    // 打印棋盘(只显示9*9)
    // DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);

    // 布置雷
    SetMine(mine, ROW, COL);

    // 排查雷
    FindMine(mine, show, ROW, COL);
}

int main(int argc, char const *argv[])
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game(); // 扫雷游戏
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误, 重新选择\n");
            break;
        }
    } while (input);

    return 0;
}

// 可以优化的
// 1.如果不是雷, 周围没有雷 - 展开一片 - (可以递归解决)
// 2.标记雷