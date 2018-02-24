/***********************************************
������������
��n���������ҳ�������С��k������ʱ�临�ӶȾ����ܵ�
������������ѡ���㷨
������������˼�룬���Կ�������һ���㷨fast_select(S,k)��
�㷨��ʼ��
ѡȡһ������Ԫ��pivot���ɲο����������������ȡ�з�������������S�ָ���������ߣ���Sl;��Sr����
���Ԫ�ض�����С������ȣ����ұ�Ԫ�ض�������
1�����kС�����Ԫ�صĸ�������ô��k����С��Ԫ��һ��������Ԫ�����ߣ����������ݹ飺fast_select(Sl,k);
2�����k�������Ԫ�ظ�����1��������Ԫ�ؾ��ǵ�k����СԪ�أ����򷵻����Ԫ��
3�����k�������Ԫ�ظ�������ô��k����С��Ԫ��һ��������Ԫ���Ұ�ߣ����Ұ�����ݹ飺fast_select(Sr,k-|Sl|-1);

���ڳ���ķ���
���Ҫ���ҵ�k�ĸ���С��Sl�ĸ�������ֱ�ӷ���Sl�н�С��k��Ԫ��
���Ҫ���ҵ�k�ĸ�������Sl�ĸ������򷵻�Sl������Ԫ�غ�Sr�н�С��k-|Sr|��Ԫ��

����ѡ���㷨��ƽ�������������O(n)��ʱ�临�Ӷ�

Author:tmw
date:2017-11-17
************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t)

//����ȡ��
int median3(int *array , int low , int high)
{
    int mid = (low+high)/2;
    int temp;
    if(array[high]<array[mid])
        swap(array[high],array[mid],temp);
    if(array[high]<array[low])
        swap(array[high],array[low],temp);
    //���ϣ���֤array[high]Ϊ���������
    if(array[low]<array[mid])
        swap(array[low],array[mid],temp);
    //���ϣ���֤array[low]Ϊ�����е��м�ֵ
    return array[low];
}

int fast_select( int* array , int low , int high , int k )
{
    //����ȡ��,����Ԫ�ش���array[low]��
    array[low] = median3(array,low,high);
    int pivot = array[low];//pivot������Ԫ�ص�ֵ������
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
    array[i]=pivot;//��ʱ��pivot����߶�����С���ұ߶�������

    /**����ѡ�����㷨**/
    if( k <= i )//���kС�����Ԫ�صĸ�������ô��k����С��Ԫ��һ��������Ԫ�����ߣ����������ݹ�
        return fast_select(array,low,i-1,k);
    if( k > i + 1)//���k�������Ԫ�ظ�������ô��k����С��Ԫ��һ��������Ԫ���Ұ�ߣ����Ұ�����ݹ�
        return fast_select(array,i+1,high,k);
    else
        return array[i];
}

int main()
{
    printf("���Դ���\n");
    int k = 4;
    int i;

    int a2[7] = {1,8,23,6,90,5,8};
    printf("ԭ��:\t    ");
    for(i=0;i<7;i++)
        printf("%d ",a2[i]);
    fast_select(a2,0,6,k);
    printf("\n��С��%d������",k);
    for(i=0;i<k;i++)
        printf("%d ",a2[i]);

    printf("\n");

    int a4[9] = {100,56,23,7,17,0,23,65,2};
    printf("\n\nԭ��:\t    ");
    for(i=0;i<9;i++)
        printf("%d ",a4[i]);
    fast_select(a4,0,8,k);
    printf("\n��С��%d������",k);
    for(i=0;i<k;i++)
        printf("%d ",a4[i]);
    return 0;
}
