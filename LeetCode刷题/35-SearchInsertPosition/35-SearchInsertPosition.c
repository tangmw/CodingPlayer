/**********************************************************************************************************

LeetCode----[easy] 35-SearchInsertPosition

Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

[Ans:]
Method:遍历给定的nums有序数组，如果发现target值大于等于nums[i]，则返回下标，当target == nums[i]时，注意返回下标前要i--
Author:tmw
date:2017-9-13

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target)
{
    //先考虑数组为空的情况
    if( numsSize == 0 )
        return 0;
    int i = 0;
    while( ( i < numsSize )  && ( nums[i] <= target ) )
            i++;
    if( i>0 && nums[i-1] == target )//前面多了个i>0是当Nums只有一个元素时，i-1会超界
        i--;
    return i;
}

int main()
{
    int *nums;
    int target = 0;
    int ans = 0;
    int len = 0;

    printf("input the nums len!\n");
    scanf("%d",&len);

    nums = (int*)malloc(len*sizeof(int));

    printf("input nums \n");
    for( ans = 0 ; ans < len ; ans++ )
        scanf("%d",&nums[ans]);

    printf("input target!\n");
    scanf("%d",&target);

    ans = searchInsert(nums,len,target);

    printf("\n");
    printf("the result is %d\n",ans);
    return 0;
}
