/*******************************************************************************************
������������
����һ���ַ�����������������Ӵ��ĳ���

���ݻ����ִ������������Դӻ��ĵġ����ġ��������ԡ����ġ�����������չ��Ȼ��ö������λ�ã�
��¼������������Ӵ�����

�㷨���»�������ѭ��������ѭ����ö������λ�ã���Ի��ĵġ����ġ������Ӵ�Ϊż����Ϊ��������ͬ��
����ڲ�ѭ����ֱ���ӻ���Ϊż����Ϊ���������жϣ����շ��������ҵ��Ļ����Ӵ������ֵ���㷨����

�㷨���Ӷ�O(n^2)

Author:tmw
date:2017-11-14
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longest_sub_Palindrome_centrol_expand(char* array)
{
    //�ַ����Ϸ��Լ��
    if( strlen(array) == 0 || array == NULL )
        return 0;

    int i,j,max_len,len_odd,len_even;//len_oddΪ�����ӻ��Ĵ����صĳ��ȣ�len_evenΪż�������Ӵ����صĳ���
    int array_len = strlen(array);
    len_odd = 0;
    len_even = 0;
    max_len=0;

    for( i = 1 ; i < array_len; i++ )//��iλ��Ϊ����
    {
        //�������
        for( j = 0 ; (i-j>=0)&&(i+j<array_len) ; j++ )//jΪ��iλ�õľ���
        {
            if( array[i-j] != array[i+j] )
                break;
            len_odd = 2*j+1;
            max_len = (max_len>len_odd?max_len:len_odd);
        }

        //ż�����
        for( j = 0 ; (i-j>=0)&&(i+j+1)<array_len ; j++ )
        {
            if( array[i-j] != array[i+j+1] )
                break;
            len_even = 2*j+2;
            max_len = (max_len>len_even?max_len:len_even);
        }
    }
    return max_len==1?0:max_len;//��������Ϊ����
}

int main()
{
    printf("���Գ���\n");

    char a1[]="";
    printf("%s,�������Ϊ %d\n",a1,longest_sub_Palindrome_centrol_expand(a1));

    char a2[]="   ";
    printf("%s,�������Ϊ %d\n",a2,longest_sub_Palindrome_centrol_expand(a2));

    char a3[]="42243323454454356";
    printf("%s,�������Ϊ %d\n",a3,longest_sub_Palindrome_centrol_expand(a3));

    char a4[]="67982232298080";
    printf("%s,�������Ϊ %d\n",a4,longest_sub_Palindrome_centrol_expand(a4));

    char a5[]="231319009009";
    printf("%s,�������Ϊ %d\n",a5,longest_sub_Palindrome_centrol_expand(a5));

    char a6[]="abba";
    printf("%s,�������Ϊ   %d\n",a6,longest_sub_Palindrome_centrol_expand(a6));

    char a7[]="sjdflkewjiofsdfew";
    printf("%s,�������Ϊ   %d\n",a7,longest_sub_Palindrome_centrol_expand(a7));

    return 0;
}
