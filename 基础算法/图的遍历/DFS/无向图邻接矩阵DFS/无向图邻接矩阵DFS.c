/*******************************************************************************************
��DFS��
���㷨�Ĳ�������Ϊ�������ݽṹ��p239�е�ͼ7-5-2
���㷨��������Ϊ�����洢��ʽ�����ڽӾ���
1�����������ڽӾ���ķ�ʽ�洢�����������ʾ����������ͼ���������һ���Գ���
2��ѡȡA��Ϊ��ʼ�㣬���ʴ˶��㣬��һ��visit��bool�������¼����״̬��false��ʾδ�����ʣ�true��ʾ�ѷ��ʣ�
3����A��δ�����ʵ��ڽӵ������������ȱ���ͼ��ֱ��ͼ�����к�v��·����ͨ�Ķ��㶼�����ʵ�

�㷨���Ӷȣ�O(n^2)
�洢��ʽ�����ڽӾ��󣬱�����һ����ά���飬Ҫ����ÿ��������ڽӵ㶼��Ҫ���ʾ����е�����Ԫ�أ����
��ҪO(n^2)��ʱ��
Author:tmw
date:2018-2-19
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

//�ӵ�ǰ��i�����������DFS����
void DFS(Martrix_Graph G, int i)
{
    int j;
    //��ǵ�ǰ����Ϊ�ѷ���״̬
    visit[i] = true;
    printf("%c ",G.vertex[i]);

    //����ö�������������δ���ʶ������DFS
    for(j=0;j<G.vertex_number;j++)
    {
        if( G.edge[i][j]==1 && !visit[j] )
            DFS(G,j);
    }
}
//������ͼ����DFS
void DFS_Travel(Martrix_Graph G)
{
    //��ʼ��visit����
    int i;
    for(i=0;i<G.vertex_number;i++)
        visit[i] = false;

    //����ͼ��DFS
    printf("�Ը�����ͼ����DFS�Ľ�����£�\n");
    for(i=0;i<G.vertex_number;i++)
    {
        if( !visit[i] )
            DFS(G,i);
    }
}

int main()
{
    printf("���Դ���\n");
    Martrix_Graph G;
    Create_non_direction_martrix_Graph(&G);
    DFS_Travel(G);
    return 0;
}
