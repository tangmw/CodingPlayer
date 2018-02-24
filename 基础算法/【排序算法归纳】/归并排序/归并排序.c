/*******************************************************************************************
��2·--�鲢����
ԭ��
�����ʼ���к���n��Ԫ�أ���ɿ����Ը���Ԫ��Ϊ��λ��n�����������У�ÿ�������г���Ϊ1��Ȼ��
�����鲢��n�����������оͱ����n/2�����������У��������鲢��...������ظ���ֱ���õ�һ����
��Ϊn����������Ϊֹ��

�鲢���������ʵ����ʽ���ݹ�ʵ�ֺͷǵݹ�ʵ��

�ݹ�ʵ�ָ��Ӷȣ�ʱ�临�Ӷ�ΪO(nlogn)
                 �ռ临�Ӷ�ΪO(n+logn)
Author:tmw
date:2017-11-4
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***�ݹ鷽��ʵ�ֹ鲢����****/
//�������ܣ��������������һ�������
//�ϲ�
void merge( int array[] , int left , int middle , int right )
{
    int left_len = middle - left;
    int right_len = right - middle - 1;
    int left_array[left_len];
    int right_array[right_len];
    int i,j,k;

    //����ժ��������������
    for( i = 0 ; i <= left_len ; i++ )
        left_array[i] = array[i+left];

    for( j = 0 ; j <= right_len ; j++)
        right_array[j] = array[j+middle+1];

    //�������������б��һ����������
    //ע�⣺��Ϊ�����������һֱ�Ƕ�array����ĵݹ飬���������ʼ�����Ƕ�array������У�
    //array����Ԫ�ص�λ�ñ仯����������array����������ñ�ı�������!!!
    k = left;
    i = 0;j = 0;
    while( i <= left_len && j <= right_len )
    {
        if( left_array[i] < right_array[j] )
            array[k++] = left_array[i++];
        else
            array[k++] = right_array[j++];
    }
    while( i <= left_len )
        array[k++] = left_array[i++];
    while( j <= right_len )
        array[k++] = right_array[j++];
}

//merge_sort()�������ٺϲ�
void merge_sort( int array[] , int left , int right )
{
    int middle;
    if( left < right )
    {
        middle = ( left + right ) / 2;
        // �ֽ� + �����Divide + Conquer
        merge_sort( array , left , middle );
        merge_sort( array , middle+1 , right );
        // �ϲ���Combine
        merge( array , left , middle , right );
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

    merge_sort( array , 0 , array_size-1 );
    printf("���鲢���������Ԫ��˳�����Ϊ��\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
