/***********************************************
【问题描述】
现有n个红白蓝三种不同个颜色的球，乱序排在一起，请通过
两两交换任意两个球，使得从左到右的球依次是红球、白球、篮球。

解法：
可以将红白蓝三种球分别标号为1、2、3，相当于1、2、3是乱序的，
需要将它们排列成1..1、2....2、3...3  照此情况，两次无差
别的快排（不关心元素的特殊性--只有1、2、3三个元素，只需要它
们从小到大排列出来）完全是可以办到的。

下面的代码是 无差别交换式快排 的实现

Author:tmw
date:2017-11-24
************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t)

int fast_sort_swap_no_different( int* array , int low , int high )
{
    int target = array[low];
    int temp;
    while(low<high)
    {
        while(array[high]>=target &&low<high)
            high--;
        swap(array[high],array[low],temp);
        while(array[low]<=target && low<high)
            low++;
        swap(array[low],array[high],temp);
    }
    return low;
}
int* fast_sort( int* array , int low , int high )
{
    int mid;
    if( low < high )
    {
        mid = fast_sort_swap_no_different(array,low,high);

        fast_sort(array,low,mid-1);
        fast_sort(array,mid+1,high);
    }
    return array;
}

int main()
{
    printf("测试程序!\n");
    int i;
    int* res;res=(int*)malloc(100*sizeof(int));

    int a1[13] = {0,2,1,1,1,2,0,0,2,0,1,1,2};
    printf("原数组为：");
    for(i=0;i<13;i++)
        printf("%d ",a1[i]);
    printf("\n");
    printf("排列后的数组为：");
    res = fast_sort(a1,0,12);
    for(i=0;i<13;i++)
        printf("%d ",res[i]);

    return 0;
}
