/*******************************************************************************************
��������
�ѵ����ʣ�
����һ����ȫ��������
1��������ÿ������ֵ�����ڻ���������Һ��ӽ���ֵ����Ϊ�󶥶�
2��������ÿ������ֵ��С�ڻ���������Һ��ӽ���ֵ����ΪС����
��ˣ��ڶѵĶ����п��Է��֣�������ֵһ���Ƕ������н��������С��ֵ

�������㷨���Դ󶥶�Ϊ����
����˼�룺
1�����������n��Ԫ�ص����й����һ���󶥶ѡ���ʱ���е����ֵ���Ǹ�����ֵ��
2������������ߣ�����������������е����һ��Ԫ�ؽ������������о�����Ϊ��ĩβԪ�ؾ������ֵ����
3����ʣ���(n-1)��Ԫ�ص��������¹����һ���󶥶ѣ����°���2���Ĳ���ִ��

����ظ����ϲ�����һ����������о�������ͱ���˵�������������

�����Ӷȷ�����
�ڹ����ѵĹ����У�����ÿһ����Ҷ�ӽ��Ľ��(n/2)��˵��������αȽϺ�һ�λ��������������������
�ѵĸ��Ӷ�ΪO(n);
������ʱ����i��ȡ�Ѷ���¼�ؽ�����Ҫ��O(logi)��ʱ�䣨��ȫ������ĳ����㵽�����ĸ߶�Ϊlog(i)+1����
������Ҫȡn-1�ζѶ���¼����ˣ��ؽ��ĸ��Ӷ�ΪO(nlogn)

Author:tmw
date:2017-11-4
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//����������ת��ɴ󶥶�����
void heap_sort( int array[] , int node_have_child_index , int array_len )
{
    array[0] = 0;//�涨����Ԫ�ش������1�ŵ�ַ��ʼ��
    int child_index;
    int temp = array[node_have_child_index];//tempֵΪ��ǰ������ֵ����ʱ����һ�������亢�ӽ�㣬��Ҫ������

    for( child_index = 2*node_have_child_index ; child_index <= array_len ; child_index = child_index*2 )//child_indexʼ��Ϊ���ӽ���нϴ�ֵ���±�
    {
        if( child_index < array_len && ( array[child_index] < array[child_index+1] ) )//����Һ��ӵ�ֵ�������ӣ���child_indexΪ�Һ����±�
            child_index++;
        if( array[child_index] <= temp )
            break;
        //���ӽ���ֵ���ڸ�����ֵ---����
        array[node_have_child_index] = array[child_index];
        node_have_child_index = child_index;
    }
    array[node_have_child_index] = temp;
}

int* heap_sort_all( int array[] , int array_len )
{
    int i;
    //�Ƚ�������������ж�����
    for( i = array_len/2 ; i > 0 ; i-- )
        heap_sort(array,i,array_len);

    //�������ȡ�������������һ��Ԫ�ػ�λ�ã������¶�ʣ��Ԫ���ٶ���������ظ�
    for( i = array_len ; i > 0 ; i-- )
    {
        int temp;
        temp = array[i];
        array[i] = array[1];
        array[1] = temp;
        heap_sort(array,1,i-1);
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
    for( i = 1 ; i <= array_size ; i++ )
        scanf("%d",&array[i]);

    array = heap_sort_all( array , array_size );
    printf("�������������Ԫ��˳�����Ϊ��\n");
    for( i = 1 ; i <= array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
