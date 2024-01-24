#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/// 调试模拟实现字符串相关函数

// 方式一:
int my_strlen(const char *str) // 健壮性(鲁棒性)
{
    // assert(str != NULL); // 注意这里断言指针不为空
    assert(str);
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
// 方式二:
size_t my_strlen(const char *str) // size_t - unsigned int(无符号整型)
{
    // assert(str != NULL); // 注意这里断言指针不为空
    assert(str);
    size_t count = 0;
    while (*str++)
    {
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    char arr[] = "abc";
    int len = strlen(arr);
    printf("%d\n", len);

    // 模拟实现strlen: 求字符串长度
    printf('%d\n', my_strlen('adbc'));

    //__cdecl -函数调用约定
    /*常见的错误分类
    编译型错误
        直接看错误提示信息(双击),解决问题.或者凭借经验就可以搞定. 相对来说简单.
    链接型错误
        看错误提示信息, 主要在代码中找到错误信息中的标识符, 然后定位问题所在. 一般是标识符名不存在或者拼写错误.
    运行时错误
        借助调试,逐步定位问题. 最难搞.
    */
    return 0;
}
