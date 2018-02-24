/**********************************************************************************************************

LeetCode----[easy] 14-LongestCommonPrefix

Write a function to find the longest common prefix string amongst an array of strings.

[Ans:]
��Ҫ����:�ַ��������ʼ������ֵ�����----ָ���������ת��
Author:tmw
date:2017-9-5

***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* fun  ---because it will return a character string not a character
char* longestCommonPrefix(char** strs, int strsSize)
{
    //��һ�������ַ��������У��ҵ�������С���Ӵ�
    int lenMin = 0;
    int i = 0;
    int len = 0;


    char *sh;
    sh = (char*)malloc(1*sizeof(char));
    memset(sh,0,1);
    if( strsSize == 0 )
    {
        printf("�ַ���Ϊ�գ�\n");
        return sh;
    }

    lenMin = strlen(strs[0]); //�Ƚ�������С������һ���ַ���
    printf("%d\n",strlen(strs[0]));
    for( i = 1 ; i < strsSize ; i++ )
    {
        len = strlen(strs[i]);
        printf("%d\n",len);
        if( len < lenMin )
            lenMin = len;
    }//��ʱ,lenMin�����ַ����������ַ���������С��ֵ��
    printf("lenMin = %d\n",lenMin);

    //�ڶ������Ƚ��ַ��������е�ÿһ���ַ�����indexλ���ϵ��ַ�������ȣ���index++�������˳�
    i = 0; //��i��λ,�����ظ������ڴ棬��Լ��Դ
    int j = 0;//j�����ַ��������е�ÿһ���ַ���
    int index = 0;//��¼�ַ���֮����ͬ�ַ����±�
    char ch;//�Ƚ��ַ�
    int flag = 0;//flag=1 ��ֹƥ���ʶ




    while( index <= lenMin )
    {
        ch = strs[0][index];
        j = 1; //j����
        while( j < strsSize )//����ÿ���ַ���---����ÿ�����������ǰ׺
        {
            while( ( j < strsSize ) && ( ch == strs[j][index] ) )//�Ƚ��ַ���������ÿһ���ַ�����indexλ���µ��ַ�
                j++;
            if( j < strsSize )
            {
                if( index == 0 )
                {
                    printf("û�������ǰ׺ƥ�䣡\n");
                    return sh;
                }
                else
                {
                    flag = 1;//flag=1��ζ�Ų���Ҫ����ƥ����
                    break;
                }
            }
        }
        if( flag != 1 )
        {
           index++;
           printf("index = %d\n",index);
        }
        if( flag == 1 )
            break;
    }


    //����������indexλ��֮ǰ���ַ�ȫ�����
    char *temp;
    temp = (char*)malloc( (index+1)*sizeof(char) );//index+1��Ϊ�˸����һλ��\0���������ƥ���ַ���
    i = 0;//��i��λ
    for( i = 0 ; i < index ; i++ )
        temp[i] = strs[0][i];
    temp[i++] = '\0';//���һλ����\0

    //���һ���������󹫹�ǰ׺�ַ���
    printf("�ַ�������strs�������ǰ׺�ַ���Ϊ��%s",temp);
    return temp;

}

int main()
{

    int i = 0;

//    char strs[20][30];
//    memset(strs,0x00,sizeof(char)*400);//memset��ʼ����ά����
/********************************************************************************************************************************
����Ĵ��룬��**strsת��Ϊ��ά���������ʽ

�ȸ�**strs ��strs����ռ䣬������һ����*strs ���sizeof(char*)��������󣬾��пռ����洢��Щ�ַ�����
�ٸ�*strs ��strs����ռ䣬������һ�����ַ��ˣ����sizeof(char)���������ÿһ��λ���£���Ҫforѭ�������ַ������пռ�洢�ˣ�
��*strs���char�ַ�������д洢������Ҫ����

***********************************************************************************************************************************/
    char **strs;
    strs = malloc(5*sizeof(char *));
    int strsSize = 0;
    int j;
    for( j = 0 ; j < 3 ; j++ )
        strs[j] = malloc(30*sizeof(char));

    printf("�������ַ���������\n");
    scanf("%d",&strsSize);

    printf("�����������ַ���\n");

    for( i = 0 ; i < strsSize ; i++ )
        scanf("%s",strs[i]);

/***********************************************************************

**strsת���ɶ�ά������ں������õ�ʱ��Ϳ����Զ�ά�������ʽ������

*************************************************************************/
    longestCommonPrefix(strs,strsSize);
    return 0;
}
