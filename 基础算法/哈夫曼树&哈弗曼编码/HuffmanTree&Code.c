/*************************************************************************
【算法】哈夫曼树----最优二叉树
--概念--
从树中一个结点到另一个结点之间的分支构成两个节点之间的路径，路径上分支数目称作路径长度
树的路径长度就是从树根到每一结点的路径长度之和
结点的带权路径长度是从结点到树根之间的路径长度与结点上权值的乘积，树的带权路径长度是树中所有叶子结点的带权路径长度之和
带权路径长度WPL最小的二叉树称为哈夫曼树

--哈夫曼树的构造--通俗来说
1）给定了n个权值分别为w1,w2,w3...wn的二叉树集合{T1，T2，T3...Tn}，此时这些二叉树的左右子树均为空
2）从n个带权二叉树中，选取权值最小的两个二叉树构成新二叉树NT1，新二叉树的权值为两个子二叉树权值之和。它的左子树为权值更小的二叉树。
3）将新二叉树NT1加入二叉树集合，同时从集合中删除选取的两个二叉树
4）重复步骤2）和步骤3），直到二叉树集合中仅有一个二叉树为止，这课树即为哈夫曼树

Author:tmw
date:2017-9-23

**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*************************
step1：哈夫曼树的构造
*************************/
//哈弗曼树节点构造
typedef struct HuffmanNode
{
    char element;//结点元素
    int weight;//权值
    struct HuffmanNode* left;
    struct HuffmanNode* right;
}HuffmanNode,*PtrHuffman;

//构造哈夫曼树
PtrHuffman CreatHuffmanTree( char* elementArray , int* weightArray , int HuffmanSize )
{
    PtrHuffman ptr_tree = NULL;//申明为HuffmanNode* 是为了在后面的集合中赋NULL
    PtrHuffman new_Huffnode = NULL;//!!!结构体指针初始值为NULL   但是如果定义成结构体，就不能把它初始化为空
    PtrHuffman PTR_array[HuffmanSize];//PTR_array是用来存放这些二叉树的集合
    int i;
    int mixWeight,semixWeight; //mixWeight是权值最小二叉树下标；semixWeight是权值第二小二叉树下标

    for( i = 0 ; i < HuffmanSize ; i++ )
    {
        ptr_tree = (PtrHuffman)malloc(sizeof(HuffmanNode));//每来一个结点数据和对应权值，申请一次空间
        ptr_tree->element = elementArray[i];
        ptr_tree->weight = weightArray[i];//!!!数组调用结构体元素用.  指针调用结构体元素用->
        ptr_tree->left = NULL;
        ptr_tree->right = NULL;
        //printf("结点为 %c 的权值为 %d \n",ptr_tree->element,ptr_tree->weight);
        PTR_array[i] = ptr_tree;
    }//形成n个权值分别为w1,w2,w3...wn的二叉树集合{T1，T2，T3...Tn}，此时这些二叉树的左右子树均为空

    for( i = 1 ; i < HuffmanSize ; i++ ) //进行（HuffmanSize-1）次循环，建立哈夫曼树
    {
        int j = 0;
        while( PTR_array[j] == NULL )//集合中被添加入新二叉树的二叉树的位置会清NULL
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
                }//找到最小权值后，将最小权值的下标值赋给mixWeight，同时将次小权值下标的值赋给semixWeight
                else if( PTR_array[j]->weight < PTR_array[semixWeight]->weight )
                    semixWeight = j;
            }
        }//此时，mixWeight为二叉树集合中权值最小二叉树的下标，semixWeight为二叉树集合中权值第二小二叉树的下标

        //构造新二叉树，它的权值二叉树集合中权值最小二叉树和二叉树集合中权值第二小二叉树权值之和。它的左子树为权值更小的二叉树

        new_Huffnode = (PtrHuffman)malloc(sizeof(HuffmanNode));

        new_Huffnode->element = '#';
        new_Huffnode->left = PTR_array[mixWeight];
        new_Huffnode->right = PTR_array[semixWeight];
        new_Huffnode->weight = PTR_array[mixWeight]->weight + PTR_array[semixWeight]->weight;

        //将二叉树PTR_array集合中，已构建new_Huffnode左右子树在此集合中的位置置NULL，同时将构建好的新树放到左子树之前在集合中的位置上
        PTR_array[mixWeight] = new_Huffnode;
        PTR_array[semixWeight] = NULL;
    }
    //到最后，PTR_array就剩下一棵二叉树，它的地址被存放在了new_Huffnode里，因此函数返回new_Huffnode
    return new_Huffnode;
}

/*****************************************************
step0：检查哈夫曼树构造是否正确---二叉树中序打印函数
*****************************************************/
void Print_HuffmanTree( PtrHuffman T )
{
    if( T )
    {
        if( T->left == NULL && T->right == NULL )
            printf("结点为 %c 的权值为 %d \n",T->element,T->weight);
        else
        {
            Print_HuffmanTree(T->left);
            Print_HuffmanTree(T->right);
        }
    }
}
/*****************************************************
step2：哈夫曼树的WPL求解（二叉树中序遍历求解）
*****************************************************/
int wpl = 0;//放在外面是不需要每次加都更新spl
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
        return 0;//空树返回0
}

/*****************************************************
step3：哈夫曼编码-----左支为0，右支为1
*****************************************************/
int codeArray[100] = {0};
void HuffmanCode( PtrHuffman T , int len )//len初始值为0
{
    int i;

    if( T != NULL )
    {
        if( T->left == NULL && T->right == NULL )
        {
            printf( "结点编号为 %c 的哈夫曼编码为：",T->element);
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
    printf("输入哈夫曼数组的大小!\n");
    scanf("%d",&HuffmanSize);

    elementArray = (char*)malloc(HuffmanSize*sizeof(char));
    memset(elementArray,0,HuffmanSize);
    printf("输入哈夫曼结点值(字符型)!\n");

    char ch;
    while( ( ch = getchar() ) != '\n' );//清空输入缓冲区中所有残留（直到回车)
    for( i = 0 ; i < HuffmanSize ; i++ )
        scanf("%c",&elementArray[i]);

    while( ( ch = getchar() ) != '\n' );//清空输入缓冲区中所有残留（直到回车)
    weightArray = (int*)malloc(HuffmanSize*sizeof(int));
    printf("输入对应结点的权值(整型)!\n");
    for( j = 0 ; j < HuffmanSize ; j++ )
        scanf("%d",&weightArray[j]);

    new_Huffnode = CreatHuffmanTree( elementArray , weightArray , HuffmanSize );
    Print_HuffmanTree( new_Huffnode );

    int wpl_m = 0;
    wpl_m = Huffman_WPL( new_Huffnode , 0 );
    printf("哈夫曼树的带权路径长度WPL为：%d \n",wpl_m);
    HuffmanCode( new_Huffnode , 0 );
    return 0;
}
