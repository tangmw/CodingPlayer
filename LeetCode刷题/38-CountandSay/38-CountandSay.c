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
1）将初值n=1时的result[]结果存成1
2）遍历result数组（len为边界条件），有相同元素则count++，将count转成char，用临时数组temp存count和它对应的数字，注意字符串末尾'\0'标记
3）将临时数组值strcmp到result_t（该数组初始化为全空）；每经过一次n的值改变，将result_t数组值strcmp到result中，
更新result的len边界条件，清空result_t数组
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
    strcpy(result_t,"");//初始化result_t,将它全部清零

    for( i = 1 ; i < n ; i++ )
    {
        len = strlen(result);
        for( j = 0 ; j < len ; j++ )
        {
            if( result[j] == result[j+1] )
                count++;
            else
            {
                temp[0] = count + '0'; //int型转化成char型
                temp[1] = result[j];
                temp[2] = '\0';

                strcat(result_t,temp);
                count = 1;
            }
        }
        strcpy(result,result_t);
        strcpy(result_t,"");//清空result_t字符串
    }
    for( i = 0 ; i <strlen(result) ; i++ )
        printf("%c ",result[i]);
    printf("\n");
    return result;
}

int main()
{
    int num;
    printf("情输入数字!\n");

    scanf("%d",&num);

    countAndSay(num);
    return 0;
}
