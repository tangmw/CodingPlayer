/*******************************************************************************************
【问题描述】
给定两个字符串a和b，一长一短，如何快速判断短字符串b中所有元素都在长字符串a中？
这里假设字符串中的元素都为大写字母
例如
1) a = “ABCD”,b = “DBA”,返回true
2) a = "ABCD",b = "AAD",返回true
3) a = "ABCD",b = "BCE",返回false
********************************************************************************************/

/************************
Author:tmw
date:2017-11-6
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
方法二：哈希表
step 1: 将a中元素放入哈希表
step 2: b中元素通过哈希地址访问哈希表，若找到相同元素，则false

时间复杂度O(1)
**/

#define MAXSIZE 100
typedef struct hash_node//链表法避免散列表冲突
{
    int element;
    struct hash_node *next;
}hash_node,hash_link[MAXSIZE];

hash_link L;//全局变量，方便后几个函数承接

int hash_fun( int at_frist )
{
    return at_frist%MAXSIZE;
}//取余法构建哈希函数
void char2hashList( char array[] , int array_len )
{
    int i;
    //哈希表初始化
    for( i = 0 ; i < MAXSIZE ; i++ )
    {
        L[i].element = i;
        L[i].next = NULL;
    }
    //字符串插进哈希表中
    for( i = 0 ; i < array_len ; i++ )
    {
        hash_node *p;
        p = (hash_node*)malloc(sizeof(hash_node));

        p->element = array[i] - 'A';
        int hash_index = hash_fun(array[i]-'A');

        //头插法插入hash_index所在链表
        p->next = L[hash_index].next;
        L[hash_index].next = p;
    }//以上MAXSIZE只要足够大于array_len，基本保证每个hash_index的链表就一个元素，大大降低了后面的查找时间
}//函数完成将a数组元素放入哈希表中

bool string_contain( char a[] , int len_a , char b[] , int len_b )
{
    int i;
    //先将a纳入哈希表
    char2hashList(a,len_a);


    for( i = 0 ; i < len_b ; i++ )
    {
        int b_hash_index = hash_fun(b[i]-'A');//将数组b的元素进行哈希地址转换

        hash_node *p;
        p = L[b_hash_index].next;//p指向b经哈希地址转换后的结点

        while(p)
        {
            if(p->element != b[i]-'A')//在b_hash_index下标所在的链表中，找与b[i]-'A'匹配的元素
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
    printf("请输入a数组长度\n");
    scanf("%d",&a_len);
    a = (char*)malloc(a_len*sizeof(char));

    printf("请输入b数组长度\n");
    scanf("%d",&b_len);
    b = (char*)malloc(b_len*sizeof(char));

    printf("请输入长字符串a元素：");
    //char ch;
    //while( ch = getchar() != '\n');
    scanf("%s",a);
    //while( ch = getchar() != '\n');
    printf("请输入短字符串b元素：");
    scanf("%s",b);
    printf("%d\n",string_contain(a,a_len,b,b_len));
    if(string_contain(a,a_len,b,b_len))
        printf("a包含b中所有元素！\n");
    else
        printf("a不包含b！\n");
    return 0;
}
