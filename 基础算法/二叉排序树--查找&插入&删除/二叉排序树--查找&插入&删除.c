/*******************************************************************************************
【二叉排序树】
二叉排序树，它或者是一棵空树，或者是具有下列性质的二叉树
1）当它的左子树不空，则左子树上所有结点的值均小于它根结构的值
2）当它的右子树不空，则右子树上所有结点的值均大于它根结构的值
3）二叉排序树的左、右子树也分别为排序树
一、查找
构造一棵二叉排序树的目的不是为了排序，而是为了方便插入和删除操作
二叉排序树经过中序遍历后就是一个有序序列

二、插入
二叉排序树的插入，实际上是把关键字插入到树中合适的位置

三、删除
删除情况分三种：
1）当待删除结点为叶子结点时：直接删除
2）当待删除结点只存在左子树或者右子树时：结点删除后，将它的左子树或者右子树直接移动到删除结点的位置即可
3）当待删除结点既存在左子树又存在右子树时：找到待删除结点的前驱或后继（中序顺序后的前驱或后继）来替换当前
结点，然后再删除此结点
Author:tmw
date:2017-10-24
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//构造二叉排序树结点数据结构
typedef struct BiTreeNode
{
    int data;
    struct BiTreeNode *left;
    struct BiTreeNode *right;
}BiTreeNode,*BiTree;

/**********************二叉排序树的查找操作********************************
查找对象为T,Find_BiSortTree()函数在T中查找是否存在key值，用fing_back指针指
向查到的结点
1）如果key值存在，则find_back指向该元素结点，并返回1；
2）如果key值不存在，则返回最后查到的元素结点，并返回0；（注意：这里返回
的最后查到的元素结点的值是接近key值的，并不是整个T最后元素的结点）
****************************************************************************/
bool Find_BiSortTree( BiTree T , int key , BiTree f , BiTree *p )
{
    if( !T )//当递归到没有叶子结点的结点或者此二叉排序树为空,说明查找失败
    {
        *p = f;//指针Find_back指向最后查到的元素结点或者是树的根节点
        return false;//返回错误
    }
    else if( key == T->data )
    {
        *p = T;//如果key值存在，则find_back指向该元素结点，并返回1；
        return true;
    }
    else if( key < T->data )
        return Find_BiSortTree( T->left , key , T , p );//注意这里的find_T用T传参，因为当前结点为T->left，因此它最后查到的结点是T
    else
        return Find_BiSortTree( T->right , key , T , p );
}
/**********************二叉排序树的插入操作********************************
当二叉排序树中不存在key,则插入
当存在key，则不用插入，返回错误
****************************************************************************/
int Insert_BiSortTree( BiTree *T , int key )
{
    BiTree p,s;
    /*********************************************************************************************
    当Find_BiSortTree返回0，即没在二叉排序树中找到key值，可能此二叉排序树为空树，也可能非空。
    1）若是空树，则将key插入根节点
    2）若不是空树，则将key值插入,此时find_back指向最后查到的元素结点
    *********************************************************************************************/
    if( !Find_BiSortTree(*T,key,NULL,&p) )
    {
        s = (BiTree)malloc(sizeof(BiTreeNode));
        s->data = key;
        s->left = NULL;
        s->right = NULL;
        /*当树为空树，直接插到根结点位置*/
        if( !p )
            *T = s;
        /*当树不为空树，比较当前查找到的最后一个结点的值与key的大小*/
        else if( key > p->data )
            p->right = s;
        else
            p->left = s;
        return true;
    }
    else
        return false;

}
/**********************二叉排序树的创建操作********************************
在上一个插入的基础上，就可以对二叉排序树进行创建了
****************************************************************************/
BiTree Create_BiSortTree()//创建T树并返回T
{
    int len,i;
    BiTree T = NULL;
    printf("请输入待构建的二叉排序树的结点数目：");
    scanf("%d",&len);
    int a[len];
    printf("请输入%d个结点的具体值：",len);
    for( i = 0 ; i < len ; i++ )
        scanf("%d",&a[i]);

    /*创建*/
    for( i = 0 ; i < len ; i++ )
        Insert_BiSortTree(&T,a[i]);
    return T;
}
/**********************二叉排序树的删除操作********************************
删除情况分三种：
1）当待删除结点为叶子结点时：直接删除
2）当待删除结点只存在左子树或者右子树时：结点删除后，将它的左子树或者右子树直接移动到删除结点的位置即可
3）当待删除结点既存在左子树又存在右子树时：找到待删除结点的前驱或后继（中序顺序后的前驱或后继）来替换当前
结点，然后再删除此结点
****************************************************************************/
BiTree Delete_BiSortTree( BiTree T , int key )
{
    BiTree *p;
    p = (BiTree*)malloc(sizeof(BiTree));
    BiTree q,s;
    if( Find_BiSortTree(T,key,NULL,p) )//找到key值在二叉排序树的位置
    {
        if( (*p)->right == NULL )//当p指向的结点没有右孩子时，根据先后顺序，也包括了左右孩子都没有的情况
        {
            q = *p;
            *p = (*p)->left;
            free(q);
        }
        else if( (*p)->left == NULL )//当p指向的结点没有左孩子时
        {
            q = *p;
            *p = (*p)->right;
            free(q);
        }
        else//即待删除结点的左右子树都存在的情况
        {
            //找当前结点的前缀结点
            q = *p;
            s = q->left;
            while( s->right )
            {
                q = s;
                s = s->right;
            }
            (*p)->data = s->data;
            if( q != *p )//即q做了移动，进了上层的while循环----说明当前结点的左右叶子结点也有叶子结点
                q->right = s->left;
            else
                q->left = s->right;//s->right实际为空
            free(s);
        }
    }
    else//没找到需删除的结点，则返回错误
        return NULL;
    return T;
}

/*******中序打印,判定二叉排序树是否构造正确********/
void Print_Inorder( BiTree T )
{
    if( !T )
         return;

    Print_Inorder(T->left);
    printf("%d ",T->data);
    Print_Inorder(T->right);
}

int main()
{
    BiTree T;
    int del_num;
    T = (BiTree)malloc(sizeof(BiTreeNode));
    T = Create_BiSortTree();
    printf("构建的二叉排序树经中序打印后的结果为:\n");
    Print_Inorder(T);
    printf("请输入删除的结点值：");
    scanf("%d",&del_num);
    T = Delete_BiSortTree(T,del_num);
    printf("删除后的二叉树中序打印后的结果为：\n");
    Print_Inorder(T);
    return 0;
}
