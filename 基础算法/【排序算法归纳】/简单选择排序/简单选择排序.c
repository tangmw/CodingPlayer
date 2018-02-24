/*******************************************************************************************
【直接选择排序】
基本思想：通过n-1次关键字比较，从n-i-1个记录中选出最小的关键字，当这个最小关键字不在i位
置时，和第i个位置的关键字记录交换

【算法复杂度分析】
1、从交换移动次数分析：
1）当最好的情况，交换移动次数为0；
2）当最坏的情况，也就是初始降序，交换移动次数为（n-1）次
2、从比较次数分析
    比较次数为：1+2+3+...+(n-1) = n*(n-1)/2次

所以总的时间复杂度还是为O(n^2),但是它总的性能比冒泡排序好一些
Author:tmw
date:2017-10-31
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int* simple_select_sort( int array[] , int array_size )
{
    int i,j,min,temp;
    for( i = 0 ; i < array_size ; i++ )
    {
        min = i;
        for( j = i+1 ; j < array_size ; j++ )
        {
            if( array[min] > array[j] )
                min = j;
        }//记录每一轮i后最小值的下标
        if( i!=min )//如果下标发生改变，则将min位置的数与i位置的数交换，反之则不交换
        {
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }//每一轮i最多交换一次，最终循环下来，最多循环n-1次
    }
    return array;
}
int main()
{
    int *array;
    int array_size,i;

    printf("请输入数组大小\n");
    scanf("%d",&array_size);

    printf("请输入 %d 个数组元素\n",array_size);
    array = (int*)malloc(array_size*sizeof(int));
    for( i = 0 ; i < array_size ; i++ )
        scanf("%d",&array[i]);

    array = simple_select_sort(array,array_size);
    printf("经直接选择排序后，顺序输出为：\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);

    return 0;
}
