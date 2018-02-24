/*******************************************************************************************
��BFS��
���㷨�Ĳ�������Ϊ�������ݽṹ��p239�е�ͼ7-5-2
���㷨��������Ϊ�����洢��ʽ�����ڽӾ���
1�����������ڽӾ���ķ�ʽ�洢�����������ʾ����������ͼ���������һ���Գ���
2��ѡȡA��Ϊ��ʼ�㣬���ʴ˶��㣬��һ��visit��bool�������¼����״̬��false��ʾδ�����ʣ�true��ʾ�ѷ��ʣ�
3����A��δ�����ʵ��ڽӵ������������ȱ���ͼ��ֱ��ͼ�����к�v��·����ͨ�Ķ��㶼�����ʵ�


Author:tmw
date:2018-2-20
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_VERTEX 100
#define inf 65535  //��ʾ����֮��û�б�����

int visit[MAX_VERTEX];   //��Ƕ����Ƿ񱻷���

/**����ͼ���ڽ�����Ľ���**/
//�߱������ݽṹ
typedef struct EdgeNode
{
    int adjvex;  //�洢�ö����Ӧ���±�
    int weight;
    struct EdgeNode *next; //ָ����һ���ڽӵ�
}EdgeNode;

//����������ݽṹ
typedef struct VertexNode
{
    char Vertex;  //�洢������Ϣ
    EdgeNode *FistEdge; //�߱�ͷָ��
}VertexNode,AdjList[MAX_VERTEX];

//�ڽ�����ͼ�����ݽṹ
typedef struct
{
    AdjList adjList;
    int VertexNumber,EdgeNumber; //�������ͱ���
}GraphAdjList;


/**����ͼ�ڽ�����Ľ���**/
void Create_no_direction_LinkList_Graph(GraphAdjList *G)
{
    int i,j,w,k;
    printf("����������ͼ�ڽ�����Ķ������ͱ�����\n");
    scanf("%d %d",&G->VertexNumber,&G->EdgeNumber);

    //���붥����Ϣ�����������
    printf("�����Ľ��������붥����Ϣ����ABCDEF.....\n");
    char ch;
    while( ( ch = getchar()  != '\n' ) );
    for(i=0;i<G->VertexNumber;i++)
    {
        scanf("%c",&G->adjList[i].Vertex);
        G->adjList[i].FistEdge = NULL;
    }
    printf("�߱�Ľ���������ߣ�vi,vj���Ķ����±꣬ȨֵͳһΪ1���磺0 1 1(Ȩֵ)\n");

    for(k=0;k<G->EdgeNumber;k++)
    {
        scanf("%d %d %d",&i,&j,&w);

        EdgeNode *e;
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->weight = w;
        e->adjvex = j;
        e->next = G->adjList[i].FistEdge;   //ͷ�巨���±�Ϊj�Ķ��������֮�������±�Ϊi�Ľ��������
        G->adjList[i].FistEdge = e;

        //����ͼ������ǶԳƵģ�ͬ���Ĳ������±�Ϊi�Ķ��������֮�������±�Ϊj�Ľ���������
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->weight = w;
        e->adjvex = i;
        e->next = G->adjList[j].FistEdge;
        G->adjList[j].FistEdge = e;
    }


//    ��ӡ���
    printf("---------------------�������������ͼ�ڽ�����ı���Ϣ����---------------------\n");
    for(i=0;i<G->VertexNumber;i++)
    {
        EdgeNode *p;
        p = G->adjList[i].FistEdge;
        printf("%d\t",i);
        while(p != NULL)
        {
            printf("%d ",p->adjvex);
            p = p->next;
        }
        printf("\n");
    }
}
/**BFS���õ�����������ݽṹ**/
/**ѭ������**/
typedef struct
{
    char data[MAX_VERTEX];
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
bool EnQueue(SqQueue *Q, char e)
{
    //�ж϶����Ƿ���
    if( ( Q->rear+1 ) % MAX_VERTEX == Q->front )
        return false;
    Q->data[Q->rear]=e;
    Q->rear = (Q->rear+1)%MAX_VERTEX;
    return true;
}
//����---ɾ������Ԫ�أ�������e
char* DeQueue(SqQueue *Q, char *e)
{
    //�ж϶����Ƿ�Ϊ��
    if( Q->front == Q->rear )
        return NULL;
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAX_VERTEX;
    return e;
}
//�����п�
bool isEmptyQueue(SqQueue *Q)
{
    return Q->front == Q->rear?true:false;
}

//����ͼ�ڽ�����BFS
void BFS_Travel(GraphAdjList G)
{
    int i,j,mark;
    char data;
    SqQueue Q;
    EdgeNode *p;
    //��ʼ��visit����
    for(i=0;i<G.VertexNumber;i++)
        visit[i] = false;

    //��ʼ������
    InitQueue(&Q);

    //��ÿ���������BFS
    printf("������ͼ�ڽ�����BFS���Ϊ��\n");
    for(i=0;i<G.VertexNumber;i++)
    {
        if(!visit[i])
        {
            visit[i] = true;

            EnQueue(&Q,G.adjList[i].Vertex);

            while(!isEmptyQueue(&Q))
            {
                DeQueue(&Q,&data);
                printf("%c ",data);

                //����ɾ������ʵʱ����׷�ٸö����±꣬�Ա���ȷ�ҵ���֮��������������
                for(j=0;j<G.VertexNumber;j++)
                    if(G.adjList[j].Vertex==data)
                        mark = j;

                p = G.adjList[mark].FistEdge;

                //��Ѱ��˶���������û���ʹ�����������
                while(p)
                {
                    if(!visit[p->adjvex])
                    {
                        visit[p->adjvex] = true;
                        EnQueue(&Q,G.adjList[p->adjvex].Vertex);
                    }
                    p = p->next;
                }
            }
        }
    }

}


int main()
{
    printf("���Դ���\n");
    GraphAdjList G;
    Create_no_direction_LinkList_Graph(&G);
    BFS_Travel(G);
    return 0;
}
