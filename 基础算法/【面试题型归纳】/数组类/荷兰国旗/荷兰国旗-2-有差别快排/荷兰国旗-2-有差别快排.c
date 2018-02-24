/***********************************************
������������
����n����������ֲ�ͬ����ɫ������������һ����ͨ��
������������������ʹ�ô����ҵ��������Ǻ��򡢰�������

�޲��Ŀ����ܸо�û�кܺõ�������Ŀ������������ֻ�к������ͺ���
��Ӧ���־���ֻ��0,1,2����ˣ�����ר�����ֻ������Ԫ�ص�������һ��
�в��Ŀ����㷨��

�������ָ�룺front current rear
�㷨��ʼ��front��current�α궼ָ��������ף�rear�α�ָ�������β
1����current�α���ָ���Ԫ��Ϊ0ʱ����front�α���ָԪ�ؽ�����front++ current++
2����current�α���ָ���Ԫ��Ϊ1ʱ����������current++
3����current�α���ָ���Ԫ��Ϊ2ʱ����rear�α���ָ���Ԫ�ؽ�����rear--

Author:tmw
date:2017-11-24
************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t)

int* Dutch_flag_like_fast_sort( int* array , int array_len )
{
    int front,current,rear,temp;
    front = current = 0;
    rear = array_len - 1;
    while(current<=rear)
    {
        if( array[current] == 0 )
        {
            swap(array[current],array[front],temp);
            current++;front++;
        }
        else if( array[current] == 1 )
            current++;
        else
        {
            swap( array[current],array[rear],temp);
            rear--;
        }
    }
    return array;
}


int main()
{
    printf("���Գ���!\n");
    int i;
    int* res;res=(int*)malloc(100*sizeof(int));

    int a1[13] = {0,2,1,1,1,2,0,0,2,0,1,1,2};
    printf("ԭ����Ϊ��");
    for(i=0;i<13;i++)
        printf("%d ",a1[i]);
    printf("\n");
    printf("���к������Ϊ��");
    res = Dutch_flag_like_fast_sort(a1,13);
    for(i=0;i<13;i++)
        printf("%d ",res[i]);

    return 0;
}
