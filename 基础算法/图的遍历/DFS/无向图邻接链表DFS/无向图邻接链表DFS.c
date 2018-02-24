/*******************************************************************************************
��DFS��
���㷨�Ĳ�������Ϊ�������ݽṹ��p239�е�ͼ7-5-2
���㷨��������Ϊ�����洢��ʽ�����ڽӾ���
1�����������ڽӾ���ķ�ʽ�洢�����������ʾ����������ͼ���������һ���Գ���
2��ѡȡA��Ϊ��ʼ�㣬���ʴ˶��㣬��һ��visit��bool�������¼����״̬��false��ʾδ�����ʣ�true��ʾ�ѷ��ʣ�
3����A��δ�����ʵ��ڽӵ������������ȱ���ͼ��ֱ��ͼ�����к�v��·����ͨ�Ķ��㶼�����ʵ�

�㷨���Ӷȣ�O(n+e)
�ڽӾ�����ڽӱ���ʵ��BFS��DFS�ķ������ڽӾ���ʱ�临�Ӷ�ΪO(n^2)���ڽӱ��ʱ�临�Ӷ�ΪO(n+e);
����ڽӾ��������ڳ���ͼ���ڽӱ�������ϡ��ͼ��


��ʵ�ʱ�д����ʱ�����߷��֣�
1���Բ����ڽ�������Ϊ�洢��ʽ��ͼ��DFSʱ�����ڽ����ڽ�����ʱ�ɲ��ò�ͬ�Ĳ��뷽��������ͷ�巨��β�巨����
ʹ����DFSʱ��ͬ��ͼ�ṹ���в�һ���Ľ����
2����ʹ��ͬ��ͼ�ṹ�����ò�ͬ�Ĵ洢��ʽ���ڽӾ�����ڽ�������DFSʱ�����ǵĽ����ʱҲ�᲻һ����

������Ϊ�ⶼ����������DFS��˼�뻹��û�䡣

Author:tmw
date:2018-2-20
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_VERTEX 100
#define inf 65535  //��ʾ����֮��û�б�����

int visit[MAX_VERTEX];   //��Ƕ����Ƿ񱻷���

/**����ͼ���ڽ�����Ľ���**/
//�߱������ݽṹ
typedef struct EdgeNode
{
    int adjvex;  //�洢�ö����Ӧ���±�
    int weight;
    struct EdgeNode *next; //ָ����һ���ڽӵ�
}EdgeNode;

//����������ݽṹ
typedef struct VertexNode
{
    char Vertex;  //�洢������Ϣ
    EdgeNode *FistEdge; //�߱�ͷָ��
}VertexNode,AdjList[MAX_VERTEX];

//�ڽ�����ͼ�����ݽṹ
typedef struct
{
    AdjList adjList;
    int VertexNumber,EdgeNumber; //�������ͱ���
}GraphAdjList;


/**����ͼ�ڽ�����Ľ���**/
void Create_no_direction_LinkList_Graph(GraphAdjList *G)
{
    int i,j,w,k;
    printf("����������ͼ�ڽ�����Ķ������ͱ�����\n");
    scanf("%d %d",&G->VertexNumber,&G->EdgeNumber);

    //���붥����Ϣ�����������
    printf("�����Ľ��������붥����Ϣ����ABCDEF.....\n");
    char ch;
    while( ( ch = getchar()  != '\n' ) );
    for(i=0;i<G->VertexNumber;i++)
    {
        scanf("%c",&G->adjList[i].Vertex);
        G->adjList[i].FistEdge = NULL;
    }
    printf("�߱�Ľ���������ߣ�vi,vj���Ķ����±꣬ȨֵͳһΪ1���磺0 1 1(Ȩֵ)\n");

    for(k=0;k<G->EdgeNumber;k++)
    {
        scanf("%d %d %d",&i,&j,&w);

        EdgeNode *e;
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->weight = w;
        e->adjvex = j;
        e->next = G->adjList[i].FistEdge;   //ͷ�巨���±�Ϊj�Ķ��������֮�������±�Ϊi�Ľ��������
        G->adjList[i].FistEdge = e;

        //����ͼ������ǶԳƵģ�ͬ���Ĳ������±�Ϊi�Ķ��������֮�������±�Ϊj�Ľ���������
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->weight = w;
        e->adjvex = i;
        e->next = G->adjList[j].FistEdge;
        G->adjList[j].FistEdge = e;
    }


//    ��ӡ���
    printf("---------------------�������������ͼ�ڽ�����ı���Ϣ����---------------------\n");
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

//����ͼ���ڽ�����ĵ�i�������DFS
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

//����������ͼ����DFS
void DFS_Travel(GraphAdjList G)
{
    int i;

    //�ȳ�ʼ��visit����
    for(i=0;i<G.VertexNumber;i++)
        visit[i] = false;

    printf("����ͼ���ڽ�����DFS���Ϊ��\n");
    for(i=0;i<G.VertexNumber;i++)
        if(!visit[i])
            DFS(G,i);
}


int main()
{
    printf("���Դ���\n");
    GraphAdjList G;
    Create_no_direction_LinkList_Graph(&G);
    DFS_Travel(G);
    return 0;
}
