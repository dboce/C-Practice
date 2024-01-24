#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// 模拟实现字符串相关函数

// 方式一:
void my_strcpy1(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = *src; // 把最后的\0赋值给 *dest
}
// 方式二: (方式一的升级)
void my_strcpy2(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest++ = *src++; // hello的拷贝
    }
    *dest = *src; // \0的拷贝
}
// 方式三: (方式二的升级)
void my_strcpy3(char *dest, char *src)
{
    while (*dest++ = *src++) // \0就是0, 0为假, 这样循环就停止了
    {
        ;
    }
}
// 方式四: (防止传参为NULL,空指针)
void my_strcpy4(char *dest, char *src)
{
    assert(src != NULL);     // 断言: 为假就会报错; 为真不提示.
    assert(dest != NULL);    // 帮助我们快速定位问题
    while (*dest++ = *src++) // \0就是0, 0为假, 这样循环就停止了
    {
        ;
    }
}
// 方式五: 防止desc和src传反了,使其报语法错误
// 把src指向的内容拷贝放进dest指向的空间中
// 从本质上讲, 希望dest指向的内容被修改, src指向的内容不应该被修改
char *my_strcpy(char *dest, const char *src)
{
    assert(src != NULL); // 断言
    assert(dest != NULL);
    char *ret = dest;
    while (*dest++ = *src++) // \0就是0, 0为假, 这样循环就停止了
    {
        ;
    }
    return ret; // 返回目标空间的起始地址
}

int main(int argc, char const *argv[])
{
    char arr1[20] = "xxxxxxxxxxxx";
    char arr2[] = "hello";
    // 把arr2的数据拷贝到arr1里面去
    strcpy(arr1, arr2);   // 参数一:目标空间的起始地址; 参数二:源空间的起始地址
    printf("%s\n", arr1); // hello

    // 模拟实现strcpy函数
    my_strcpy(arr1, arr2);
    // my_strcpy(arr1, NULL);
    // my_strcpy(arr2, arr1);
    printf("%s\n", arr1);
    // 参数一:目标空间的起始地址; 参数二:源空间的起始地址
    printf("%s\n", my_strcpy(arr1, arr2)); // 链式访问

    // const的作用
    // const修饰变量, 这个变量就被称为常变量, 不能被修改, 但是本质上还是变量
    const int num = 10;
    // num = 20;//err: 直接报错
    int *p = &num;
    *p = 20; // 通过指针的方式却更改了num的值, 这是不安全的
    printf("%d\n", num);

    const int num = 10;
    // const修饰指针变量的时候
    // const如果放在*的左边, 修饰的是*p, 表示指针指向的内容, 是不能通过指针来改变的
    // 但是指针变量本身是可以修改的
    const int *p = &num;
    *p = 20; // error: 这样就实现了const修饰的常变量不能修改
    int n = 100;
    p = &n; // 不报错, 不限制指针变量(p)的值, 只是限制指针指向内容(*p)不能改变.
    printf("%d\n", num);

    const int num = 10;
    // const修饰指针变量的时候
    // const如果放在*的右边, 修饰的是指针变量p, 表示指针变量不能被改变
    // 但是指针指向的内容,可以被改变
    int *const p = &num;
    *p = 20; // ok
    int n = 100;
    p = &n; // error
    printf("%d\n", num);

    return 0;
}
