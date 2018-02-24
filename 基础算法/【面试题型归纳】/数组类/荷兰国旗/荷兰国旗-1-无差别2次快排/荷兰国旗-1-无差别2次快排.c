/***********************************************
������������
����n����������ֲ�ͬ����ɫ������������һ����ͨ��
������������������ʹ�ô����ҵ��������Ǻ��򡢰�������

�ⷨ��
���Խ������������ֱ���Ϊ1��2��3���൱��1��2��3������ģ�
��Ҫ���������г�1..1��2....2��3...3  �մ�����������޲�
��Ŀ��ţ�������Ԫ�ص�������--ֻ��1��2��3����Ԫ�أ�ֻ��Ҫ��
�Ǵ�С�������г�������ȫ�ǿ��԰쵽�ġ�

����Ĵ����� �޲�𽻻�ʽ���� ��ʵ��

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
    printf("���Գ���!\n");
    int i;
    int* res;res=(int*)malloc(100*sizeof(int));

    int a1[13] = {0,2,1,1,1,2,0,0,2,0,1,1,2};
    printf("ԭ����Ϊ��");
    for(i=0;i<13;i++)
        printf("%d ",a1[i]);
    printf("\n");
    printf("���к������Ϊ��");
    res = fast_sort(a1,0,12);
    for(i=0;i<13;i++)
        printf("%d ",res[i]);

    return 0;
}
