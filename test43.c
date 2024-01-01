#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// 自定义函数
/*函数的组成
ret_type fun_name(para1, *)
{
    statement; //语句项
}
ret_type 返回类型
fun_name 函数名
para1 函数参数
*/

int get_max(int x, int y)
{
    int z = 0;
    if (x > y)
        z = x;
    else
        z = y;
    return z; // 返回z-返回最大值
}

void Swap(int *pa, int *pb)
{ // 不是交换地址,是交换值
    int z = 0;
    z = *pa;
    *pa = *pb;
    *pb = z;
}

int main(int argc, char const *argv[])
{
    // 写一个函数可以找出两个整数中的最大值.
    int a = 10;
    int b = 20;
    // 函数的调用
    int max = get_max(a, b);
    printf("max = %d\n", max);

    // 写一个函数 - 交换2个整形变量的值
    printf("交换前: a=%d b=%d\n", a, b);
    Swap(&a, &b);//传址调用
    printf("交换后: a=%d b=%d\n", a, b);

    return 0;
}
/*
实际参数(实参):
    真实传给函数的参数, 叫实参.实参可以是:常量\变量\表达式\函数等.
形式参数(形参):
    形式参数指函数名后括号中的变量, 因为形式参数只有在函数被调用的过程中才实例化(分配内存单元),所以叫形式参数.
    形参当函数调用完成之后就会自动销毁.因此形参仅在函数中有效.
其实形参是实参的一份临时拷贝, 改变形参, 不能改变实参.
*/
