#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// 指针进阶2

void print1(int arr[3][5], int r, int c)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// p是一个数组指针
void print2(int (*p)[5], int r, int c)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    float f = 9.0f;
    int *p = (int *)&f; // 以整型的形式去看浮点型
    printf("%d\n", *p);

    /*数组指针
    数组指针是指针?还是数组? 答案: 是指针.
        整形指针: int * pint;能够指向整形数据的指针.
        浮点型指针: float * pf;能够指向浮点型数据的指针.
    */
    int a = 10;
    int *pa = &a;
    char ch = 'w';
    char *pc = &ch;

    int arr[10] = {1, 2, 3, 4, 5};
    // arr - 数组名是首元素的地址 - arr[0]
    // &arr - 取出的数组的地址
    int(*parr)[10] = &arr; // parr就是一个数组指针 - 其中存放的是数组地址

    double *d[5];          // 表示: 数组有5个元素, 每个元素是double*类型
    double *(*pd)[5] = &d; // 指针变量pd, 指向一个数组, 数组有5个元素, 每个元素的类型是double*
    // pd就是一个数组指针
    /* int (*p)[10];
    解释: p先和*结合, 说明p是一个指针变量, 然后指针指向的是一个大小为10个整型的数组.
    所以p是一个指针, 指向一个数组, 叫数组指针.

    //这里要注意: []的优先级要高于*号的, 所以必须加上()来保证p先和*结合.
    */

    // &数组名VS数组名
    int arr[10] = {0};
    printf("%p\n", arr);  // 007FF94C
    printf("%p\n", &arr); // 007FF94C
    // 虽然打印地址值一样, 但类型不一样
    // 类似的情况
    char c = 'a'; // 97 - char
    int i = 97;   // 97 - int

    int *p1 = arr;          // 指向数组首元素地址
    int(*p2)[10] = &arr;    // 指向数组
    printf("%p\n", p1);     // 00CFFCF8
    printf("%p\n", p1 + 1); // 00CFFCFC 加1差4个字节
    printf("%p\n", p2);     // 00CFFCF8
    printf("%p\n", p2 + 1); // 00CFFD20 加1差40个字节
    /*
    根据上面的代码我们发现, 其实&arr和arr, 虽然值是一样的, 但意义应该不一样的.
    实际上: &arr表示的是数组的地址, 而不是数组首元素的地址.
    数组的地址+1, 跳过整个数组的大小, 所以&arr+1相对于&arr的差值是40.
    */

    /*数组名是数组首元素的地址, 但是有2个例外:
    1. sizeof(数组名) - 数组名表示整个数组, 计算的是整个数组的大小, 单位是字节
    2. &数组名 - 数组名表示整个数组, 取出的事整个数组的地址
    */

    // 数组指针的使用
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 打印数组元素 - 不好的写法的示范
    int(*pa)[10] = &arr; // 这样使用让取值变的复杂
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *((*pa) + i));
    }

    int arr[3][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
    print1(arr, 3, 5);
    print2(arr, 3, 5); // arr数组名,表示数组首元素的地址

    // 练习:
    int arr[5];         // 整型指针
    int *parr1[10];     // 整型指针的数组
    int(*parr2)[10];    // 数组指针, 该指针能够指向一个数组, 数组10个元素, 每个元素的类型是int
    int(*parr3[10])[5]; // parr3是一个存放数组指针的数组, 该数组能够存放10个数组指针, 每个数组指针能够指向一个数组, 数组5个元素, 每个元素都是int类型

    // 数组参数\指针参数
    // 在写代码的时候难免要把[数组]或者[指针]传给函数, 那函数的参数该如何设计呢?
    // 一维数组传参
    int arr[10] = {0};
    int *arr2[20] = {0}; // arr 是一个存放int*的数组
    test(arr);
    test2(arr2);
    /*
    void test(int arr[]) {}     // ok
    void test(int arr[10]) {}   // ok
    void test(int *arr) {}      // ok
    void test2(int *arr[20]) {} // ok
    void tet2(int **arr) {}     // ok
    */

    // 二维数组
    int arr[3][5] = {0};
    test(arr);
    /*
    void test(int arr[3][5]) {} // ok
    void test(int arr[][]) {}   // err
    void test(int arr[][5]) {}  // ok
    // 总结: 二维数组传参, 函数形参的设计只能省略第一个[]的数字.
    // 因为对一个二维数组, 可以不知道有多少行, 但是必须知道一行有多少元素. 这样才方便计算
    void test(int *arr) {}      // err - 传地址传的是首行的地址, 第一行是5个整型的数组
    void test(int *arr[5]) {}   // err
    void test(int (*arr)[5]) {} // ok
    void test(int **arr) {}     // err -传过去的不是二级指针
    */

    return 0;
}
