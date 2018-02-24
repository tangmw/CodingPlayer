/***********************************************
【问题描述】
一个台阶总共有n级，如果一次可以跳1级，也可以跳2级，求总共有多少种跳法

通过枚举可以发现：台阶级数和跳法有如下关系
级数 0 1 2 3 4 5 6  7  8
跳法 0 1 2 3 5 8 13 21 35...

从这个规律来看，可以发现，从第三级开始，跳法是一个斐波拉契数列

Author:tmw
date:2017-11-23
************************************************/
#include <stdio.h>
#include <stdlib.h>

int jump_stairs_fibonacci(int n)
{
    int F[100];
    F[0] = 0;F[1] = 1;F[2] = 2;
    if(n<=2)
        return F[n];
    else
        return jump_stairs_fibonacci(n-1) + jump_stairs_fibonacci(n-2);
}

int main()
{
    printf("测试代码!\n");
    int n1,n2,n3,res1,res2,res3;

    n1=5;
    res1 = jump_stairs_fibonacci(n1);
    printf("跳%d个台阶共有%d种跳法\n",n1,res1);

    n2=10;
    res2 = jump_stairs_fibonacci(n2);
    printf("跳%d个台阶共有%d种跳法\n",n2,res2);

    n3=45;
    res3 = jump_stairs_fibonacci(n3);
    printf("跳%d个台阶共有%d种跳法\n",n3,res3);

    return 0;
}
