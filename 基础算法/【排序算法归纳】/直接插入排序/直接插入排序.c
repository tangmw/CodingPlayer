/*******************************************************************************************
��ֱ�Ӳ�������
����˼�룺��һ����¼���뵽�Ѿ��ź����������У��Ӷ��õ�һ���µģ���¼��1�ı�
ʱ�临�Ӷ�ΪO(n^2),�������ܵ����ܱ�ð������ͼ�ѡ�������һЩ
Author:tmw
date:2017-10-31
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int* direct_insert_sort( int array[] , int array_size )
{
    array[0] = 0;//����ĵ�һλ������temp,�൱����������λ���˸���

    int i,j;
    for( i = 2 ; i <= array_size ; i++ )//�տ�ʼ����Ϊ��һ������Ϊ�����
    {
        if( array[i] < array[i-1] )//��һ��Ԫ�ر�ǰһ��Ԫ��С������Ҫ�ƶ�λ���ˣ�ͬʱ����λ���,���ѭ��
        {
            array[0] = array[i];
            for( j = i-1 ; array[j] > array[0] ; j-- )
                array[j+1] = array[j];
            array[j+1] = array[0];//����ǰi��ָ���Ԫ�ط�����ȷ��λ��
        }
    }
    return array;
}

int main()
{
    int *array;
    int i,array_size;
    printf("����������Ԫ�صĸ���\n");
    scanf("%d",&array_size);

    array = (int*)malloc(sizeof(int));
    printf("������ %d ��Ԫ��\n",array_size);
    for( i = 1 ; i <= array_size ; i++ )
        scanf("%d",&array[i]);

    array = direct_insert_sort( array , array_size );
    printf("��ֱ�Ӳ������������Ԫ��˳�����Ϊ��\n");
    for( i = 1 ; i <= array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
