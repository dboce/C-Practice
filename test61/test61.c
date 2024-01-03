#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h" //包含头文件
/// 三子棋
/*
test.c 测试游戏的逻辑

game.h 关于游戏相关的函数声明, 符号声明头文件的包含

game.c 游戏相关函数的实现
*/

void menu()
{
    printf("********************************\n");
    printf("********  1.play  **************\n");
    printf("********  0.exit  **************\n");
    printf("********************************\n");
}

void game()
{
    // 存储数据 - 二维数组
    char board[ROW][COL];
    // 初始化棋盘 - 初始化空格
    InitBoard(board, ROW, COL);
    // 打印一下棋盘
    DisplayBoard(board, ROW, COL);
    char ret = 0; // 接收游戏状态
    while (1)
    {
        // 玩家下棋
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        // 判断玩家是否赢得游戏
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
        // 电脑下棋
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        // 判断电脑是否赢得游戏
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
    }
    if (ret == '*')
    {
        printf("玩家赢了\n");
    }
    else if (ret == '#')
    {
        printf("玩家赢了\n");
    }
    else
    {
        printf("平局\n");
    }
    DisplayBoard(board, ROW, COL);
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
            game();
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

/* 数组作为函数传参的时候:
    形参可以写成2种形式:
    1. 数组形式
    2. 指针形式
    可以传数组的形式, 也可以传指针的形式, 但本质上是指针

    int arr[10]; //一维数组
    char ch[3][5]; //二维数组

    test1(arr);//调用

    // 形参是数组
    void test1(int arr[10]){}
    void test1(int arr[]){}

    // 形参是指针
    void test1(int *arr){}

    test2(ch);//调用

    // 形参是数组
    void test2(char arr[3][5]){}
    void test2(char arr[][5]){}

    // 形参也可以是指针

*/