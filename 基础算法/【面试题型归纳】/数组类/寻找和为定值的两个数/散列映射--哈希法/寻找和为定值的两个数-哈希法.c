/***********************************************
������������
����һ�����������һ���������������в���һ�������������ǵĺ�����������
���Ǹ�����������ж�����ĺ͵���������������������һ�Լ��ɡ�

�ⷨһ��������ϣ��
��Ա��⣬�����������⣬���߱Ƚ������뵽�ķ����ǹ�����ϣ�����������㷨����������
�㷨׼������������������鹹���ɹ�ϣ��--�ڹ�����ϣ��ʱ�����߲���ȡ��ķ���������ϣ�������������������ͻ
step1: ����������������飬�������Ŀ�������������е�Ԫ��array[i]������õ��µ�����b[i]��
step2: �ڹ����Ĺ�ϣ���в���b[i]��ֵ��
step3: ���ҵ�����ӡarray[i]��b[i]��ֵ���㷨�����������ظ�step1��step2

�㷨���Ӷȷ���
���������ѯarray[i]�����Ӷ�ΪO(n),���ݹ�ϣӳ�����b[i]�Ƿ���������У����ַ�����ʱO(1)�������ܵ�
ʱ�临�Ӷ�ΪO(n)��
Author:tmw
date:2017-11-19
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASHSIZE 100
//��ϣ�����ݽṹ
typedef struct hash_node
{
    int elem;
    struct hash_node *next;
}hash_node;

struct hash_node HashList[HASHSIZE];//�����Ĺ�ϣ����Ϊȫ�ֱ���

//ȡ�෨������ϣ����
int hash_fun( int elem )
{
    return elem%HASHSIZE;
}

//������ϣ��
void Create_Hash_List( int* array , int array_len )
{
    int i;
    //��ʼ����ϣ��
    for( i = 0 ; i < array_len ; i++ )
    {
        HashList[i].elem = i;
        HashList[i].next = NULL;
    }
    //������Ԫ��ת�����ϣ��
    int hash_index;
    for( i = 0 ; i < array_len ; i++ )
    {
        hash_node *new_node;
        new_node = (hash_node*)malloc(sizeof(hash_node));
        new_node->elem = array[i];

        hash_index = hash_fun(array[i]);
        //ͷ�巨��������
        new_node->next = HashList[hash_index].next;
        HashList[hash_index].next = new_node;
    }
}
//���㷨����ϣ�����Һ�Ϊ��ֵ������������
bool Find_twoNumber_Stable_Sum_usingHash(int *array , int array_len , int sum )
{
    Create_Hash_List( array , array_len );
    int i,target,target_hash_index;
    for( i = 0 ; i < array_len ; i++ )
    {
        target = sum - array[i];
        //�ڹ�ϣ������target
        target_hash_index = hash_fun(target);
        hash_node *p;
        p = HashList[target_hash_index].next;
        while(p)
        {
            if(p->elem == target)
            {
                printf("%d + %d = %d\n",array[i],target,sum);
                return true;
                //break; //[�������]�ɽ�return trueע��,��break��ע
            }
            p = p->next;
        }
    }
    printf("û�к�Ϊ %d ��������",sum);
    return false;
}

int main()
{
    printf("���Դ���\n");
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
