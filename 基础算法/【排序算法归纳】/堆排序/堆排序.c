/*******************************************************************************************
【堆排序】
堆的性质：
堆是一个完全二叉树，
1）若它的每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆
2）若它的每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆
因此，在堆的定义中可以发现：根结点的值一定是堆中所有结点的最大（最小）值

堆排序算法（以大顶堆为例）
基本思想：
1）将待排序的n个元素的序列构造成一个大顶堆。此时序列的最大值就是根结点的值；
2）将根结点移走（即将根结点与序列中的最后一个元素交换，在序列中就体现为最末尾元素就是最大值），
3）将剩余的(n-1)个元素的序列重新构造成一个大顶堆，重新按照2）的步骤执行

如此重复以上操作，一个随机的序列经堆排序就变成了递增的有序序列

【复杂度分析】
在构建堆的过程中，对于每一个有叶子结点的结点(n/2)来说，最多两次比较和一次互换操作，因此整个构建
堆的复杂度为O(n);
在排序时，第i次取堆顶记录重建堆需要用O(logi)的时间（完全二叉树某个结点到根结点的高度为log(i)+1），
并且需要取n-1次堆顶记录，因此，重建的复杂度为O(nlogn)

Author:tmw
date:2017-11-4
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//将无序序列转变成大顶堆序列
void heap_sort( int array[] , int node_have_child_index , int array_len )
{
    array[0] = 0;//规定无序元素从数组的1号地址开始填
    int child_index;
    int temp = array[node_have_child_index];//temp值为当前根结点的值，此时它不一定大于其孩子结点，需要待交换

    for( child_index = 2*node_have_child_index ; child_index <= array_len ; child_index = child_index*2 )//child_index始终为孩子结点中较大值的下标
    {
        if( child_index < array_len && ( array[child_index] < array[child_index+1] ) )//如果右孩子的值大于左孩子，则child_index为右孩子下标
            child_index++;
        if( array[child_index] <= temp )
            break;
        //孩子结点的值大于根结点的值---交换
        array[node_have_child_index] = array[child_index];
        node_have_child_index = child_index;
    }
    array[node_have_child_index] = temp;
}

int* heap_sort_all( int array[] , int array_len )
{
    int i;
    //先将所有无序结点进行堆排序
    for( i = array_len/2 ; i > 0 ; i-- )
        heap_sort(array,i,array_len);

    //将根结点取出（与序列最后一个元素换位置），重新对剩余元素再堆排序，如此重复
    for( i = array_len ; i > 0 ; i-- )
    {
        int temp;
        temp = array[i];
        array[i] = array[1];
        array[1] = temp;
        heap_sort(array,1,i-1);
    }
    return array;
}

int main()
{
    int *array;
    int i,array_size;
    printf("请输入数组元素的个数:\n");
    scanf("%d",&array_size);

    array = (int*)malloc(sizeof(int));
    printf("请输入 %d 个元素\n",array_size);
    for( i = 1 ; i <= array_size ; i++ )
        scanf("%d",&array[i]);

    array = heap_sort_all( array , array_size );
    printf("经堆排序后，数组元素顺序输出为：\n");
    for( i = 1 ; i <= array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
