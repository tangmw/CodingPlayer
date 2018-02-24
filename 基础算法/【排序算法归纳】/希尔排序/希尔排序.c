/*******************************************************************************************
【希尔排序】
基本思想：设置单位间隔：d = n/3 + 1  n为数组长度
从数组后位往前推：
刚开始，若后者behind的值小于前者forward的值，则将后者behind的值放到“哨兵”处作为标称，此后，从
前者forward开始，往前以间隔d为单位进行前溯：
若前者behind的值存在且前者的值大于“哨兵”，则将前者的值以d为单位往后挪；
若前者behind的值不存在或者小于“哨兵”，则将哨兵直接放置在behind值的下一个单位间隔处

总结：
希尔排序的关键是将间隔某个“增量”的记录组成一个子序列，让这个子序列在该“增量”间隔下是递增的，
然后逐步缩小增量，直到最后增量变为1---即前后元素两两比较。实现了跳跃式移动，使得排序效率提高

需注意的是：希尔排序的最后一个“增量”必须是1

【复杂度分析】
希尔排序的“增量”选取十分关键，可如何选取合适的增量目前还是个数学难题，迄今为止还没有人找
到一种合适的增量。不过大量研究表明，当增量序列为dita[k] = 2^(t-k+1)-1 ( 0=<k=<t=<log2(n+1))时，
可以获得不错的效果，其时间复杂度为O(n^(3/2))，优于直接插入排序

由于希尔排序是跳跃式的，它并不是一种稳定的算法

Author:tmw
date:2017-11-2
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int* Xier_Sort( int array[] , int array_len )
{
    array[0] = 0;//将array[0]的位置初始化为哨兵
    int i,j;
    int interval = array_len;

    while( interval > 1 )
    {
        interval = interval/3 + 1;//这里设定数组长度为9，选取此间隔比较合适
        for( i = interval + 1 ; i <= array_len ; i++ )//从“增量间隔”的behind值位置下标为1开始找
        {
            if( array[i] < array[i-interval] )//当forward的值小于behind的值，则需要将forward的值作为“哨兵”
            {
                array[0] = array[i];//将forward的值作为哨兵
                //若前者behind的值存在(j>0)且前者的值大于“哨兵”(array[0] < array[j])，则将前者的值以d为单位往后挪
                for( j = i - interval ; j>0 && array[0] < array[j]; j = j - interval )//J指向前者的前者
                    array[j+interval] = array[j];
                //若前者behind的值不存在或者小于“哨兵”，则将哨兵直接放置在behind值的下一个单位间隔处
                array[j+interval] = array[0];
            }
        }
    }
    return array;
}
int main()
{
    int *array;
    int i,array_size;
    printf("请输入数组元素的个数(考虑到希尔排序的“增量”，这里请输入9):\n");
    scanf("%d",&array_size);

    array = (int*)malloc(sizeof(int));
    printf("请输入 %d 个元素\n",array_size);
    for( i = 1 ; i <= array_size ; i++ )
        scanf("%d",&array[i]);

    array = Xier_Sort( array , array_size );
    printf("经希尔排序后，数组元素顺序输出为：\n");
    for( i = 1 ; i <= array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}
