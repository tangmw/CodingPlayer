/**********************************************************************************************************

LeetCode----[easy] 38-Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

[Ans:]
Method:
1������ֵn=1ʱ��result[]������1
2������result���飨lenΪ�߽�������������ͬԪ����count++����countת��char������ʱ����temp��count������Ӧ�����֣�ע���ַ���ĩβ'\0'���
3������ʱ����ֵstrcmp��result_t���������ʼ��Ϊȫ�գ���ÿ����һ��n��ֵ�ı䣬��result_t����ֵstrcmp��result�У�
����result��len�߽����������result_t����
Author:tmw
date:2017-9-14

***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000
char* countAndSay(int n)
{
    char* result;
    char result_t[MAX_SIZE];
    int i = 0;
    int j = 0;
    int len = 0;
    int count = 1;
    char temp[3];

    result = (char*)malloc(MAX_SIZE*sizeof(char));

    result[0] = '1';
    strcpy(result_t,"");//��ʼ��result_t,����ȫ������

    for( i = 1 ; i < n ; i++ )
    {
        len = strlen(result);
        for( j = 0 ; j < len ; j++ )
        {
            if( result[j] == result[j+1] )
                count++;
            else
            {
                temp[0] = count + '0'; //int��ת����char��
                temp[1] = result[j];
                temp[2] = '\0';

                strcat(result_t,temp);
                count = 1;
            }
        }
        strcpy(result,result_t);
        strcpy(result_t,"");//���result_t�ַ���
    }
    for( i = 0 ; i <strlen(result) ; i++ )
        printf("%c ",result[i]);
    printf("\n");
    return result;
}

int main()
{
    int num;
    printf("����������!\n");

    scanf("%d",&num);

    countAndSay(num);
    return 0;
}
