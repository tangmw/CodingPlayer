/**************************************************************************
【问题描述】
有n个整数，找出其中最小的k个数，时间复杂度尽可能低

方法一：全排序--快排
算法复杂度O(nlogn)

方法二：部分排序，维护一个容量为k的最大堆
算法描述：
1）遍历给定整数的前k个数，建立一个容量为k的最大堆（根结点数值大于子结点），
假设这k个数即为给定n个数里最小的k个数，遍历和建堆耗时O(k)，此时k个数里最大
的数在根结点。
2）遍历剩余的(n-k)个数，将遍历到的数xi与堆顶元素比较，如果小于堆顶元素，则
用xi替换堆顶元素，更新堆，这里的时间复杂度为O(logk)；如果大于或等于堆顶元素，
则继续往下遍历。

时间复杂度分析
最坏的情况，如果每次遍历剩余的(n-k)个数时，都需要更新堆，则时间复杂度为
O((n-k)logk)+nk)=O(nlogk)

当然，部分排序也可以采用其他的排序方案，但通过改变数据的存储结构，利用堆的特点，
用堆代替数组，在相同的部分排序思想下，采用堆排序的时间复杂度由于其他排序，因此
笔者重点介绍这个方法。

方法三：线性选择算法

Author:tmw
date:2017-11-16
************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t) //交换功能

/**将无序序列变成最大堆**/
void heap_create(int* array , int father_index , int array_len)
{
    array[0] = 0;//规定无序元素从数组的1号地址开始填
    int child_index;
    int temp = array[father_index];//父结点不一定大于孩子结点，待交换
    for( child_index = 2*father_index ; child_index <= array_len ; child_index=child_index*2 )
    {
        if( child_index < array_len && ( array[child_index] < array[child_index+1] ) )//找出左右孩子结点的较大值，方便下面与父结点比较
            child_index++;//以上：array[child_index]的值就是最大孩子结点，接下来用这个值与根结点比较
        if( array[child_index] <= temp )//与根结点的值比较
            break;
        //大于根结点的值则交换
        array[father_index] = array[child_index];
        father_index = child_index;
    }
    array[father_index] = temp;//完成交换
}

/**将k个无序序列变成最大堆**/
void find_min_k_numbers_using_max_heapSort(int* array , int k , int array_len)
{
    //参数合法性检查
    if(k==0||array==NULL||array_len==0||k>array_len)
        return;

    int father_node;
    //将k个结点进行堆排序
    for( father_node = k/2 ; father_node > 0 ; father_node-- )//因为数组从1号位算起，因此k实际应该从k+1算起
        heap_create(array,father_node,k);

    //遍历剩余的(n-k)个元素，与堆顶元素比较，小则与堆顶元素交换，同时对新堆进行重排
    int i;
    for( i = k+1 ; i <= array_len ; i++ )
    {
        //int x = array[i];
        int temp11;
        if( array[i] < array[1] )//小于堆顶元素，则交换，重排k个元素的堆
        {
            swap(array[i],array[1],temp11);//交换
            heap_create(array,1,k);
        }
    }//以上，array数组前k个数就是n个数里面最小的k个数
    for( i = 1 ; i <= k ; i++ )//数组下标从1开始
        printf("%d ",array[i]);
    printf("\n\n");
}

int main()
{
    printf("测试代码\n");
    int k = 4;
    int i;

    int a2[9] = {0,1,8,23,6,90,5,8};//数组有效元素从位置1开始
    printf("原串：");
    for(i=1;i<8;i++)
        printf("%d ",a2[i]);
    printf("\n最小的%d个数：\n",k);
    find_min_k_numbers_using_max_heapSort(a2,k,7);

    int a4[11] = {0,100,56,23,7,17,0,23,65,2};
    printf("原串：");
    for(i=1;i<10;i++)
        printf("%d ",a4[i]);
    printf("\n最小的%d个数：\n",k);
    find_min_k_numbers_using_max_heapSort(a4,k,9);
    return 0;
}
