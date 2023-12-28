/// 常量变量
#define _CRT_SECURE_NO_WARNINGS 1 // 放在源文件的第一行
#include <stdio.h>

//全局变量 - {}外部定义的
int a = 100;

int main(int argc, char const *argv[]) {
  //创建一个变量
  // 类型 变量的名字 = 0; //推荐
  // 类型 变量的名字; //不推荐
  int age = 20;
  double weight = 75.3;

  age = age + 1;
  weight = weight - 10;
  printf("%d\n", age);
  printf("%lf\n", weight);

  //局部变量
  //当局部变量和全局变量名字冲突的情况下,局部优先
  int a = 10; //大括号内部定义的变量都是局部变量

  return 0;
}

int main(int argc, char const *argv[])
{
    int a = 0;
    int b = 0;
    int sum = 0;
    scanf("%d %d", &a, &b); // scanf函数是VS编译器提供的,不是C语言标准规定的
    sum = a + b;
    printf("sum = %d\n", sum);

    return 0;
}
