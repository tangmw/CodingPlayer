/*******************************************************************************************
【最小生成树-克鲁斯卡尔算法】
本算法的测试用例为《大话数据结构》p252中的图7-6-7
本算法以无向图为例，图的存储方式采用邻接矩阵
与普里姆算法有所区别的是，克鲁斯卡尔算法以图的边为研究点
1）将图以邻接矩阵的方式存储，由于这里的示例采用无向图，因此它是一个对称阵
2）将该邻接矩阵转换为按权值由低到高排序、并同时记录了边的起点和终点的“新矩阵”
3）遍历此“新矩阵”，由于遍历前矩阵已按权值从低到高排序，因此最小生成树一定集中分布在新矩阵的前面
4）考虑到仅以权值最小这一个指标来生成最小生成树会造成“环路”，因此需要额外设定一个find函数来追溯每一个生成树内顶点的“源头”
5）在这个find函数中，返回值是输入顶点的“源头顶点”，若当前权值较小的边，它的起始点的“源头顶点”相同，说明加入此边后，最小生成树会形成“环路”
，因此要“牺牲”掉这个当前权值较小的边，转而从“新矩阵”中寻找下一个元素---即当前权值次较小边。算法如此循环，直到“新矩阵”的边找完为止，每次
被纳入生成树的边的起点和终点在程序中都进行打印输出。

算法复杂度：O(elog(e))  其中e由边数决定
log(e)来自于find函数，e来自于对边的大循环
Author:tmw
date:2017-10-19
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
    scanf("%d %d",&G->vertex_number,&G->edge_number);

    printf("请输入无向图顶点信息(如ABCD...)：\n");
    char ch;
    while( ( ch = getchar() ) != '\n' );
    for( i = 0 ; i < G->vertex_number ; i++ )
        scanf("%c",&G->vertex[i]);

    //初始化边信息
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
        {
            if( i == j )
                G->edge[i][j] = 0;
            else
                G->edge[i][j] = inf;
        }

    printf("请输入无向图中相连的两个顶点下标值(Vi,Vj)，以及权值---即边信息\n");
    for( k = 0 ; k < G->edge_number ; k++ )
    {
        scanf("%d %d %d",&i,&j,&w);
        G->edge[i][j] = w;
        G->edge[j][i] = G->edge[i][j];//由于是无向图，故是对称阵
    }
    //打印邻接矩阵
    printf("*************************构造的邻接矩阵如下**************************\n");
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%d\t",G->edge[i][j]);
        printf("\n");
    }
}

/*************************克鲁斯卡尔算法**************************/
//构造记录权值、边的起点、边的终点的边集矩阵结点
typedef struct Edge_Node
{
    int begin;
    int end;
    int weight;
}Edge_Node;
/***find函数***/
//功能：找寻每一个输入顶点的“源顶点”，并返回此源顶点
int find( int *parent , int f )//parent[i]数组记录顶点i的father为parent[i],层层追寻father，就可以找到顶点i的“源顶点”
{
    while( parent[f] > 0 )
        f = parent[f];
    return f;
}
void fastSort( Edge_Node array[] , int l , int r )
{
    int key = 0;
    Edge_Node key_node;
    int i = 0;
    int j = 0;

    key = array[l].weight; // digging
    key_node = array[l];

    i = l;  // set i be the left index
    j = r;  // set j be the right index

    while( ( i < j ) )
    {
        //right first
        while( ( array[j].weight >= key ) && ( i < j ))
            j--;
        if( i < j )  // array[j] < key
        {
            array[i] = array[j]; //fill dig
            i++;
        }//then array[j] be the dig

        //left next
        while( ( array[i].weight < key ) && ( i < j ) )
            i++;
        if( i < j )
        {
            array[j] = array[i];
            j--;
        }
    }
    //break: j == i
    array[i] = key_node;

    //the i be the critical point
    //recursive
    if( l < r )  //recurse end condition
    {
        fastSort(array,l,i-1);
        fastSort(array,i+1,r);
    }
    else
        return;
}
//克鲁斯卡尔主功能代码
void Kruscal( Matrix_Graph *G )
{
    int i,j,k,m,n,path;
    Edge_Node Edge[G->edge_number+2];
    int parent[G->vertex_number+2];

    //将邻接矩阵转换成记录权值、边的起点、边的终点的边集矩阵----“新矩阵”
    k = 0;
    path = 1;
    for( i = 1 ; i < G->vertex_number ; i++ )
    {
        for( j = 0 ; j < i ; j++ )
        {
            if( G->edge[i][j] != inf )
           {
                Edge[k].weight = G->edge[i][j];
                Edge[k].begin = i;
                Edge[k].end = j;
                k++;
           }
        }
    }
    //对边集矩阵进行排序---采用快速排序方法
    fastSort(Edge,0,G->edge_number);
    //打印“新矩阵”
    printf("***************构造的边集矩阵如下****************\n");
    printf("Edge[ ] \tbegin\tend\tweight\n");
    for( i = 0 ; i < G->edge_number ; i++ )
        printf("Edge[%d]:\t %d \t %d \t %d \t\n",i,Edge[i].begin,Edge[i].end,Edge[i].weight);

    //parent[]数组初始化：将所有顶点的父亲顶点置0
    for( i = 0 ; i < G->vertex_number ; i++ )
        parent[i] = 0;
    for( i = 0 ; i < G->edge_number ; i++ )
    {
        n = find( parent , Edge[i].begin );
        m = find( parent , Edge[i].end );//通过find找寻“待选”边两个顶点的“源顶点”
        if( n != m )
        {
            parent[m] = n;//更新m顶点的“源顶点”是n
            printf("路径 %d : [%d %d] , 权值为 %d\n",path,Edge[i].begin,Edge[i].end,Edge[i].weight);
            path++;
        }
    }
}

int main()
{
    Matrix_Graph *G;
    G = (Matrix_Graph*)malloc(sizeof(Matrix_Graph));
    create_non_direction_matrix_Graph(G);
    Kruscal(G);
    return 0;
}
