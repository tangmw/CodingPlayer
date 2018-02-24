/*******************************************************************************************
������ķ�㷨��
���㷨������ͼΪ����ͼ�Ĵ洢��ʽ�����ڽӾ���
1)�Ե�һ�����㿪ʼ���㷨������һ������(i = 0)������С��������low_cost[i] = 0��0�����Ѿ�������������;
2)������i���ڽӾ��󣬸����붥��i�бߵĶ����Ȩֵ(��Ȩֵ���ĳ�ʼ��ֵΪ���һ�������б����ӵĶ����Ȩֵ)
3)�������low_costȨֵ���ϣ��ҵ���СȨֵ�����
Ϊ���ҵ��뵱ǰ�����бߵ�ǰһ�����㣬�㷨��Vertex_Information[]�����˼�¼
Author:tmw
date:2017-10-17
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
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%d\t",G->edge[i][j]);
        printf("\n");
    }
}
void Min_Create_Tree_Prim( Matrix_Graph *G )
{
    int i,j,min;
    int mark = 0;
    int low_cost[MAX_VERTEX];
    int Vertex_Information[MAX_VERTEX];//�����ҵ�Ȩֵ��С�ߵ�ǰһ������

    low_cost[0] = 0;     //low_cost��¼�Ѿ�����������С�������Ķ��㣬��Ϊ0������Ϊ�ù�
                        //����ӵ�һ�����㿪ʼ������С��������������ȱ����Ϊ0
    for( i = 1 ; i < G->vertex_number ; i++ )//��Ϊ��һ�������Ѿ���������������˴ӵڶ������㿪ʼ����
    {
        low_cost[i] = G->edge[0][i];//�����һ�������б������Ķ���Ȩֵ����low_cost����
        Vertex_Information[i] = 0; //��ʼ����ض�����±궼�ӵ�һ�����㿪ʼ
    }
    for( i = 1 ; i < G->vertex_number ; i++ )
    {
        min = inf;
        j = 1;
        while( j < G->vertex_number )//�ҳ��뵱ǰ����Ȩֵ��С�Ķ���
        {
            if( low_cost[j]!=0 && low_cost[j] < min )
            {
                min = low_cost[j];
                mark = j;//����СȨֵ�����������
            }
            j++;
        }
        low_cost[mark] = 0;//����¼��붥���Ѿ�������������
        printf("[%d %d] ---",Vertex_Information[mark],mark);//��ӡ�����±��
        printf("%c %c\n",G->vertex[Vertex_Information[mark]],G->vertex[mark]);//��ӡ�ҵ��ĵ�ǰ�������СȨֵ��

        //�� �뵱ǰ������¼��붥���� ����������������
        for( j = 1 ; j < G->vertex_number ; j++ )
        {
            if( low_cost[j] != 0 && low_cost[j] > G->edge[mark][j] )//���� �뵱ǰ������¼��붥��� ������֮���������Ȩֵ
            {
                low_cost[j] = G->edge[mark][j];
                Vertex_Information[j] = mark;//��Ǳߵĵ�һ������
            }
        }
    }
}
int main()
{
    Matrix_Graph *G;
    G = (Matrix_Graph*)malloc(sizeof(Matrix_Graph));
    create_non_direction_matrix_Graph(G);
    Min_Create_Tree_Prim(G);
    return 0;
}
