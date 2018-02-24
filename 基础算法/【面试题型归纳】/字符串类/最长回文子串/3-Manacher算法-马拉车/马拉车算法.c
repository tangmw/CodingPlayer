/*******************************************************************************************
������������
����һ���ַ�����������������Ӵ��ĳ���

�㷨���Ӷ�O(n)

Author:tmw
date:2017-11-15
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a,b) (a<b?a:b)
#define max(x,y) (x>y?x:y)

/*ԭʼ����ʽת������*/
char* Manacher_change(char* array)
{
    int i;
    char* temp;
    temp = (char*)malloc( (strlen(array)*2+3)*sizeof(char) );//��β��'$',���м��'#'����Խ��
    temp[0] = '$';//���׼�'$'
    for( i = 1 ; i < 2*strlen(array) ; i+=2 )
    {
        temp[i] = '#';
        temp[i+1] = array[i/2];
    }
    temp[2*strlen(array)+1] = '#';
    temp[2*strlen(array)+2] = '\0';//�ַ����������
    return temp;
}

int longest_sub_Palindrome_Manacher(char* s)
{
    //�ַ����Ϸ��Լ��
    if(strlen(s)==0 || s==NULL)
        return 0;

    //���ַ�����д���������㷨�涨��ʽ
    char* S;
    S = (char*)malloc( (strlen(s)*2+4)*sizeof(char) );
    S = Manacher_change(s);

    char* P;
    P = (char*)malloc( (strlen(S)*sizeof(char)) );//Ϊp����������Sͬ�ȿռ�

    /*��ʼ����Manacher�㷨����*/
    int i,mx,id,ans;
    mx = 0;//��ʼ���������Ӵ��߽糤��
    ans = 0;
    for( i = 1 ; i < strlen(S) ; i++ )//��ÿһ��P[i]��ֵ,S[]����1��λ�����$����Խ��ģ����ÿ�����
    {
        //��mx>i(Ŀ���������������Ӵ��߽緶Χ��)��P[i]>=min(P[2id-i],mx-i)
        if( mx > i )
            P[i] = min( P[2*id-i], mx-i );
        else//��mx<=i(Ŀ���������������Ӵ��߽緶Χ��)����P[i]=1��ƥ�����
            P[i] = 1;
        while( S[i+P[i]] == S[i-P[i]] )//��iΪ���ģ�ƥ�����P[i]
            P[i]++;
        if( i+P[i] > mx )//�����������Ӵ��߽�ֵ,����¼�������Ӵ�����λ��id
        {
            mx = i+P[i];
            id = i;
        }
        //max(P[I]-1)����ԭ�ַ�����������Ӵ��ĳ���
        ans = max(ans,P[i]);
    }
    return ans-1 == 1?0:ans-1;//����Ԫ�ز����ڻ���
}


int main()
{
    printf("���Գ���\n");

    char a1[]="";
    printf("%s,�������Ϊ %d\n",a1,longest_sub_Palindrome_Manacher(a1));

    char a2[]="   ";
    printf("%s,�������Ϊ %d\n",a2,longest_sub_Palindrome_Manacher(a2));

    char a3[]="42243323454454356";
    printf("%s,�������Ϊ %d\n",a3,longest_sub_Palindrome_Manacher(a3));

    char a4[]="67982232298080";
    printf("%s,�������Ϊ %d\n",a4,longest_sub_Palindrome_Manacher(a4));

    char a5[]="231319009009";
    printf("%s,�������Ϊ %d\n",a5,longest_sub_Palindrome_Manacher(a5));

    char a6[]="abba";
    printf("%s,�������Ϊ   %d\n",a6,longest_sub_Palindrome_Manacher(a6));

    char a7[]="sjdflkewjiofsdfew";
    printf("%s,�������Ϊ   %d\n",a7,longest_sub_Palindrome_Manacher(a7));

    return 0;
}
