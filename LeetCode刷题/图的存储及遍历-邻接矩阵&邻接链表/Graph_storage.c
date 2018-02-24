/*******************************************************************************************
��ͼ�Ĵ洢��---�ڽӾ���&&�ڽ�����
*�ڽӾ�������֮���б�����������1��������0

һ���ڽӾ����ŵ�
1����֪����������֮���Ƿ��б�
2������ȷ���ⶥ��Ķ�Ϊ���٣���Ϊ����ͼ��������ȷ���ⶥ��ĳ��ȣ�
3������ȷ���ⶥ����֮�����ĵ㶼��˭

*�ڽ�����--ʹ����ʽ�洢�ṹ������ռ��˷�����
1��ÿ��������һ��һά����洢
2��ÿ������������ڽӵ㹹��һ�����Ա�

Author:tmw
date:2017-10-14
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
    scanf("%d,%d",&G->vertex_number,&G->edge_number);

    printf("����������ͼ������Ϣ(��ABCD...)��\n");
    for( i = 0 ; i < G->vertex_number ; i++ )
        scanf("%c",&G->vertex[i]);

    //��ʼ������Ϣ
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
            G->edge[i][j] = inf;

    printf("����������ͼ�����������������±�ֵ(Vi,Vj)���Լ�Ȩֵ---������Ϣ\n");
    for( k = 0 ; k < G->edge_number ; k++ )
    {
        scanf("%d %d %d",&i,&j,&w);
        G->edge[i][j] = w;
        G->edge[j][i] = G->edge[i][j];//����������ͼ�����ǶԳ���
    }
    //��ӡ�ڽӾ���
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%d ",G->edge[i][j]);
}

/*************************��������ͼ�ڽӾ���**************************/
void create_direction_matrix_Graph(Matrix_Graph *G)
{
    int i,j,k,w;
    printf("�����붥�����ͱ�����\n");
    scanf("%d %d",&G->vertex_number,&G->edge_number);

    printf("����������ͼ������Ϣ(��ABCD....)��\n");
    for( i = 0 ; i < G->vertex_number ; i++ )
        scanf("%c",&G->vertex[i]);

    //��ʼ������ͼ
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
            G->edge[i][j] = inf;

    printf("����������ͼ���������������±�ֵ(Vi,Vj)�Լ�Ȩֵ\n");
    for( k = 0 ; k < G->edge_number ; k++ )
    {
        scanf("%d %d %d",&i,&j,&w);
        G->edge[i][j] = w;
    }
    //��ӡ�ڽӾ���
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%d ",G->edge[i][j]);
}

/*************************��������ͼ�ڽ�����**************************/
typedef struct EdgeNode//�����߱���
{
    int vertex_number;
    int weight;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode//�����������
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
    printf("���ڿ�ʼ��������ͼ���ڽ�����\n");
    printf("�����붥�����ͱ�����\n");
    scanf("%d %d",&G->number_of_vertex,&G->number_of_edges);
    //�����ͷ�ṹ
    printf("�����붥����Ϣ<��ABCD....>��\n");
    for( i = 0 ; i < G->number_of_vertex ; i++ )
    {
        scanf("%c",&G->list[i].vertex);
        G->list[i].firstEdge = NULL;//��ʼ����ͷָ����
    }
    //����߽��
    printf("������%d����ÿ���ߵ�����������Ϣ�Լ�Ȩֵ��\n",G->number_of_edges);
    for( k = 0 ; k < G->number_of_edges ; k++ )
    {
        scanf("%d %d %d",&i,&j,&w);
        EdgeNode *edge;
        edge = (EdgeNode*)malloc(sizeof(EdgeNode));
        edge->weight = w;
        edge->vertex_number = j;
        edge->next = G->list[i].firstEdge;
        G->list[i].firstEdge = edge;//ͷ�巨

        //���������ͼ������һ�����Բ���д��������һ��
        EdgeNode *edge_1;
        edge_1 = (EdgeNode*)malloc(sizeof(EdgeNode));
        edge_1->weight = w;
        edge_1->vertex_number = i;
        edge_1->next = G->list[j].firstEdge;
        G->list[j].firstEdge = edge_1;//��Ϊ������ͼ������i j����ı���Ϣ�ǶԳƵ�
    }
}

/*************************************************************
���ڽӾ���DFS��������������ݹ��㷨---DFS----���Ӷ�O(n^2)
**************************************************************/
int visit_matrix[MAX_VERTEX];
void DFS_Matrix(Matrix_Graph G , int i)
{
    //����һ��visit���飬��¼�����Ƿ񱻷���
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
    //��ʼ��visit_matrix����
    int i;
    for( i = 0 ; i < G.vertex_number ; i++ )
        visit_matrix[i] = 0;
    for( i = 0 ; i < G.vertex_number ; i++ )
    {
        if( visit_matrix[i] != 1 )
            DFS_Matrix(G,i);//������ͨͼ��ѭ��ֻ����һ�Σ����ڷ���ͨͼ��ѭ���������
    }
}
/*********************************************************
���ڽ�����DFS��������������ݹ��㷨---DFS----���Ӷ�O(n)
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
            DFS_Linklist(G,i);//������ͨͼ��ѭ��ֻ����һ�Σ����ڷ���ͨͼ��ѭ���������
}


/***************************���в���****************************/
/**˳��������ݽṹ**/
typedef struct SqQueue
{
    char data[MAX_VERTEX];
    int front;//ͷָ��
    int rear;//βָ��
}SqQueue;
/**��ʼ���ն���**/
void InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}
/**�����п�**/
int QueueisEmpty(SqQueue *Q)
{
    if( Q->front == Q->rear )
        return 0;
    return 1;
}
/**�����**/
int EnQueue(SqQueue *Q , int element)
{
    /**�����֮ǰ���ж������Ƿ���**/
    if( (Q->rear+1)%MAX_VERTEX == Q->front )
        return 0;
    Q->data[Q->rear] = element;
    Q->rear = (Q->rear+1)%MAX_VERTEX;
    return 1;
}
/**������**/
int DeQueue(SqQueue *Q , int *element)//�����зǿգ�ɾ����ͷԪ�أ�����element������ֵ
{
    /**������֮ǰ���ж������Ƿ�Ϊ��**/
    if( QueueisEmpty(Q) )
        return 0;
    *element = Q->data[Q->front];
    Q->front = (Q->front+1)%MAX_VERTEX;
    return 1;
}
/***************************************************
���ڽӾ���BFS��������������㷨---BFS---���в���
**************************************************/
void BFS_Travel_Matrix(Matrix_Graph *G)
{
    int visit[G->vertex_number];
    int i,j;
    SqQueue Q;
    InitQueue(&Q);
    for( i = 0 ; i < G->vertex_number ; i++ )
        visit[i] = 0;//��ʼ����Ƿ�������
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        if( !visit[i] )//����Ϊ�����ʹ��Ķ���
        {
            visit[i] = 1;
            EnQueue(&Q,i);//���Ѱݷõ��������������
            printf("%c ",G->vertex[i]);
            while( !QueueisEmpty(&Q) )
            {
                DeQueue(&Q,&i);//�������еĶ���Ԫ���Ƴ����в����Ƴ�ֵ����G->vertex[i]
                for( j = 0 ; j < G->vertex_number ; j++ )
                {
                    if( G->edge[i][j] == 1 && !visit[j] )//�����뵱ǰɾ�����е�Ԫ�ش��ڱ���δ���ʹ��Ķ���
                    {
                        visit[j] = 1;
                        EnQueue(&Q,j);//���뵱ǰɾ�����е�Ԫ�ش��ڱ���δ���ʹ��Ķ���������
                        printf("%c ",G->vertex[j]);
                    }
                }
            }
        }
    }
}

/***************************************************
���ڽ�����BFS��������������㷨---BFS---���в���
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
                p = G->list[i].firstEdge;//pָ��ǰ��ɾ������߱������ͷָ��---��ָ���뵱ǰɾ�������бߵĶ���
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
