#define _CRT_SECURE_NO_WARNINGS 1

int Divide(int x, int y)
{
    return x + y;
}

// 右击项目名称 > 属性 > 常规 > 配置类型 > 改一下"应用程序(.exe)"为"静态库(.lib)" 
// 编译之后, 在A项目目录的"Debug"文件夹下会出现一个xxx.lib文件, 这是编译产生的静态库
// 静态库打开后是二进制的乱码
// A 卖给别人, 只需要将 divide.h 和 divide.lib 给别人就行了, 无需给源码.