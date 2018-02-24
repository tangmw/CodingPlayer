/*******************************************************************************************
【有序表查找-插值查找】
插值查找前提：
1、顺序存储
2、有序（升序或降序）
算法思想：
插值查找的思想，只不过它的middle值不是middle = ( low + high ) / 2 = low + (1/2)*(high - low)； 而变成了：
middle = low + (high - low) * [(key - a[low])/(a[high] - a[low])]

算法复杂度：O(logn)
Author:tmw
date:2017-10-23
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***插值查找函数****/
int insert_value_search( int array[] , int number_of_size , int key_number )
{
    int low,high,middle;
    low = 0;
    high = number_of_size - 1;

    while( low <= high )
    {
        middle = low + ( high - low ) * ( key_number - array[low] ) / ( array[high] - array[low] );
        if( key_number > array[middle] )//关键值大于查找值，则在右半边区域查找
            low = middle + 1;
        else if( key_number < array[middle])//关键值小于查找值，则在左半区查找
            high = middle - 1;
        else//此时key_number = array[middle] 说明找到了
            return middle;
    }
    return -1;//表示查找失败
}

int main()
{
    int array[20];
    int i,key,ans;
    printf("请输入待查找的有序数组：");
    for( i = 0 ; i < 20 ; i++ )
        scanf("%d",&array[i]);
    printf("请输入关键值:");
    scanf("%d",&key);
    ans = insert_value_search(array,20,key);
    printf("待查找的数在数组的第 %d 位\n",ans);
    return 0;
}
