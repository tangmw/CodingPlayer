/***********************************************
【问题描述】
一个台阶总共有n级，如果一次可以跳1级，也可以跳2级，求总共有多少种跳法

通过枚举可以发现：台阶级数和跳法有如下关系
级数 0 1 2 3 4 5 6  7  8
跳法 0 1 2 3 5 8 13 21 35...

同样是斐波拉契数列，采用递归会发现，越到递归的后面，它的重复计算很多，
时间花费比较大，因此采用递推，每个位置的值只需算一次，大大节省了时间

Author:tmw
date:2017-11-23
************************************************/
#include <stdio.h>
#include <stdlib.h>

int jump_stairs_fibonacci_recursive(int n)
{
    int a[3] = {0,1,2};//规律之外的额外列出
    if(n<3)
        return a[n];
    int i;
    int front_1 = 1;//当前所求值的前两位
    int front_2 = 2;//当前所求值的前一位
    int current;//当前所求值
    for(i=2;i<n;i++)
    {
        current = front_1+front_2;
        front_1=front_2;//更新front_1,相当于游标下移
        front_2=current;//更新front_2，相当于游标下移
    }

    return current;
}

int main()
{
    printf("测试代码!\n");
    int n1,n2,n3,res1,res2,res3;

    n1=5;
    res1 = jump_stairs_fibonacci_recursive(n1);
    printf("跳%d个台阶共有%d种跳法\n",n1,res1);

    n2=10;
    res2 = jump_stairs_fibonacci_recursive(n2);
    printf("跳%d个台阶共有%d种跳法\n",n2,res2);

    n3=45;
    res3 = jump_stairs_fibonacci_recursive(n3);
    printf("跳%d个台阶共有%d种跳法\n",n3,res3);

    return 0;
}
