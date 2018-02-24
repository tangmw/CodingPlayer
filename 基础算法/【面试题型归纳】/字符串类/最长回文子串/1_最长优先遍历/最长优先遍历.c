/*******************************************************************************************
【问题描述】
给定一个字符串，求它的最长回文子串的长度

针对这个问题，笔者最先想到的方法是以最长长度(即字符串本身长度)开始，从头到尾遍历以长度
为单位遍历字符串，一旦不符合回文匹配，则跳出字符串遍历，继续走最外层循环--即将遍历长度
逐次减一，直到遍历长度减到2为止，若找到，返回最外层循环长度，若没找到，则返回0，程序结束。

本算法最好的情况就是，一开始这个字符串就是回文，则最外层循环只进行了一次，内层循环走了n/2次，
时间复杂度为O(n)
最坏的情况就是，最长子回文出现在字符串最后两位，外层循环走了n-2次，内层循环走了n-1次，时间
复杂度为O(n^2)

Author:tmw
date:2017-11-14
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int longest_sub_Palindrome_travel(char* array)
{
    //字符串合法性检查
    if(strlen(array)==0||array==NULL)
        return 0;

    int len,array_len;
    len=array_len=strlen(array);
    for( len = strlen(array);len>1;len--)//外层循环：回文字串从最长开始找起
    {
        //当前子回文串长度为len
        int i=0;
        int j=len-1;
        while(j<array_len)//以len为跨度找是否有匹配的回文
        {
            int ii=i;//ii和jj用来保护当前游标位置，防止因进入while循环打乱
            int jj=j;
            while(ii<jj)
            {
                if(array[ii]!=array[jj])
                    break;
                jj--;
                ii++;
            }
            if((ii==jj)||(ii==jj+1))//奇数情况或者偶数情况找到回文，并返回长度
            {
                return len;//因为len从大到小，一旦找到，一定是最大的
                break;
            }
            i++;
            j++;
        }
    }
    return 0;//跳出for循环，此时len一定为1,说明没找到
}

int main()
{
    printf("测试程序\n");

    char a1[]="";
    printf("%s,最长回文数为 %d\n",a1,longest_sub_Palindrome_travel(a1));

    char a2[]="   ";
    printf("%s,最长回文数为 %d\n",a2,longest_sub_Palindrome_travel(a2));

    char a3[]="42243323454454356";
    printf("%s,最长回文数为 %d\n",a3,longest_sub_Palindrome_travel(a3));

    char a4[]="67982232298080";
    printf("%s,最长回文数为 %d\n",a4,longest_sub_Palindrome_travel(a4));

    char a5[]="231319009009";
    printf("%s,最长回文数为 %d\n",a5,longest_sub_Palindrome_travel(a5));

    char a6[]="abba";
    printf("%s,最长回文数为   %d\n",a6,longest_sub_Palindrome_travel(a6));

    char a7[]="sjdflkewjiofsdfew";
    printf("%s,最长回文数为   %d\n",a7,longest_sub_Palindrome_travel(a7));

    return 0;
}
