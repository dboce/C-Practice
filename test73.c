#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 操作符详解 3
/*操作符分类:
    算术操作符
        + - * / %
    移位操作符
        >>  <<
    位操作符
        &按位与  |按位或  ^按位异或
    赋值操作符
        = += -= *= /= >>=  <<= %= |= ^=
    单目操作符
        ! 逻辑反操作
        - + & sizeof ~ -- ++
        * 间接访问操作符(解引用操作符)
        (类型) 强制类型转换
    关系操作符
        > >= < <= != ==
    逻辑操作符
        &&  ||
    条件操作符
        三目操作符
    逗号表达式
    下标引用/函数调用和结构成员
*/

void test1(int arr[])
{
    printf("%d\n", sizeof(arr)); // 4/8 - 首元素的地址
}

void test2(char ch[])
{
    printf("%d\n", sizeof(ch)); // 4/8 - 首元素的地址
}

int main(int argc, char const *argv[])
{
    int a = 10;
    printf("%p\n", &a); // & - 取地址操作符
    int *pa = &a;       // pa是用来存放地址的 - *表示:pa是一个指针变量
    *pa = 20;           // * - 解引用操作符 - 间接访问操作符
    printf("%p\n", &a); // 20

    // 强制类型转换
    int a = (int)3.14; // 3.14强制类型转换为int类型

    // sizeof
    int arr[10] = {0};
    char ch[10] = {0};
    printf("%d\n", sizeof(arr)); // 40
    printf("%d\n", sizeof(ch));  // 10
    test1(arr);
    test2(ch);

    /// 关系操作符
    // 比较2个字符串相等, 不能使用 ==

    /// 逻辑操作符
    // 只关注真假
    int i = 0, a = 0, b = 2, c = 3, d = 4;
    i = a++ && ++b && d++; // a++ 为0, && 后面的就不会再判断计算真假
    // i = a++ || ++b || d++; // 1 3 3 4
    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d); // 1 2 3 4
    // 解析:比如 int c = a && b; 如果a为0, 则c为0, 那么&&后面不会再计算
    // 同理比如 int c = a || b; 如果a为真, 则c为真, 那么||后面不会再计算

    /// 三目操作符
    int a = 3;
    int b = 0;

    if (a > 5)
        b = 1;
    else
        b = -1;
    // 使用三目操作符
    b = (a > 5 ? 1 : -1);

    /// 逗号表达式
    // 要从左向右依次计算, 但是整个表达式的结果是最后一个表达式的结果
    int a = 3;
    int b = 5;
    int c = 0;
    int d = (c = 5, a = c + 3, b = a - 4, c += 5);
    printf("%d\n", d); // 10

    // 逗号表达式示例一:
    a = get_val();
    count_val(a);
    while (a > 0)
    {
        // 业务处理
        a = get_val();
        count_val(a);
    }
    // 如果使用逗号表达式, 改写:
    while (a = get_val(), count_val(a), a > 0)
    {
        // 业务代码
    }

    return 0;
}
