/***********************************************
【问题描述】
现有n个红白蓝三种不同个颜色的球，乱序排在一起，请通过
两两交换任意两个球，使得从左到右的球依次是红球、白球、篮球。

无差别的快排总感觉没有很好地利用题目给出的条件：只有红球白球和黑球，
对应数字就是只有0,1,2，因此，可以专门针对只有三种元素的情况设计一种
有差别的快排算法：

设计三种指针：front current rear
算法开始，front和current游标都指向数组的首，rear游标指向数组的尾
1）当current游标所指向的元素为0时，与front游标所指元素交换，front++ current++
2）当current游标所指向的元素为1时，不交换，current++
3）当current游标所指向的元素为2时，与rear游标所指向的元素交换，rear--

Author:tmw
date:2017-11-24
************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t)

int* Dutch_flag_like_fast_sort( int* array , int array_len )
{
    int front,current,rear,temp;
    front = current = 0;
    rear = array_len - 1;
    while(current<=rear)
    {
        if( array[current] == 0 )
        {
            swap(array[current],array[front],temp);
            current++;front++;
        }
        else if( array[current] == 1 )
            current++;
        else
        {
            swap( array[current],array[rear],temp);
            rear--;
        }
    }
    return array;
}


int main()
{
    printf("测试程序!\n");
    int i;
    int* res;res=(int*)malloc(100*sizeof(int));

    int a1[13] = {0,2,1,1,1,2,0,0,2,0,1,1,2};
    printf("原数组为：");
    for(i=0;i<13;i++)
        printf("%d ",a1[i]);
    printf("\n");
    printf("排列后的数组为：");
    res = Dutch_flag_like_fast_sort(a1,13);
    for(i=0;i<13;i++)
        printf("%d ",res[i]);

    return 0;
}
