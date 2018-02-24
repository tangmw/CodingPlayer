/**********************************************************************************************************

LeetCode----[easy] 28-Implement strStr

Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

[Ans:]
Method:本题考查字符串的匹配算法,本题采用sunday算法，复杂度大大降低 74个测试用例平均用时3ms
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

    //初始化检查
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
            hay_i = hay_i - need_j + need_len ;//若不匹配，则hay_i游标挪动到need右后一位，寻找need中是不是有与这个右后一位相同的字符
            temp = need_len-1;
            while( temp >= 0 )//寻找need中是否存在跟这个右后一位相同的字符
            {
                if( needle[temp] != haystack[hay_i] )
                    temp--;
                else
                    break;
            }

            if( temp < 0 )//说明没有找到，则把hay_i游标继续往右移动一位，need_j游标归0位，继续前面的判断if( haystack[hay_i] == needle[need_j] )
            {
                hay_i = hay_i+1;
                need_j = 0;
            }
            else//说明找到need中与这个右后一位相同的字符，则将hay_i游标返回到相对need_j归零位的位置，继续前面的判断if( haystack[hay_i] == needle[need_j] )
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
