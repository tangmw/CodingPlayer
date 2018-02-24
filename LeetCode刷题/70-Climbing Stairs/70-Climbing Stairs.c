/**********************************************************************************************************

LeetCode----[easy] 70-Climbing Stairs.c

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.

[Ans:]
����������̬�滮��
F(0) = 1
F(1) = 1
n>1ʱ������ÿһ��̨��i��Ҫ����̨�ף����һ���������ַ�������i-1��һ�������i-2��������
Ҳ����˵����̨��i�ķ�����=��̨��i-1�ķ�����+��̨��i-2�ķ�����������
F(i) = F(i-1) + F(i-2)
���ԣ��������б���ˣ�1 1 2 3 5 8 ....�����쳲��������� ���n-1��λ���ϵ�ֵ

Author:tmw
date:2017-10-11

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n)
{
    if( n == 0 || n == 1 )
        return 1;
    int i = 0;
    int pre_step1 = 1;//ָ���current_step���Ǹ�Ԫ��
    int pre_step2 = 1;
    int current_step = 0;

    for( i = 2 ; i <= n ; i++ )
    {
        current_step = pre_step1 + pre_step2;
        pre_step2 = pre_step1;
        pre_step1 = current_step;
    }
    return current_step;
}


int main()
{
    int n = 0;
    int result = 0;
    printf("Please input your total steps:\n");
    scanf("%d",&n);
    printf("There are %d ways to climb to the top!\n",result = climbStairs(n));
    return 0;
}
