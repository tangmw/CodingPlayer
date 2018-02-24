/*******************************************************************************************
【2路--归并排序】
原理：
假设初始序列含有n个元素，则可看成以各个元素为单位是n个有序子序列，每个子序列长度为1，然后
两两归并，n个有序子序列就变成了n/2个有序子序列，再两两归并，...，如此重复，直到得到一个长
度为n的有序序列为止。

归并排序的两种实现形式：递归实现和非递归实现

递归实现复杂度：时间复杂度为O(nlogn)
                 空间复杂度为O(n+logn)
Author:tmw
date:2017-11-4
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***递归方法实现归并排序****/
//函数功能：将两个有序表变成一个有序表
//合并
void merge( int array[] , int left , int middle , int right )
{
    int left_len = middle - left;
    int right_len = right - middle - 1;
    int left_array[left_len];
    int right_array[right_len];
    int i,j,k;

    //单独摘出两个有序序列
    for( i = 0 ; i <= left_len ; i++ )
        left_array[i] = array[i+left];

    for( j = 0 ; j <= right_len ; j++)
        right_array[j] = array[j+middle+1];

    //将两个有序序列变成一个有序序列
    //注意：因为后面的排序函数一直是对array数组的递归，因此排序至始至终是对array数组进行，
    //array数组元素的位置变化必须体现在array数组里，不能用别的变量代替!!!
    k = left;
    i = 0;j = 0;
    while( i <= left_len && j <= right_len )
    {
        if( left_array[i] < right_array[j] )
            array[k++] = left_array[i++];
        else
            array[k++] = right_array[j++];
    }
    while( i <= left_len )
        array[k++] = left_array[i++];
    while( j <= right_len )
        array[k++] = right_array[j++];
}

//merge_sort()先排序，再合并
void merge_sort( int array[] , int left , int right )
{
    int middle;
    if( left < right )
    {
        middle = ( left + right ) / 2;
        // 分解 + 解决：Divide + Conquer
        merge_sort( array , left , middle );
        merge_sort( array , middle+1 , right );
        // 合并：Combine
        merge( array , left , middle , right );
    }
}

int main()
{
    int *array;
    int i,array_size;
    printf("请输入数组元素的个数:\n");
    scanf("%d",&array_size);

    array = (int*)malloc(sizeof(int));
    printf("请输入 %d 个元素\n",array_size);
    for( i = 0 ; i < array_size ; i++ )
        scanf("%d",&array[i]);

    merge_sort( array , 0 , array_size-1 );
    printf("经归并排序后，数组元素顺序输出为：\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
