/*******************************************************************************************
【快速排序】
【原理】
    快速排序的基本思想就是从一个数组中任意挑选一个元素（通常来说会选择最左边的元素）作为
中轴元素，将剩下的元素以中轴元素作为比较的标准，将小于等于中轴元素的放到中轴元素的左边，
将大于中轴元素的放到中轴元素的右边，然后以当前中轴元素的位置为界，将左半部分子数组和右半
部分子数组看成两个新的数组，重复上述操作，直到子数组的元素个数小于等于1。
【时间复杂度】
在最好情况下，快速排序算法的时间复杂度为O(nlogn)
在最坏情况下，待排序的序列为正序或者逆序，每次划分只得到一个臂上次划分少一个记录的子序列，
而且另一个序列还为空。如果递归树画出来，它就是一棵斜树。此时需要执行(n-1)次递归调用，且第
i次划分需要经过i-1次关键字的比较才能找到第i个记录，即中轴元素的位置，因此比较次数为：
n-1+n-2+n-3+...+1 = n*(n-1)/2 时间复杂度为O(n^2)
【空间复杂度】
在最好情况下，递归树的深度为logn，其时间复杂度为O(logn)
在最坏情况下，需要进行n-1次递归调用，其空间复杂度为O(n)

Author:tmw
date:2017-11-5
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**普通快速排序**/
//选取序列中的第一个元素作为中轴元素
int first_ele_fast_sort( int array[] , int low , int high )
{
    int target = array[low];//选取最左边元素为中轴
    while( low < high )
    {
        while( low < high && array[high] >= target )
            high--;//high为数组最右边下标
        //交换
        int temp;
        temp = array[high];
        array[high] = array[low];//当前low的位置存的是target值
        array[low] = temp;

        while( low < high && array[low] <= target )
            low++;
        //交换
        temp = array[low];
        array[low] = array[high];//经上一轮交换，当前high位置存的是target值
        array[high] = temp;
    }
    return low;//返回当前中轴元素下标值
}

int* first_ele_fast_sort_all( int array[] , int low , int high )//这里的high为array_len-1
{
    if( low < high )
    {
        int target_index;
        target_index = first_ele_fast_sort(array,0,high);//数组元素从0下标开始存

        first_ele_fast_sort(array,0,target_index-1);//对中轴元素左边快排
        first_ele_fast_sort(array,target_index+1,high);//对中轴元素的右边快排
    }
    return array;
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

    first_ele_fast_sort_all( array , 0 , array_size-1 );
    printf("经快速排序后，数组元素顺序输出为：\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
