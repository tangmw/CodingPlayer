/***********************************************
【问题描述】
插入一个整数数组和一个整数，在数组中查找一对数，满足它们的和正好是输入
的那个整数。如果有多对数的和等于输入的整数，输出任意一对即可。

解法一：构建哈希表
针对本题，除了排序以外，笔者比较容易想到的方法是构建哈希表。下面对这个算法进行描述：
算法准备：将插入的整数数组构建成哈希表--在构建哈希表时，笔者采用取余的方法构建哈希函数，采用链表法避免冲突
step1: 遍历输入的整数数组，将输入的目标整数与数组中的元素array[i]相减，得到新的整数b[i]；
step2: 在构建的哈希表中查找b[i]的值；
step3: 若找到，打印array[i]，b[i]的值，算法结束；否则，重复step1和step2

算法复杂度分析
遍历数组查询array[i]，复杂度为O(n),根据哈希映射查找b[i]是否存在数组中，此种方法耗时O(1)，所以总的
时间复杂度为O(n)。
Author:tmw
date:2017-11-19
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASHSIZE 100
//哈希表数据结构
typedef struct hash_node
{
    int elem;
    struct hash_node *next;
}hash_node;

struct hash_node HashList[HASHSIZE];//构建的哈希表作为全局变量

//取余法构建哈希函数
int hash_fun( int elem )
{
    return elem%HASHSIZE;
}

//创建哈希表
void Create_Hash_List( int* array , int array_len )
{
    int i;
    //初始化哈希表
    for( i = 0 ; i < array_len ; i++ )
    {
        HashList[i].elem = i;
        HashList[i].next = NULL;
    }
    //将数组元素转存入哈希表
    int hash_index;
    for( i = 0 ; i < array_len ; i++ )
    {
        hash_node *new_node;
        new_node = (hash_node*)malloc(sizeof(hash_node));
        new_node->elem = array[i];

        hash_index = hash_fun(array[i]);
        //头插法插入链表
        new_node->next = HashList[hash_index].next;
        HashList[hash_index].next = new_node;
    }
}
//主算法：哈希法查找和为定值的任意两个数
bool Find_twoNumber_Stable_Sum_usingHash(int *array , int array_len , int sum )
{
    Create_Hash_List( array , array_len );
    int i,target,target_hash_index;
    for( i = 0 ; i < array_len ; i++ )
    {
        target = sum - array[i];
        //在哈希表中找target
        target_hash_index = hash_fun(target);
        hash_node *p;
        p = HashList[target_hash_index].next;
        while(p)
        {
            if(p->elem == target)
            {
                printf("%d + %d = %d\n",array[i],target,sum);
                return true;
                //break; //[如果测多个]可将return true注解,将break解注
            }
            p = p->next;
        }
    }
    printf("没有和为 %d 的两个数",sum);
    return false;
}

int main()
{
    printf("测试代码\n");
    int i;
    int sum = 15;

    int a[12] = {1,2,4,5,7,11,54,3,8,6,10,13};
    for(i=0;i<12;i++)
        printf("%d ",a[i]);
    printf("\n");
    Find_twoNumber_Stable_Sum_usingHash(a,12,sum);

    int b[15] = {3,4,2,10,5,0,12,13,8,9,16,17,20,1,6};
    for(i=0;i<15;i++)
        printf("%d ",b[i]);
    printf("\n");
    Find_twoNumber_Stable_Sum_usingHash(b,15,sum);

    return 0;
}
