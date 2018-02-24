/**************************************************************************
������������
��n���������ҳ�������С��k������ʱ�临�ӶȾ����ܵ�

����һ��ȫ����--����
�㷨���Ӷ�O(nlogn)

����������������ά��һ������Ϊk������
�㷨������
1����������������ǰk����������һ������Ϊk�����ѣ��������ֵ�����ӽ�㣩��
������k������Ϊ����n��������С��k�����������ͽ��Ѻ�ʱO(k)����ʱk���������
�����ڸ���㡣
2������ʣ���(n-k)������������������xi��Ѷ�Ԫ�رȽϣ����С�ڶѶ�Ԫ�أ���
��xi�滻�Ѷ�Ԫ�أ����¶ѣ������ʱ�临�Ӷ�ΪO(logk)��������ڻ���ڶѶ�Ԫ�أ�
��������±�����

ʱ�临�Ӷȷ���
�����������ÿ�α���ʣ���(n-k)����ʱ������Ҫ���¶ѣ���ʱ�临�Ӷ�Ϊ
O((n-k)logk)+nk)=O(nlogk)

��Ȼ����������Ҳ���Բ������������򷽰�����ͨ���ı����ݵĴ洢�ṹ�����öѵ��ص㣬
�öѴ������飬����ͬ�Ĳ�������˼���£����ö������ʱ�临�Ӷ����������������
�����ص�������������

������������ѡ���㷨

Author:tmw
date:2017-11-16
************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t) //��������

/**���������б������**/
void heap_create(int* array , int father_index , int array_len)
{
    array[0] = 0;//�涨����Ԫ�ش������1�ŵ�ַ��ʼ��
    int child_index;
    int temp = array[father_index];//����㲻һ�����ں��ӽ�㣬������
    for( child_index = 2*father_index ; child_index <= array_len ; child_index=child_index*2 )
    {
        if( child_index < array_len && ( array[child_index] < array[child_index+1] ) )//�ҳ����Һ��ӽ��Ľϴ�ֵ�����������븸���Ƚ�
            child_index++;//���ϣ�array[child_index]��ֵ��������ӽ�㣬�����������ֵ������Ƚ�
        if( array[child_index] <= temp )//�������ֵ�Ƚ�
            break;
        //���ڸ�����ֵ�򽻻�
        array[father_index] = array[child_index];
        father_index = child_index;
    }
    array[father_index] = temp;//��ɽ���
}

/**��k���������б������**/
void find_min_k_numbers_using_max_heapSort(int* array , int k , int array_len)
{
    //�����Ϸ��Լ��
    if(k==0||array==NULL||array_len==0||k>array_len)
        return;

    int father_node;
    //��k�������ж�����
    for( father_node = k/2 ; father_node > 0 ; father_node-- )//��Ϊ�����1��λ�������kʵ��Ӧ�ô�k+1����
        heap_create(array,father_node,k);

    //����ʣ���(n-k)��Ԫ�أ���Ѷ�Ԫ�رȽϣ�С����Ѷ�Ԫ�ؽ�����ͬʱ���¶ѽ�������
    int i;
    for( i = k+1 ; i <= array_len ; i++ )
    {
        //int x = array[i];
        int temp11;
        if( array[i] < array[1] )//С�ڶѶ�Ԫ�أ��򽻻�������k��Ԫ�صĶ�
        {
            swap(array[i],array[1],temp11);//����
            heap_create(array,1,k);
        }
    }//���ϣ�array����ǰk��������n����������С��k����
    for( i = 1 ; i <= k ; i++ )//�����±��1��ʼ
        printf("%d ",array[i]);
    printf("\n\n");
}

int main()
{
    printf("���Դ���\n");
    int k = 4;
    int i;

    int a2[9] = {0,1,8,23,6,90,5,8};//������ЧԪ�ش�λ��1��ʼ
    printf("ԭ����");
    for(i=1;i<8;i++)
        printf("%d ",a2[i]);
    printf("\n��С��%d������\n",k);
    find_min_k_numbers_using_max_heapSort(a2,k,7);

    int a4[11] = {0,100,56,23,7,17,0,23,65,2};
    printf("ԭ����");
    for(i=1;i<10;i++)
        printf("%d ",a4[i]);
    printf("\n��С��%d������\n",k);
    find_min_k_numbers_using_max_heapSort(a4,k,9);
    return 0;
}
