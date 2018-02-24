/***********************************************
【问题描述】
给定一个整数数组，数组里可能有正数、负数和0.数组中连续的
一个或多个整数组成一个子数组，每个子数组都有一个和。求所
有子数组的和的最大值。

这个问题可以看成：现在有一个合集，当前元素a[i]要不要加入这个和集，或者自己重新开启一个合集；

作出选择的关键在于，使得合集值最大

我们知道，正数相加一定会使和集增大，因此，判定因素变成了：
如果当前合集为正，则a[i]加入这个合集
如果当前合集为负，则a[i]重新开启一个合集

写成数学表达就是：sum = max(curren_sum,0)+a[i],式子中，curren_sum为当前和集的和，sum记录和集的最大和

Author:tmw
date:2017-11-21
************************************************/
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a>b?a:b)
//int max_sub_array_sum( int *array , int array_len )
//{
//    int i;
//    int sum = 0;
//    int temp_sum;
//    int curren_sum = array[0];//array[i]从1开始找起
//    for( i = 1 ; i < array_len ; i++ )
//    {
//        temp_sum = curren_sum;//保存一下curren_sum变化前的值
//        curren_sum = max(curren_sum,0)+array[i];
//        //后面的sum为sum变化前的值，sum更新的前提是：新的sum要比原的sum大
//        sum=max(max(temp_sum,curren_sum),sum);
//    }
//    return sum;
//}
/**优化：找到最大连续子数组和的下标并输出这个最大子数组**/
int max_sub_array_sum_find_index( int *array , int array_len )
{
    int i=1;
    int sum = 0;
    int temp_sum;
    int curren_sum = array[0];//array[i]从1开始找起

    int index_left;
    for( i = 1 ; i < array_len ; i++ )
    {
        temp_sum = curren_sum;//保存一下curren_sum变化前的值
        curren_sum = max(curren_sum,0)+array[i];
        if( curren_sum <= 0 )//curren_sum<=0时，说明加上当前的a[i]值不大于0，应舍弃，因此新的最大子数组和首位应该是i的后一位
            index_left = i+1;
        //后面的sum为sum变化前的值，sum更新的前提是：新的sum要比原的sum大
        sum=max(max(temp_sum,curren_sum),sum);
    }

    /**下面的代码是已知最大连续子数组和以及首位之后，找到它的末尾并打印**/
    printf("最大连续子数组为：");
    printf("%d + ",array[index_left]);
    int find_sum = array[index_left];//find_sum用于最终找temp_sum = sum
    i=index_left+1;
    while( i < array_len )
    {
        find_sum = find_sum + array[i];
        if( find_sum != sum )
        {
            printf("%d + ",array[i]);
            i++;
        }
        else
            break;
    }
    printf("%d\n",array[i]);//此时，i为最大连续子数组和的末位
    return sum;
}


int main()
{
    printf("测试代码!\n");
    int i;

    int a1[8] = {1,-2,3,10,-4,7,2,-5};
    printf("原数组为：");
    for(i = 0 ; i < 8 ; i++ )
        printf("%d ",a1[i]);
    printf("\n");
    int result1 = max_sub_array_sum_find_index(a1,8);
    printf("最大子数组和为 %d\n",result1);

    printf("\n");

    int a2[9] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("原数组为：");
    for(i = 0 ; i < 9 ; i++ )
        printf("%d ",a2[i]);
    printf("\n");
    int result2 = max_sub_array_sum_find_index(a2,9);

    printf("最大子数组和为 %d\n",result2);

    return 0;
}
