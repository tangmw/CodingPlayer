/*******************************************************************************************
��ϣ��Ĳ���ʱ�临�Ӷȣ�O(1)
Author:tmw
date:2017-10-30
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*********��ϣ��Ĵ���**************/
#define HASHSIZE 10  //��ϣ���С  --ʵ���о������ʵ��������ó��������С��ͬ
//�����ϣ�����ݽṹ
typedef struct hashNode
{
    int data;
    struct hashNode *next;
}hashNode;
struct hashNode HashLink[HASHSIZE];//����ϣ����Ϊȫ�ֱ������㺯��ģ�����
int m; //����ϣ��Ĵ�С����Ϊȫ�ֱ���
//��ϣ���ʼ��
void init_hash_table()
{
    int i;
    m = HASHSIZE;
    for( i = 0 ; i < m ; i++ )
    {
        HashLink[i].data = i;//��ʼ����ϣ��ַ
        HashLink[i].next = NULL;//��ʼ����ͷ���
    }
}
//��ϣ�����Ľ���
int hash_func( int key )
{
    return key%m;  //����ȡ�෨
}
//��ϣ�����Ĳ���----���������ͻ
int insert_ele2hash_Linklist( int key )
{
    int i = 0;
    hashNode *p;

    p = (hashNode*)malloc(sizeof(hashNode));
    p->data = key;

    while( hash_func(key) != HashLink[i].data )//�ڹ���Ĺ�ϣ�����в��ҵ�ַΪp.addr�ڹ�ϣ���е�λ��
        i++;
    //��p������λ��Ϊi�Ĺ�ϣ������---����ͷ�巨
    p->next = HashLink[i].next;
    HashLink[i].next = p;
    return i;
}
//��ϣ����Ĳ���
int find_ele4hash_Linklist( int key )
{
    int hash_addr = hash_func(key);
    int i = 0;
    hashNode *p;//*pָ��ƥ��Ĺ�ϣ��ַ���׵�ַ

    if( !HashLink[hash_addr].next )//��һ��ʼ�����ϣ��ַ���û��Ԫ�أ���ֱ�ӷ��ش���
    {
        printf("Ԫ�� %d �ڹ�ϣ���в����ڣ�����\n",key);
        return 0;
    }

    p = HashLink[hash_addr].next;
    while( p != NULL && ( p->data != key ) )
    {
        p = p->next;
        i++;
    }
    if( p->data == key )
    {
        printf("Ԫ�� %d �ڹ�ϣ���еĵ�ַΪ %d ���ڸõ�ַ�� %d λ��\n",key,hash_addr,i);
        return 0;
    }
    else
    {
        printf("Ԫ�� %d �ڹ�ϣ���в����ڣ�����\n",key);
        return 0;
    }
    return 0;
}
int main()
{
    init_hash_table();
    int array[10];
    int i,elem;

    printf("������10���������ϣ��Ĺؼ��ּ��ϣ�\n");
    for( i = 0 ; i < 10 ; i++ )
    {
        scanf("%d",&array[i]);
        printf("Ԫ�� %d �����ϣ���λ��Ϊ %d\n",array[i],insert_ele2hash_Linklist(array[i]));
    }
    for( i = 0 ; i < 2 ; i++ )//��������
    {
        printf("����������ҵ�Ԫ�أ�");
        scanf("%d",&elem);
        find_ele4hash_Linklist(elem);
    }
    return 0;
}
