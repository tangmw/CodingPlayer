/*******************************************************************************************
��BFS��
���㷨�Ĳ�������Ϊ�������ݽṹ��p242�е�ͼ7-5-3
���㷨��������Ϊ�����洢��ʽ�����ڽӾ���
1�����������ڽӾ���ķ�ʽ�洢�����������ʾ����������ͼ���������һ���Գ���
2��ѡȡA��Ϊ��ʼ�㣬���ʴ˶��㣬��һ��visit��bool�������¼����״̬��false��ʾδ�����ʣ�true��ʾ�ѷ��ʣ�
3����A��δ�����ʵ��ڽӵ������������ȱ���ͼ��ֱ��ͼ�����к�v��·����ͨ�Ķ��㶼�����ʵ�

������ȱ�����Ҫ�������У�˼����������Ĳ����������


Author:tmw
date:2018-2-20
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_VERTEX 100
#define inf 65535  //��ʾ����֮��û�б�����

int visit[MAX_VERTEX];   //��Ƕ����Ƿ񱻷���

/**ͼ���ڽӾ���Ľ���**/
//�ڽӾ������ݽṹ����
typedef struct Martrix_Graph
{
    char vertex[MAX_VERTEX]; //�洢������Ϣ
    int edge[MAX_VERTEX][MAX_VERTEX]; //�洢����Ϣ
    int vertex_number,edge_number;//�洢�������ͱ���
}Martrix_Graph;

void Create_non_direction_martrix_Graph( Martrix_Graph *G )
{
    int i,j,k,m;
    printf("�����빹�������ͼ�Ķ������ͱ�����\n");
    scanf("%d %d",&G->vertex_number,&G->edge_number);

    printf("����������ͼ������Ϣ����ABCDEF....����\n");
    char ch;
    while( ( ch = getchar() != '\n' ) );  //���˵�ǰ���\n����ֹ\n��scanf��ȥ
    for(i=0;i<G->vertex_number;i++)
        scanf("%c",&G->vertex[i]);

    //�������Ķ���֮���Ȩֵ��Ϊinf��������������
    //��ʼ���ڽӾ���
    for(i=0;i<G->vertex_number;i++)
        for(j=0;j<G->vertex_number;j++)
            G->edge[i][j] = inf;

    //��������ͼ����Ϣ
    printf("����������ͼ�ڽӾ��������ı���Ϣ���������Ϊ1\n");
    for(k=0;k<G->edge_number;k++)
    {
        scanf("%d %d %d",&i,&j,&m);
        G->edge[i][j] = m;
        G->edge[j][i] = G->edge[i][j];//����ͼ�ǶԳ���
    }


    //��ӡ�ڽӾ���洢��Ϣ�������ȷ��
    printf("---------------------�������������ͼ�ڽӾ�������---------------------\n");
    for(i=0;i<G->vertex_number;i++)
    {
        for(j=0;j<G->vertex_number;j++)
            printf("%d\t",G->edge[i][j]);
        printf("\n");
    }
}
/**BFS���õ�����������ݽṹ**/
/**ѭ������**/
typedef struct
{
    char data[MAX_VERTEX];
    int front;  //ͷָ��
    int rear;   //βָ�룬���зǿ���ָ���β���һ��Ԫ�غ�һ��λ��
}SqQueue;

//���г�ʼ��
void InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}
//���
bool EnQueue(SqQueue *Q, char e)
{
    //�ж϶����Ƿ���
    if( ( Q->rear+1 ) % MAX_VERTEX == Q->front )
        return false;
    Q->data[Q->rear]=e;
    Q->rear = (Q->rear+1)%MAX_VERTEX;
    return true;
}
//����---ɾ������Ԫ�أ�������e
char* DeQueue(SqQueue *Q, char *e)
{
    //�ж϶����Ƿ�Ϊ��
    if( Q->front == Q->rear )
        return NULL;
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAX_VERTEX;
    return e;
}
//�����п�
bool isEmptyQueue(SqQueue *Q)
{
    return Q->front == Q->rear?true:false;
}

//����ͼ�ڽӾ���BFS
void BFS_Travel(Martrix_Graph G)
{
//    int layerNumer = 0;
    SqQueue Q;
    int i,j,mark;
    char data;
    //��ʼ��visit����
    for(i=0;i<G.vertex_number;i++)
        visit[i] = false;
    //��ʼ������
    InitQueue(&Q);

    //��ʼ��������ͼ�Ķ���--Ĭ�ϴӵ�һ�����㿪ʼ
    printf("���ڽӾ�������ͼBFS�Ľ��Ϊ��\n");
    for(i=0;i<G.vertex_number;i++)
    {
        //��δ���ʵĶ�����BFS
        if(!visit[i])
        {
            visit[i] = true;

            //���˶������
            EnQueue(&Q,G.vertex[i]);
//            layerNumer++;

            while(!isEmptyQueue(&Q))
            {
                DeQueue(&Q,&data);  //���׶�����ӣ�����ֵ��data
                printf("%c ",data);

                //����ɾ��������±꣬���¸��±�ֵ���Ա���ȷ�ҵ������Ԫ����������������
                for( j = 0;j<G.vertex_number;j++)
                    if(G.vertex[j] == data )
                        mark = j ;
                //��Ѱ��˶���������δ�����ʵĶ��㣬��α�ǡ���ӡ�������
                for(j=0;j<G.vertex_number;j++)
                {
                    if(G.edge[mark][j]==1 && !visit[j])
                    {

                        visit[j] = true;
//                        printf("%c ",G.vertex[j]);
                        EnQueue(&Q,G.vertex[j]);
                    }
                }
            }
        }

    }

}


int main()
{
    printf("���Դ���\n");
    Martrix_Graph G;
    Create_non_direction_martrix_Graph(&G);
    BFS_Travel(G);
    return 0;
}
