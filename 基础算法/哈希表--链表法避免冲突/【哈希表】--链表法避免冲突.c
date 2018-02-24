/*******************************************************************************************
哈希表的查找时间复杂度：O(1)
Author:tmw
date:2017-10-30
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*********哈希表的创建**************/
#define HASHSIZE 10  //哈希表大小  --实际中尽量设大，实验代码设置成与输入大小相同
//定义哈希表数据结构
typedef struct hashNode
{
    int data;
    struct hashNode *next;
}hashNode;
struct hashNode HashLink[HASHSIZE];//将哈希表作为全局变量方便函数模块调用
int m; //将哈希表的大小设置为全局变量
//哈希表初始化
void init_hash_table()
{
    int i;
    m = HASHSIZE;
    for( i = 0 ; i < m ; i++ )
    {
        HashLink[i].data = i;//初始化哈希地址
        HashLink[i].next = NULL;//初始化表头结点
    }
}
//哈希函数的建立
int hash_func( int key )
{
    return key%m;  //采用取余法
}
//哈希链表表的插入----链表法避免冲突
int insert_ele2hash_Linklist( int key )
{
    int i = 0;
    hashNode *p;

    p = (hashNode*)malloc(sizeof(hashNode));
    p->data = key;

    while( hash_func(key) != HashLink[i].data )//在构造的哈希链表中查找地址为p.addr在哈希表中的位置
        i++;
    //将p结点插在位置为i的哈希链表中---采用头插法
    p->next = HashLink[i].next;
    HashLink[i].next = p;
    return i;
}
//哈希链表的查找
int find_ele4hash_Linklist( int key )
{
    int hash_addr = hash_func(key);
    int i = 0;
    hashNode *p;//*p指向匹配的哈希地址的首地址

    if( !HashLink[hash_addr].next )//从一开始这个哈希地址里就没有元素，则直接返回错误
    {
        printf("元素 %d 在哈希表中不存在！！！\n",key);
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
        printf("元素 %d 在哈希表中的地址为 %d ，在该地址的 %d 位置\n",key,hash_addr,i);
        return 0;
    }
    else
    {
        printf("元素 %d 在哈希表中不存在！！！\n",key);
        return 0;
    }
    return 0;
}
int main()
{
    init_hash_table();
    int array[10];
    int i,elem;

    printf("请输入10个待插入哈希表的关键字集合：\n");
    for( i = 0 ; i < 10 ; i++ )
    {
        scanf("%d",&array[i]);
        printf("元素 %d 插入哈希表的位置为 %d\n",array[i],insert_ele2hash_Linklist(array[i]));
    }
    for( i = 0 ; i < 2 ; i++ )//测试两次
    {
        printf("请输入待查找的元素：");
        scanf("%d",&elem);
        find_ele4hash_Linklist(elem);
    }
    return 0;
}
