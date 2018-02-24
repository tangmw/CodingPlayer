/**********************************************************************************************************

LeetCode----[easy] 27-RemoveElement

Given an array and a value, remove all instances of that value in place and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

[Ans:]
Method:题目要求不能申请新数组空间来存放结果，则在原数组中做改动，用val值与数组每个元素比较，把不同的元素从数组头开始覆盖这个数组即可
Author:tmw
date:2017-9-12

***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//方法一：复杂度太高
//int removeElement(int* nums, int numsSize, int val)
//{
//    int i = 0;
//    int j = 0;
//    int len = numsSize;
//
//    if( numsSize == 0 )
//        return 0;
//    else
//    {
//        while( i < numsSize )
//        {
//            if( nums[i] != val )
//            {
//                i++;
//            }
//
//            else
//            {
//                j = i;
//                while( (j) < len )
//                {
//                    nums[j] = nums[j+1];
//                    j++;
//                }
//                len--;
//            }
//        }
//    }
//    for( j = 0 ; j < len ; j++ )
//        printf("%d ",nums[j]);
//    return len;
//}

//方法二：复杂度满足题意
int removeElement(int* nums, int numsSize, int val)
{
    int i;
    int mark = 0;

    for( i = 0 ; i < numsSize ; i++ )
    {
        if( nums[i] != val )
        {
            nums[mark] = nums[i];
            mark++;
        }
    }

    printf("结果为：\n");
    for( i = 0 ; i < mark ; i++ )
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return mark;
}

int main()
{
    int numsSize = 0;
    int i = 0;
    int *nums;
    int val = 0;
    int ans = 0;

    printf("请输入数组长度!\n");
    scanf("%d",&numsSize);

    if(numsSize == 0)
        return 0;

    nums = (int*)malloc(numsSize*sizeof(int));
    printf("请输入数组元素!\n");
    for( i = 0 ; i < numsSize; i++ )
        scanf("%d",&nums[i]);

    printf("请输入val值：\n");
    scanf("%d",&val);

    ans = removeElement(nums,numsSize,val);
    printf("输出长度为：%d",ans);
    return 0;
}
