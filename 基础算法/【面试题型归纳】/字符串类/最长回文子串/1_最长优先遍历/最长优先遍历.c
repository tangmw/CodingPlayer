/*******************************************************************************************
������������
����һ���ַ�����������������Ӵ��ĳ���

���������⣬���������뵽�ķ������������(���ַ���������)��ʼ����ͷ��β�����Գ���
Ϊ��λ�����ַ�����һ�������ϻ���ƥ�䣬�������ַ��������������������ѭ��--������������
��μ�һ��ֱ���������ȼ���2Ϊֹ�����ҵ������������ѭ�����ȣ���û�ҵ����򷵻�0�����������

���㷨��õ�������ǣ�һ��ʼ����ַ������ǻ��ģ��������ѭ��ֻ������һ�Σ��ڲ�ѭ������n/2�Σ�
ʱ�临�Ӷ�ΪO(n)
���������ǣ���ӻ��ĳ������ַ��������λ�����ѭ������n-2�Σ��ڲ�ѭ������n-1�Σ�ʱ��
���Ӷ�ΪO(n^2)

Author:tmw
date:2017-11-14
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int longest_sub_Palindrome_travel(char* array)
{
    //�ַ����Ϸ��Լ��
    if(strlen(array)==0||array==NULL)
        return 0;

    int len,array_len;
    len=array_len=strlen(array);
    for( len = strlen(array);len>1;len--)//���ѭ���������ִ������ʼ����
    {
        //��ǰ�ӻ��Ĵ�����Ϊlen
        int i=0;
        int j=len-1;
        while(j<array_len)//��lenΪ������Ƿ���ƥ��Ļ���
        {
            int ii=i;//ii��jj����������ǰ�α�λ�ã���ֹ�����whileѭ������
            int jj=j;
            while(ii<jj)
            {
                if(array[ii]!=array[jj])
                    break;
                jj--;
                ii++;
            }
            if((ii==jj)||(ii==jj+1))//�����������ż������ҵ����ģ������س���
            {
                return len;//��Ϊlen�Ӵ�С��һ���ҵ���һ��������
                break;
            }
            i++;
            j++;
        }
    }
    return 0;//����forѭ������ʱlenһ��Ϊ1,˵��û�ҵ�
}

int main()
{
    printf("���Գ���\n");

    char a1[]="";
    printf("%s,�������Ϊ %d\n",a1,longest_sub_Palindrome_travel(a1));

    char a2[]="   ";
    printf("%s,�������Ϊ %d\n",a2,longest_sub_Palindrome_travel(a2));

    char a3[]="42243323454454356";
    printf("%s,�������Ϊ %d\n",a3,longest_sub_Palindrome_travel(a3));

    char a4[]="67982232298080";
    printf("%s,�������Ϊ %d\n",a4,longest_sub_Palindrome_travel(a4));

    char a5[]="231319009009";
    printf("%s,�������Ϊ %d\n",a5,longest_sub_Palindrome_travel(a5));

    char a6[]="abba";
    printf("%s,�������Ϊ   %d\n",a6,longest_sub_Palindrome_travel(a6));

    char a7[]="sjdflkewjiofsdfew";
    printf("%s,�������Ϊ   %d\n",a7,longest_sub_Palindrome_travel(a7));

    return 0;
}
