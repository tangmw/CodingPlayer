/*******************************************************************************************
������������
���������ַ���a��b��һ��һ�̣���ο����ж϶��ַ���b������Ԫ�ض��ڳ��ַ���a�У�
��������ַ����е�Ԫ�ض�Ϊ��д��ĸ
����
1) a = ��ABCD��,b = ��DBA��,����true
2) a = "ABCD",b = "AAD",����true
3) a = "ABCD",b = "BCE",����false
********************************************************************************************/

/************************
Author:tmw
date:2017-11-6
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
����������ϣ��
step 1: ��a��Ԫ�ط����ϣ��
step 2: b��Ԫ��ͨ����ϣ��ַ���ʹ�ϣ�����ҵ���ͬԪ�أ���false

ʱ�临�Ӷ�O(1)
**/

#define MAXSIZE 100
typedef struct hash_node//��������ɢ�б��ͻ
{
    int element;
    struct hash_node *next;
}hash_node,hash_link[MAXSIZE];

hash_link L;//ȫ�ֱ���������󼸸������н�

int hash_fun( int at_frist )
{
    return at_frist%MAXSIZE;
}//ȡ�෨������ϣ����
void char2hashList( char array[] , int array_len )
{
    int i;
    //��ϣ���ʼ��
    for( i = 0 ; i < MAXSIZE ; i++ )
    {
        L[i].element = i;
        L[i].next = NULL;
    }
    //�ַ��������ϣ����
    for( i = 0 ; i < array_len ; i++ )
    {
        hash_node *p;
        p = (hash_node*)malloc(sizeof(hash_node));

        p->element = array[i] - 'A';
        int hash_index = hash_fun(array[i]-'A');

        //ͷ�巨����hash_index��������
        p->next = L[hash_index].next;
        L[hash_index].next = p;
    }//����MAXSIZEֻҪ�㹻����array_len��������֤ÿ��hash_index�������һ��Ԫ�أ���󽵵��˺���Ĳ���ʱ��
}//������ɽ�a����Ԫ�ط����ϣ����

bool string_contain( char a[] , int len_a , char b[] , int len_b )
{
    int i;
    //�Ƚ�a�����ϣ��
    char2hashList(a,len_a);


    for( i = 0 ; i < len_b ; i++ )
    {
        int b_hash_index = hash_fun(b[i]-'A');//������b��Ԫ�ؽ��й�ϣ��ַת��

        hash_node *p;
        p = L[b_hash_index].next;//pָ��b����ϣ��ַת����Ľ��

        while(p)
        {
            if(p->element != b[i]-'A')//��b_hash_index�±����ڵ������У�����b[i]-'A'ƥ���Ԫ��
                p = p->next;
            else
                break;
        }
        if( !p )
            return false;
    }
    return true;
}


int main()
{
    int a_len,b_len;
    char* a;
    char* b;
    printf("������a���鳤��\n");
    scanf("%d",&a_len);
    a = (char*)malloc(a_len*sizeof(char));

    printf("������b���鳤��\n");
    scanf("%d",&b_len);
    b = (char*)malloc(b_len*sizeof(char));

    printf("�����볤�ַ���aԪ�أ�");
    //char ch;
    //while( ch = getchar() != '\n');
    scanf("%s",a);
    //while( ch = getchar() != '\n');
    printf("��������ַ���bԪ�أ�");
    scanf("%s",b);
    printf("%d\n",string_contain(a,a_len,b,b_len));
    if(string_contain(a,a_len,b,b_len))
        printf("a����b������Ԫ�أ�\n");
    else
        printf("a������b��\n");
    return 0;
}
