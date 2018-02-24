/**********************************************************************************************************

LeetCode----[easy] 26-RemoveDuplicatesfromSortedArray

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

[Ans:]
Method:��ĿҪ��������������ռ�����Ž��������ԭ���������Ķ���ǰ��Ƚϣ���¼��ͬ���ֵ�λ�ã��ò�ͬ�����ֲ�λ��ֱ���������������
Author:tmw
date:2017-9-12

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize)
{
    int pre = 0;
    int back = 1;
    int len = 0;

    if(numsSize == 0)
        len = 0;

    else
    {
        while( back < numsSize )
        {
            if( nums[pre] < nums[back] )
            {
                pre++;
                nums[pre] = nums[back];
                back++;
            }
            else
                back++;
        }
        len = pre+1;
        int i = 0;
        for( i = 0 ; i < len ; i++ )
            printf("%d ",nums[i]);
    }
    return len;
}

int main()
{
    int length = 0;
    int *s;
    int i = 0;
    int ans = 0;

    printf("���������鳤��!\n");
    scanf("%d",&length);

    s = (int*)malloc(length*sizeof(int));
    printf("����������Ԫ��:\n");
    for( i = 0 ; i < length ; i++ )
    {
        scanf("%d",&s[i]);
    }

    ans = removeDuplicates(s,length);
    printf("The final answer is %d",ans);
    printf("\n");

    return 0;
}
