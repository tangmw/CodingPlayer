/**********************************************************************************************************
LeetCode----[easy] 88-MergeSortedArray.c
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional
elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

[Ans:]
��������Ŀ�Ѿ���������˵��a����ĳ��Ȳ�ֹm��������Ϊm+n��������ڰ�Merge���Ԫ�طŵ�a����ʱ�����ÿ���a�����Ƿ����ɲ���
������á��Ӻ���ǰ���ıȽϷ�������Ϊ�ܹ���m+n��Ԫ�أ��Ӻ���ǰ��a�������������ܵ�����ǰ���󡰱�����Լ�����������ڴ��������ռ䡣

Author:tmw
date:2017-10-12
***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int m, int* nums2, int n)
{
    int i = m-1;//iָ��nums1�������һ��Ԫ��
    int j = n-1;//jָ��nums2�������һ��Ԫ��
    int k = n+m-1;//kָ����nums1�������һ��Ԫ��

    if( n == 0 )
        return;
    if( m == 0 && n != 0 )
    {
        int s;
        for( s = 0 ; s < n ; s++ )
            nums1[s] = nums2[s];
        return;
    }

    while( i >= 0 && j >= 0 )
    {
        if( nums1[i] < nums2[j] )
        {
            nums1[k] = nums2[j];
            j--;
        }
        else
        {
            nums1[k] = nums1[i];
            i--;
        }
        k--;
    }
    while( i >= 0 )//˵��nums1��nums2��
    {
        nums1[k] = nums1[i];
        i--;
        k--;
    }
    while( j >= 0 )//˵��nuns2��nums1��
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
