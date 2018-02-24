/*******************************************************************************************
【BFS】
本算法的测试用例为《大话数据结构》p239中的图7-5-2
本算法以无向网为例，存储方式采用邻接矩阵
1）将该网以邻接矩阵的方式存储，由于这里的示例采用无向图，因此它是一个对称阵
2）选取A点为起始点，访问此顶点，用一个visit的bool型数组记录访问状态（false表示未被访问，true表示已访问）
3）从A的未被访问的邻接点出发，宽度优先遍历图，直到图中所有和v有路径相通的顶点都被访问到


Author:tmw
date:2018-2-20
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_VERTEX 100
#define inf 65535  //表示两点之间没有边相连

int visit[MAX_VERTEX];   //标记顶点是否被访问

/**无向图的邻接链表的建立**/
//边表结点数据结构
typedef struct EdgeNode
{
    int adjvex;  //存储该顶点对应的下标
    int weight;
    struct EdgeNode *next; //指向下一个邻接点
}EdgeNode;

//顶点表结点数据结构
typedef struct VertexNode
{
    char Vertex;  //存储顶点信息
    EdgeNode *FistEdge; //边表头指针
}VertexNode,AdjList[MAX_VERTEX];

//邻接链表图的数据结构
typedef struct
{
    AdjList adjList;
    int VertexNumber,EdgeNumber; //顶点数和边数
}GraphAdjList;


/**无向图邻接链表的建立**/
void Create_no_direction_LinkList_Graph(GraphAdjList *G)
{
    int i,j,w,k;
    printf("请输入无向图邻接链表的顶点数和边数：\n");
    scanf("%d %d",&G->VertexNumber,&G->EdgeNumber);

    //输入顶点信息，建立顶点表
    printf("顶点表的建立：输入顶点信息，如ABCDEF.....\n");
    char ch;
    while( ( ch = getchar()  != '\n' ) );
    for(i=0;i<G->VertexNumber;i++)
    {
        scanf("%c",&G->adjList[i].Vertex);
        G->adjList[i].FistEdge = NULL;
    }
    printf("边表的建立：输入边（vi,vj）的顶点下标，权值统一为1，如：0 1 1(权值)\n");

    for(k=0;k<G->EdgeNumber;k++)
    {
        scanf("%d %d %d",&i,&j,&w);

        EdgeNode *e;
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->weight = w;
        e->adjvex = j;
        e->next = G->adjList[i].FistEdge;   //头插法将下标为j的顶点插入与之相连的下标为i的结点链表中
        G->adjList[i].FistEdge = e;

        //无向图，因此是对称的，同样的操作将下标为i的顶点插入与之相连的下标为j的结点的链表中
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->weight = w;
        e->adjvex = i;
        e->next = G->adjList[j].FistEdge;
        G->adjList[j].FistEdge = e;
    }


//    打印检查
    printf("---------------------构造出来的无向图邻接链表的边信息如下---------------------\n");
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
/**BFS会用到队列这个数据结构**/
/**循环队列**/
typedef struct
{
    char data[MAX_VERTEX];
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
bool EnQueue(SqQueue *Q, char e)
{
    //判断队列是否满
    if( ( Q->rear+1 ) % MAX_VERTEX == Q->front )
        return false;
    Q->data[Q->rear]=e;
    Q->rear = (Q->rear+1)%MAX_VERTEX;
    return true;
}
//出队---删除队首元素，并赋给e
char* DeQueue(SqQueue *Q, char *e)
{
    //判断队列是否为空
    if( Q->front == Q->rear )
        return NULL;
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAX_VERTEX;
    return e;
}
//队列判空
bool isEmptyQueue(SqQueue *Q)
{
    return Q->front == Q->rear?true:false;
}

//无向图邻接链表BFS
void BFS_Travel(GraphAdjList G)
{
    int i,j,mark;
    char data;
    SqQueue Q;
    EdgeNode *p;
    //初始化visit数组
    for(i=0;i<G.VertexNumber;i++)
        visit[i] = false;

    //初始化队列
    InitQueue(&Q);

    //对每个顶点进行BFS
    printf("此无向图邻接链表BFS结果为：\n");
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

                //根据删除顶点实时更新追踪该顶点下标，以便正确找到与之相连的其他顶点
                for(j=0;j<G.VertexNumber;j++)
                    if(G.adjList[j].Vertex==data)
                        mark = j;

                p = G.adjList[mark].FistEdge;

                //找寻与此顶点相连且没访问过的其他顶点
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
    printf("测试代码\n");
    GraphAdjList G;
    Create_no_direction_LinkList_Graph(&G);
    BFS_Travel(G);
    return 0;
}
