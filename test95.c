#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// C语言初阶练习

int cnt = 0;
int fib(int n)
{
    cnt++;
    if (n == 0)
        return 1;
    else if (n == 1)
        return 2;
    else
        return fib(n - 1) + fib(n - 2);
}

int a = 1;
void test()
{
    int a = 2;
    a += 1; // 加的是局部的a
}

void reverse(char *left, char *right)
{
    while (left < right)
    {
        char tmp = 0;
        tmp = *left;
        *left = *right;
        *right = tmp;

        left++;
        right--;
    }
}

int main(int argc, char const *argv[])
{
    // 练习一: 下列程序执行后,输出的结果为()
    fib(8);
    printf("%d", cnt); // 67
    /*分析
    8
    7       6
    6 5    5 4
    ...
    拆到0和1的时候就不能再拆了
    都列出来之后, 加起来数一下
    */

    // 练习二:以下程序的输出结果是?
    int x = 1;
    do
    {
        printf("%2d\n", x++); // sp1
    } while (x--);            // sp2
    // 陷入死循环

    // 练习三: 下面的代码中,执行之后的i和j的值是什么?
    int i = 1;
    int j;
    j = i++;
    // i=2;j=1;

    // 练习四: 以下程序k的最终是:
    int i = 10;
    int j = 20;
    int k = 3;
    k *= i + j; // 90; +的优先级比*=高

    // 练习五: 以下程序的最终的输出结果为:
    test();
    printf("%d\n", a); // 1

    // 练习六: C语言规定,在一个源程序中, main函数的位置可以任意

    // 练习七: C语言本身没有输入输出语句
    // C语言只规定了各种语法规则; 库函数是独立于C语言语法之外的,利用C语言写出的,不属于C语言的一部分.

    // 练习八: 执行如下代码, c的值是: -1
    int a = 0, c = 0;
    do
    {
        --c;
        a = a - 1;
    } while (a > 0);

    // 练习九: 假定x和y为double型, 则执行 x=2; y=x+3/2; 后y的值为
    // 3.000000; 因为3/2得到的是1

    // 练习十: 循环次数为4次
    int x = 0;
    int y = 0;
    for (x = 0, y = 0; (y = 123) && (x < 4); x++)
        ;

    // 练习十:
    /*若有定义语句: int year=1009, *p=&year; 以下不能使变量year中的值增至 1010的语句是
    A *p+=1
    B (*p)++
    C ++(*p)
    D *p++

    答: D; 原因: ++的优先级高于*, 会进行p的++, 不会*p++
    */

    // 练习十一:
    // 选择表达式 11|10 的结果(本题均为十进制)
    // 答: 11

    // 练习十二:
    // char a; int b; flat c; double d;
    // 则表达式 a*b+d-c值的类型为
    // 答: double

    // 练习十三:
    /*正整数A和正整数B的最小公倍数是指 能被A和B整除的最小的正整数值, 设计一个算法, 求输入A和B的最小公倍数.
    输入两个正整数A和B.
    输出A和B的最小公倍数.
    比如: 输入5 7  输出35
    */
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b); // 输入
    // 方法一:
    int m = a > b ? a : b; // m表示最小公倍数
    while (1)
    {
        if (m % a == 0 && m % b == 0)
        {
            printf("%d\n", m);
            break;
        }
        m++;
    }
    // 方法二:
    int i = 1;
    for (i = 1;; i++)
    {
        if ((a * i) & b == 0)
        {
            printf("%d\n", a * i);
            break;
        }
    }
    // 方法三: 辗转相除法

    // 练习十三:
    /*将一句话的单词进行倒置, 标点标志. 比如 I like beijing. 经过函数后变为: beijing. like i
    每个测试输入包含1个测试用例: I like beiing.输入用例长度不超过100
    依次输出倒置之后的字符串, 以空格分隔
    输入: I like beijing.
    输出: beijing. like I
    */
    char arr[100] = {0};
    // scanf("%s", arr); //这样无法输入完整字符串内容, 比如"abc df", 只能输出abc(空格前面的部分)
    gets(arr); // 使用gets获取字符数组内容
    /* 三步翻转法
    第一步: 字符串整体翻转
        .gnijieb ekil I
    第二步: 每个单词逆序
        beiing, like I
    */
    // sp1: 字符串整体翻转
    int len = strlen(arr);
    reverse(arr, arr + len - 1); // 参数一:起始位置; 参数二:最后一个字符串的位置
    // sp2: 每个单词逆序
    char *start = arr;
    while (*start) // 如果不是/0还可以继续找单词
    {
        char *end = start;
        while (*end != ' ' && *end != '\0')
        {
            end++;
        }
        // 逆序一个单词
        reverse(start, end - 1);
        if (*end == ' ')
            start = end + 1;
        else
            start = end;
    }
    printf("%s\n", arr);

    return 0;
}
