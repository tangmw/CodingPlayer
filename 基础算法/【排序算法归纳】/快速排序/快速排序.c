/*******************************************************************************************
����������
��ԭ��
    ��������Ļ���˼����Ǵ�һ��������������ѡһ��Ԫ�أ�ͨ����˵��ѡ������ߵ�Ԫ�أ���Ϊ
����Ԫ�أ���ʣ�µ�Ԫ��������Ԫ����Ϊ�Ƚϵı�׼����С�ڵ�������Ԫ�صķŵ�����Ԫ�ص���ߣ�
����������Ԫ�صķŵ�����Ԫ�ص��ұߣ�Ȼ���Ե�ǰ����Ԫ�ص�λ��Ϊ�磬����벿����������Ұ�
���������鿴�������µ����飬�ظ�����������ֱ���������Ԫ�ظ���С�ڵ���1��
��ʱ�临�Ӷȡ�
���������£����������㷨��ʱ�临�Ӷ�ΪO(nlogn)
�������£������������Ϊ�����������ÿ�λ���ֻ�õ�һ�����ϴλ�����һ����¼�������У�
������һ�����л�Ϊ�ա�����ݹ�����������������һ��б������ʱ��Ҫִ��(n-1)�εݹ���ã��ҵ�
i�λ�����Ҫ����i-1�ιؼ��ֵıȽϲ����ҵ���i����¼��������Ԫ�ص�λ�ã���˱Ƚϴ���Ϊ��
n-1+n-2+n-3+...+1 = n*(n-1)/2 ʱ�临�Ӷ�ΪO(n^2)
���ռ临�Ӷȡ�
���������£��ݹ��������Ϊlogn����ʱ�临�Ӷ�ΪO(logn)
�������£���Ҫ����n-1�εݹ���ã���ռ临�Ӷ�ΪO(n)

Author:tmw
date:2017-11-5
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**��ͨ��������**/
//ѡȡ�����еĵ�һ��Ԫ����Ϊ����Ԫ��
int first_ele_fast_sort( int array[] , int low , int high )
{
    int target = array[low];//ѡȡ�����Ԫ��Ϊ����
    while( low < high )
    {
        while( low < high && array[high] >= target )
            high--;//highΪ�������ұ��±�
        //����
        int temp;
        temp = array[high];
        array[high] = array[low];//��ǰlow��λ�ô����targetֵ
        array[low] = temp;

        while( low < high && array[low] <= target )
            low++;
        //����
        temp = array[low];
        array[low] = array[high];//����һ�ֽ�������ǰhighλ�ô����targetֵ
        array[high] = temp;
    }
    return low;//���ص�ǰ����Ԫ���±�ֵ
}

int* first_ele_fast_sort_all( int array[] , int low , int high )//�����highΪarray_len-1
{
    if( low < high )
    {
        int target_index;
        target_index = first_ele_fast_sort(array,0,high);//����Ԫ�ش�0�±꿪ʼ��

        first_ele_fast_sort(array,0,target_index-1);//������Ԫ����߿���
        first_ele_fast_sort(array,target_index+1,high);//������Ԫ�ص��ұ߿���
    }
    return array;
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

    first_ele_fast_sort_all( array , 0 , array_size-1 );
    printf("���������������Ԫ��˳�����Ϊ��\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
