/// 什么是常量

// C语言中的常量分为以下几种:
// 字面常量/const修饰的常量/#define定义的标识符常量/枚举常量
#include <stdio.h>

#define MAX 10000

// 枚举-性别
enum Sex
{
    // 这种枚举类型的变量未来可能取值
    // 枚举常量
    MALE = 3,   // 赋初值,默认从0开始
    FEMALE, // 4
    SECRET  // 5
};

int main(int argc, char const *argv[])
{
    // 1. 字面常量
    // 3.14;
    // 10;
    // 'a';
    // "abcdef";

    // 2. const修饰的常变量: 本质上是个变量
    const int num = 10; // num就是常变量 - 具有常属性(不能被改变的属性)
    // num = 20;
    printf("num = %d\n", num); // 10

    int arr[10] = {0}; // 10个元素

    const int n = 10;
    // int arr2[n] = {0}; // n是常变量,这里是报错的

    // 3.#define定义的标识符常量
    // MAX = 20000;//error
    int d = MAX;
    printf("d = %d\n", d);

    // 4.枚举常量
    // 可以一一列举的常量
    enum Sex s = MALE;
    printf("%d\n", MALE);
    printf("%d\n", FEMALE);
    printf("%d\n", SECRET);

    return 0;
}
