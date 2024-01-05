/// 关键字2
#include <stdio.h>

// typedef: 类型重命名
typedef unsigned int u_int;

void test()
{
    static int a = 1; // 改变了局部变量的生命周期
    a++;
    printf("%d", a); // 打印: 2-11

    // int a = 1;
    // a++;
    // printf("%d", a); // 打印: 10个2
}

int main(int argc, char const *argv[])
{
    unsigned int num = 100;
    u_int num2 = 100;

    /*staitc - 静态的
    1. static修饰局部变量
        改变了局部变量的生命周期(本质上改变了变量的储存类型)
        一开始在栈区,被static修饰之后进入了静态区
    2. staitc修饰全局变量
        使得这个全局变量只能在自己所在的源文件(.c)内部可以使用, 其他源文件不能使用!
        全局变量在其他源文件中可以被使用,是因为全局变量具有外部链接属性.
            但是被staitc修饰之后,就变成了内部链接属性,其他源文件就不能链接到这个静态全局变量了!
    3. staitc修饰函数
        使得函数只能在自己的源文件内部使用,不能在其他源文件内部使用
        本质上: staitc是将内部的外部链接属性变成了内部链接属性(与修饰全局变量很类似)

    内存分为几个区:
    栈区
        局部变量
        函数的参数
    堆区
        动态内存分配的
    静态区
        全局变量
        static修饰的静态变量
    */
    int i = 0;
    while (i < 10)
    {
        test();
        i++;
    }

    return 0;
}