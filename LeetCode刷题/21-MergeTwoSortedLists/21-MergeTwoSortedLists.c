/**********************************************************************************************************

LeetCode----[easy] 21-MergeTwoSortedLists

Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together
the nodes of the first two lists

[Ans:]
Method:����һ����������ֱ����������������С�ķŽ�������У�ֱ��ĳһ����������꣬�򽫶���Ĳ���
ȫ���������������
Author:tmw
date:2017-9-6

***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��һ������������ڵ�
typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

//�ڶ���������������������
ListNode* becomeLinkList( int array[], int len )
{
    int i = 0;
    ListNode* L;
    ListNode* p;
    p = (ListNode*)malloc(sizeof(ListNode));
    ListNode* e;
    L = p;
    for( i = 0 ; i < len ; i++ )
    {
        e = (ListNode*)malloc(sizeof(ListNode));
        e->val = array[i];
        p->next = e;
        p = e;
    }//β�巨��������
    p->next = NULL;
    return L;
}

//����������������������һ����������
ListNode* mergeTwoLists( ListNode* l1 , ListNode* l2 )
{
    //������ŵĽ��������ʼ��
    ListNode *result;
    ListNode *pr;
    pr = (ListNode*)malloc(sizeof(ListNode));
    ListNode *temp;
    result = pr;
    l1 = l1->next;
    l2 = l2->next;

    if( pr == NULL )
    {
        printf("�ڴ�����ʧ�ܣ�\n");
        return 0;
    }

    while( ( l1 != NULL ) && ( l2 != NULL ) )
    {
        if( ( l1->val ) < ( l2->val ) )
        {
            temp = malloc(sizeof(struct ListNode));
            temp->val = l1->val;
            pr->next = temp;
            pr = temp;
            l1 = l1->next;
        }
        else
        {
            temp = malloc(sizeof(struct ListNode));
            temp->val = l2->val;
            pr->next = temp;
            pr = temp;
            l2 = l2->next;
        }
    }
    while( l2 != NULL )
    {
        temp = malloc(sizeof(struct ListNode));
        temp->val = l2->val;
        pr->next = temp;
        pr = temp;
        l2 = l2->next;
    }
    while( l1 != NULL )
    {
        temp = malloc(sizeof(struct ListNode));
        temp->val = l1->val;
        pr->next = temp;
        pr = temp;
        l1 = l1->next;
    }
    pr->next = NULL;

    printf("������������merge��Ľ��Ϊ��\n");
    pr = result->next;
    while( pr != NULL )
    {
        printf("%d ",pr->val);
        pr = pr->next;
    }
    printf("\n");
    return result;
}

int main()
{
    int array1[30] = {0};
    int array2[30] = {0};
    int i = 0;
    ListNode *L1;
    ListNode *L2;


    printf("�������1�����������������!\n");
    while(1)
    {
        scanf("%d",&array1[i]);
        i++;
        if( getchar() == '\n')
            break;
    }
    L1 = becomeLinkList(array1,i);

    i = 0;
    printf("�������2�����������������!\n");
    while(1)
    {
        scanf("%d",&array2[i]);
        i++;
        if( getchar() == '\n')
            break;
    }

    L2 = becomeLinkList(array2,i);

    mergeTwoLists( L1 , L2 );
    return 0;
}
