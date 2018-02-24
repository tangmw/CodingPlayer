/***********************************************
【问题描述】
在一个m行n列的二维数组中，每一行都按照从左到右递增的顺序排列，
每一列都按照从上到下递增的顺序排列。现输入这样的一个二维数组和
一个整数，请完成一个函数，判断数组中是否含有该整数key。例如给定如
下所示二维数组，它的每一行每一列都递增排序。如果在这个数组中查
找数6，则返回true，如果查找数5，则返回false


1   2   8   9
2   4   9   12
4   7   10  13
6   8   11  15


【解法】定位法
题中所述行和列都递增的二维数组叫杨氏矩阵，根据矩阵特点，可按如下方法求解：
1）首先将起点定位到二维数组第一行最后一列的元素，从该元素开始出发
2）如果这个元素比key大，则往下走（列是递增的）
3）如果这个元素比key小，则往左走（行是递增的）

该方法的时间复杂度为O(m+n)，其中m和n分别为二维数组的行和列

Author:tmw
date:2018-2-23
************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 4
#define COL 4

bool PositionMethod_of_YangMartrix(int array[][COL],int key)
{
    //初始化行列参数
    int i = 0;
    int j = COL-1;
    int val = array[i][j];  //val值为起点位置，指向第一行最后一列的元素

    while(1)
    {
        if( val < key && i < ROW - 1) //key值更大，说明应往列上找----i增--注意i别越界
            val = array[++i][j]; //更新val值

        else if( val > key && j > 0)//key值更小，说明应往行上找----j值减--注意j别越界
            val = array[i][--j];

        else if( val == key )
            return true;

        else
            return false;
    }
}





int main()
{
    printf("测试代码\n");

    int array[][4] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};

    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",array[i][j]);
        printf("\n");
    }

    int res1 = PositionMethod_of_YangMartrix(array,6);
    int res2 = PositionMethod_of_YangMartrix(array,5);

    printf("\n");

    printf("%d \n",res1);
    printf("%d \n",res2);


    return 0;
}
