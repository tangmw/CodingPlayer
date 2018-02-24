/**********************************************************************************************************

LeetCode----[easy] 66-Plus One

Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.

[Ans:]
Method:
1����Ҫmalloc�����ֻ��һ�֣����Ǽ�һ֮ǰ���������Ԫ�ض�Ϊ9����ʱ������Ԫ����0����λmalloc��1
2�����������������
    һ���ǣ����λ��ε�λ��λ���ε�λ��1����λ��0
    һ���ǣ�����λ����λ��1

Author:tmw
date:2017-9-22

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i = 0;
    int mark = 0;
    int *array;//��¼���ܻ��λ��λ�� =---Ϊ0

    if(digitsSize == 0)
        return 0;

    array = (int *)malloc(digitsSize*sizeof(int));
    memset(array,0,digitsSize);

    //��Ҫmalloc�����
    for( i = 0 ; i < digitsSize ; i++ )
    {
        if( digits[i] == 9 )
        {
            array[i] = 1;
            mark++;
        }
    }
    i--;
//    printf("i = %d\n",i);
//    printf("mark = %d\n",mark);
    //��λ��λ�����
    int j = 0;
    if( mark == digitsSize )
    {
        *returnSize = digitsSize + 1;
        digits = (int*)realloc(digits,(digitsSize+1)*sizeof(int));
        digits[0] = 1;
        for( j = 1 ; j < ( digitsSize + 1 ) ; j++ )
            digits[j] = 0;
    }
    //�ε�λ��λ�����
    else
    {
        int markey = 0;
        *returnSize = digitsSize;
        while( digits[i] == 9 )
        {
            i--;
            markey++;//��¼�ӵ�λ��ʼ���ж��ٸ�������9
        }
        printf("markey = %d\n",markey);
        if( markey ==0 )//û�н�λ
        {
            digits[digitsSize-1] = digits[digitsSize-1] + 1;
            for( j = 0 ; j < *returnSize ; j++ )
                printf("%d ",digits[j]);
            printf("\n");

            return digits;
        }
        else//��λ�н�λ����¼��λ����Ϊ9�����λλ�ã��ӵ�λ�����λ��֮�������Ԫ����0�����λ�õ�Ԫ���Լ�1
        {
            for( j = digitsSize - markey ; j < digitsSize ; j++ )
                digits[j] = 0;
            digits[digitsSize - markey - 1] = digits[digitsSize - markey - 1] + 1;

            for( j = 0 ; j < *returnSize ; j++ )
                printf("%d ",digits[j]);
            printf("\n");

            return digits;
        }
    }
    for( j = 0 ; j < *returnSize ; j++ )
        printf("%d ",digits[j]);
    printf("\n");
    return digits;
}
int main()
{
    int* digits;
    int digitsSize;
    int* returnSize;
    int i = 0;
    printf("Please input your digitsSize\n");
    scanf("%d",&digitsSize);

    digits = (int*)malloc(digitsSize*sizeof(int));
    returnSize = (int*)malloc(sizeof(int));
    printf("input the digits:\n");
    for( i = 0 ; i < digitsSize ; i++ )
        scanf("%d",&digits[i]);
    *returnSize = digitsSize;
    plusOne(digits,digitsSize,returnSize);
    return 0;
}
