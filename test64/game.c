#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    for (i = 0; i < rows; i++)
    {
        int j = 0;
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    printf("---------扫雷游戏------------\n");
    // 打印列号
    for (j = 0; j <= col; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i); // 打印行号
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("---------扫雷游戏------------\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
    // 布置10个雷
    int count = EASY_COUNT;
    while (count)
    {
        // 生成随机下标
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (mine[x][y] == '0')
        {
            mine[x][y] = '1';
            count--;
        }
    }
}

// static
// 1. 修饰局部变量
// 2. 修饰全局变量
// 3. 修饰函数
static int get_mine_count(char mine[ROWS][COLS], int row, int col)
{
    return mine[row][col] +
           mine[row - 1][col - 1] +
           mine[row][col - 1] +
           mine[row + 1][col - 1] +
           mine[row - 1][col] +
           mine[row + 1][col] +
           mine[row - 1][col + 1] +
           mine[row][col + 1] +
           mine[row + 1][col + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    // 1. 输入排查的坐标
    // 2. 检查坐标处是不是雷
    //   (1) 是雷 - 很遗憾炸死了 - 游戏结束
    //   (2) 不是雷 - 统计坐标周围有几个雷 - 存储排查雷的信息到show数组, 游戏继续
    int x = 0;
    int y = 0;
    int win = 0;
    while (win < row * col - EASY_COUNT)
    {

        printf("请输入要排查的坐标:>");
        scanf("%d %d", &x, &y); // x的坐标1-9; y的坐标也是1-9;
        // 判断坐标的合法性
        if (x > 0 && x <= row && y > 0 && y <= col)
        {
            if (mine[x][y] == '1')
            {
                printf("很遗憾, 你被炸死了\n");
                DisplayBoard(mine, row, col);
                break;
            }
            else
            {
                // 不是雷情况下,统计 x,y坐标周围有几个雷
                int count = get_mine_count(mine, x, y);
                show[x][y] = count + '0';
                // 显示排查的信息
                DisplayBoard(show, row, col);
                win++;
            }
        }
        else
        {
            printf("坐标不合法, 请重新输入\n");
        }
    }
    // 判断所有的雷找出来
    if (win == row * col - EASY_COUNT)
    {
        printf("恭喜你,排雷成功\n");
        DisplayBoard(mine, row, col);
    }
}