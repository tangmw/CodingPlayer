/***********************************************
【问题描述】
给定一个二叉树，找出其最小深度。
二叉树的最小深度为根节点到最近叶子节点的距离。

Author:tmw
date:2018-2-14
************************************************/
#include <stdio.h>
#include <stdlib.h>

/**二叉树的数据结构**/
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;


/**二叉树的建立--按照先序方式建立--插入**/
void CreateBiTree(BiTree *T)
{
    char val;
    scanf("%c",&val);

    if(val == '#')
        *T = NULL;  //null表示为空枝

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
    printf("测试代码\n");

    BiTree T;
    printf("建立二叉树：请按先序遍历的方式输入二叉树结点：\n");
    CreateBiTree(&T);
    printf("此二叉树的最小深度为：%d\n",minDepth(T));
    printf("此二叉树的最大深度为：%d\n",maxDepth(T));

    return 0;
}
