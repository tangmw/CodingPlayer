/***********************************************
【问题描述】
有n个整数，找出其中最小的k个数，时间复杂度尽可能低
方法三：线性选择算法
联想快速排序的思想，可以考虑这样一种算法fast_select(S,k)：
算法开始：
选取一个中轴元素pivot（可参考快速排序里的三数取中方法），将集合S分割成左右两边（左：Sl;右Sr），
左边元素都比它小（或相等），右边元素都比它大；
1）如果k小于左边元素的个数，那么第k个最小的元素一定在中轴元素左半边，对左半边做递归：fast_select(Sl,k);
2）如果k等于左边元素个数加1，即中轴元素就是第k个最小元素，程序返回这个元素
3）如果k大于左边元素个数，那么第k个最小的元素一定在中轴元素右半边，对右半边做递归：fast_select(Sr,k-|Sl|-1);

关于程序的返回
如果要查找的k的个数小于Sl的个数，则直接返回Sl中较小的k个元素
如果要查找的k的个数大于Sl的个数，则返回Sl中所有元素和Sr中较小的k-|Sr|个元素

线性选择算法在平均情况下能做到O(n)的时间复杂度

Author:tmw
date:2017-11-17
************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t)

//三数取中
int median3(int *array , int low , int high)
{
    int mid = (low+high)/2;
    int temp;
    if(array[high]<array[mid])
        swap(array[high],array[mid],temp);
    if(array[high]<array[low])
        swap(array[high],array[low],temp);
    //以上：保证array[high]为三者中最大
    if(array[low]<array[mid])
        swap(array[low],array[mid],temp);
    //以上：保证array[low]为三者中的中间值
    return array[low];
}

int fast_select( int* array , int low , int high , int k )
{
    //三数取中,中枢元素存在array[low]中
    array[low] = median3(array,low,high);
    int pivot = array[low];//pivot对中枢元素的值做备份
    int i = low;
    int j = high;
    while( i < j )
    {
        while( i < j && array[j] >= pivot )
            j--;
        array[i] = array[j];
        while( i < j && array[i] <= pivot)
            i++;
        array[j] = array[i];
    }
    array[i]=pivot;//此时，pivot的左边都比它小，右边都比它大

    /**线性选择主算法**/
    if( k <= i )//如果k小于左边元素的个数，那么第k个最小的元素一定在中轴元素左半边，对左半边做递归
        return fast_select(array,low,i-1,k);
    if( k > i + 1)//如果k大于左边元素个数，那么第k个最小的元素一定在中轴元素右半边，对右半边做递归
        return fast_select(array,i+1,high,k);
    else
        return array[i];
}

int main()
{
    printf("测试代码\n");
    int k = 4;
    int i;

    int a2[7] = {1,8,23,6,90,5,8};
    printf("原串:\t    ");
    for(i=0;i<7;i++)
        printf("%d ",a2[i]);
    fast_select(a2,0,6,k);
    printf("\n最小的%d个数：",k);
    for(i=0;i<k;i++)
        printf("%d ",a2[i]);

    printf("\n");

    int a4[9] = {100,56,23,7,17,0,23,65,2};
    printf("\n\n原串:\t    ");
    for(i=0;i<9;i++)
        printf("%d ",a4[i]);
    fast_select(a4,0,8,k);
    printf("\n最小的%d个数：",k);
    for(i=0;i<k;i++)
        printf("%d ",a4[i]);
    return 0;
}
