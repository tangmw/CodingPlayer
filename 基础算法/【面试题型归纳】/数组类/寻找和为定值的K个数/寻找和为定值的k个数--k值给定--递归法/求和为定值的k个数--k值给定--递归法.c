/***********************************************
【问题描述】
输入两个整数n和sum，要求从正整数数列中随意取出
几个数，使得它们的和等于sum，将其中所有可能的组合列出来

解法：递归法
此题是在n个数中找和为sum的任意组合，那么可以将问题转化为：
1）若选第n个数，则在剩余的n-1个数中找和为sum-val(n)的数
2）若不选第n个数，则在剩余的n-1个数中找和为sum的数

这里的n是不定的，所以当代码层层递归后，最后问题变成了在数列中
找一个目标值，使它的值与sum-val(i)-val(j)-val(k)..的值相等

下面代码给出的是求和为定值的任意k个数的组合
Author:tmw
date:2017-11-21
************************************************/
#include <stdio.h>
#include <stdlib.h>

int result[100] = {0};//将结果数组定义成全局变量是避免在递归调用函数时，重复申请内存空间
int j = 0;
void choose_k_numbers_equal_to_sum(int* array , int array_len , int sum , int k )
{
    //输入合法性检查 && 递归出口
    if( !array || array_len <=0 || sum <= 0 )
        return;
    //结果打印
    if( j > 0 )
    {
        if( array[array_len-1] == sum && j == k - 1)//如果一直递归，这个sum值和n值是不断变化的：sum-val(i)-val(j)-val(k)..
        {
            int i;
            for( i = 0 ; i < j ; i++ )
                printf("%d + ",result[i]);
            //此时array[n-1]并没有赋入result数组中，因此要单独打印
            printf("%d \n",array[array_len-1]);
        }
    }
    result[j++] = array[array_len-1];
    choose_k_numbers_equal_to_sum(array,array_len-1,sum-array[array_len-1],k);//放n，前n-1个数满足sum-val(n)
    j--;//不放n时，游标要撤回
    choose_k_numbers_equal_to_sum(array,array_len-1,sum,k);//不放n，前n-1个数满足sum
}


int main()
{
    printf("测试代码\n");
    int i;
    int k=4;
    int a[12] = {1,2,4,5,7,11,54,3,8,6,10,13};
    printf("原数列如下：\n");
    for(i=0;i<12;i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("数列中和为10的%d个数的组合为：\n",k);
    choose_k_numbers_equal_to_sum(a,12,10,k);

    int b[15] = {2,8,32,15,1,6,9,10,7,6,13,14,20,0,5};
    printf("原数列如下：\n");
    for(i=0;i<15;i++)
        printf("%d ",b[i]);
    printf("\n");
    printf("数列中和为10的%d个数的组合为：\n",k);
    choose_k_numbers_equal_to_sum(b,15,10,k);

    return 0;
}
