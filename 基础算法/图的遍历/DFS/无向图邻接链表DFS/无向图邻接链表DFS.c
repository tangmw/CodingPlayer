/*******************************************************************************************
【DFS】
本算法的测试用例为《大话数据结构》p239中的图7-5-2
本算法以无向网为例，存储方式采用邻接矩阵
1）将该网以邻接矩阵的方式存储，由于这里的示例采用无向图，因此它是一个对称阵
2）选取A点为起始点，访问此顶点，用一个visit的bool型数组记录访问状态（false表示未被访问，true表示已访问）
3）从A的未被访问的邻接点出发，深度优先遍历图，直到图中所有和v有路径相通的顶点都被访问到

算法复杂度：O(n+e)
邻接矩阵和邻接表都是实现BFS和DFS的方法，邻接矩阵时间复杂度为O(n^2)，邻接表的时间复杂度为O(n+e);
因此邻接矩阵适用于稠密图，邻接表适用于稀疏图。


在实际编写代码时，笔者发现：
1）对采用邻接链表作为存储方式的图做DFS时，由于建立邻接链表时可采用不同的插入方法：比如头插法和尾插法，会
使得做DFS时相同的图结构会有不一样的结果；
2）即使相同的图结构，采用不同的存储方式（邻接矩阵和邻接链表）做DFS时，它们的结果有时也会不一样；

笔者认为这都是正常现象，DFS的思想还是没变。

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

//无向图的邻接链表的第i个顶点的DFS
void DFS(GraphAdjList G, int i)
{
    visit[i] = true;
    printf("%c ",G.adjList[i].Vertex);

    EdgeNode *p;
    p = G.adjList[i].FistEdge;

    while(p)
    {
        if( !visit[p->adjvex] )
            DFS(G,p->adjvex);
        p = p->next;
    }
}

//对整个无向图进行DFS
void DFS_Travel(GraphAdjList G)
{
    int i;

    //先初始化visit数组
    for(i=0;i<G.VertexNumber;i++)
        visit[i] = false;

    printf("无向图的邻接链表DFS结果为：\n");
    for(i=0;i<G.VertexNumber;i++)
        if(!visit[i])
            DFS(G,i);
}


int main()
{
    printf("测试代码\n");
    GraphAdjList G;
    Create_no_direction_LinkList_Graph(&G);
    DFS_Travel(G);
    return 0;
}
