/***********************************************
【问题描述】
有一个长度为2n的数组{a1,a2,a3,...an,b1,b2,b3,...,bn},希望排序后变成{a1,b1,a2,b2,...,an,bn}，
请考虑有没有时间复杂度为O(n)，空间复杂度为O(1)的解法

下面继续简化问题，换一种方式再实现一个时间复杂度为O(n^2)，空间复杂度为O(1)的算法，
本算法参考july《编程之法》给的第二条思路，笔者在这里做一个代码的复现；

算法思想：
算法准备：定义两个游标from,to，from的起始位置在n，to的起始位置在n+1---也就是两半数组的各自尾和首；
           再定义一个游标i,i的起始位置在from，终止位置在i，负责标记两两交换的元素
step1i从from位置出发，每次跳两个元素，交换i和i+1位置上的元素,直到to位置结束
step2:from--,to++
。。。
直到from,to游标分别指向第二个元素和倒数第二个元素为止，算法结束

Author:tmw
date:2017-11-28
************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t)

int* shuffle2_swap_middle2sides( int* array , int n )
{
    int from = n-1;
    int to = n;

    int temp;
    while( from > 0 && to < 2*n-1 )//循环交换的条件是：from没有走到数组的第一个元素，to没有走到数组的最后一个元素--第一个和最后一个不需要交换
    {
        int i = from;
        for( i = from ; i < to ; i = i+2 )
            swap(array[i],array[i+1],temp);//交换从左到右开始
        from--;
        to++;
    }
    return array;
}


int main()
{
    printf("测试程序!\n");
    int i;

    int array[10] ={1,2,3,4,5,11,22,33,44,55};
    printf("原数组为：");
    for(i=0;i<10;i++)
        printf("%d ",array[i]);
    printf("\n");

    shuffle2_swap_middle2sides(array,5);

    printf("洗牌后的数组为：");
    for(i=0;i<10;i++)
        printf("%d ",array[i]);
    printf("\n");

    return 0;
}
