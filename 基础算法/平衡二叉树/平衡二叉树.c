/*******************************************************************************************
【平衡二叉树】
---概念---
【平衡二叉树】
平衡二叉树也是一种二叉排序树，满足：每一个结点的左子树和右子树的高度差不大于1
【BF:平衡因子】
二叉树结点的左子树深度减去右子树深度的值。若为负，说明左子树深度低于右子树深度；若为正，说明左子树深度高于右子树深度
根据平衡二叉树定义可知，平衡二叉树的平衡因子取值只有三种情况：-1 0 1
归纳以上，可知：
满足平衡二叉树的两个条件：1）必须是二叉排序树；2）平衡因子只可能为 -1 0 1
【最小不平衡树】
以距离插入结点最近，且平衡因子的绝对值大于1的结点为根的二叉子树，称为最小不平衡树

平衡二叉树又称AVL树

算法实现原理：
在构建平衡二叉树的过程中，判定插入结点是否破坏了平衡性，若是，则找到最小不平衡树，在不破坏二叉排序树的前提
下，调整最小不平衡树结点间的连接关系，进行相应的左旋转操作和右旋转操作，使之成为平衡二叉树
【关于旋转】
1）当最小不平衡树的根节点的BF值为正，且它的左孩子的BF值也为正，则进行一次右旋转操作（顺时针旋转）；
2）当最小不平衡树的根节点的BF值为负，且它的右孩子的BF值也为负，则进行一次坐旋转操作（逆时针旋转）；
3）当最小不平衡树的根节点的BF值为正，且它的左孩子的BF值为负，则先以它的左孩子为根进行左旋转，把左孩子的BF值的正负性调整为与它根节点正负性一致后，
再以根节点为根进行右旋转；
4）当最小不平衡树的根节点的BF值为负，且它的右孩子的BF值为正，则先以它的右孩子为根进行右旋转，把右孩子的BF值的正负性调整为与它根节点正负性一致后，
再以根节点为根进行左旋转。

下面的代码分为五个模块：
左旋转、右旋转、左平衡旋转、右平衡旋转、构建平衡二叉树（插入）
考虑到【关于旋转】里的3）和4）情况，对应到排序二叉树的左支和右支处理方式不同，所以将左平衡旋转和右平衡旋转分别写了功能模块，方便最终平衡二叉树的构建

【平衡二叉树应用场合】
如果需要查找的集合本身没有顺序，且在频繁查找过程中同时也需要经常地加入或者删除某些元素，则需要构建一棵二叉排序树，
但是不平衡的二叉排序树的查找是非常低效的，因此在构建二叉排序树时，就让它是一棵平衡二叉树

平衡二叉树的查找时间复杂度为O(logn)，插入和删除时间复杂度为O(logn)

Author:tmw
date:2017-10-28
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***平衡二叉树结点结构体定义****/
typedef struct Balance_BinTreeNode
{
    int key;
    int bf;
    struct Balance_BinTreeNode *lchild;
    struct Balance_BinTreeNode *rchild;
}B_BinTreeNode,*BiTree;

/***左旋转操作***/
//以指针p指向的结点为根，对其进行左旋转操作，旋转完后，*p指向新的根结点
void L_rotate( BiTree *p )
{
    BiTree R;
    R = (*p)->rchild;//R为*p所指向结点的右孩子
    (*p)->rchild = R->lchild;
    R->lchild = (*p);
    *p = R; //*p指向新的根节点
}
/***右旋转操作***/
//以指针p指向的结点为根，对其进行右旋转操作，旋转完后，*p指向新的根结点
void R_rotate( BiTree *p )
{
    BiTree L;
    L = (*p)->lchild;//R为*p所指向结点的左孩子
    (*p)->lchild = L->rchild;
    L->rchild = (*p);
    *p = L;//*p指向新的根节点
}
/***左支平衡旋转操作***/
//当新插入的结点插在了原平衡二叉树的左支后，打破了原平衡，形成了最小不平衡二叉树
//此时的代码需要对上面所述的【关于旋转】的1）和3）进行实现
#define LH 1  //左支高
#define EN 0  //等高
#define RH -1 //右支高
void Left_Part_Balance( BiTree *T )//*T指向最小不平衡树的根节点
{
    BiTree L;
    BiTree Lr;

    L = (*T)->lchild; //L为*T左孩子的根节点
    Lr = L->lchild;

    switch( L->bf ) //检查看新结点插在了L的左孩子还是右孩子
    {
        case LH://此时新结点插在了L的左孩子上，属于【关于旋转】的1），即最小不平衡树的根节点的BF值为正，且它的左孩子的BF值也为正
        {
            //进行一次右旋转操作即可
            L->bf = (*T)->bf = EN;//先更新bf值
            R_rotate(T);
            break;
        }
        case RH://此时新结点插在了L的右孩子上，属于【关于旋转】的3），即最小不平衡树的根节点的BF值为正，且它的左孩子的BF值为负

            //判断是插入L右孩子的左子树还是右子树---虽然都要进行双旋处理，但分开判定是因为双旋后，*T和L的bf有所不同
            switch( Lr->bf )
            {
                case LH://新结点插在了L右孩子的左子树上,更新特定值
                        (*T)->bf = RH;
                        L->bf = EN;
                        break;
                case RH://新结点插在了L右孩子的右子树上，更新特定值
                        (*T)->bf = EN;
                        L->bf = LH;
                        break;
//                case EN:
//                        (*T)->bf = L->bf = EN;
//                        break;
            }
            Lr->bf = EN;
            L_rotate( &((*T)->lchild) );//先左旋的目的是让(*T)->bf与L->bf符号保持一致
            R_rotate(T);
    }
}
//分左支平衡旋转操作和右支平衡旋转操作处理是因为 左平衡处理的bf>0而右平衡处理的bf<0，对应当做双旋处理时，应
//先右旋再左旋，与左平衡处理刚好相反，因此需分成两个函数处理
/***右支平衡旋转操作***/
//当新插入的结点插在了原平衡二叉树的右支后，打破了原平衡，形成了最小不平衡二叉树
//此时的代码需要对上面所述的【关于旋转】的2）和4）进行实现
void Right_Part_Balance( BiTree *T )//*T指向最小不平衡树的根节点
{
    BiTree R;
    BiTree Rl;

    R = (*T)->rchild;
    Rl = R->lchild;

    switch( R->bf )
    {
        case RH://说明新结点插入在*T右孩子根节点的右半支---只需要进行单左旋操作即可
            (*T)->bf = R->bf = EN;
            L_rotate(T);
            break;
        case LH://说明新结点插入在*T右孩子根节点的左半支---需要进行双旋操作
            switch( Rl->bf )
            {
                case LH://新结点插入在R左孩子根节点的左半支,更新特定值
                        (*T)->bf = EN;
                        R->bf = RH;
                        break;
                case RH://新结点插入在R左孩子根节点的右半支,更新特定值
                        (*T)->bf = RH;
                        R->bf = EN;
                        break;
//                case EN:
//                        (*T)->bf = R->bf = EN;
            }
            Rl->bf = EN;
            R_rotate( &((*T)->rchild) );//先右旋的目的是让(*T)->bf与L->bf符号保持一致
            L_rotate(T);
    }
}
/***AVL树的创建***/
//采用递归的方式
//*T指向一棵平衡二叉树（或为空或实平衡）
//当树中存在关键字与待插入元素e相同的结点，则返回插入失败false
//插入e时，若导致平衡二插树不平衡，则进行相应的左支平衡或右支平衡操作
//布尔变量*taller跟踪新树左右是否长高
bool Insert_AVL_Tree( BiTree *T , int e , bool *taller )
{
    if( !*T )//当为空树时插进根节点；当为找到合适位置时，申请内存插进原平衡二叉树
    {
        *T = (BiTree)malloc(sizeof(B_BinTreeNode));
        (*T)->bf = EN;
        (*T)->key = e;
        (*T)->lchild = (*T)->rchild = NULL;
        *taller = true;
    }
    else //没找到合适的插入位置时
    {
        if( e == (*T)->key )//已存在关键字为e的结点，则返回错误
        {
            *taller = false;
            return false;
        }
        if( e < (*T)->key ) //e比当前结点关键字小，则进入左半支
        {
            if( !Insert_AVL_Tree( &(*T)->lchild , e , taller ) )//左支中存在关键字为e的结点，则返回false
                return false;
            if( *taller ) //e插进原平衡二叉树了，接下来判断是否造成不平衡
            {
                switch( (*T)->bf )//检查原平衡度
                {
                    case LH://原左支高，现在结点加入左支，需进行左支平衡操作
                            Left_Part_Balance(T);
                            *taller = false;//*taller值复位
                            break;
                    case EN://原本平衡，现在结点加入左支，无需旋转，只不过树增高了
                            (*T)->bf = LH;
                            *taller = true;
                            break;
                    case RH://原右支高，现在结点加入左支，现左右等高
                            (*T)->bf = EN;
                            *taller = false;
                            break;
                }
            }
        }
        else//e比当前结点关键字大，则进入右半支
        {
            if( !Insert_AVL_Tree( &(*T)->rchild , e , taller ) )//右支中存在关键字为e的结点，则返回false
                    return false;
            if( *taller )
            {
                switch( (*T)->bf )//检查原平衡度
                {
                    case LH://原左支高，插入右支，现平衡，无需旋转，更新bf,*taller值即可
                            (*T)->bf = EN;
                            *taller = false;
                            break;
                    case EN://原平衡，插入右支，无需旋转，更新bf,*taller值即可
                            (*T)->bf = RH;
                            *taller = true;
                            break;
                    case RH://原右支高，插入右支，现需做右支平衡操作，平衡后，更新bf,*taller
                            *taller = false;
                            Right_Part_Balance(T);//在右支平衡操作和左支平衡操作里，已经对(*T)->bf值做了更新，因此这里不重复更新了
                            break;
                }
            }
        }
    }
    return true;
}

/***AVL树的中序打印检查***/
void Print_In_order( BiTree *T )
{
    if( !*T )
        return;
    else
    {
        Print_In_order(&(*T)->lchild);
        printf("%d ",(*T)->key);
        Print_In_order(&(*T)->rchild);
    }
}

int main()
{
    int len,i;
    bool res;
    int *array;
    BiTree T=NULL;//T初始化为空

    printf("请输入待构建平衡二叉树的数组长度：\n");
    scanf("%d",&len);
    array = (int*)malloc(len*sizeof(int));
    printf("请输入数组元素(下面开始构建平衡二叉树，如果构建成功，则返回1,否则返回0\n)：");
    for( i = 0 ; i < len ; i++ )
    {
        scanf("%d",&array[i]);
        res = Insert_AVL_Tree(&T,array[i],&res);
        printf(" %d 插入平衡二叉树状态为：%d\n",array[i],res);
    }
    printf("平衡二叉树中序打印结果为：");
    Print_In_order(&T);
    return 0;
}
