/*******************************************************************************************
【问题描述】
打印给定字符串的所有排列情况。

字典序排列算法
给定两个偏序集A和B,(a,b)和(a′,b′)属于笛卡尔积A×B，则字典序定义为(a,b) ≤ (a′,b′) 当且仅当a<a′ 或 (a=a′ 且b≤b′).
1）如果给定的两个等长字符串，从起点开始将它们对应的字符逐个比较，则先出现较小字符的字符串字典序小
2）如果给定的是两个非等长字符串，如果字符一直相等，则较短那个字符串的字典序小

例如：“abc”、“abcd”、“acde”、“adbc”
字典序从小到大排列为："abc"、“abcd”、“acde”、“adbc”

所以，要求出给定任意字符串的全排列，则采用字典序排序算法如下：
算法起点：找到字典序最小的排列1~n，如“12345”
step1:从右至左找寻字符串中第一次出现递减序列的首位字符a[i];
step2:寻找i位置往右的字符中，比a[i]大的所有字符里面最小的字符，记为b[j];
step3:交换a[i]与b[j]；
step4:把第i+1位到最后部分的字符翻转，执行此步骤后，i+1到n的字符变成升序排列
算法终点：找到字典序最大的排列n~1，如“54321”，算法结束
********************************************************************************************/
/**字典序排列算法实现**/
/************************
Author:tmw
date:2017-11-12
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define swap(x,y,t) (t=x,x=y,y=t)
//算法起点：普通快排找出已给字符串的字典序最小排列
int first_ele_fast_sort( char* array , int low , int high )//注意是针对字符串的快排  char
{
    int target = 0;
    target = array[low];//偷个懒，直接用数组中的第一个元素作为中轴元素

    while( low < high )
    {
        while( low < high && array[high] >= target  )
            high--;
        array[low] = array[high];//此时high位置上的元素为待处理元素

        while( low < high && array[low] <= target   )
            low++;
        array[high] = array[low];//将大于target值的元素放到待处理的high位置上，那么此时,low位置变为待处理
    }
    array[low] = target; //以上，省去交换，变为“挖坑赋值”，降低时间复杂度
    return low;
}
char* fast_sort( char* array , int low , int high )
{
    if( low < high )
    {
        int index;
        index = first_ele_fast_sort(array,low,high);
        fast_sort(array,low,index-1);
        fast_sort(array,index+1,high);
    }
    return array;
}

void reverse( char* array , int start , int end )
{
    while( start < end )
    {
        char temp;
        swap(array[start],array[end],temp);
        start++;
        end--;
    }
}

//字典序排列算法----找到比当前排列字典序大1的新排列
bool dictionary_sort( char* array , int array_len )
{
    //step1:从右至左找寻字符串中第一次出现递减序列的首位字符a[i]
    int i = 0;
    int j = 0;
    for( i = array_len - 2 ; (i >= 0) && array[i] >= array[i+1] ; i-- );//此时i位置上的元素array[i]即为目标元素a

    if( i < 0 )//说明此时已经是最大字典序列
        return false;

    //step2:寻找i位置往右的字符中，比a[i]大的所有字符里面最小的字符，记为b[j];
    for( j = array_len-1 ; ( j > i ) && array[j] <= array[i] ; j-- );
    //for循环后，就找到了第二个目标元素b---array[j]

    //step3:交换a[i]与b[j]
    char temp;
    swap(array[j],array[i],temp);

    //step4:把第i+1位到最后部分的字符翻转
    reverse(array,i+1,array_len-1);
    return true;
}

/**字典序全排列--找出给定字符串按字典序从小到大找出全排列**/
void dictionary_full_sort(char* array , int array_len )
{
    int i = 1;
    array = fast_sort(array,0,array_len-1);//先快排，找出最小字典序列
    printf("\tcase #%d \t%s\n",i,array);
    while(dictionary_sort(array,array_len))
        printf("\tcase #%d \t%s\n",++i,array);
}


int main()
{
    char array[] = "aaabb";
    printf("%s 的全排列为：\n",array);
    dictionary_full_sort(array,strlen(array));
    return 0;
}
