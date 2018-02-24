/**********************************************************************************************************

LeetCode----[easy] 53-MaximumSubarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

[Ans:] http://www.cnblogs.com/boring09/p/4252780.html
Method:
【方法一：动态规划】 动态规划理解参考：http://www.cnblogs.com/boring09/p/4252780.html
                                         http://www.cnblogs.com/bourbon/archive/2011/08/23/2151044.html
令sum[i]表示从i开始的最大子串和，则有递推公式：sum[i] = max{A[i], A[i] + sum[i+1]}
因为递推式只用到了后一项，所以在编码实现的时候可以进行状态压缩，用一个变量即可
时间复杂度O(n)

【具体思路】
1）定义局部最大值sum和全局最大值maxSum，初始值均为数组第一个值
2）局部最大值的作用在于：判定当前元素值能否加入它之前元素构成的集合，即：
    a）若当前元素值小于将此元素放入之前元素构成的集合之后的和值，则将此元素加入集合，局部最大值更新为新集合之和
    b）若当前元素值大于将此元素放入之前元素构成的集合之后的和值，则将局部最大值更新为当前元素值，放弃之前的集合，
    改为从当前元素开始的集合。
3）全局最大值始终记录局部最大值变化的最大值，即本题的最终答案

【方法二：暴力搜索】
1）从数组位置0出发，依次顺序递加后，和值的最大值
2）从数组位置1出发，依次顺序递加后，和值在前两轮最大值（因为满足最大条件后，最大值才更新）
......
n）直到遍历到数组最后一个位置numSize-1 ，和值在前numSize轮的最大值，即本题最终答案

【方法三：分治法】
1）首先将其分成两半A[l..m]和A[m+1..r]，其中m=(l+r)/2，并分别求递归求出这两半的最大子串和，不妨称为left，right
2）A[l..r]的连续子串和可能出现在左半边（即left），或者可能出现在右半边（即right），还可能出现在横跨左右两半的地方
3）按照方法一，从中间向两边扫，求最大值。

那么这个分治法的主要作用在于 缩小了方法一的扫描范围

时间复杂度O(nlogn)

Author:tmw
date:2017-9-18~9-21

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/******************************************
【方法一：动态规划】----复杂度O(n)
*******************************************/
//int max( int a , int b )
//{
//    a = (b > a ? b : a);
//    return a;
//}
//
//int maxSubArray(int* nums, int numsSize)
//{
//    int sum = nums[0];
//    int maxSum = sum;
//    int index = 0;
//    int index_mark = 0;
//    int temp;
//
//    /***本题算法的核心****/
//    for( index = 1 ; index < numsSize ; index++ )
//    {
//        sum = max( nums[index] , sum + nums[index] );
//        temp = maxSum;//记录maxSum变化前的值
//        maxSum = max( sum , maxSum );
//        if( temp != maxSum )//记录当maxSum为最大时的首位数字的下标
//            index_mark++;
//    }
//
//    /***以下代码是在找到了maxSum和首位数字下标后，找出和为maxSum的所有元素并打印****/
//    index_mark--;
//    int j = index_mark;
//    int sum1 = 0;
//    while( sum1 != maxSum )
//    {
//        sum1 = sum1 + nums[j];
//        j++;
//    }
//    j--;
//    printf("the answer array index range is [%d-%d]\n",index_mark,j);
//    printf("the specific answer is: -----  ");
//    for(index = index_mark ; index <= j ; index++ )
//        printf("%d ",nums[index]);
//    printf("\n");
//    return maxSum;
//}
/******************************************
【方法二：暴力搜索】----复杂度O(n^2)
*******************************************/
//int maxSubArray(int* nums, int numsSize)
//{
//    int max = INT_MIN;
//    int i,j,sum;
//
//    for( i = 0 ; i < numsSize ; i++ )
//    {
//        sum = 0;
//        for( j = i ; j < numsSize ; j++)
//        {
//            sum = nums[j] + sum;
//            if( sum > max )
//                max = sum;
//        }
//        printf("第%d轮最大值为:%d \n",i,max);
//    }
//    return max;
//}

/******************************************
【方法二：分治法】----复杂度O(nlogn))
*******************************************/
int max( int a , int b )
{
    a = (b > a ? b : a);
    return a;
}
//构造分治法子函数
int dividConquer( int *nums , int l , int r )
{
    int middle,left,right;//存储左、中、右值的变量
    int m;//中间值的下标
    int i,j,temp,result;

    if( l == r )
        return nums[l];//确定分治边界

    m = ( l + r ) / 2;
    middle = nums[m];
    left = dividConquer( nums , l , m );
    right = dividConquer( nums , m+1 , r );

    //这个middle的值可以看成一个不断包容吞并和值最大的值，
    //当递归进行到r = l+1时，middle记录的值是只有两个值存在下的最大和值（要么是原位置m上的值，要么是两个值的和值，反正取只有两个数存在下的最大值）
    //所以可以判断，当这两个值庞大到左右两个部分的时候，middle记录的是要么包含原位置m上的值与左半支或者右半支的和值，要么不包含原位置m下的值，就是左半支或右半支返回的最大值
    //但是注意，middle并不代表本题的最大值，因为它跳到最外层循环的时候，返回的值是
    //1）本身m位置下的值
    //2）m位置下的值与左半支或右半支的和值
    //3）m位置下的值与左右半支总和值
    //三种情况下的最大值，总之middle的值是包含m位置下的值的最大和值情况，但答案可能是不包含m位置下的值，可能在左分支最大值也可能在右分支最大值，因此
    //result = max( max(left , right ) , middle );正是做了最大值要么包括m位置下的值，要么不包括m位置下的值（取左边或右边）这一件事。
    for( i = m-1 , temp = middle ; i >= l ; i-- )
    {
        temp = nums[i] + temp;
        middle = max( temp , middle );
    }

    for( j = m+1 , temp = middle ; j <= r ; j++ )
    {
        temp = nums[j] + temp;
        middle = max( temp , middle );
    }

    result = max( max(left , right ) , middle );
    return result;
}

int maxSubArray(int* nums, int numsSize)
{
    return dividConquer( nums , 0 , numsSize - 1 );;
}

int main()
{
    printf("测试代码!\n");
    int i;

    int a1[8] = {1,-2,3,10,-4,7,2,-5};
    int result1 = maxSubArray(a1,8);
    printf("原数组为：");
    for(i = 0 ; i < 8 ; i++ )
        printf("%d ",a1[i]);
    printf("最大子数组和为 %d\n",result1);

    int a2[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int result2 = maxSubArray(a2,9);
    printf("原数组为：");
    for(i = 0 ; i < 9 ; i++ )
        printf("%d ",a2[i]);
    printf("最大子数组和为 %d\n",result2);

    return 0;
}
