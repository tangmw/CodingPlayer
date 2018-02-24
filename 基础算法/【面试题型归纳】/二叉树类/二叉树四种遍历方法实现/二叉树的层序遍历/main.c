/*******************************************************************************************
【二叉树层序遍历】
先将树的根节点入队，
    如果队列不空，则进入循环
    {
      将队首元素出队，并输出它；
      如果该队首元素有左孩子，则将其左孩子入队；
      如果该队首元素有右孩子，则将其右孩子入队
    }
Author:tmw
date:2018-2-12
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

/**二叉树数据结构定义**/
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *left;
    struct BiTreeNode *right;
}BiTreeNode,*BiTree;

/**层序遍历会用到队列这个数据结构**/
/**循环队列**/
typedef struct
{
    BiTreeNode data[MAXSIZE];
    int front;  //头指针
    int rear;   //尾指针，队列非空则指向队尾最后一个元素后一个位置
}SqQueue;

//队列初始化
void InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}
//入队
bool EnQueue(SqQueue *Q, BiTreeNode *e)
{
    //判断队列是否满
    if( ( Q->rear+1 ) % MAXSIZE == Q->front )
        return false;
    Q->data[Q->rear]=*e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return true;
}
//出队---删除队首元素，并赋给e
BiTree DeQueue(SqQueue *Q, BiTreeNode *e)
{
    //判断队列是否为空
    if( Q->front == Q->rear )
        return NULL;
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return e;
}
//队列判空
bool isEmptyQueue(SqQueue *Q)
{
    return Q->front == Q->rear?true:false;
}

/**二叉树层序遍历算法**/
void LayerOrderTravel(BiTree T)
{
    SqQueue q;
    BiTreeNode p;

    if(T!=NULL)
    {
        //初始化队列
        InitQueue(&q);
        //先将根节点入队
        EnQueue(&q,T);

        //层序遍历
        while(!isEmptyQueue(&q))
        {
            //将根节点出队，并打印
            DeQueue(&q,&p);
            printf("%c ",p.data);
            if( p.left != NULL ) EnQueue(&q,p.left);
            if( p.right != NULL ) EnQueue(&q,p.right);
        }
        printf("\n");
    }
}

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
        CreateBiTree(&(*T)->left);
        CreateBiTree(&(*T)->right);
    }
}


int main()
{

    printf("测试代码\n");
    BiTree T;
    T = (BiTree)malloc(sizeof(BiTreeNode));

    printf("请给二叉树按照先序方式依次输入结点的值(空结点为#):\n");
    CreateBiTree(&T);

    printf("层序方式遍历结果：\n");
    LayerOrderTravel(T);
    printf("\n");

    return 0;
}
