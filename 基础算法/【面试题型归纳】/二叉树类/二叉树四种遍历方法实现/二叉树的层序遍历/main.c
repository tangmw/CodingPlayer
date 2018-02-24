/*******************************************************************************************
�����������������
�Ƚ����ĸ��ڵ���ӣ�
    ������в��գ������ѭ��
    {
      ������Ԫ�س��ӣ����������
      ����ö���Ԫ�������ӣ�����������ӣ�
      ����ö���Ԫ�����Һ��ӣ������Һ������
    }
Author:tmw
date:2018-2-12
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

/**���������ݽṹ����**/
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *left;
    struct BiTreeNode *right;
}BiTreeNode,*BiTree;

/**����������õ�����������ݽṹ**/
/**ѭ������**/
typedef struct
{
    BiTreeNode data[MAXSIZE];
    int front;  //ͷָ��
    int rear;   //βָ�룬���зǿ���ָ���β���һ��Ԫ�غ�һ��λ��
}SqQueue;

//���г�ʼ��
void InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}
//���
bool EnQueue(SqQueue *Q, BiTreeNode *e)
{
    //�ж϶����Ƿ���
    if( ( Q->rear+1 ) % MAXSIZE == Q->front )
        return false;
    Q->data[Q->rear]=*e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return true;
}
//����---ɾ������Ԫ�أ�������e
BiTree DeQueue(SqQueue *Q, BiTreeNode *e)
{
    //�ж϶����Ƿ�Ϊ��
    if( Q->front == Q->rear )
        return NULL;
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return e;
}
//�����п�
bool isEmptyQueue(SqQueue *Q)
{
    return Q->front == Q->rear?true:false;
}

/**��������������㷨**/
void LayerOrderTravel(BiTree T)
{
    SqQueue q;
    BiTreeNode p;

    if(T!=NULL)
    {
        //��ʼ������
        InitQueue(&q);
        //�Ƚ����ڵ����
        EnQueue(&q,T);

        //�������
        while(!isEmptyQueue(&q))
        {
            //�����ڵ���ӣ�����ӡ
            DeQueue(&q,&p);
            printf("%c ",p.data);
            if( p.left != NULL ) EnQueue(&q,p.left);
            if( p.right != NULL ) EnQueue(&q,p.right);
        }
        printf("\n");
    }
}

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
        CreateBiTree(&(*T)->left);
        CreateBiTree(&(*T)->right);
    }
}


int main()
{

    printf("���Դ���\n");
    BiTree T;
    T = (BiTree)malloc(sizeof(BiTreeNode));

    printf("�����������������ʽ�����������ֵ(�ս��Ϊ#):\n");
    CreateBiTree(&T);

    printf("����ʽ���������\n");
    LayerOrderTravel(T);
    printf("\n");

    return 0;
}
