/***********************************************
【问题描述】
有一个长度为2n的数组{a1,a2,a3,...an,b1,b2,b3,...,bn},希望排序后变成{a1,b1,a2,b2,...,an,bn}，
请考虑有没有时间复杂度为O(n)，空间复杂度为O(1)的解法

此问题将时间复杂度和空间复杂度都定死了，笔者为了满足这个要求废了不少脑细胞也---没想出来。。
现暂时抛开复杂度设定，从简单易实现的解法出发，先实现一个时间复杂度为O(n^2)，空间复杂度为O(1)的算法

算法思想
算法准备：设计两个游标i和j，i起始位置从数组第二个元素开始，j起始位置从n+1开始（总元素为2*n）
step1:把j位置的元素抽取出来，将i之后的元素（包含i）到j之前的元素（不包含j）挨个向后挪一个位置
step2:i游标向后移2位，j游标向后移1位
step3:重复前两个步骤，直到i和j相等，算法结束

Author:tmw
date:2017-11-27
************************************************/
#include <stdio.h>
#include <stdlib.h>

int* shuffle1_Choose_Move(int* array , int n )//数组总长为2*n
{
    int i=1;
    int j=n;
    int k;

    while( i != j )
    {
        int temp = array[j];//抽取第n+1个位置的元素
        for( k = j-1 ; k >= i ; k-- )//元素往后挪动
            array[k+1] = array[k];
        array[i] = temp;//挪完后，此时原来的i位置填上抽取的元素，完成一次抽取+移动操作

        i = i + 2;
        j++;
    }
    //跳出while循环，此时i==j，数组更新完成
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

    shuffle1_Choose_Move(array,5);

    printf("洗牌后的数组为：");
    for(i=0;i<10;i++)
        printf("%d ",array[i]);
    printf("\n");

    return 0;
}
