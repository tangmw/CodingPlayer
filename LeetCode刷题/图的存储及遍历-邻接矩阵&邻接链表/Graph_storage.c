/*******************************************************************************************
【图的存储】---邻接矩阵&&邻接链表
*邻接矩阵：两点之间有边相连，则置1，无则置0

一、邻接矩阵优点
1）能知道任意两点之间是否有边
2）可明确任意顶点的度为多少（若为有向图，可以明确任意顶点的出度）
3）可明确任意顶点与之相连的点都有谁

*邻接链表--使用链式存储结构，避免空间浪费问题
1）每个顶点用一个一维数组存储
2）每个顶点的所有邻接点构成一个线性表

Author:tmw
date:2017-10-14
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100
#define inf 65535  //用65535代表无穷大
/*************************建立无向图邻接矩阵**************************/
typedef struct Matrix_Graph
{
    char vertex[MAX_VERTEX];//存储顶点信息
    int edge[MAX_VERTEX][MAX_VERTEX];//存储边信息
    int vertex_number,edge_number;//存储图中的顶点数和边数
}Matrix_Graph;
void create_non_direction_matrix_Graph( Matrix_Graph *G )
{
    int i,j,w,k;
    printf("请输入顶点数和边数：\n");
    scanf("%d,%d",&G->vertex_number,&G->edge_number);

    printf("请输入无向图顶点信息(如ABCD...)：\n");
    for( i = 0 ; i < G->vertex_number ; i++ )
        scanf("%c",&G->vertex[i]);

    //初始化边信息
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
            G->edge[i][j] = inf;

    printf("请输入无向图中相连的两个顶点下标值(Vi,Vj)，以及权值---即边信息\n");
    for( k = 0 ; k < G->edge_number ; k++ )
    {
        scanf("%d %d %d",&i,&j,&w);
        G->edge[i][j] = w;
        G->edge[j][i] = G->edge[i][j];//由于是无向图，故是对称阵
    }
    //打印邻接矩阵
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%d ",G->edge[i][j]);
}

/*************************建立有向图邻接矩阵**************************/
void create_direction_matrix_Graph(Matrix_Graph *G)
{
    int i,j,k,w;
    printf("请输入顶点数和边数：\n");
    scanf("%d %d",&G->vertex_number,&G->edge_number);

    printf("请输入有向图顶点信息(如ABCD....)：\n");
    for( i = 0 ; i < G->vertex_number ; i++ )
        scanf("%c",&G->vertex[i]);

    //初始化有向图
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
            G->edge[i][j] = inf;

    printf("请输入有向图中两个相连顶点下标值(Vi,Vj)以及权值\n");
    for( k = 0 ; k < G->edge_number ; k++ )
    {
        scanf("%d %d %d",&i,&j,&w);
        G->edge[i][j] = w;
    }
    //打印邻接矩阵
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%d ",G->edge[i][j]);
}

/*************************建立无向图邻接链表**************************/
typedef struct EdgeNode//建立边表结点
{
    int vertex_number;
    int weight;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode//建立顶点表结点
{
    char vertex;
    struct EdgeNode *firstEdge;
}VertexNode,Vertex_List[MAX_VERTEX];
typedef struct Graph_Linklist
{
    Vertex_List list;
    int number_of_vertex,number_of_edges;
}Graph_Linklist;

void create_non_direction_Linklist_Graph(Graph_Linklist *G)
{
    int i,j,k,w;
    printf("现在开始建立无向图的邻接链表！\n");
    printf("请输入顶点数和边数：\n");
    scanf("%d %d",&G->number_of_vertex,&G->number_of_edges);
    //输入表头结构
    printf("请输入顶点信息<如ABCD....>：\n");
    for( i = 0 ; i < G->number_of_vertex ; i++ )
    {
        scanf("%c",&G->list[i].vertex);
        G->list[i].firstEdge = NULL;//初始化表头指针结点
    }
    //插入边结点
    printf("请输入%d条边每条边的两个顶点信息以及权值：\n",G->number_of_edges);
    for( k = 0 ; k < G->number_of_edges ; k++ )
    {
        scanf("%d %d %d",&i,&j,&w);
        EdgeNode *edge;
        edge = (EdgeNode*)malloc(sizeof(EdgeNode));
        edge->weight = w;
        edge->vertex_number = j;
        edge->next = G->list[i].firstEdge;
        G->list[i].firstEdge = edge;//头插法

        //如果是有向图，则这一步可以不用写，其他都一样
        EdgeNode *edge_1;
        edge_1 = (EdgeNode*)malloc(sizeof(EdgeNode));
        edge_1->weight = w;
        edge_1->vertex_number = i;
        edge_1->next = G->list[j].firstEdge;
        G->list[j].firstEdge = edge_1;//因为是无向图，所以i j顶点的边信息是对称的
    }
}

/*************************************************************
【邻接矩阵DFS】深度优先搜索递归算法---DFS----复杂度O(n^2)
**************************************************************/
int visit_matrix[MAX_VERTEX];
void DFS_Matrix(Matrix_Graph G , int i)
{
    //定义一个visit数组，记录顶点是否被访问
    int j;
    visit_matrix[i] = 1;
    printf("%c ",G.vertex[i]);
    for( j = 0 ; j < G.vertex_number ; j++ )
    {
        if( G.edge[i][j] == 1 && !visit_matrix[j] )
            DFS_Matrix(G,j);
    }
}
void DFS_Travel_Matrix(Matrix_Graph G)
{
    //初始化visit_matrix数组
    int i;
    for( i = 0 ; i < G.vertex_number ; i++ )
        visit_matrix[i] = 0;
    for( i = 0 ; i < G.vertex_number ; i++ )
    {
        if( visit_matrix[i] != 1 )
            DFS_Matrix(G,i);//对于连通图，循环只会做一次，对于非连通图，循环会做多次
    }
}
/*********************************************************
【邻接链表DFS】深度优先搜索递归算法---DFS----复杂度O(n)
***********************************************************/
int visit_linklist[MAX_VERTEX];
void DFS_Linklist( Graph_Linklist G , int i )
{
    visit_linklist[i] = 1;
    printf("%c ",G.list[i].vertex);
    EdgeNode *p;
    p = G.list[i].firstEdge;
    while( p )
    {
        if( !visit_linklist[p->vertex_number] )
            DFS_Linklist(G,p->vertex_number);
        p = p->next;
    }
}
void DFS_Travel_Linklist( Graph_Linklist G )
{
    int i;
    for( i = 0 ; i < G.number_of_vertex ; i++ )
        visit_linklist[i] = 0;
    for( i = 0 ; i < G.number_of_vertex ; i++ )
        if( !visit_linklist[i] )
            DFS_Linklist(G,i);//对于连通图，循环只会做一次，对于非连通图，循环会做多次
}


/***************************队列操作****************************/
/**顺序队列数据结构**/
typedef struct SqQueue
{
    char data[MAX_VERTEX];
    int front;//头指针
    int rear;//尾指针
}SqQueue;
/**初始化空队列**/
void InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}
/**队列判空**/
int QueueisEmpty(SqQueue *Q)
{
    if( Q->front == Q->rear )
        return 0;
    return 1;
}
/**入队列**/
int EnQueue(SqQueue *Q , int element)
{
    /**入队列之前先判定队列是否满**/
    if( (Q->rear+1)%MAX_VERTEX == Q->front )
        return 0;
    Q->data[Q->rear] = element;
    Q->rear = (Q->rear+1)%MAX_VERTEX;
    return 1;
}
/**出队列**/
int DeQueue(SqQueue *Q , int *element)//当队列非空，删除队头元素，并用element返回其值
{
    /**出队列之前先判定队列是否为空**/
    if( QueueisEmpty(Q) )
        return 0;
    *element = Q->data[Q->front];
    Q->front = (Q->front+1)%MAX_VERTEX;
    return 1;
}
/***************************************************
【邻接矩阵BFS】宽度优先搜索算法---BFS---队列操作
**************************************************/
void BFS_Travel_Matrix(Matrix_Graph *G)
{
    int visit[G->vertex_number];
    int i,j;
    SqQueue Q;
    InitQueue(&Q);
    for( i = 0 ; i < G->vertex_number ; i++ )
        visit[i] = 0;//初始化标记访问数组
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        if( !visit[i] )//处理为被访问过的顶点
        {
            visit[i] = 1;
            EnQueue(&Q,i);//将已拜访的这个顶点放入队列
            printf("%c ",G->vertex[i]);
            while( !QueueisEmpty(&Q) )
            {
                DeQueue(&Q,&i);//将队列中的队首元素移除队列并将移出值赋给G->vertex[i]
                for( j = 0 ; j < G->vertex_number ; j++ )
                {
                    if( G->edge[i][j] == 1 && !visit[j] )//查找与当前删除队列的元素存在边且未访问过的顶点
                    {
                        visit[j] = 1;
                        EnQueue(&Q,j);//将与当前删除队列的元素存在边且未访问过的顶点加入队列
                        printf("%c ",G->vertex[j]);
                    }
                }
            }
        }
    }
}

/***************************************************
【邻接链表BFS】宽度优先搜索算法---BFS---队列操作
***************************************************/
void BFS_Travel_Linklist(Graph_Linklist *G)
{
    int i;
    int visit[MAX_VERTEX];
    SqQueue Q;
    InitQueue(&Q);
    EdgeNode *p;
    for( i = 0 ; i < MAX_VERTEX ; i++ )
        visit[i] = 0;
    for( i = 0 ; i < G->number_of_vertex ; i++ )
    {
        if( !visit[i] )
        {
            visit[i] = 1;
            EnQueue(&Q,i);
            printf("%c ",G->list[i].vertex);
            while( !QueueisEmpty(&Q) )
            {
                DeQueue(&Q,&i);
                p = G->list[i].firstEdge;//p指向当前已删除顶点边表链表的头指针---即指向与当前删除顶点有边的顶点
                while( p )
                {
                    if( !visit[p->vertex_number] )
                    {
                        visit[p->vertex_number] = 1;
                        EnQueue(&Q,p->vertex_number);
                        printf("%c ",G->list[p->vertex_number].vertex);
                    }
                    p = p->next;
                }
            }
        }
    }

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
