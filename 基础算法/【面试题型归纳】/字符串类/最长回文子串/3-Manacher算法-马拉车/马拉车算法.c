/*******************************************************************************************
【问题描述】
给定一个字符串，求它的最长回文子串的长度

算法复杂度O(n)

Author:tmw
date:2017-11-15
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a,b) (a<b?a:b)
#define max(x,y) (x>y?x:y)

/*原始串格式转换函数*/
char* Manacher_change(char* array)
{
    int i;
    char* temp;
    temp = (char*)malloc( (strlen(array)*2+3)*sizeof(char) );//串尾加'$',串中间加'#'，防越界
    temp[0] = '$';//串首加'$'
    for( i = 1 ; i < 2*strlen(array) ; i+=2 )
    {
        temp[i] = '#';
        temp[i+1] = array[i/2];
    }
    temp[2*strlen(array)+1] = '#';
    temp[2*strlen(array)+2] = '\0';//字符串结束标记
    return temp;
}

int longest_sub_Palindrome_Manacher(char* s)
{
    //字符串合法性检查
    if(strlen(s)==0 || s==NULL)
        return 0;

    //将字符串改写成马拉车算法规定格式
    char* S;
    S = (char*)malloc( (strlen(s)*2+4)*sizeof(char) );
    S = Manacher_change(s);

    char* P;
    P = (char*)malloc( (strlen(S)*sizeof(char)) );//为p数组申请与S同等空间

    /*开始运行Manacher算法主体*/
    int i,mx,id,ans;
    mx = 0;//初始化最大回文子串边界长度
    ans = 0;
    for( i = 1 ; i < strlen(S) ; i++ )//给每一个P[i]赋值,S[]数组1号位存的是$，防越界的，不用考虑它
    {
        //当mx>i(目标中心在最大回文子串边界范围内)，P[i]>=min(P[2id-i],mx-i)
        if( mx > i )
            P[i] = min( P[2*id-i], mx-i );
        else//当mx<=i(目标中心在最大回文子串边界范围外)，让P[i]=1，匹配待续
            P[i] = 1;
        while( S[i+P[i]] == S[i-P[i]] )//以i为中心，匹配更新P[i]
            P[i]++;
        if( i+P[i] > mx )//更新最大回文子串边界值,并记录最大回文子串中心位置id
        {
            mx = i+P[i];
            id = i;
        }
        //max(P[I]-1)就是原字符串中最长回文子串的长度
        ans = max(ans,P[i]);
    }
    return ans-1 == 1?0:ans-1;//单个元素不属于回文
}


int main()
{
    printf("测试程序\n");

    char a1[]="";
    printf("%s,最长回文数为 %d\n",a1,longest_sub_Palindrome_Manacher(a1));

    char a2[]="   ";
    printf("%s,最长回文数为 %d\n",a2,longest_sub_Palindrome_Manacher(a2));

    char a3[]="42243323454454356";
    printf("%s,最长回文数为 %d\n",a3,longest_sub_Palindrome_Manacher(a3));

    char a4[]="67982232298080";
    printf("%s,最长回文数为 %d\n",a4,longest_sub_Palindrome_Manacher(a4));

    char a5[]="231319009009";
    printf("%s,最长回文数为 %d\n",a5,longest_sub_Palindrome_Manacher(a5));

    char a6[]="abba";
    printf("%s,最长回文数为   %d\n",a6,longest_sub_Palindrome_Manacher(a6));

    char a7[]="sjdflkewjiofsdfew";
    printf("%s,最长回文数为   %d\n",a7,longest_sub_Palindrome_Manacher(a7));

    return 0;
}
