/***********************************************
������������
����һ�����������ҳ�����С��ȡ�
����������С���Ϊ���ڵ㵽���Ҷ�ӽڵ�ľ��롣

Author:tmw
date:2018-2-14
************************************************/
#include <stdio.h>
#include <stdlib.h>

/**�����������ݽṹ**/
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;


/**�������Ľ���--��������ʽ����--����**/
void CreateBiTree(BiTree *T)
{
    char val;
    scanf("%c",&val);

    if(val == '#')
        *T = NULL;  //null��ʾΪ��֦

    else
    {
        *T = (BiTree)malloc(sizeof(BiTreeNode));
        if(!*T)
            exit(0);
        (*T)->data = val;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

int minDepth(BiTree T)
{
    if(T==NULL)
        return 0;
    int depth_left = minDepth(T->lchild);
    int depth_right = minDepth(T->rchild);
    if(depth_left==0||depth_right==0)
        return depth_left+depth_right+1;
    else
        return depth_left>depth_right?depth_right+1:depth_left+1;
}

int maxDepth(BiTree T)
{
    if(T==NULL)
        return 0;
    int depth_left = maxDepth(T->lchild);
    int depth_right = maxDepth(T->rchild);
    return depth_left>depth_right?depth_left+1:depth_right+1;
}

int main()
{
    printf("���Դ���\n");

    BiTree T;
    printf("�������������밴��������ķ�ʽ�����������㣺\n");
    CreateBiTree(&T);
    printf("�˶���������С���Ϊ��%d\n",minDepth(T));
    printf("�˶�������������Ϊ��%d\n",maxDepth(T));

    return 0;
}
