/*******************************************************************************************
��ð������
����˼�룺�����Ƚ����ڼ�¼�Ĺؼ��֣�������򼴽�����ֱ��û�з���ļ�¼Ϊֹ��

���Ӷȷ�����
1������õ��������Ҫ����ı����������ģ���������ð��������룬����У�n-1���αȽϣ�û
�����ݽ�����ʱ�临�Ӷ�ΪO(n)��
2��������������Ҫ����ı�������ģ������(n-1)+(n-2)+...+3+2+1 = n*(n-1)/2�αȽϺ�n*(n-1)/2
�ε����ݽ�����ʱ�临�Ӷ�ΪO(n^2)��
���ԣ�ð��������ܵ�ʱ�临�Ӷ�ΪO(n^2)
Author:tmw
date:2017-10-31
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**ð������**/
int* Bubble_Sort( int array[] , int array_size )
{
    int i,j,temp;
    int flag = 1;//flag��ʼ��Ϊ�棬��������Ѿ���������������ݽ��������---���ٱ�������Ⱦͽϸߵ����еıȽϴ���

    for( i = 0 ; i < array_size && flag ; i++ )
    {
        flag = 0;//����һ��i����flag����Ϊ0��˵��i�����Ѿ������ˣ�������Ų��i�ٶ�i���½��������飬�Ϳ���ֱ������forѭ��
        for( j = array_size - 2 ; j >= i ; j-- )
        {
            if( array[j] > array[j+1] )//�������ݽ���
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 1;
            }
        }
    }
    return array;
}

int main()
{
    int *array;
    int array_size,i;

    printf("���������鳤��\n");
    scanf("%d",&array_size);
    array = (int*)malloc(array_size*sizeof(int));

    printf("������%d������Ԫ��\n",array_size);
    for( i = 0 ; i < array_size ; i++ )
        scanf("%d",&array[i]);

    array = Bubble_Sort(array,array_size);
    printf("��ð�������˳�����Ϊ��\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);

    return 0;
}
