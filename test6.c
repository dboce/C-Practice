/// 数据类型
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 计算机中最小的单位:bit - 比特位
    // 计算机中识别二进制: 0 1
    // 一个比特是用来存放一个二进制位
    // 1 byte(字节) = 8 bit
    // 1 kb = 1024 byte
    // 1 mb = 1024 kb
    // 1 gb = 1024 mb
    // 1 tb = 1024 gb
    // 1 pb = 1024 tb

    //sizeof的单位是字节byte
    printf("%d\n",sizeof(char)); // 1个字节
    printf("%d\n",sizeof(short));// 2个字节
    printf("%d\n",sizeof(int));// 4个字节
    printf("%d\n",sizeof(long));// 4个字节
    printf("%d\n",sizeof(long long));// 8个字节
    printf("%d\n",sizeof(float));// 4个字节
    printf("%d\n",sizeof(double));// 8个字节

    return 0;
}

// clang --version #查看clang版本
// whereis clang++ #查看C++的路径

// 远程:
// sudo apt-get update #安装gcc
// gcc -v #查看版本
// clangd --version
// sudo apt-get install clangd

