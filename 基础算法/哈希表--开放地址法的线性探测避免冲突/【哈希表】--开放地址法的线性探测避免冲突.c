/*******************************************************************************************
【哈希表】---散列表
【概念】
1、散列函数--哈希函数
    存储位置 = f(关键字)
    散列技术是在记录的存储位置和它的关键字之间建立一个确定的对应关系f，使得每个关键字key
对应一个存储位置f(key)。查找时，可根据这个确定的对应关系找到给定值key的映射f(key)，即，若
查找集合中存在这个记录，则必定在f(key)的位置上。f就是散列函数(即哈希函数)
2、散列表--哈希表
    采用散列技术将记录存储在一个连续的存储空间中，这块连续的存储空间成为散列表(又称哈希表)

    散列技术既是一种存储方法，也是一种查找方法
    散列技术最适合的场景是查找与给定值相等的元素
3、冲突
    一般情况下，每一个关键字，通过同一个哈希函数算出来的地址会不一样，但是也不可避免会产生
一样的地址---即，我们时常会碰到两个关键字key1!=key2，但是f(key1)==f(key2)，这种现象就叫做冲突
4、散列函数(哈希函数)的构造方法
    以下方法的核心在于：将原来的数字按照某种规律转变成另外一个数字。
    1）直接定址法 2）数字分析法 3）平方取中法 4）折叠法 5）除留余数法 6）随机数法
    最常用的是除留余数法  其他方法请参考《大话数据结构》第八章部分内容，这里不加赘述
5、散列函数(哈希函数)处理冲突的方法
    1）开放地址法 2）再散列函数法 3）链地址法 4）公共溢出区法
    下面的代码将分别对1）和3）方法进行实现
6、散列表的装填因子
    装填因子 = 填入表的记录个数 / 散列表的长度
    装填因子标志着哈希表的装满程度，填入表中的记录越多，装填因子值就越大，产生冲突的可能性越大
    散列表的平均查找长度取决于装填因子，而不是取决于查找集合中的个数
    装填因子越大，哈希查找的时间复杂度越接近O(1)，通常会将哈希表的空间设置得比查找集合大，虽然
浪费空间，但换来了查找效率的提升。

哈希表的查找时间复杂度：O(1)
Author:tmw
date:2017-10-30
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*********哈希表的创建**************/
#define HASHSIZE 10  //哈希表大小  --实际中尽量设大，实验代码设置成与输入大小相同
#define NUMBER_INIT -65534  //表结点值初始化
//定义哈希表数据结构
typedef struct HashTable
{
    int *hash_array; //经哈希函数后，数据元素地址的存放数组
    int number; //记录当前哈希表的元素个数
}HashTable;
int m; //将哈希表的大小设置为全局变量方便函数模块调用
//哈希表初始化
void init_hash_table(HashTable *H)
{
    int i;
    m = HASHSIZE;

    H->number = m;
    H->hash_array = (int*)malloc(m*sizeof(int));
    for( i = 0 ; i < m ; i++ )
        H->hash_array[i] = NUMBER_INIT;
}
//哈希函数的建立
int hash_func( int key )
{
    return key%m;  //采用取余法
}
//哈希表的插入----线性探测法避免冲突
int insert_ele2hash_table( int key , HashTable *H )
{
    int hash_addr = hash_func(key);//元素与哈希地址一一对应
    while( H->hash_array[hash_addr] != NUMBER_INIT )
        hash_addr = (hash_addr+1)%m; //采用线性探测法避免冲突
    H->hash_array[hash_addr] = key;
    return hash_addr;//返回元素插入地址
}
//哈希表的查找
int find_ele4hash_table( int key , HashTable *H )
{
    int hash_addr = hash_func(key);
    while( H->hash_array[hash_addr] != key )
    {
        hash_addr = (hash_addr+1)%m;
        if( H->hash_array[hash_addr] == NUMBER_INIT || hash_func(key) == hash_addr )//当hash后的地址里不存在key或者线性探测了整个哈希表一次，没有key，则返回false
            return -1;
    }
    return hash_addr;
}

int main()
{
    int array[10],i,elem;
    HashTable *H;
    H = (HashTable*)malloc(sizeof(HashTable));
    init_hash_table(H);

    printf("请输入10个待插入哈希表的关键字集合：\n");
    for( i = 0 ; i < 10 ; i++ )
    {
        scanf("%d",&array[i]);
        printf("元素 %d 插入哈希表的位置为 %d\n",array[i],insert_ele2hash_table(array[i],H));
    }
    for( i = 0 ; i < 2 ; i++ )//测试两次
    {
        printf("请输入待查找的元素：");
        scanf("%d",&elem);
        if( find_ele4hash_table(elem,H)>0 )
            printf("元素 %d 在哈希表中第 %d 位置\n",elem,find_ele4hash_table(elem,H));
        else
            printf("元素 %d 在哈希表中不存在！！！\n",elem);
    }
    return 0;
}
