/*******************************************************************************************
����������-���ֲ��ҡ�
���ֲ���ǰ�᣺
1��˳��洢
2�������������
�㷨˼�룺
��˳��洢��������У�ѡȡ�м�ֵ��Ϊ�Ƚ϶���
1��������ֵ��Ƚ�ֵ��ȣ��򷵻ز��ҳɹ�
2��������ֵС�ڱȽ�ֵ�����ڲ���ֵ���Ұ�����������
3��������ֵ���ڱȽ�ֵ�����ڲ���ֵ���������������
�����ظ��������̣�ֱ����ѯ�ɹ�������ʧ�ܡ�

�㷨���Ӷȣ�O(logn)
Author:tmw
date:2017-10-23
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***���ֲ��Һ���****/
int half_divide_search( int array[] , int number_of_size , int key_number )
{
    int low,high,middle;
    low = 0;
    high = number_of_size - 1;

    while( low <= high )
    {
        middle = ( high + low ) / 2;
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
    ans = half_divide_search(array,20,key);
    printf("�����ҵ���������ĵ� %d λ\n",ans);
    return 0;
}
