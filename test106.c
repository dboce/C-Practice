#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
/// 指针初阶等练习

struct stu
{
    int num;
    char name[10];
    int age;
};
void fun(struct stu *p)
{
    printf("%s\n", (*p).name);
    return;
}

void reverse(char *str)
{
    assert(str != NULL);
    int len = strlen(str);
    char *left = str;
    char *right = str + len - 1;
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

int aaa; // aaa是全局变量, 不初始化, 默认是0
int main(int argc, char const *argv[])
{
    // 练习一: 输出什么? >
    aaa--;
    // sizeof这个操作符,算出的结果的类型是unsigned int
    // 有符号整型和无符号整形比较大小的时候, 会把有符号整型先转换成无符号整型, 然后再和进行比较
    // aaa解读为符号数, 也就是-1被解读成无符号数, 这是一个超级大的正数
    if (aaa > sizeof(aaa)) //-1>4
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }

    // 练习二: 计算求和
    // 求Sn = a+aa+aaa+aaaa+aaaaa的前5项之和, 其中a是一个数字,
    // 例如: 2+22+222+2222+22222
    // 由a组成前n项之和 - 不考虑溢出的情况
    int a = 0;
    int n = 0;
    scanf("%d %d", &a, &n);
    int i = 0;
    int ret = 0; // 一项的值
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        ret = ret * 10 + a; // 算出一项
        sum = sum + ret;
    }
    printf("sum = %d\n", sum);

    // 练习三: 写一个函数打印arr数组的内容, 不使用数组下标, 使用指针.(arr是一个整型一维数组)
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int *p = arr;
    // 方法一:
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf('%d ', *(p + i));
    }
    // 方法二:
    int *pend = arr + sz - 1;
    while (p <= pend)
    {
        printf('%d ', *p);
        p++;
    }

    // 练习四: 求出0~100000之间所有"水仙花数",并输出.
    // "水仙花数"是指一个n位数, 其各位数字的n次方之和正好等于该数本身.
    //  如: 153 = 1^3 + 5^3 + 3^3, 则153是一个"水仙花数".
    int i = 0;
    for (i = 0; i <= 100000; i++)
    {
        // 判断i是否会自幂数
        // 1.计算i的位数 - n
        int n = 1;
        int tmp = i;
        while (tmp / 10)
        {
            n++;
            tmp = tmp / 10;
        }
        // 2.计算i的每一位的n次方之和
        tmp = i;
        int sum = 0;
        while (tmp)
        {
            sum += pow(tmp % 10, n); // pow是用来求次方数
            tmp = tmp / 10;
        }
        // 3.判断
        if (sum == i)
        {
            printf("%d ", i);
        }
    }

    // 练习五: 下列程序段的运行结果是什么?
    unsigned long pulArray[] = {6, 7, 8, 9, 10};
    unsigned long *pulPtr;
    pulPtr = pulArray;
    *(pulPtr + 3) += 3;
    printf("%d, %d\n", *pulPtr, *(pulPtr + 3)); // 6, 12

    // 练习六: 下面程序的输出结果是什么?
    struct stu students[3] = {{9801, "zhang", 20},
                              {9802, "wang", 19},
                              {9803, "zhao", 18}};
    fun(students + 1); // "wang"

    // 练习七: 字符串逆序
    // 写一个函数, 可以逆序一个字符串的内容
    char arr[] = "abcdef"; // fedcba
    reverse(arr);
    printf("%s\n", arr);

    return 0;
}
