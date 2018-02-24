/*******************************************************************************************
Author:tmw
date:2017-11-5
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>


/**���������Ż�----����ȡ��&&�Ż�����Ҫ�Ľ���**/
//ȡ����Ԫ���Ƚ������򣬽��м�ֵ��Ϊ����Ԫ�أ�ѡȡ��ˡ��Ҷˡ��м���������Ҳ�������ѡȡ
int Three_choose_one_optimize_fastSort( int array[] , int low , int high )
{
    int mid = ( low + high ) / 2;
    if( array[high] < array[low] )
    {
        int temp1;
        temp1 = array[high];
        array[high] = array[low];
        array[low] = temp1;
    }
    if( array[high] < array[mid] )
    {
        int temp2;
        temp2 = array[high];
        array[high] = array[mid];
        array[mid] = temp2;
    }//���ϣ���֤highΪ����ֵ�������ֵ���±�
    if( array[mid] > array[low] )//��low��Ϊ�м�ֵ���±�
    {
        int temp3;
        temp3 = array[low];
        array[low] = array[mid];
        array[mid] = temp3;
    }//���ϣ����������ȡ�У���ʱarray[low]������Ϊ�����Ż��������Ԫ��

    int target = 0;
    target = array[low];

    while( low < high )
    {
        while( low < high && array[high] >= target  )
            high--;
        array[low] = array[high];//��ʱhighλ���ϵ�Ԫ��Ϊ������Ԫ��

        while( low < high && array[low] <= target   )
            low++;
        array[high] = array[low];//������targetֵ��Ԫ�طŵ��������highλ���ϣ���ô��ʱ,lowλ�ñ�Ϊ������
    }
    array[low] = target; //���ϣ�ʡȥ��������Ϊ���ڿӸ�ֵ��������ʱ�临�Ӷ�
    return low;
}
void fast_sort( int array[] , int low , int high )
{
    if( low < high )
    {
        int index;
        index = Three_choose_one_optimize_fastSort(array,low,high);
        fast_sort(array,low,index-1);
        fast_sort(array,index+1,high);
    }
}

int main()
{
    int *array;
    int i,array_size;
    printf("����������Ԫ�صĸ���:\n");
    scanf("%d",&array_size);

    array = (int*)malloc(sizeof(int));
    printf("������ %d ��Ԫ��\n",array_size);
    for( i = 0 ; i < array_size ; i++ )
        scanf("%d",&array[i]);

    fast_sort( array , 0 , array_size-1 );
    printf("���Ż���Ŀ�����������Ԫ��˳�����Ϊ��\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
