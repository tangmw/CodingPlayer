/***********************************************
������������
һ��̨���ܹ���n�������һ�ο�����1����Ҳ������2�������ܹ��ж���������

ͨ��ö�ٿ��Է��֣�̨�׼��������������¹�ϵ
���� 0 1 2 3 4 5 6  7  8
���� 0 1 2 3 5 8 13 21 35...

������������������Է��֣��ӵ�������ʼ��������һ��쳲���������

Author:tmw
date:2017-11-23
************************************************/
#include <stdio.h>
#include <stdlib.h>

int jump_stairs_fibonacci(int n)
{
    int F[100];
    F[0] = 0;F[1] = 1;F[2] = 2;
    if(n<=2)
        return F[n];
    else
        return jump_stairs_fibonacci(n-1) + jump_stairs_fibonacci(n-2);
}

int main()
{
    printf("���Դ���!\n");
    int n1,n2,n3,res1,res2,res3;

    n1=5;
    res1 = jump_stairs_fibonacci(n1);
    printf("��%d��̨�׹���%d������\n",n1,res1);

    n2=10;
    res2 = jump_stairs_fibonacci(n2);
    printf("��%d��̨�׹���%d������\n",n2,res2);

    n3=45;
    res3 = jump_stairs_fibonacci(n3);
    printf("��%d��̨�׹���%d������\n",n3,res3);

    return 0;
}
