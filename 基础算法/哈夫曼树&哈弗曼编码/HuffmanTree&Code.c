/*************************************************************************
���㷨����������----���Ŷ�����
--����--
������һ����㵽��һ�����֮��ķ�֧���������ڵ�֮���·����·���Ϸ�֧��Ŀ����·������
����·�����Ⱦ��Ǵ�������ÿһ����·������֮��
���Ĵ�Ȩ·�������Ǵӽ�㵽����֮���·������������Ȩֵ�ĳ˻������Ĵ�Ȩ·����������������Ҷ�ӽ��Ĵ�Ȩ·������֮��
��Ȩ·������WPL��С�Ķ�������Ϊ��������

--���������Ĺ���--ͨ����˵
1��������n��Ȩֵ�ֱ�Ϊw1,w2,w3...wn�Ķ���������{T1��T2��T3...Tn}����ʱ��Щ������������������Ϊ��
2����n����Ȩ�������У�ѡȡȨֵ��С�����������������¶�����NT1���¶�������ȨֵΪ�����Ӷ�����Ȩֵ֮�͡�����������ΪȨֵ��С�Ķ�������
3�����¶�����NT1������������ϣ�ͬʱ�Ӽ�����ɾ��ѡȡ������������
4���ظ�����2���Ͳ���3����ֱ�������������н���һ��������Ϊֹ���������Ϊ��������

Author:tmw
date:2017-9-23

**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*************************
step1�����������Ĺ���
*************************/
//���������ڵ㹹��
typedef struct HuffmanNode
{
    char element;//���Ԫ��
    int weight;//Ȩֵ
    struct HuffmanNode* left;
    struct HuffmanNode* right;
}HuffmanNode,*PtrHuffman;

//�����������
PtrHuffman CreatHuffmanTree( char* elementArray , int* weightArray , int HuffmanSize )
{
    PtrHuffman ptr_tree = NULL;//����ΪHuffmanNode* ��Ϊ���ں���ļ����и�NULL
    PtrHuffman new_Huffnode = NULL;//!!!�ṹ��ָ���ʼֵΪNULL   �����������ɽṹ�壬�Ͳ��ܰ�����ʼ��Ϊ��
    PtrHuffman PTR_array[HuffmanSize];//PTR_array�����������Щ�������ļ���
    int i;
    int mixWeight,semixWeight; //mixWeight��Ȩֵ��С�������±ꣻsemixWeight��Ȩֵ�ڶ�С�������±�

    for( i = 0 ; i < HuffmanSize ; i++ )
    {
        ptr_tree = (PtrHuffman)malloc(sizeof(HuffmanNode));//ÿ��һ��������ݺͶ�ӦȨֵ������һ�οռ�
        ptr_tree->element = elementArray[i];
        ptr_tree->weight = weightArray[i];//!!!������ýṹ��Ԫ����.  ָ����ýṹ��Ԫ����->
        ptr_tree->left = NULL;
        ptr_tree->right = NULL;
        //printf("���Ϊ %c ��ȨֵΪ %d \n",ptr_tree->element,ptr_tree->weight);
        PTR_array[i] = ptr_tree;
    }//�γ�n��Ȩֵ�ֱ�Ϊw1,w2,w3...wn�Ķ���������{T1��T2��T3...Tn}����ʱ��Щ������������������Ϊ��

    for( i = 1 ; i < HuffmanSize ; i++ ) //���У�HuffmanSize-1����ѭ����������������
    {
        int j = 0;
        while( PTR_array[j] == NULL )//�����б�������¶������Ķ�������λ�û���NULL
            j++;
        mixWeight = j;
        j++;
        while( PTR_array[j] == NULL )
            j++;
        semixWeight = j;

        for( j = semixWeight ; j < HuffmanSize ; j++ )
        {
            if( PTR_array[j] != NULL )
            {
                if( PTR_array[j]->weight < PTR_array[mixWeight]->weight )
                {
                    semixWeight = mixWeight;
                    mixWeight = j;
                }//�ҵ���СȨֵ�󣬽���СȨֵ���±�ֵ����mixWeight��ͬʱ����СȨֵ�±��ֵ����semixWeight
                else if( PTR_array[j]->weight < PTR_array[semixWeight]->weight )
                    semixWeight = j;
            }
        }//��ʱ��mixWeightΪ������������Ȩֵ��С���������±꣬semixWeightΪ������������Ȩֵ�ڶ�С���������±�

        //�����¶�����������Ȩֵ������������Ȩֵ��С�������Ͷ�����������Ȩֵ�ڶ�С������Ȩֵ֮�͡�����������ΪȨֵ��С�Ķ�����

        new_Huffnode = (PtrHuffman)malloc(sizeof(HuffmanNode));

        new_Huffnode->element = '#';
        new_Huffnode->left = PTR_array[mixWeight];
        new_Huffnode->right = PTR_array[semixWeight];
        new_Huffnode->weight = PTR_array[mixWeight]->weight + PTR_array[semixWeight]->weight;

        //��������PTR_array�����У��ѹ���new_Huffnode���������ڴ˼����е�λ����NULL��ͬʱ�������õ������ŵ�������֮ǰ�ڼ����е�λ����
        PTR_array[mixWeight] = new_Huffnode;
        PTR_array[semixWeight] = NULL;
    }
    //�����PTR_array��ʣ��һ�ö����������ĵ�ַ���������new_Huffnode���˺�������new_Huffnode
    return new_Huffnode;
}

/*****************************************************
step0�����������������Ƿ���ȷ---�����������ӡ����
*****************************************************/
void Print_HuffmanTree( PtrHuffman T )
{
    if( T )
    {
        if( T->left == NULL && T->right == NULL )
            printf("���Ϊ %c ��ȨֵΪ %d \n",T->element,T->weight);
        else
        {
            Print_HuffmanTree(T->left);
            Print_HuffmanTree(T->right);
        }
    }
}
/*****************************************************
step2������������WPL��⣨���������������⣩
*****************************************************/
int wpl = 0;//���������ǲ���Ҫÿ�μӶ�����spl
int Huffman_WPL( PtrHuffman T , int len )
{
    if( T )
    {
        if( T->left == NULL && T->right == NULL )
            return len * ( T->weight );
        else
            return Huffman_WPL( T->left , len+1 ) + Huffman_WPL( T->right , len+1 );
    }
    else
        return 0;//��������0
}

/*****************************************************
step3������������-----��֧Ϊ0����֧Ϊ1
*****************************************************/
int codeArray[100] = {0};
void HuffmanCode( PtrHuffman T , int len )//len��ʼֵΪ0
{
    int i;

    if( T != NULL )
    {
        if( T->left == NULL && T->right == NULL )
        {
            printf( "�����Ϊ %c �Ĺ���������Ϊ��",T->element);
            for( i = 0 ; i < len ; i++ )
                printf("%d ",codeArray[i]);
            printf("\n");
        }
        else
        {
            codeArray[len] = 0;
            HuffmanCode( T->left , len+1 );
            codeArray[len] = 1;
            HuffmanCode( T->right , len+1 );
        }
    }
}

int main()
{
    int HuffmanSize;
    char* elementArray;
    int* weightArray;
    PtrHuffman new_Huffnode = NULL;
    int i,j;
    printf("�������������Ĵ�С!\n");
    scanf("%d",&HuffmanSize);

    elementArray = (char*)malloc(HuffmanSize*sizeof(char));
    memset(elementArray,0,HuffmanSize);
    printf("������������ֵ(�ַ���)!\n");

    char ch;
    while( ( ch = getchar() ) != '\n' );//������뻺���������в�����ֱ���س�)
    for( i = 0 ; i < HuffmanSize ; i++ )
        scanf("%c",&elementArray[i]);

    while( ( ch = getchar() ) != '\n' );//������뻺���������в�����ֱ���س�)
    weightArray = (int*)malloc(HuffmanSize*sizeof(int));
    printf("�����Ӧ����Ȩֵ(����)!\n");
    for( j = 0 ; j < HuffmanSize ; j++ )
        scanf("%d",&weightArray[j]);

    new_Huffnode = CreatHuffmanTree( elementArray , weightArray , HuffmanSize );
    Print_HuffmanTree( new_Huffnode );

    int wpl_m = 0;
    wpl_m = Huffman_WPL( new_Huffnode , 0 );
    printf("���������Ĵ�Ȩ·������WPLΪ��%d \n",wpl_m);
    HuffmanCode( new_Huffnode , 0 );
    return 0;
}
