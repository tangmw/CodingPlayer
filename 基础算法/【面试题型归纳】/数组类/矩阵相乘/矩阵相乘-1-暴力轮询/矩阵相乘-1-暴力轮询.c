/***********************************************
【问题描述】
两个矩阵的乘法仅当第一个矩阵A的行数和另一个矩阵
B的列数相等时才能定义。例如：如果A是m（行）*n（列）的矩阵，B是
n*p的矩阵，它们的乘积C是一个m*p的矩阵。请编程实现矩阵乘法，并考
虑当矩阵规模较大时的优化方法。

笔者想了想这道题，想了一段时间发现能力所及只能想出复杂度为O(n^2)
的暴力轮询，代码如下：

Author:tmw
date:2017-11-26
************************************************/
#include <stdio.h>
#include <stdlib.h>

void matrix_multiplication_travel(int matrix_A[][3] , int matrix_B[][1] , int matrix_C[][1] , int row_A , int col_A , int col_B )
{
    int i,j,k;//i,j分别是A矩阵的行和列的游标;k是B矩阵列的游标
    k=0;
    for(k=0;k<col_B;k++)
    {
        for( i=0;i<row_A;i++)
        {
            matrix_C[i][k] = 0;//初始化累加值
            for( j = 0 ; j < col_A ; j++ )
                matrix_C[i][k] = matrix_A[i][j]*matrix_B[j][k] + matrix_C[i][k];
        }
    }
}

int main()
{
    printf("测试代码!\n");
    int j,i;

    int matrix_A[2][3]={{10,2,3},{4,5,6}};
    int matrix_B[3][1]={{1},{4},{8}};
    int matrix_C[2][1]={{0},{0}};

    printf("matrix_A数组为：\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
            printf("%d ",matrix_A[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("matrix_B数组为：\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
            printf("%d ",matrix_B[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("matrix_C数组为：\n");
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
