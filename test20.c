/// 常见关键字
/**
 * auto break case char const continue default do double eles
 * enum extern float for goto if int logn register return short
 * signed sizeof static struct switch typedef union unsigned
 * void volatile while
 *
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* C语言提供的关键字
    1. c语言提供的,

     */

    // auto 是自动的 - 每个局部变量都是auto修饰的
    auto int a = 10; // 自动创建,自动销毁的-自动变量, auto一般都省略写

    // extern 是用来声明外部符号的

    // register 寄存器关键字: 大量频繁被使用的数据,想放在寄存器中,提高效率
    register int num = 100; // 建议num的值存放在寄存器中
    // 是不是最终放到寄存器中,由编译器决定
    /*计算机中数据可以存储到哪里呢?
    1.寄存器    更小
    2.高速缓存  几十MB
    3.内存  8G-16G
    4.硬盘  500G - 买的
    5.网盘  2T-免费
    */

    // signed\unsigned  有符号无符号  10 -10

    // union 联合体(共用体)
    return 0;
}
