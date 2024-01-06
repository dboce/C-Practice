#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 操作符详解 5

int fun()
{
    static int count = 1; // 被static修饰第一次创建时赋值1, 再次调用时不会再重新创建赋值, 而是直接使用保存的值2
    return ++count;
}

int main(int argc, char const *argv[])
{
    /* 算术转换
    如果某个操作符的各个操作数属于不同的类型,
    那么除非其中一个操作数的转换为另一个操作数的类型, 否则操作就无法进行

    下面的层次体系称为"寻常算术转换":
    long double
    double
    float
    unsigned long int
    long int
    unsigned int
    int

    如果某个操作数的类型在上面这个列表中排名较低, 那么首先要转换为另外一个操作数的类型后执行运算.
    向上转换, 比如: 如果一个int类型遇到一个float类型运算, int要转换位float类型进行运算.
    */
    float f = 3.14;
    int num = f; // 隐式转换, 会有精度丢失

    /*操作符的属性
    复杂表达式的求值有三个影响的因素.
        1.操作符的优先级
        2.操作符的结合性
        3.是否控制求值顺序.
    两个相邻的操作符先执行哪个? 取决于他们的优先级. 如果两者的优先级相同, 取决于他们的结合性.
    */
    int a = 4;
    int b = 5;
    // int c = a + b * 7; //优先级决定了计算顺序
    int c = a + b + 7; // 优先级不起作用, 结合性决定了顺序

    // 问题代码示例:
    int answer;
    answer = fun() - fun() * fun();
    printf("%d\n", answer); // 2 - 3 * 4 = -10
                            // 函数的调用先后顺序无法通过操作符的优先级确定

    /*计算机的寄存器:
    eax
    ebx
    ecx
    edx
    ebp
    esp
    */

    // 练习一: 代码的输出结果是多少?
    int arr[] = {1, 2, (3, 4), 5}; // (3,4)是逗号表达式, 逗号表达式的结果是最后一个数, 4
    printf("%d\n", sizeof(arr));   // 4*4 = 16

    // 练习二: 代码的输出结果是多少?
    char str[] = "hello bit"; // 数组里面放的内容是 [hello bit\0]
    printf("%d %d\n", sizeof(str), strlen(str));// 10 9
    // sizeof计算的是数组的总大小: 10
    // strlen计算时,\0不算计算的长度

    //strlen - 函数 - 求字符串长度的(找\0之前出现的字符个数)
    //sizeof - 操作符 - 计算变量/类型所占内存大小, 单位是字节
    
    return 0;
}
