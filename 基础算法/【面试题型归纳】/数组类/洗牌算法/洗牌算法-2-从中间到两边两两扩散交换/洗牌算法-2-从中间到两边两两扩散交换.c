/***********************************************
������������
��һ������Ϊ2n������{a1,a2,a3,...an,b1,b2,b3,...,bn},ϣ���������{a1,b1,a2,b2,...,an,bn}��
�뿼����û��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)�Ľⷨ

������������⣬��һ�ַ�ʽ��ʵ��һ��ʱ�临�Ӷ�ΪO(n^2)���ռ临�Ӷ�ΪO(1)���㷨��
���㷨�ο�july�����֮�������ĵڶ���˼·��������������һ������ĸ��֣�

�㷨˼�룺
�㷨׼�������������α�from,to��from����ʼλ����n��to����ʼλ����n+1---Ҳ������������ĸ���β���ף�
           �ٶ���һ���α�i,i����ʼλ����from����ֹλ����i������������������Ԫ��
step1i��fromλ�ó�����ÿ��������Ԫ�أ�����i��i+1λ���ϵ�Ԫ��,ֱ��toλ�ý���
step2:from--,to++
������
ֱ��from,to�α�ֱ�ָ��ڶ���Ԫ�غ͵����ڶ���Ԫ��Ϊֹ���㷨����

Author:tmw
date:2017-11-28
************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t)

int* shuffle2_swap_middle2sides( int* array , int n )
{
    int from = n-1;
    int to = n;

    int temp;
    while( from > 0 && to < 2*n-1 )//ѭ�������������ǣ�fromû���ߵ�����ĵ�һ��Ԫ�أ�toû���ߵ���������һ��Ԫ��--��һ�������һ������Ҫ����
    {
        int i = from;
        for( i = from ; i < to ; i = i+2 )
            swap(array[i],array[i+1],temp);//���������ҿ�ʼ
        from--;
        to++;
    }
    return array;
}


int main()
{
    printf("���Գ���!\n");
    int i;

    int array[10] ={1,2,3,4,5,11,22,33,44,55};
    printf("ԭ����Ϊ��");
    for(i=0;i<10;i++)
        printf("%d ",array[i]);
    printf("\n");

    shuffle2_swap_middle2sides(array,5);

    printf("ϴ�ƺ������Ϊ��");
    for(i=0;i<10;i++)
        printf("%d ",array[i]);
    printf("\n");

    return 0;
}
