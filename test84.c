#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// 结构体初阶

// struct Node
// {
//     int data;
//     struct Point p;
//     struct Node *next;
// } n1 = {10, {4, 5}, NULL}; // 结构体嵌套初始化

struct B
{
    char c;
    short s;
    double d;
};

struct Stu
{
    // 成员变量
    struct B sb;   // 另外一个结构体作为成员变量
    char name[20]; // 名字
    int age;       // 年龄
    char id[20];
} s1, s2; // s1和s2也是结构体的变量(声明类型的同时定义变量s1,s2)
// s1,s2是全局变量

void print1(struct Stu t)
{
    printf("%c %d %lf %s %d %s\n", t.sb.c, t.sb.s, t.sb.d, t.name, t.age, t.id);
}

void print2(struct Stu *ps)
{
    printf("%c %d %lf %s %d %s\n", ps->sb.c, ps->sb.s, ps->sb.d, ps->name, ps->age, ps->id);
}

int main(int argc, char const *argv[])
{
    // s是局部变量
    struct Stu s = {{'w', 20, 3.14}, "张三", 30, "202000503"}; // 对象
    // 结构体的初始化也是用{}

    /// 结构体成员访问 . ->
    printf("%c", s.sb.c);
    printf("%s", s.id);

    struct Stu *ps = &s;
    printf("%c", (*ps).sb.c);
    printf("%c", ps->sb.c);

    /// 写一个函数打印s的内容
    print1(s);  // 传值调用 (传过去的数据要重新开辟空间,时间和空间都有浪费)
    print2(&s); // 传址调用(推荐: 传参效率高一些)
    // 函数的传参的时候, 参数是需要压栈的.如果传递一个结构体对象的时候, 结构体过大, 参数压栈的系统开销比较大, 所以会导致性能下降.
    // 结论: 结构体传参的时候, 要传结构体的地址.

    /// 什么叫函数调用的参数压栈?
    /*
    栈, 是一种数据结构
    栈的特点: 先进的后出, 后进的先出
        给栈存放数据, 叫做压栈;
        释放数据, 叫做出栈

    每一个函数调用, 都会在内存的栈区上开辟一块儿空间!
    */

    return 0;
}
