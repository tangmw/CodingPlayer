/*******************************************************************************************
�����·��-�Ͻ�˹�����㷨��
���㷨�Ĳ�������Ϊ�������ݽṹ��p262�е�ͼ7-7-7
���㷨��������Ϊ�����洢��ʽ�����ڽӾ���
1�����������ڽӾ���ķ�ʽ�洢�����������ʾ����������ͼ���������һ���Գ���
2��ѡȡA��Ϊ��ʼ�㣬��A�㵽������������֮������·��
3���㷨��ʼ��prim�㷨���ƣ�����һ��min_weight[]����洢�붥��i�б�������Ȩֵ������ÿһ��ѭ�����ҳ��붥��i
�б�������Ȩֵ��С�ߵĶ��㣬��������final_mark[]����ҵ���������㣨final_mark[i]=1��ζ��������㱻�������·���У�
4���������㷨��ʼ��prim��ͬ�ˡ�����3���ҵ���Ȩֵ��С�ߵĶ���j֮���ٱ����ڽӾ������붥��j�б�������Ȩֵ��
�ж���Щ��������·���Ǵ�Aֱ�ӵ���Щ�����·�������Ǵ�A��������i�ٵ���Щ�����·���͡����Ǻ��ߣ������
min_weight[]Ȩֵ���飬����path[]�����¼���·����·���±ꡣ
5����ѭ��ֱ����ÿһ�����㶼�ж����Ϊֹ

�㷨���Ӷȣ�O(n^2)  ����n�ɶ���������
Author:tmw
date:2017-10-21
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100
#define inf 65535  //��65535���������
/*************************��������ͼ�ڽӾ���**************************/
typedef struct Matrix_Graph
{
    char vertex[MAX_VERTEX];//�洢������Ϣ
    int edge[MAX_VERTEX][MAX_VERTEX];//�洢����Ϣ
    int vertex_number,edge_number;//�洢ͼ�еĶ������ͱ���
}Matrix_Graph;
void create_non_direction_matrix_Graph( Matrix_Graph *G )
{
    int i,j,w,k;
    printf("�����붥�����ͱ�����\n");
    scanf("%d %d",&G->vertex_number,&G->edge_number);

    printf("����������ͼ������Ϣ(��ABCD...)��\n");
    char ch;
    while( ( ch = getchar() ) != '\n' );
    for( i = 0 ; i < G->vertex_number ; i++ )
        scanf("%c",&G->vertex[i]);

    //��ʼ������Ϣ
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
        {
            if( i == j )
                G->edge[i][j] = 0;
            else
                G->edge[i][j] = inf;
        }

    printf("����������ͼ�����������������±�ֵ(Vi,Vj)���Լ�Ȩֵ---������Ϣ\n");
    for( k = 0 ; k < G->edge_number ; k++ )
    {
        scanf("%d %d %d",&i,&j,&w);
        G->edge[i][j] = w;
        G->edge[j][i] = G->edge[i][j];//����������ͼ�����ǶԳ���
    }
    //��ӡ�ڽӾ���
    printf("*************************������ڽӾ�������**************************\n");
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%d\t",G->edge[i][j]);
        printf("\n");
    }
}

/*************************�Ͻ�˹�����㷨**************************/
int min_weight[MAX_VERTEX];//��¼�������·��Ȩֵ��,�������Ϊ����ķ�������
int path[MAX_VERTEX];//��¼�������·���±꣬�������Ϊ����ķ�������
int final_mark[MAX_VERTEX];//final_mark[i]=1��ζ�Ŷ���i�Ѽ������·����
/****�ҵ�array�����У�����i��A��ʵ��·���±꼰�����·�����ȣ���������ۼ�ֵ****/
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
void Dijkstra(Matrix_Graph *G , int first_index , int min_weight[] , int path[])//��A����Ϊ�㷨���
{
    int i,j,k,min;

    /************��ʼ��**************/
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        min_weight[i] = G->edge[0][i]; //��ʼ��min_weight[]Ȩֵ����Ϊ������A���б������ıߵ�Ȩֵ
        path[i] = 0;  //��ʼ��ȫ���������·����·���±�Ϊ0
        final_mark[i] = 0;//ȫ�������ʼ��Ϊ��δ������·��״̬
    }

    /*******����һ������A�����ʼ�����·���������ļ�¼����******/
    final_mark[0] = 1;//��Ƕ���A���������·����
    path[0] = 0;//���A�����·��ΪA��A

    /***������A��������������㣬ÿѭ��һ���ҵ�A������i�����·��***/
    for( i = 1 ; i < G->vertex_number ; i++ )
    {
        min = inf;
        //����prim�㷨�Ĳ���������ʼ����������ҵ���˶����б�������Ȩֵ��С�Ķ��㣬����¼
        for( j = 0 ; j < G->vertex_number ; j++ )
        {
            if( !final_mark[j] && min_weight[j] < min )//�ҵ��������ʼ�����б�������Ȩֵ��С�ĵ�
            {
                k = j;//��¼�����±�
                min = min_weight[j];//���²ο��Ƚ�ֵ���ڽ���forѭ����������min���ҵ��˲���׷�����±�
            }
        }
        final_mark[k] = 1;//����ҵ��ľ൱ǰ��������ĵ�
        //�ӱ�ǵĶ��������������ǰ·��������
        for( j = 0 ; j < G->vertex_number ; j++ )
        {
            if( !final_mark[j] && min+G->edge[k][j] < min_weight[j] )//��ǰ����С�ڴ�A��ֱ�ӵ��õ�ľ��룬����¾��뼰·��
            {
                path[j] = k;//�޸ĵ�ǰ·��
                min_weight[j] = min+G->edge[k][j];//�޸ĵ�ǰ����
            }
        }
    }
    /*****��ӡ���·����·������******/
    printf("*****������******\n");
    int ans;
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        printf("����A������%c�����·��Ϊ: ",G->vertex[i]);
        ans = find_print(G,path,i);
        printf("\t\t·������Ϊ��%d\n",ans);
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
