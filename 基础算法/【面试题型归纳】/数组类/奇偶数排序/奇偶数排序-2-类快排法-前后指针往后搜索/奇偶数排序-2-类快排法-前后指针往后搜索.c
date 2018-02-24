/***********************************************
【问题描述】
给定一个整数数组，请调整数组中数的顺序，使得所有奇数位于
数组的前半部分，所有的偶数位于数组的后半部分，要求时间复杂度
为O(n)

前后指针往后搜索
算法准备：
定义两个游标--front和back，一前一后，front指向数组的第一个元素，
back指向第一个元素的前一个元素
定义一个游标--rear 指向数组的最后一个元素

算法基本思想：
rear作为中枢元素，若front指向的元素为奇数，则游标前移，back游标不动；
若front指向的元素为偶数，则back游标前移，back指向的元素与front指向的
元素交换。直到front游标挪动到rear的前一位判定完是偶数（或者交换完是偶数）
之后，back游标前移一位，back指向的元素与rear的中枢元素交换


下面的代码用的方法是一次快排中的“前后指针往后搜索”的方法

关于第2种快排实现--前后指针往后快排的方法，见july《编程之法》P46-47

Author:tmw
date:2017-11-24
************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,z) (z=x,x=y,y=z)
int* odd_even_sort_like_qsort_2(int *array , int array_len)
{
    int front,back,rear,temp;
    front = 0;
    back = -1;//数组元素从0开始存起
    rear = array_len - 1;

    while( front < rear )
    {
        while( array[front]%2 == 0 && front < rear )
            front++;
        //当array[front]值为奇数时：交换
        if( array[front]%2!=0 )
        {
            back++;
            swap(array[back],array[front],temp);
            front++;
        }
    }
    //此时，front==rear
    back++;
    swap(array[back],array[front],temp);
    return array;
}


int main()
{
    printf("测试代码！\n");
    int i;

    int a1[10] = {6,2,3,4,7,8,1,0,-1,-5};
    printf("原数组为：");
    for(i=0;i<10;i++)
        printf("%d ",a1[i]);
    printf("\n");
    printf("奇偶排序后为：");
    odd_even_sort_like_qsort_2(a1,10);
    for(i=0;i<10;i++)
        printf("%d ",a1[i]);
    printf("\n");

    int a2[16] = {23,3,28,5,6,100,54,-2,-17,2,-36,0,26,-11,9,16};
    printf("原数组为：");
    for(i=0;i<16;i++)
        printf("%d ",a2[i]);
    printf("\n");
    printf("奇偶排序后为：");
    odd_even_sort_like_qsort_2(a2,16);
    for(i=0;i<16;i++)
        printf("%d ",a2[i]);
    printf("\n");


    return 0;
}

