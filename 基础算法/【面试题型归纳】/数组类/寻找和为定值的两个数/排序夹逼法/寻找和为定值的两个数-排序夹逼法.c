/***********************************************
【问题描述】
插入一个整数数组和一个整数，在数组中查找一对数，满足它们的和正好是输入
的那个整数。如果有多对数的和等于输入的整数，输出任意一对即可。

解法二：
如果数组是无序的，可以考虑把数组排成有序的，数组变成有序的后，便有好几种方法
可以找到其和等于给定的数的两个数。
在这里，笔者重点推荐排序夹逼的方法。算法如下：
算法准备：用快速排序，将无序数组变成有序
step1:设定两个游标begin和end,分别指向数组的头和尾
step2:如果某一时刻，array[begin]+array[end]>sum，则begin不动，end--,缩小array[begin]+array[end]的值
step3:如果某一时刻，array[begin]+array[end]<sum，则end不动，begin++,增大array[begin]+array[end]的值
算法结束：当array[begin]+array[end]==sum时，返回array[begin]和array[end]的值，算法结束；当begin==end
但array[begin]+array[end]!=sum，说明数组内没有和为sum的两个数，返回错误

Author:tmw
date:2017-11-19
************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t)

//快排中枢元素选取--三数取中子模块
int median3(int *array , int low , int high )
{
    int mid = ( low + high ) / 2;
    int temp;
    if( array[high] < array[mid] )
        swap( array[high] , array[mid] , temp );
    if( array[high] < array[low] )
        swap( array[high] , array[low] , temp );
    //以上，保证array[high]为三数中的最大值
    if( array[low] < array[mid] )
        swap( array[low] , array[mid] , temp );
    //以上，保证array[low]为三数中的中间值
    return array[low];
}
//一次快排
int fast_sort_using_median3(int *array , int low , int high )
{
    array[low] = median3(array,low,high);

    int target = array[low];//中枢元素备份

    while( low < high )
    {
        while( low < high && array[high] >= target  )
            high--;
        array[low] = array[high];

        while( low < high && array[low] <= target   )
            low++;
        array[high] = array[low];
    }
    array[low] = target;
    return low;
}
//所有元素快排
int* fast_sort_all(int *array , int low , int high)
{
    if( low < high )
    {
        int mid_index;
        mid_index = fast_sort_using_median3(array,low,high);
        fast_sort_all(array,0,mid_index-1);
        fast_sort_all(array,mid_index+1,high);
    }
    return array;
}

//排序夹逼主算法
void TowSum_Sort_and_Aproach(int *array , int array_len , int sum )
{
    int begin = 0;
    int end = array_len - 1;
    array = fast_sort_all(array,0,array_len - 1);//将数组由无序变有序

    while( begin < end )
    {
        if( array[begin] + array[end] == sum )
        {
            printf("%d + %d = %d\n",array[begin],array[end],sum);
            //begin++;
            //end--;
            break;//如果要求的是输出所有满足条件的整数对，则将此break注解，将begin++;end--解注
        }
        else
        {
            if( array[begin] + array[end] > sum )//array[begin]+array[end]>sum，则begin不动，end--
                end--;
            else//array[begin]+array[end]<sum，则end不动，begin++
                begin++;
        }
    }
    if(begin == end)
        printf("数组中没有和为 %d 的两个数\n",sum);
}


int main()
{
    printf("测试代码\n");
    int i;
    int sum = 15;

    int a[12] = {1,2,4,5,7,11,54,3,8,6,10,13};
    for(i=0;i<12;i++)
        printf("%d ",a[i]);
    printf("\n");
    TowSum_Sort_and_Aproach(a,12,sum);

    int b[15] = {3,4,2,10,5,0,12,13,8,9,16,17,20,1,6};
    for(i=0;i<15;i++)
        printf("%d ",b[i]);
    printf("\n");
    TowSum_Sort_and_Aproach(b,15,sum);

    return 0;
}

