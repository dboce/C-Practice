#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
/// 操作符详解 1
/*操作符分类:
    算术操作符
        + - * / %
    移位操作符
        >>  <<
    位操作符
        &按位与  |按位或  ^按位异或
    赋值操作符
    单目操作符
    关系操作符
    逻辑操作符
    条件操作符
    逗号表达式
    下标引用/函数调用和结构成员
*/

int main(int argc, char const *argv[])
{
    /// 除法
    int a = 3 / 5; // 0; 因为除号左右都是整数, 商0余3
    printf("%d\n", a);

    float a = 6 / 5; // 1.000000; 因为除号左右都是整数
    printf("%f\n", a);

    // 想得到浮点数, 就要保证除数/被除数至少有一个是浮点数
    double a = 6 / 5.0; // 1.200000; 5.0是double类型, 用float接收会报丢失精度
    printf("%lf\n", a);

    float a = 6.0f / 5.0f; // 1.200000
    printf("%f\n", a);

    /// 取模 %
    int a = 7 % 3; // %操作符的两个操作数为整数. 返回的是整除之后的余数.

    /// 移位操作符 (操作数必须是整数)
    int a = 2; // 4个字节(32个比特位)
    // 把a的二进制位向左移动一位
    int b = a << 1;
    // 000000000000000000000000000000010 //2
    // 000000000000000000000000000000100 //4
    // 左移操作符的规则: 左边丢弃, 右边补0

    int a = 10;
    // 把a的二进制位向右移动一位
    int b = a >> 1;
    // 000000000000000000000000000001010 //10
    // 000000000000000000000000000000101 //5
    /* 右移操作符的规则:(通常是算术右移)
    1. 算术右移
        右边丢弃, 左边补原符号位
    2. 逻辑右移
        右边丢弃, 左边补0
    */
    int a = -1;
    // 把a的二进制位向右移动一位
    int b = a >> 1;
    printf("%d\n", b); //-1  ;当前右移操作符使用的: 算术右移
    /*负数: -1
    存放在内存中, 存放的是二进制的补码

    整数的二进制表示形式, 其实有3种:
    原码
        直接根据数值写出的二进制序列就是原码
    反码
        原码的符号位不变, 其他位按位取反就是反码
    补码
        反码+1,就是补码

    -1的原码: 100000000000000000000000000000001
    -1的反码: 111111111111111111111111111111110
    -1的补码: 111111111111111111111111111111111

    // 右移其实对补码就行了右移
    -1右移后: 111111111111111111111111111111111

    上面的原码/反码/补码是针对负数的; 对于正整数来说, 原码/反码/补码相同.
    */

    /// 位操作符 (它们的操作数必须是整数)
    int a = 3;
    int b = 5;
    // & - 按(2进制)位与
    int c = a & b;
    printf("c = %d\n", c); // 1
    // 000000000000000000000000000000011 //3
    // 000000000000000000000000000000101 //5
    // 000000000000000000000000000000001 //1 按位与

    // | - 按(2进制)位或
    int c = a | b;
    printf("c = %d\n", c); // 7
    // 000000000000000000000000000000011 //3
    // 000000000000000000000000000000101 //5
    // 000000000000000000000000000000111 //7 按位或

    // ^ - 按(2进制)位异或
    // 对应的二进制位进行异或, 规则: 相同为0, 相异为1
    int c = a ^ b;
    printf("c = %d\n", c); // 7
    // 000000000000000000000000000000011 //3
    // 000000000000000000000000000000101 //5
    // 000000000000000000000000000000110 //6 按位异或

    // 习题一: 交互两个int变量的值, 不能使用第三个变量, 即a=3,b=5,交换之后a=5,b=3;
    int a = 3;
    int b = 5;
    printf("a = %d b = %d\n", a, b); // a = 3 b = 5
    // 交换
    //  方法一: 不满足要求:使用了第三个变量
    //  int c = 0;//空瓶
    //  c = a;
    //  a = b;
    //  b = c;

    // 方法二: 缺点是数值太大会溢出
    // a = a + b;
    // b = a - b;
    // a = a - b;

    // 方法三: 异或一下
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    // a ^ b ^ b == a

    printf("a = %d b = %d\n", a, b); // a = 5 b = 3

    // 习题二: 求一个整数存储在内存中的二进制中1的个数
    // 方法1
    int num = 10;
    int count = 0; // 计数
    while (num)
    {
        if (num % 2 == 1)
            count++;
        num = num / 2;
    }
    printf("二进制中1的个数 = %d\n", count);
    // 思考这样的实现方式有没有问题?

    // 方式2
    int num = -1;
    int i = 0;
    int count = 0; // 计数
    for (i = 0; i < 32; i++)
    {
        if (((num >> i) & 1) == 1)
            count++;
    }
    printf("二进制中1的个数 = %d\n", count);
    // 思考还能不能优化, 这里必须循环32次的.

    // 方法3
    int num = -1;
    int i = 0;
    int count = 0; // 计数
    while (num)
    {
        count++;
        num = num & (num - 1);
    }
    printf("二进制中1的个数 = %d\n", count);
    // 这种方式是不是很好? 达到了优化的效果, 但是难以想到

    return 0;
}
