#define _CRT_SECURE_NO_WARNINGS 1
/// 循环语句do while2
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

int main(int argc, char const *argv[])
{

    // 4.编写代码, 演示多个字符从两端移动, 向中间汇聚
    // ####################
    // w##################!
    // we################!!
    // wel##############!!!
    //...
    // welcome to China!!!!
    char arr1[] = "welcome to China!!!!";
    char arr2[] = "####################";
    int left = 0;
    int right = 0;
    int right = strlen(arr1) - 1;
    while (left <= right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s\n", arr2);
        Sleep(1000);   // 休眠1000毫秒=一秒
        system("cls"); // 清空屏幕
        left++;
        right--;
    }
    printf("%s\n", arr2);

    // 5.编写代码实现,模拟用户登录情景,并且登录三次.(只允许输入三次密码,如果密码正确提示登录成功,如果三次均输入错误,则退出程序.)
    int i = 0;
    // 假设正确的密码是字符串"123456"

    char password[20] = {0};

    for (i = 0; i < 3; i++)
    {
        printf("请输入密码:>");
        scanf("%s", password);
        // if(password =="123456") // err - 两个字符串比较不能用==, 应该使用strcmp
        if (strcmp(password, "123456") == 0) // 返回0,表示这个两个数相等
        {
            printf("登录成功\n");
            break;
        }
        else
        {
            printf("密码错误重新输入!\n");
        }
    }
    if (i == 3)
    {
        printf("三次密码均错误, 退出程序!\n");
    }

    // 6.猜数字游戏:
    /*自动生成一个1-100之间的随机数
    猜数字
        猜对了, 就恭喜你, 游戏结束
        猜错了, 会告诉你, 猜大了还是猜小了, 继续猜, 直到猜对
    游戏一直玩, 除非退出游戏
    */
    int input = 0;
    srand((unsigned int)time(NULL)); // 随机数:设置一个随机的起点,可以传入一个时间戳

    do
    {
        menu(); // 打印菜单
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
            printf("选择错误,重新选择\n");
            break;
        }
    } while (input);

    return 0;
}

void menu()
{
    printf("***************************"\n);
    printf("*******     1.play    *****"\n);
    printf("*******     0.exit    *****"\n);
    printf("***************************"\n);
}

void game()
{
    // 猜数字游戏的实现
    // 1. 生成随机数

    // rand函数返回了一个0-32767之间的数字
    // 时间 - 时间戳
    int ret = rand() % 100 + 1; // %100的余数是0-99,然后+1,范围就是1-100
    printf("%d\n", ret);

    // 2.猜数字
    int guess = 0;
    while (1)
    {
        printf("请猜数字:>");
        scanf("%d", &guess);
        if (guess < ret)
        {
            printf("猜小了\n");
        }
        else if (guess > ret)
        {
            printf("猜大了"\n);
        }
        else
        {
            printf("恭喜你, 猜对了\n");
            break;
        }
    }
}