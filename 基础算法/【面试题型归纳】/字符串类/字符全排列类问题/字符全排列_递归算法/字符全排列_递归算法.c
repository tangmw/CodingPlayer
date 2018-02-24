/*******************************************************************************************
【问题描述】
打印给定字符串的所有排列情况。
例如
1) 输入字符串‘abc’，则打印出它的全排列形式：
abc acb bac bca cab cba

注意：写算法时要考虑到有相同元素的情况：
输入字符串‘aab’，它的全排列打印应该为 aab aba baa

所以，设计的算法应该对这两种情况有区分
********************************************************************************************/

/************************
Author:tmw
date:2017-11-9
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**递归算法实现**/
//#define swap(x,y,t) (t=x,x=y,y=t)---宏定义方法
void swap( char* array , int i , int j ) //---函数实参传递方法
{
    char temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
bool can_swap( char *array , int i , int left );
void char_all_permutate(char array[] , int left , int right )
{
    int i;
    if( left == right )
        printf("\t %s\n",array);

    for( i = left ; i <= right ; i++ )
    {
        if(can_swap(array,left,i))
        {
            swap(array,i,left);
            //对i位置以后的元素进行全排序,如此递归
            char_all_permutate(array,left+1,right);
            //返回上一层的同时恢复上一层序列排序，以防i叠加后，进入第一个swap时，又和之前相同的元素调换了，打印相同交换结果
            //---真正实现与i位置元素轮流调换的功能
            swap(array,i,left);
        }
    }
}
//以上子函数虽能实现对字符数组的全排列，但是如果排列元素中有重复的元素，此全排列算法会失效
//因为此算法没有对元素判重区分后再交换，因此，优化此算法的点在于，优化swap，对swap增加一个元素判重的判定

//元素非重复，返回true，可交换
bool can_swap( char *array , int left , int i )
{
    //由于i起始位置是left，因此在判断待交换的两个元素是否需要交换时应避免i=left的情况
    int kk = left;
    for( kk = left ; kk < i ; kk++)
        if( array[kk] == array[i] && i != kk )
            return false;
    return true;
}


int main()
{
    char array[] = "aaabb";
    printf(" %s 的全排列为：\n",array);
    char_all_permutate(array,0,strlen(array)-1);
    return 0;
}
