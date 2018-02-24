/*******************************************************************************************
��ֱ��ѡ������
����˼�룺ͨ��n-1�ιؼ��ֱȽϣ���n-i-1����¼��ѡ����С�Ĺؼ��֣��������С�ؼ��ֲ���iλ
��ʱ���͵�i��λ�õĹؼ��ּ�¼����

���㷨���Ӷȷ�����
1���ӽ����ƶ�����������
1������õ�����������ƶ�����Ϊ0��
2������������Ҳ���ǳ�ʼ���򣬽����ƶ�����Ϊ��n-1����
2���ӱȽϴ�������
    �Ƚϴ���Ϊ��1+2+3+...+(n-1) = n*(n-1)/2��

�����ܵ�ʱ�临�ӶȻ���ΪO(n^2),�������ܵ����ܱ�ð�������һЩ
Author:tmw
date:2017-10-31
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int* simple_select_sort( int array[] , int array_size )
{
    int i,j,min,temp;
    for( i = 0 ; i < array_size ; i++ )
    {
        min = i;
        for( j = i+1 ; j < array_size ; j++ )
        {
            if( array[min] > array[j] )
                min = j;
        }//��¼ÿһ��i����Сֵ���±�
        if( i!=min )//����±귢���ı䣬��minλ�õ�����iλ�õ�����������֮�򲻽���
        {
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }//ÿһ��i��ཻ��һ�Σ�����ѭ�����������ѭ��n-1��
    }
    return array;
}
int main()
{
    int *array;
    int array_size,i;

    printf("�����������С\n");
    scanf("%d",&array_size);

    printf("������ %d ������Ԫ��\n",array_size);
    array = (int*)malloc(array_size*sizeof(int));
    for( i = 0 ; i < array_size ; i++ )
        scanf("%d",&array[i]);

    array = simple_select_sort(array,array_size);
    printf("��ֱ��ѡ�������˳�����Ϊ��\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);

    return 0;
}
