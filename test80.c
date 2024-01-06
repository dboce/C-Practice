#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// 指针初阶2

int *test()
{
    int a = 10;
    return &a;
}

int my_strlen(char *str)
{ // 判断\0之前有多少个字符

    // 方法一: 计数器的方法
    // int count = 0;
    // while (*str != '0')
    // {
    //     count++;
    //     str++;
    // }
    // return count;

    // 方法二: 指针-指针
    char *p = str;
    while (*p != '\0')
        p++;
    return p - str;
}

int main(int argc, char const *argv[])
{
    // 野指针: 指针指向的位置是不可知的(随机的\不正确的\没有明确限制的)

    // 野指针成因: 1.指针未初始化
    int *p;  // p是一个局部的指针变量, 局部变量指针未初始化, 默认为随机值
    *p = 20; // 非法访问内存了

    // 野指针成因: 2.指针越界访问
    int arr[10] = {0};
    int *p = arr;
    int i = 0;
    for (i = 0; i <= 10; i++)
    {
        *p = i; // 加到10时,出现了越界访问
        p++;
    }

    // 野指针成因: 3.指针指向的空间释放了
    int *p = test();
    *p = 20;

    /*如何规避野指针
    1. 指针初始化
    2. 小心指针越界
    3. 指针指向空间释放即使置为NULL
    4. 指针使用之前检查有效性.
    */

    // 当前不知道p应该初始化为什么地址的时候, 直接初始化为NULL;
    int *p = NULL;
    // 明确知道初始化的值
    int a = 10;
    int *ptr = &a;

    // C语言本身是不会检测越界行为的

    // 指针使用之前检查有效性
    if (p != NULL)
        *p = 10;

        /* 指针运算
        - 指针 +- 整数
        - 指针 - 指针
        - 指针的关系运算
        */

        // 指针 +- 整数

#define N_VALUES 5
    float values[N_VALUES];
    float *vp;
    // 指针+-整数: 指针的关系运算
    for (vp = &values[0]; vp < &values[N_VALUES];) // vp < &values[N_VALUES :指针的关系运算
    {
        *vp++ = 0; //*vp++ :指针+整数, 可以理解成*(vp++)
    }

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr;
    int *pend = arr + 9;
    while (p <= pend)
    {
        printf("%d\n", *p);
        p++;
    }

    // 指针 - 指针
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", &arr[9] - &arr[0]); // 9
    // 指针 - 指针 = 两个指针之间的元素个数
    // 指针和指针相减的前提是: 两个指针指向同一块空间

    // strlen(); - 求字符串长度
    //  int len = strlen("abc"); // 3
    int len = my_strlen("abc"); // 递归
    printf("%d\n", len);        // 3

    // 指针的关系运算
    for (vp = &values[N_VALUES]; vp > &values[0];)
    {
        *--vp = 0;
    }
    // 不推荐下面的写法
    for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
    {
        *vp = 0;
    } // 实际上绝大部分编译器上可以顺利完成任务的, 然而我们还是应该避免这样写, 因为标准并不保证它可行.
    /*标准规定:
    允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较,
    但是不允许与指向第一个元素之前的那个内存位置的指针进行比较.
    */
    return 0;
}
