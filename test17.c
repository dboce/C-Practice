/// 函数\数组
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d%d", &num1, &num2);

    // int sum = num1 +num2;
    // 函数的方式解决
    int sum = Add(num1, num2);


    //数组 - 一组相同类型的元素的集合
    //10个整形1-10存起来
    //数组是用下标来访问的
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    while (i<10)
    {
        printf("%d",arr[i]);
        i++;
    }
    //char ch[5] = {'a','b','c'};//不完全初始化,剩余的默认为0
    

    return 0;
}

int Add(int x, int y)
{
    int z = 0;
    z = x + y;
    return z;
}
