/*******************************************************************************************
【直接插入排序】
基本思想：将一个记录插入到已经排好序的有序表中，从而得到一个新的，记录增1的表
时间复杂度为O(n^2),但是它总的性能比冒泡排序和简单选择排序好一些
Author:tmw
date:2017-10-31
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int* direct_insert_sort( int array[] , int array_size )
{
    array[0] = 0;//数组的第一位用来做temp,相当于在数组首位挖了个坑

    int i,j;
    for( i = 2 ; i <= array_size ; i++ )//刚开始，认为第一个数即为有序的
    {
        if( array[i] < array[i-1] )//后一个元素比前一个元素小，则需要移动位置了，同时往首位填坑,如此循环
        {
            array[0] = array[i];
            for( j = i-1 ; array[j] > array[0] ; j-- )
                array[j+1] = array[j];
            array[j+1] = array[0];//将当前i所指向的元素放入正确的位置
        }
    }
    return array;
}

int main()
{
    int *array;
    int i,array_size;
    printf("请输入数组元素的个数\n");
    scanf("%d",&array_size);

    array = (int*)malloc(sizeof(int));
    printf("请输入 %d 个元素\n",array_size);
    for( i = 1 ; i <= array_size ; i++ )
        scanf("%d",&array[i]);

    array = direct_insert_sort( array , array_size );
    printf("经直接插入排序后，数组元素顺序输出为：\n");
    for( i = 1 ; i <= array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
