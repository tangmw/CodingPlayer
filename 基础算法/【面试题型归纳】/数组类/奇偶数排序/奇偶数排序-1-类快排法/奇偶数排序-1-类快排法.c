/***********************************************
������������
����һ���������飬���������������˳��ʹ����������λ��
�����ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�Ҫ��ʱ�临�Ӷ�
ΪO(n)

��Ͽ��������˼�룺һ�ο����ܽ�С������Ԫ�ص�ֵȫ����ߣ���������Ԫ�ص�ֵȫ���ұߣ�
��ô�ƶ���֮��һ�ο��ţ�Ҳ��������������λ��ǰ�벿�֣�����ż��λ�ں�벿��

����Ĵ����õķ�����һ�ο����еġ���ͷ���м��������ķ���

Author:tmw
date:2017-11-23
************************************************/
#include <stdio.h>
#include <stdlib.h>

int* odd_even_sort_like_qsort(int *array , int array_len)
{
    //����Ϸ��Լ��
    if(!array||array_len==0)
        return NULL;
    int low = 0;
    int high = array_len-1;
    int target = array[low];//ȡ��һ������Ϊ����Ԫ�أ�����
    while( low < high )
    {
        while( array[high]%2 == 0 && low < high )//��벿��Ϊż��
            high--;
        array[low] = array[high];
        while( array[low]%2 != 0 && low < high )
            low++;
        array[high] = array[low];
    }
    array[low] = target;//����ţ�����Ҫ�ݹ飬һ���Ծ���������������λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿��
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
    odd_even_sort_like_qsort(a1,10);
    for(i=0;i<10;i++)
        printf("%d ",a1[i]);
    printf("\n");

    int a2[16] = {23,3,28,5,6,100,54,-2,-17,2,-36,0,26,-11,9,16};
    printf("ԭ����Ϊ��");
    for(i=0;i<16;i++)
        printf("%d ",a2[i]);
    printf("\n");
    printf("��ż�����Ϊ��");
    odd_even_sort_like_qsort(a2,16);
    for(i=0;i<16;i++)
        printf("%d ",a2[i]);
    printf("\n");

    return 0;
}
