/***********************************************
������������
����һ���������飬���������������˳��ʹ����������λ��
�����ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�Ҫ��ʱ�临�Ӷ�
ΪO(n)

ǰ��ָ����������
�㷨׼����
���������α�--front��back��һǰһ��frontָ������ĵ�һ��Ԫ�أ�
backָ���һ��Ԫ�ص�ǰһ��Ԫ��
����һ���α�--rear ָ����������һ��Ԫ��

�㷨����˼�룺
rear��Ϊ����Ԫ�أ���frontָ���Ԫ��Ϊ���������α�ǰ�ƣ�back�α겻����
��frontָ���Ԫ��Ϊż������back�α�ǰ�ƣ�backָ���Ԫ����frontָ���
Ԫ�ؽ�����ֱ��front�α�Ų����rear��ǰһλ�ж�����ż�������߽�������ż����
֮��back�α�ǰ��һλ��backָ���Ԫ����rear������Ԫ�ؽ���


����Ĵ����õķ�����һ�ο����еġ�ǰ��ָ�������������ķ���

���ڵ�2�ֿ���ʵ��--ǰ��ָ��������ŵķ�������july�����֮����P46-47

Author:tmw
date:2017-11-24
************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,z) (z=x,x=y,y=z)
int* odd_even_sort_like_qsort_2(int *array , int array_len)
{
    int front,back,rear,temp;
    front = 0;
    back = -1;//����Ԫ�ش�0��ʼ����
    rear = array_len - 1;

    while( front < rear )
    {
        while( array[front]%2 == 0 && front < rear )
            front++;
        //��array[front]ֵΪ����ʱ������
        if( array[front]%2!=0 )
        {
            back++;
            swap(array[back],array[front],temp);
            front++;
        }
    }
    //��ʱ��front==rear
    back++;
    swap(array[back],array[front],temp);
    return array;
}


int main()
{
    printf("���Դ��룡\n");
    int i;

    int a1[10] = {6,2,3,4,7,8,1,0,-1,-5};
    printf("ԭ����Ϊ��");
    for(i=0;i<10;i++)
        printf("%d ",a1[i]);
    printf("\n");
    printf("��ż�����Ϊ��");
    odd_even_sort_like_qsort_2(a1,10);
    for(i=0;i<10;i++)
        printf("%d ",a1[i]);
    printf("\n");

    int a2[16] = {23,3,28,5,6,100,54,-2,-17,2,-36,0,26,-11,9,16};
    printf("ԭ����Ϊ��");
    for(i=0;i<16;i++)
        printf("%d ",a2[i]);
    printf("\n");
    printf("��ż�����Ϊ��");
    odd_even_sort_like_qsort_2(a2,16);
    for(i=0;i<16;i++)
        printf("%d ",a2[i]);
    printf("\n");


    return 0;
}

