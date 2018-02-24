/*******************************************************************************************
【最短路径-迪杰斯特拉算法】
本算法的测试用例为《大话数据结构》p262中的图7-7-7
本算法以无向网为例，存储方式采用邻接矩阵
1）将该网以邻接矩阵的方式存储，由于这里的示例采用无向图，因此它是一个对称阵
2）选取A点为起始点，求A点到其他各个顶点之间的最短路径
3）算法开始跟prim算法类似，先用一个min_weight[]数组存储与顶点i有边相连的权值，并在每一次循环中找出与顶点i
有边相连的权值最小边的顶点，并用数组final_mark[]标记找到的这个顶点（final_mark[i]=1意味着这个顶点被加入最短路径中）
4）接下来算法开始与prim不同了。经过3）找到了权值最小边的顶点j之后，再遍历邻接矩阵中与顶点j有边相连的权值，
判断这些顶点的最短路径是从A直接到这些顶点的路径，还是从A经过顶点i再到这些顶点的路径和。若是后者，则更新
min_weight[]权值数组，并用path[]数组记录最短路径的路径下标。
5）大循环直到将每一个顶点都判定完结为止

算法复杂度：O(n^2)  其中n由顶点数决定
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

/*************************迪杰斯特拉算法**************************/
int min_weight[MAX_VERTEX];//记录各点最短路径权值和,最后需作为程序的返回数组
int path[MAX_VERTEX];//记录各点最短路径下标，最后需作为程序的返回数组
int final_mark[MAX_VERTEX];//final_mark[i]=1意味着顶点i已加入最短路径中
/****找到array数组中，顶点i到A的实际路径下标及对最短路径长度，返回这个累加值****/
int find_print( Matrix_Graph *G , int array[] , int f )
{
    int re_min_weight = min_weight[f];
    printf("%c<-",G->vertex[f]);
    while( array[f] != 0 )
    {
        f = array[f];
        printf("%c<-",G->vertex[f]);
    }
    printf("%c",G->vertex[0]);
    return re_min_weight;
}
void Dijkstra(Matrix_Graph *G , int first_index , int min_weight[] , int path[])//以A点作为算法起点
{
    int i,j,k,min;

    /************初始化**************/
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        min_weight[i] = G->edge[0][i]; //初始化min_weight[]权值数组为所有与A点有边相连的边的权值
        path[i] = 0;  //初始化全部顶点最短路径的路径下标为0
        final_mark[i] = 0;//全部顶点初始化为还未求的最短路径状态
    }

    /*******将第一个顶点A纳入最开始的最短路径相关数组的记录当中******/
    final_mark[0] = 1;//标记顶点A已纳入最短路径中
    path[0] = 0;//标记A的最短路径为A到A

    /***遍历除A顶点外的其他顶点，每循环一次找到A到顶点i的最短路径***/
    for( i = 1 ; i < G->vertex_number ; i++ )
    {
        min = inf;
        //类似prim算法的操作：从起始顶点出发，找到与此顶点有边相连的权值最小的顶点，并记录
        for( j = 0 ; j < G->vertex_number ; j++ )
        {
            if( !final_mark[j] && min_weight[j] < min )//找到了与该起始顶点有边相连的权值较小的点
            {
                k = j;//记录顶点下标
                min = min_weight[j];//更新参考比较值，在结束for循环后，真正的min就找到了并且追踪了下标
            }
        }
        final_mark[k] = 1;//标记找到的距当前顶点最近的点
        //从标记的顶点出发，修正当前路径及距离
        for( j = 0 ; j < G->vertex_number ; j++ )
        {
            if( !final_mark[j] && min+G->edge[k][j] < min_weight[j] )//若前距离小于从A点直接到该点的距离，则更新距离及路径
            {
                path[j] = k;//修改当前路径
                min_weight[j] = min+G->edge[k][j];//修改当前距离
            }
        }
    }
    /*****打印最短路径及路径长度******/
    printf("*****结果输出******\n");
    int ans;
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        printf("顶点A到顶点%c的最短路径为: ",G->vertex[i]);
        ans = find_print(G,path,i);
        printf("\t\t路径长度为：%d\n",ans);
    }
}

int main()
{
    Matrix_Graph *G;
    G = (Matrix_Graph*)malloc(sizeof(Matrix_Graph));
    create_non_direction_matrix_Graph(G);
    Dijkstra(G,0,min_weight,path);
    return 0;
}
