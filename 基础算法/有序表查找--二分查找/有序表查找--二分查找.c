/*******************************************************************************************
【有序表查找-二分查找】
二分查找前提：
1、顺序存储
2、有序（升序或降序）
算法思想：
在顺序存储的有序表中，选取中间值作为比较对象
1）若查找值与比较值相等，则返回查找成功
2）若查找值小于比较值，则在查找值的右半区继续查找
3）若查找值大于比较值，则在查找值的左半区继续查找
不断重复上述过程，直到查询成功，或者失败。

算法复杂度：O(logn)
Author:tmw
date:2017-10-23
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***二分查找函数****/
int half_divide_search( int array[] , int number_of_size , int key_number )
{
    int low,high,middle;
    low = 0;
    high = number_of_size - 1;

    while( low <= high )
    {
        middle = ( high + low ) / 2;
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
    ans = half_divide_search(array,20,key);
    printf("待查找的数在数组的第 %d 位\n",ans);
    return 0;
}
