/***********************************************
������������
һ��̨���ܹ���n�������һ�ο�����1����Ҳ������2�������ܹ��ж���������

ͨ��ö�ٿ��Է��֣�̨�׼��������������¹�ϵ
���� 0 1 2 3 4 5 6  7  8
���� 0 1 2 3 5 8 13 21 35...

ͬ����쳲��������У����õݹ�ᷢ�֣�Խ���ݹ�ĺ��棬�����ظ�����ܶ࣬
ʱ�仨�ѱȽϴ���˲��õ��ƣ�ÿ��λ�õ�ֵֻ����һ�Σ�����ʡ��ʱ��

Author:tmw
date:2017-11-23
************************************************/
#include <stdio.h>
#include <stdlib.h>

int jump_stairs_fibonacci_recursive(int n)
{
    int a[3] = {0,1,2};//����֮��Ķ����г�
    if(n<3)
        return a[n];
    int i;
    int front_1 = 1;//��ǰ����ֵ��ǰ��λ
    int front_2 = 2;//��ǰ����ֵ��ǰһλ
    int current;//��ǰ����ֵ
    for(i=2;i<n;i++)
    {
        current = front_1+front_2;
        front_1=front_2;//����front_1,�൱���α�����
        front_2=current;//����front_2���൱���α�����
    }

    return current;
}

int main()
{
    printf("���Դ���!\n");
    int n1,n2,n3,res1,res2,res3;

    n1=5;
    res1 = jump_stairs_fibonacci_recursive(n1);
    printf("��%d��̨�׹���%d������\n",n1,res1);

    n2=10;
    res2 = jump_stairs_fibonacci_recursive(n2);
    printf("��%d��̨�׹���%d������\n",n2,res2);

    n3=45;
    res3 = jump_stairs_fibonacci_recursive(n3);
    printf("��%d��̨�׹���%d������\n",n3,res3);

    return 0;
}
