/**********************************************************************************************************
LeetCode----[easy] 100-SameTree.c
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

[Ans:]
����һ��
�ֱ��������������������������ֱ�洢���ַ����У��Ƚ����������������ַ����Ƿ���ȫ��ȡ�
ע�⣺����������������޷�ȷ��һ�����ģ�����Ҫ�Ա����ֱ�������µĽ�����ܵó��϶���
����ʹ���������ݹ飬�ᵼ��run time error
��������
д�ɵݹ��ж�---�ݹ���⡣���ж���ֹ������Ȼ�����������ݹ顣

Author:tmw
date:2017-10-12
***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 //Definition for a binary tree node.
 struct TreeNode
 {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
/*******
����һ
*******/
//int i = 0;
//int j = 0;
//char a[100];
//char b[100];
//char* pre_order_travel(struct TreeNode* T)
//{
//    if(T==NULL)
//        return;//������һ��ݹ�
//    a[i] = T->val - '0';i++; //������valֵת�浽�ַ�����
//    pre_order_travel(T->left);
//    pre_order_travel(T->right);
//    return a;
//}
//char* in_order_travel(struct TreeNode* T)
//{
//    if(T==NULL)
//        return;
//    in_order_travel(T->left);
//    b[j] = T->val - '0';j++;
//    in_order_travel(T->right);
//    return b;
//}
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if( p == NULL && q == NULL )
//        return true;
//    //����Ƚ�
//    char *p_pre; p_pre = (char*)malloc(100*sizeof(char));
//    char *p_in; p_in = (char*)malloc(100*sizeof(char));
//    char *q_pre; q_pre = (char*)malloc(100*sizeof(char));
//    char *q_in; q_in = (char*)malloc(100*sizeof(char));
//
//    p_pre = pre_order_travel(p);
//    i = 0;memset(a,'\0',100);//����i��a����ȫ�ֱ������ù���
//    q_pre = pre_order_travel(q);
//    if( strcmp(p_pre,q_pre) != 0 )
//        return false;
//
//    p_in = in_order_travel(p);
//    j = 0;memset(b,'\0',100);//����j��b����ȫ�ֱ������ù���
//    q_in = in_order_travel(q);
//    if( strcmp(p_in,q_in) != 0 )
//        return false;
//    return true;
//}
/*******
������---accept  ����ʱ�临�Ӷȸ���
*******/
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if( p == NULL && q == NULL )
        return true;
    if( p == NULL || q == NULL )
        return false;
    if( p->val != q->val )
        return false;
    bool left_result = isSameTree(p->left,q->left);
    bool right_result = isSameTree(p->right,q->right);
    return left_result&&right_result;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
