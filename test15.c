/// 选择语句
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int coding = 0;
    printf("你会去敲代码吗?(选择1or0):>");
    scanf("%d", &coding);
    if (coding == 1)
    {
        printf("坚持, 你会有好offer\n");
    }
    else
    {
        printf("放弃,回家卖红薯\n");
    }

    return 0;
}
