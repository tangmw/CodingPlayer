/***********************************************
【问题描述】
给定一个整数数组，请调整数组中数的顺序，使得所有奇数位于
数组的前半部分，所有的偶数位于数组的后半部分，要求时间复杂度
为O(n)

结合快速排序的思想：一次快排能将小于中轴元素的值全放左边，大于中轴元素的值全放右边，
那么推而言之，一次快排，也可以让所有奇数位于前半部分，所有偶数位于后半部分

下面的代码用的方法是一次快排中的“两头往中间搜索”的方法

Author:tmw
date:2017-11-23
************************************************/
#include <stdio.h>
#include <stdlib.h>

int* odd_even_sort_like_qsort(int *array , int array_len)
{
    //输入合法性检查
    if(!array||array_len==0)
        return NULL;
    int low = 0;
    int high = array_len-1;
    int target = array[low];//取第一个数作为中枢元素，备份
    while( low < high )
    {
        while( array[high]%2 == 0 && low < high )//后半部分为偶数
            high--;
        array[low] = array[high];
        while( array[low]%2 != 0 && low < high )
            low++;
        array[high] = array[low];
    }
    array[low] = target;//类快排，不需要递归，一次性就做完了所有奇数位于数组的前半部分，所有的偶数位于数组的后半部分
    return array;
}

int main()
{
    printf("测试代码！\n");
    int i;

    int a1[10] = {6,2,3,4,7,8,1,0,-1,-5};
    printf("原数组为：");
    for(i=0;i<10;i++)
        printf("%d ",a1[i]);
    printf("\n");
    printf("奇偶排序后为：");
    odd_even_sort_like_qsort(a1,10);
    for(i=0;i<10;i++)
        printf("%d ",a1[i]);
    printf("\n");

    int a2[16] = {23,3,28,5,6,100,54,-2,-17,2,-36,0,26,-11,9,16};
    printf("原数组为：");
    for(i=0;i<16;i++)
        printf("%d ",a2[i]);
    printf("\n");
    printf("奇偶排序后为：");
    odd_even_sort_like_qsort(a2,16);
    for(i=0;i<16;i++)
        printf("%d ",a2[i]);
    printf("\n");

    return 0;
}
