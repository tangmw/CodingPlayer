/**********************************************************************************************************

LeetCode----[easy] 28-Implement strStr

Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

[Ans:]
Method:���⿼���ַ�����ƥ���㷨,�������sunday�㷨�����Ӷȴ�󽵵� 74����������ƽ����ʱ3ms
Author:tmw
date:2017-9-13

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle)
{
    int hay_i = 0;
    int need_j = 0;
    int temp = 0;

    int hay_len = strlen(haystack);
    int need_len = strlen(needle);

    //��ʼ�����
    if( ( hay_len == 0 && need_len == 0 ) || ( hay_len !=0 && need_len == 0 ) )
        return 0;
    if( hay_len == 0 && need_len != 0 )
        return -1;

    while( hay_i < hay_len )
    {
        if( haystack[hay_i] == needle[need_j] )
        {
            hay_i++;
            need_j++;
            if( need_j == need_len )
            {
                printf("success!\n");
                return (hay_i - need_len);
            }
        }
        else
        {
            hay_i = hay_i - need_j + need_len ;//����ƥ�䣬��hay_i�α�Ų����need�Һ�һλ��Ѱ��need���ǲ�����������Һ�һλ��ͬ���ַ�
            temp = need_len-1;
            while( temp >= 0 )//Ѱ��need���Ƿ���ڸ�����Һ�һλ��ͬ���ַ�
            {
                if( needle[temp] != haystack[hay_i] )
                    temp--;
                else
                    break;
            }

            if( temp < 0 )//˵��û���ҵ������hay_i�α���������ƶ�һλ��need_j�α��0λ������ǰ����ж�if( haystack[hay_i] == needle[need_j] )
            {
                hay_i = hay_i+1;
                need_j = 0;
            }
            else//˵���ҵ�need��������Һ�һλ��ͬ���ַ�����hay_i�α귵�ص����need_j����λ��λ�ã�����ǰ����ж�if( haystack[hay_i] == needle[need_j] )
            {
                need_j = 0;
                hay_i = hay_i - temp;
            }
        }
    }
    printf("failed!\n");
    return -1;
}

int main()
{
    char* haystack;
    char* needle;
    int ans;

    haystack = (char*)malloc(100*sizeof(char));
    needle = (char*)malloc(100*sizeof(char));

    printf("hay_stack input!\n");
    scanf("%s",haystack);

    printf("needle input!\n");
    scanf("%s",needle);

    ans = strStr( haystack , needle );
    printf("%d ",ans);
    printf("\n");
    return 0;
}
