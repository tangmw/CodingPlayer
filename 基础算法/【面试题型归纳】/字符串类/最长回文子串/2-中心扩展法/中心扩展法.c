/*******************************************************************************************
【问题描述】
给定一个字符串，求它的最长回文子串的长度

根据回文字串的特征，可以从回文的“中心”出发，以“中心”向两边逐渐扩展，然后枚举中心位置，
记录并更新最长回文子串长度

算法大致会有两层循环，外层大循环是枚举中心位置，针对回文的“中心”会因子串为偶数或为奇数而不同，
因此内层循环会分别对子回文为偶数或为奇数进行判断，最终返回两者找到的回文子串的最大值，算法结束

算法复杂度O(n^2)

Author:tmw
date:2017-11-14
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longest_sub_Palindrome_centrol_expand(char* array)
{
    //字符串合法性检查
    if( strlen(array) == 0 || array == NULL )
        return 0;

    int i,j,max_len,len_odd,len_even;//len_odd为奇数子回文串返回的长度，len_even为偶数回文子串返回的长度
    int array_len = strlen(array);
    len_odd = 0;
    len_even = 0;
    max_len=0;

    for( i = 1 ; i < array_len; i++ )//以i位置为中心
    {
        //奇数情况
        for( j = 0 ; (i-j>=0)&&(i+j<array_len) ; j++ )//j为距i位置的距离
        {
            if( array[i-j] != array[i+j] )
                break;
            len_odd = 2*j+1;
            max_len = (max_len>len_odd?max_len:len_odd);
        }

        //偶数情况
        for( j = 0 ; (i-j>=0)&&(i+j+1)<array_len ; j++ )
        {
            if( array[i-j] != array[i+j+1] )
                break;
            len_even = 2*j+2;
            max_len = (max_len>len_even?max_len:len_even);
        }
    }
    return max_len==1?0:max_len;//单个数不为回文
}

int main()
{
    printf("测试程序\n");

    char a1[]="";
    printf("%s,最长回文数为 %d\n",a1,longest_sub_Palindrome_centrol_expand(a1));

    char a2[]="   ";
    printf("%s,最长回文数为 %d\n",a2,longest_sub_Palindrome_centrol_expand(a2));

    char a3[]="42243323454454356";
    printf("%s,最长回文数为 %d\n",a3,longest_sub_Palindrome_centrol_expand(a3));

    char a4[]="67982232298080";
    printf("%s,最长回文数为 %d\n",a4,longest_sub_Palindrome_centrol_expand(a4));

    char a5[]="231319009009";
    printf("%s,最长回文数为 %d\n",a5,longest_sub_Palindrome_centrol_expand(a5));

    char a6[]="abba";
    printf("%s,最长回文数为   %d\n",a6,longest_sub_Palindrome_centrol_expand(a6));

    char a7[]="sjdflkewjiofsdfew";
    printf("%s,最长回文数为   %d\n",a7,longest_sub_Palindrome_centrol_expand(a7));

    return 0;
}
