/*******************************************************************************************
线索二叉树---中序遍历

时间复杂度：O(n)

思想：
step1:以二叉树的前序遍历方式输入数据，空位补NULL；
step2:将建立好的二叉树进行中序线索化
step3:给已中序线索化的二叉树(此时变成了双向链表)加入头结点，方便遍历和查找
step4:找到中序遍历的第一个元素后，中序遍历整个二叉树

关键：
线索二叉树数据结构中的布尔型变量Thread和Link,,
1)当结点存在左(右)孩子时，则为Link(即0)，结点的左(右)孩子指向正常的左(右孩子)
2)当结点不存在左(右)孩子时，则为Thread(即1，结点的左(右)孩子指向它中序遍历的前驱(后继)

注意：
1)下面的代码在前序遍历二叉树和中序线索化二叉树采用了递归方法
2)但在中序遍历二叉树过程中并没有用到递归方法
3)中序遍历递归方法将在注解中体现出来

Author:tmw
date:2017-9-11
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****定义二叉树线索化的数据结构*****/
/**************************************************8***
    Link == 0 --代表存在左(右)孩子
    Thread == 1 --代表不存在左(右)孩子，需进行线索化
*******************************************************/
typedef enum {Link,Thread} PointerFlag;
typedef struct ThreadedBinaryNode
{
    char data;
    PointerFlag ltag;
    PointerFlag rtag;
    struct ThreadedBinaryNode* lchild;
    struct ThreadedBinaryNode* rchild;
}ThreadedBinaryNode, *ThreadBinaryTree;

ThreadBinaryTree pre; //全局变量---指向当前结点的前驱，即刚刚访问过的点

/*****step1:创建二叉树：前序输入方式创建；方法：递归*****/
ThreadBinaryTree CreatBiTree_preTravel(ThreadBinaryTree T)//ThreadBinaryTree* 相当于**ThreadedBinaryNode
{
    char ch;

    //printf("创建二叉树：请按前序遍历方式输入结点数据[结点数据为空的用#表示]：\n");
    //while( ( ch = getchar()) != '\n' );//清除缓存里的内容，包括\n
    scanf("%c ",&ch);
    if( ch == '#')
        T = NULL;//当没有结点时，应设置为NULL，方便判断父结点是不是存在孩子结点
    else
    {
        T = (ThreadedBinaryNode*)malloc(sizeof(ThreadedBinaryNode));
        T->data = ch;
        T->ltag = Link;//未线索化之前统统把ltag置0，不论它是否真有子结点。在后面的程序中，会将没有子结点的ltag置1标记
        T->rtag = Link;

        T->lchild = CreatBiTree_preTravel(T->lchild);
        T->rchild = CreatBiTree_preTravel(T->rchild);
    }
    return T;
}

/*****************************************************
step0：检查树构造是否正确---二叉树中序打印函数
*****************************************************/
void Print_Tree( ThreadBinaryTree T )
{
    if( T )
    {
        if( T->lchild == NULL && T->rchild == NULL )
            printf("结点的data为 %c \n",T->data);
        else
        {
            Print_Tree(T->lchild);
            Print_Tree(T->rchild);
        }
    }
}

/*****step2:线索化二叉树：中序线索化；方法：递归*****/
/***************************************************************************************************
注意：这个代码应用的就是中序递归的模板，只不过在中间加了记录线索路径的操作，
因此在中序递归的过程中，它的前驱就是中序后的前驱，它的后继就是中序递归后的后继，
而现在这个线索化，完全是为了后面一个子函数的功能：把树变成双向链表，方便对二叉树实现查找和遍历
****************************************************************************************************/
void ThreadBinTree( ThreadBinaryTree T )
{
    if(T)
    {
        ThreadBinTree(T->lchild);//左
        if( !T->lchild )
        {
            T->ltag = Thread;//当前结点左孩子不存在，将ltag改标记位置1
            T->lchild = pre; //pre指向当前结点的前驱,pre的初始化是指向后面即将定义的双向链表的头结点
        }
        if( !(pre->rchild) )
        {
            pre->rtag = Thread;
            pre->rchild = T;
        }
        pre = T;   //中
        ThreadBinTree( T->rchild );//右
    }
}

/*****step3:给线索化的二叉树建立头结点，使之成为标准双向链表*****/
/******************************************************************************************************************
第二步做完之后，形成了一个没有头结点的双向链表，因此为了更好地符合双向链表“身份”，下面的函数将为这个链表建立
头结点，同时将上一个函数涉及到的pre的初始值指向这个头结点，这样一来pre就不至于指向最前面的那个元素自己了；

为了实现双向链表，除了将pre的初始值指向这个头结点之外，还做了以下事：
1)将头结点左孩子指针指向树T的根结点
2)将中序遍历的最后一个元素的右孩子(既然是最后一个元素了，它肯定没有右孩子)标记为置Thread，并指向头结点
3)将头结点右孩子指针指向中序遍历最后一个元素

这样处理之后，树T就完完全全变成了首尾相连有头结点的标准双向链表了。
*******************************************************************************************************************/
void ThreadBinInOrder( ThreadBinaryTree T , ThreadBinaryTree* Head )
{
    *Head = (ThreadBinaryTree)malloc(sizeof(ThreadedBinaryNode));
    (*Head)->ltag = Link;
    (*Head)->rtag = Thread;
    (*Head)->rchild = (*Head);

    if(!T)
        (*Head)->lchild = (*Head);//当树T为空时，头结点指向自己本身，而不让头结点指针乱飞造成指针错误
    else
    {
        (*Head)->lchild = T;//如上所述：当树T存在时，将头结点的左孩子指向树T根结点
        pre = (*Head);//如上所述：将pre初始值指向这个头结点
        ThreadBinTree(T);
        pre->rtag = Thread;//如上所述，pre指向中序遍历后的最后一个元素，将它的右指针标记位置1，
        pre->rchild = (*Head);//如上所述：将pre指向它的后继---头结点
        (*Head)->rchild = pre;//如上所述：将头结点的后继指回中序遍历后的最后一个元素pre，实现首尾相连的双向链表
    }
}

/*****step4:中序遍历线索二叉树；方法：非递归*****/
void TravelThreadBinTree( ThreadBinaryTree T )
{
    ThreadedBinaryNode *p;
    p = T->lchild;

    while( p != T )
    {
        while( p->ltag == Link )
            p = p->lchild;//当当前结点有左孩子，说明它一定不是中序遍历第一个结点，中序遍历第一个结点是一定没有左孩子的
        /***跳出while循环时，说明中序遍历最左边的元素已经找到了***/
        printf("%c",p->data);
        /***接下来就按照双向链表的方式对树T进行遍历***/
        /**当当前结点没有右孩子时，它的rtag标记为Thread，因此，它的右孩子指针就指向它中序遍历的后继，找到后可以直接打印输出***/
        while( p->rtag == Thread && p->rchild != T )
        {
            p = p->rchild;
            printf("%c",p->data);
        }
        /**当当前结点有右孩子时，它的rtag标记为Link,此时只需要将指针挪到它真正的右孩子，对其右孩子的分支进行相同的判断操作而不是直接打印**/
        p = p->rchild;
    }

}


int main()
{
    ThreadBinaryTree T;
    ThreadedBinaryNode* Head;

    T = (ThreadBinaryTree)malloc(100*sizeof(ThreadedBinaryNode));

    printf("创建二叉树：前序输入方式创建\n");

    char ch;
    while( ( ch = getchar()) != '\n' );//清除缓存里的内容，包括\n
    T = CreatBiTree_preTravel(T);
    while( ( ch = getchar()) != '\n' );//清除缓存里的内容，包括\n
    Print_Tree(T);

    ThreadBinInOrder(T,&Head);

    printf("中序输出结果为：\n");

    TravelThreadBinTree(T);
    printf("\n");
    return 0;
}
