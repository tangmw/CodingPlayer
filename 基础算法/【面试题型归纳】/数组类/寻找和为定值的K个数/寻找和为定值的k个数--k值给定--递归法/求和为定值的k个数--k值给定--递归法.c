/***********************************************
������������
������������n��sum��Ҫ�������������������ȡ��
��������ʹ�����ǵĺ͵���sum�����������п��ܵ�����г���

�ⷨ���ݹ鷨
��������n�������Һ�Ϊsum��������ϣ���ô���Խ�����ת��Ϊ��
1����ѡ��n����������ʣ���n-1�������Һ�Ϊsum-val(n)����
2������ѡ��n����������ʣ���n-1�������Һ�Ϊsum����

�����n�ǲ����ģ����Ե�������ݹ���������������������
��һ��Ŀ��ֵ��ʹ����ֵ��sum-val(i)-val(j)-val(k)..��ֵ���

�����������������Ϊ��ֵ������k���������
Author:tmw
date:2017-11-21
************************************************/
#include <stdio.h>
#include <stdlib.h>

int result[100] = {0};//��������鶨���ȫ�ֱ����Ǳ����ڵݹ���ú���ʱ���ظ������ڴ�ռ�
int j = 0;
void choose_k_numbers_equal_to_sum(int* array , int array_len , int sum , int k )
{
    //����Ϸ��Լ�� && �ݹ����
    if( !array || array_len <=0 || sum <= 0 )
        return;
    //�����ӡ
    if( j > 0 )
    {
        if( array[array_len-1] == sum && j == k - 1)//���һֱ�ݹ飬���sumֵ��nֵ�ǲ��ϱ仯�ģ�sum-val(i)-val(j)-val(k)..
        {
            int i;
            for( i = 0 ; i < j ; i++ )
                printf("%d + ",result[i]);
            //��ʱarray[n-1]��û�и���result�����У����Ҫ������ӡ
            printf("%d \n",array[array_len-1]);
        }
    }
    result[j++] = array[array_len-1];
    choose_k_numbers_equal_to_sum(array,array_len-1,sum-array[array_len-1],k);//��n��ǰn-1��������sum-val(n)
    j--;//����nʱ���α�Ҫ����
    choose_k_numbers_equal_to_sum(array,array_len-1,sum,k);//����n��ǰn-1��������sum
}


int main()
{
    printf("���Դ���\n");
    int i;
    int k=4;
    int a[12] = {1,2,4,5,7,11,54,3,8,6,10,13};
    printf("ԭ�������£�\n");
    for(i=0;i<12;i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("�����к�Ϊ10��%d���������Ϊ��\n",k);
    choose_k_numbers_equal_to_sum(a,12,10,k);

    int b[15] = {2,8,32,15,1,6,9,10,7,6,13,14,20,0,5};
    printf("ԭ�������£�\n");
    for(i=0;i<15;i++)
        printf("%d ",b[i]);
    printf("\n");
    printf("�����к�Ϊ10��%d���������Ϊ��\n",k);
    choose_k_numbers_equal_to_sum(b,15,10,k);

    return 0;
}
