/*******************************************************************************************
����С������-��³˹�����㷨��
���㷨�Ĳ�������Ϊ�������ݽṹ��p252�е�ͼ7-6-7
���㷨������ͼΪ����ͼ�Ĵ洢��ʽ�����ڽӾ���
������ķ�㷨����������ǣ���³˹�����㷨��ͼ�ı�Ϊ�о���
1����ͼ���ڽӾ���ķ�ʽ�洢�����������ʾ����������ͼ���������һ���Գ���
2�������ڽӾ���ת��Ϊ��Ȩֵ�ɵ͵������򡢲�ͬʱ��¼�˱ߵ������յ�ġ��¾���
3�������ˡ��¾��󡱣����ڱ���ǰ�����Ѱ�Ȩֵ�ӵ͵������������С������һ�����зֲ����¾����ǰ��
4�����ǵ�����Ȩֵ��С��һ��ָ����������С����������ɡ���·���������Ҫ�����趨һ��find������׷��ÿһ���������ڶ���ġ�Դͷ��
5�������find�����У�����ֵ�����붥��ġ�Դͷ���㡱������ǰȨֵ��С�ıߣ�������ʼ��ġ�Դͷ���㡱��ͬ��˵������˱ߺ���С���������γɡ���·��
�����Ҫ���������������ǰȨֵ��С�ıߣ�ת���ӡ��¾�����Ѱ����һ��Ԫ��---����ǰȨֵ�ν�С�ߡ��㷨���ѭ����ֱ�����¾��󡱵ı�����Ϊֹ��ÿ��
�������������ıߵ������յ��ڳ����ж����д�ӡ�����

�㷨���Ӷȣ�O(elog(e))  ����e�ɱ�������
log(e)������find������e�����ڶԱߵĴ�ѭ��
Author:tmw
date:2017-10-19
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

/*************************��³˹�����㷨**************************/
//�����¼Ȩֵ���ߵ���㡢�ߵ��յ�ı߼�������
typedef struct Edge_Node
{
    int begin;
    int end;
    int weight;
}Edge_Node;
/***find����***/
//���ܣ���Ѱÿһ�����붥��ġ�Դ���㡱�������ش�Դ����
int find( int *parent , int f )//parent[i]�����¼����i��fatherΪparent[i],���׷Ѱfather���Ϳ����ҵ�����i�ġ�Դ���㡱
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
//��³˹���������ܴ���
void Kruscal( Matrix_Graph *G )
{
    int i,j,k,m,n,path;
    Edge_Node Edge[G->edge_number+2];
    int parent[G->vertex_number+2];

    //���ڽӾ���ת���ɼ�¼Ȩֵ���ߵ���㡢�ߵ��յ�ı߼�����----���¾���
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
    //�Ա߼������������---���ÿ������򷽷�
    fastSort(Edge,0,G->edge_number);
    //��ӡ���¾���
    printf("***************����ı߼���������****************\n");
    printf("Edge[ ] \tbegin\tend\tweight\n");
    for( i = 0 ; i < G->edge_number ; i++ )
        printf("Edge[%d]:\t %d \t %d \t %d \t\n",i,Edge[i].begin,Edge[i].end,Edge[i].weight);

    //parent[]�����ʼ���������ж���ĸ��׶�����0
    for( i = 0 ; i < G->vertex_number ; i++ )
        parent[i] = 0;
    for( i = 0 ; i < G->edge_number ; i++ )
    {
        n = find( parent , Edge[i].begin );
        m = find( parent , Edge[i].end );//ͨ��find��Ѱ����ѡ������������ġ�Դ���㡱
        if( n != m )
        {
            parent[m] = n;//����m����ġ�Դ���㡱��n
            printf("·�� %d : [%d %d] , ȨֵΪ %d\n",path,Edge[i].begin,Edge[i].end,Edge[i].weight);
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
