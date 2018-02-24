/*******************************************************************************************
Author:tmw
date:2017-11-5
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>


/**快速排序优化----三数取中&&优化不必要的交换**/
//取三个元素先进行排序，将中间值作为中轴元素，选取左端、右端、中间三个数，也可以随机选取
int Three_choose_one_optimize_fastSort( int array[] , int low , int high )
{
    int mid = ( low + high ) / 2;
    if( array[high] < array[low] )
    {
        int temp1;
        temp1 = array[high];
        array[high] = array[low];
        array[low] = temp1;
    }
    if( array[high] < array[mid] )
    {
        int temp2;
        temp2 = array[high];
        array[high] = array[mid];
        array[mid] = temp2;
    }//以上，保证high为三个值当中最大值的下标
    if( array[mid] > array[low] )//将low作为中间值的下标
    {
        int temp3;
        temp3 = array[low];
        array[low] = array[mid];
        array[mid] = temp3;
    }//以上，完成了三数取中，此时array[low]即可作为快排优化后的中轴元素

    int target = 0;
    target = array[low];

    while( low < high )
    {
        while( low < high && array[high] >= target  )
            high--;
        array[low] = array[high];//此时high位置上的元素为待处理元素

        while( low < high && array[low] <= target   )
            low++;
        array[high] = array[low];//将大于target值的元素放到待处理的high位置上，那么此时,low位置变为待处理
    }
    array[low] = target; //以上，省去交换，变为“挖坑赋值”，降低时间复杂度
    return low;
}
void fast_sort( int array[] , int low , int high )
{
    if( low < high )
    {
        int index;
        index = Three_choose_one_optimize_fastSort(array,low,high);
        fast_sort(array,low,index-1);
        fast_sort(array,index+1,high);
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

    fast_sort( array , 0 , array_size-1 );
    printf("经优化后的快速排序，数组元素顺序输出为：\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
