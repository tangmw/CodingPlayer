/*******************************************************************************************
�����·��-���������㷨��
���㷨�Ĳ�������Ϊ�������ݽṹ��p267�е�ͼ7-7-13
���㷨��������Ϊ�����洢��ʽ�����ڽӾ���
1�����������ڽӾ���ķ�ʽ�洢�����������ʾ����������ͼ���������һ���Գ���
2�����������㷨���������ڣ����������ⶥ�㵽������������·���������ϣ��㷨�ȵϽ�˹���������׶�
����Ȼ���Ͻ�˹����Ҳ���������ⶥ�㵽������������·����ֻ���������ѭ������һ��forѭ�����ɣ���
�����Ӷ��븥�������㷨һ����
3���㷨�ľ������ڣ�ÿ�������ѭ��һ�Σ��㷨�����ÿ���������һ���ж����������·����̣����Ǿ�
�������ѭ���Ķ��������ת���·�����
4���㷨��������ά����ֱ�����·��path[][]�����·���ϵ�Ȩֵ��min_weight[][]���м�¼�ʹ洢

����������Ҫ�����ж��㵽���ж�������·��ʱ�����������㷨Ӧ���ǲ����ѡ��
�㷨���Ӷȣ�O(n^3)  ����n�ɶ���������
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

/*************************���������㷨**************************/
int path[MAX_VERTEX][MAX_VERTEX];//���·����ά����
int min_weight[MAX_VERTEX][MAX_VERTEX];//���·��Ȩֵ�Ͷ�ά����
void Floyed( Matrix_Graph *G , int path[][MAX_VERTEX] , int min_weight[][MAX_VERTEX] )//��ά������Ϊ�β���ָ������������Ƿ�
{
    int begin_vertex,end_vertex,insert_vertex;
    int i,j;

    /****��ʼ�����·����ά��������·��Ȩֵ�Ͷ�ά����*****/
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        for( j = 0 ; j < G->vertex_number ; j++ )
        {
            min_weight[i][j] = G->edge[i][j];
            path[i][j] = j;
        }
    }
    /****�������²���*****/
    for( insert_vertex = 0 ; insert_vertex < G->vertex_number ; insert_vertex++ )//��ת����
    {
        for( begin_vertex = 0 ; begin_vertex < G->vertex_number ; begin_vertex++ )//���
        {
            for( end_vertex = 0 ; end_vertex < G->vertex_number ; end_vertex++ )//�յ�
            {
                //��������±�Ϊinsert_vertex�Ķ����·����ԭ����֮��·������
                if( min_weight[begin_vertex][end_vertex] > min_weight[begin_vertex][insert_vertex]+min_weight[insert_vertex][end_vertex])
                {
                    //�������·��Ȩֵ��
                    min_weight[begin_vertex][end_vertex] = min_weight[begin_vertex][insert_vertex]+min_weight[insert_vertex][end_vertex];
                    //����·����ά����
                    path[begin_vertex][end_vertex] = path[begin_vertex][insert_vertex];
                }
            }
        }
    }
    printf("\n");
    /****��ӡ���·����ά��������·��Ȩֵ�Ͷ�ά����*****/
    printf("&������&\n");
    printf("******************���·��Ȩֵ�Ͷ�ά����**********************\n");
    printf("   A  B  C  D  E  F  G  H  I \n");
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        printf("%c",G->vertex[i]);
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%3d",min_weight[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("********************���·����ά����************************\n");
    printf("  A B C D E F G H I \n");
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        printf("%c ",G->vertex[i]);
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%d ",path[i][j]);
        printf("\n");
    }
    printf("\n");
    /****��ϸ�����ӡ����A���������ж��������·��Ϊ��*****/
    printf("*��ϸ�����ӡ����A���������ж��������·��Ϊ��*\n");
    int mark;
    for( i = 1 ; i < G->vertex_number ; i++ )//��Ϊȷ����A���������ж�������·�����������i��1��ʼ�����������㵽���������·����ֻ��������һ��ѭ������
    {
        mark = path[0][i];
        printf("����%c������%c�����·��Ϊ��",G->vertex[0],G->vertex[i]);
        printf("%c->",G->vertex[0]);
        while( mark != i )
        {
            printf("%c->",G->vertex[mark]);
            mark = path[mark][i];
        }
        printf("%c  \t",G->vertex[mark]);
        printf("����Ϊ��%d\n",min_weight[0][i]);
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
