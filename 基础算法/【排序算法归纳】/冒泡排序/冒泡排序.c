/*******************************************************************************************
【冒泡排序】
基本思想：两两比较相邻记录的关键字，如果反序即交换，直到没有反序的记录为止；

复杂度分析：
1）当最好的情况：即要排序的表本身就是有序的，根据以下冒泡排序代码，会进行（n-1）次比较，没
有数据交换，时间复杂度为O(n)；
2）当最坏的情况，即要排序的表是逆序的，会进行(n-1)+(n-2)+...+3+2+1 = n*(n-1)/2次比较和n*(n-1)/2
次的数据交换，时间复杂度为O(n^2)；
所以，冒泡排序的总的时间复杂度为O(n^2)
Author:tmw
date:2017-10-31
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**冒泡排序**/
int* Bubble_Sort( int array[] , int array_size )
{
    int i,j,temp;
    int flag = 1;//flag初始化为真，用来标记已经有序无需进行数据交换的情况---减少本身有序度就较高的序列的比较次数

    for( i = 0 ; i < array_size && flag ; i++ )
    {
        flag = 0;//经过一轮i，当flag还是为0，说明i以下已经有序了，无需再挪动i再对i以下进行有序检查，就可以直接跳出for循环
        for( j = array_size - 2 ; j >= i ; j-- )
        {
            if( array[j] > array[j+1] )//进行数据交换
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 1;
            }
        }
    }
    return array;
}

int main()
{
    int *array;
    int array_size,i;

    printf("请输入数组长度\n");
    scanf("%d",&array_size);
    array = (int*)malloc(array_size*sizeof(int));

    printf("请输入%d个乱序元素\n",array_size);
    for( i = 0 ; i < array_size ; i++ )
        scanf("%d",&array[i]);

    array = Bubble_Sort(array,array_size);
    printf("经冒泡排序后，顺序输出为：\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);

    return 0;
}
