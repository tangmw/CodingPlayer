/*******************************************************************************************
����������-��ֵ���ҡ�
��ֵ����ǰ�᣺
1��˳��洢
2�������������
�㷨˼�룺
��ֵ���ҵ�˼�룬ֻ��������middleֵ����middle = ( low + high ) / 2 = low + (1/2)*(high - low)�� ������ˣ�
middle = low + (high - low) * [(key - a[low])/(a[high] - a[low])]

�㷨���Ӷȣ�O(logn)
Author:tmw
date:2017-10-23
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***��ֵ���Һ���****/
int insert_value_search( int array[] , int number_of_size , int key_number )
{
    int low,high,middle;
    low = 0;
    high = number_of_size - 1;

    while( low <= high )
    {
        middle = low + ( high - low ) * ( key_number - array[low] ) / ( array[high] - array[low] );
        if( key_number > array[middle] )//�ؼ�ֵ���ڲ���ֵ�������Ұ���������
            low = middle + 1;
        else if( key_number < array[middle])//�ؼ�ֵС�ڲ���ֵ���������������
            high = middle - 1;
        else//��ʱkey_number = array[middle] ˵���ҵ���
            return middle;
    }
    return -1;//��ʾ����ʧ��
}

int main()
{
    int array[20];
    int i,key,ans;
    printf("����������ҵ��������飺");
    for( i = 0 ; i < 20 ; i++ )
        scanf("%d",&array[i]);
    printf("������ؼ�ֵ:");
    scanf("%d",&key);
    ans = insert_value_search(array,20,key);
    printf("�����ҵ���������ĵ� %d λ\n",ans);
    return 0;
}
