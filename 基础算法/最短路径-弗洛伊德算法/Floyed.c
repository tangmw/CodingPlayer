/*******************************************************************************************
【最短路径-弗洛伊德算法】
本算法的测试用例为《大话数据结构》p267中的图7-7-13
本算法以无向网为例，存储方式采用邻接矩阵
1）将该网以邻接矩阵的方式存储，由于这里的示例采用无向图，因此它是一个对称阵
2）弗洛伊德算法的优势在于，它在求任意顶点到其他顶点的最短路径的问题上，算法比迪杰斯特拉简明易懂
（当然，迪杰斯特拉也可以求任意顶点到其他顶点的最短路径，只需在最外层循环再套一层for循环即可，算
法复杂度与弗洛伊德算法一样）
3）算法的精髓在于，每进行外层循环一次，算法都会对每个顶点进行一个判定：是两点间路径最短，还是经
过最外层循环的顶点进行中转后的路径最短
4）算法用两个二维数组分别对最短路径path[][]和最短路径上的权值和min_weight[][]进行记录和存储

当面临着需要求所有顶点到所有顶点的最短路径时，弗洛伊德算法应该是不错的选择。
算法复杂度：O(n^3)  其中n由顶点数决定
Author:tmw
date:2017-10-21
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

/*************************佛洛依德算法**************************/
int path[MAX_VERTEX][MAX_VERTEX];//最短路径二维数组
int min_weight[MAX_VERTEX][MAX_VERTEX];//最短路径权值和二维数组
void Floyed( Matrix_Graph *G , int path[][MAX_VERTEX] , int min_weight[][MAX_VERTEX] )//二维数组作为形参需指定列数，否则非法
{
    int begin_vertex,end_vertex,insert_vertex;
    int i,j;

    /****初始化最短路径二维数组和最短路径权值和二维数组*****/
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        for( j = 0 ; j < G->vertex_number ; j++ )
        {
            min_weight[i][j] = G->edge[i][j];
            path[i][j] = j;
        }
    }
    /****弗洛伊德操作*****/
    for( insert_vertex = 0 ; insert_vertex < G->vertex_number ; insert_vertex++ )//中转顶点
    {
        for( begin_vertex = 0 ; begin_vertex < G->vertex_number ; begin_vertex++ )//起点
        {
            for( end_vertex = 0 ; end_vertex < G->vertex_number ; end_vertex++ )//终点
            {
                //如果经过下标为insert_vertex的顶点的路径比原两点之间路径还短
                if( min_weight[begin_vertex][end_vertex] > min_weight[begin_vertex][insert_vertex]+min_weight[insert_vertex][end_vertex])
                {
                    //更新最短路径权值和
                    min_weight[begin_vertex][end_vertex] = min_weight[begin_vertex][insert_vertex]+min_weight[insert_vertex][end_vertex];
                    //更新路径二维数组
                    path[begin_vertex][end_vertex] = path[begin_vertex][insert_vertex];
                }
            }
        }
    }
    printf("\n");
    /****打印最短路径二维数组和最短路径权值和二维数组*****/
    printf("&输出结果&\n");
    printf("******************最短路径权值和二维数组**********************\n");
    printf("   A  B  C  D  E  F  G  H  I \n");
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        printf("%c",G->vertex[i]);
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%3d",min_weight[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("********************最短路径二维数组************************\n");
    printf("  A B C D E F G H I \n");
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        printf("%c ",G->vertex[i]);
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%d ",path[i][j]);
        printf("\n");
    }
    printf("\n");
    /****详细结果打印：以A到其他所有顶点间的最短路径为例*****/
    printf("*详细结果打印：以A到其他所有顶点间的最短路径为例*\n");
    int mark;
    for( i = 1 ; i < G->vertex_number ; i++ )//因为确定求A到其他所有顶点的最短路径，因此这里i从1开始，如果求任意点到任意点的最短路径，只需往外层加一个循环即可
    {
        mark = path[0][i];
        printf("顶点%c到顶点%c的最短路径为：",G->vertex[0],G->vertex[i]);
        printf("%c->",G->vertex[0]);
        while( mark != i )
        {
            printf("%c->",G->vertex[mark]);
            mark = path[mark][i];
        }
        printf("%c  \t",G->vertex[mark]);
        printf("长度为：%d\n",min_weight[0][i]);
    }
}

int main()
{
    Matrix_Graph *G;
    G = (Matrix_Graph*)malloc(sizeof(Matrix_Graph));
    create_non_direction_matrix_Graph(G);
    Floyed(G,path,min_weight);
    return 0;
}
