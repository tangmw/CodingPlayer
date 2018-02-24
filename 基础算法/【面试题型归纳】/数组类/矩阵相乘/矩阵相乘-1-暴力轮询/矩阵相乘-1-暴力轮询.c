/***********************************************
������������
��������ĳ˷�������һ������A����������һ������
B���������ʱ���ܶ��塣���磺���A��m���У�*n���У��ľ���B��
n*p�ľ������ǵĳ˻�C��һ��m*p�ľ�������ʵ�־���˷�������
�ǵ������ģ�ϴ�ʱ���Ż�������

��������������⣬����һ��ʱ�䷢����������ֻ��������Ӷ�ΪO(n^2)
�ı�����ѯ���������£�

Author:tmw
date:2017-11-26
************************************************/
#include <stdio.h>
#include <stdlib.h>

void matrix_multiplication_travel(int matrix_A[][3] , int matrix_B[][1] , int matrix_C[][1] , int row_A , int col_A , int col_B )
{
    int i,j,k;//i,j�ֱ���A������к��е��α�;k��B�����е��α�
    k=0;
    for(k=0;k<col_B;k++)
    {
        for( i=0;i<row_A;i++)
        {
            matrix_C[i][k] = 0;//��ʼ���ۼ�ֵ
            for( j = 0 ; j < col_A ; j++ )
                matrix_C[i][k] = matrix_A[i][j]*matrix_B[j][k] + matrix_C[i][k];
        }
    }
}

int main()
{
    printf("���Դ���!\n");
    int j,i;

    int matrix_A[2][3]={{10,2,3},{4,5,6}};
    int matrix_B[3][1]={{1},{4},{8}};
    int matrix_C[2][1]={{0},{0}};

    printf("matrix_A����Ϊ��\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
            printf("%d ",matrix_A[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("matrix_B����Ϊ��\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
            printf("%d ",matrix_B[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("matrix_C����Ϊ��\n");
    matrix_multiplication_travel(matrix_A,matrix_B,matrix_C,2,3,1);
    for(i=0;i<2;i++)
    {
        for(j=0;j<1;j++)
            printf("%d ",matrix_C[i][j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}
