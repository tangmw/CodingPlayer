/***********************************************
������������
����һ���������飬�����������������������0.������������
һ�������������һ�������飬ÿ�������鶼��һ���͡�����
��������ĺ͵����ֵ��

���������Կ��ɣ�������һ���ϼ�����ǰԪ��a[i]Ҫ��Ҫ��������ͼ��������Լ����¿���һ���ϼ���

����ѡ��Ĺؼ����ڣ�ʹ�úϼ�ֵ���

����֪�����������һ����ʹ�ͼ�������ˣ��ж����ر���ˣ�
�����ǰ�ϼ�Ϊ������a[i]��������ϼ�
�����ǰ�ϼ�Ϊ������a[i]���¿���һ���ϼ�

д����ѧ�����ǣ�sum = max(curren_sum,0)+a[i],ʽ���У�curren_sumΪ��ǰ�ͼ��ĺͣ�sum��¼�ͼ�������

Author:tmw
date:2017-11-21
************************************************/
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a>b?a:b)
//int max_sub_array_sum( int *array , int array_len )
//{
//    int i;
//    int sum = 0;
//    int temp_sum;
//    int curren_sum = array[0];//array[i]��1��ʼ����
//    for( i = 1 ; i < array_len ; i++ )
//    {
//        temp_sum = curren_sum;//����һ��curren_sum�仯ǰ��ֵ
//        curren_sum = max(curren_sum,0)+array[i];
//        //�����sumΪsum�仯ǰ��ֵ��sum���µ�ǰ���ǣ��µ�sumҪ��ԭ��sum��
//        sum=max(max(temp_sum,curren_sum),sum);
//    }
//    return sum;
//}
/**�Ż����ҵ��������������͵��±겢���������������**/
int max_sub_array_sum_find_index( int *array , int array_len )
{
    int i=1;
    int sum = 0;
    int temp_sum;
    int curren_sum = array[0];//array[i]��1��ʼ����

    int index_left;
    for( i = 1 ; i < array_len ; i++ )
    {
        temp_sum = curren_sum;//����һ��curren_sum�仯ǰ��ֵ
        curren_sum = max(curren_sum,0)+array[i];
        if( curren_sum <= 0 )//curren_sum<=0ʱ��˵�����ϵ�ǰ��a[i]ֵ������0��Ӧ����������µ�������������λӦ����i�ĺ�һλ
            index_left = i+1;
        //�����sumΪsum�仯ǰ��ֵ��sum���µ�ǰ���ǣ��µ�sumҪ��ԭ��sum��
        sum=max(max(temp_sum,curren_sum),sum);
    }

    /**����Ĵ�������֪���������������Լ���λ֮���ҵ�����ĩβ����ӡ**/
    printf("�������������Ϊ��");
    printf("%d + ",array[index_left]);
    int find_sum = array[index_left];//find_sum����������temp_sum = sum
    i=index_left+1;
    while( i < array_len )
    {
        find_sum = find_sum + array[i];
        if( find_sum != sum )
        {
            printf("%d + ",array[i]);
            i++;
        }
        else
            break;
    }
    printf("%d\n",array[i]);//��ʱ��iΪ�������������͵�ĩλ
    return sum;
}


int main()
{
    printf("���Դ���!\n");
    int i;

    int a1[8] = {1,-2,3,10,-4,7,2,-5};
    printf("ԭ����Ϊ��");
    for(i = 0 ; i < 8 ; i++ )
        printf("%d ",a1[i]);
    printf("\n");
    int result1 = max_sub_array_sum_find_index(a1,8);
    printf("����������Ϊ %d\n",result1);

    printf("\n");

    int a2[9] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("ԭ����Ϊ��");
    for(i = 0 ; i < 9 ; i++ )
        printf("%d ",a2[i]);
    printf("\n");
    int result2 = max_sub_array_sum_find_index(a2,9);

    printf("����������Ϊ %d\n",result2);

    return 0;
}
