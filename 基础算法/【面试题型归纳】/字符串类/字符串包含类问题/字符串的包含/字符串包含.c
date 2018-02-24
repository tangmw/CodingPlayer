/*******************************************************************************************
【问题描述】
给定两个字符串a和b，一长一短，如何快速判断短字符串b中所有元素都在长字符串a中？
这里假设字符串中的元素都为大写字母
例如
1) a = “ABCD”,b = “DBA”,返回true
2) a = "ABCD",b = "AAD",返回true
3) a = "ABCD",b = "BCE",返回false
********************************************************************************************/

/************************
Author:tmw
date:2017-11-6
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
方法一：排序+查找
step 1: 将a和b使用快排成为递增序列，复杂度o(nlogn)
step 2: b中元素与a匹配，匹配成功则返回false,复杂度O(m+n)

ps:不做排序的直接匹配，由于序列不是有序，因此每一次匹配都要把a数组遍历一次，复杂度O(n*m)
**/
int first_ele_fast_sort( char array[] , int low , int high )//注意是针对字符串的快排  char
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
void fast_sort( char array[] , int low , int high )
{
    if( low < high )
    {
        int index;
        index = first_ele_fast_sort(array,low,high);
        fast_sort(array,low,index-1);
        fast_sort(array,index+1,high);
    }
}
bool string_contain( char a[] , int a_len , char b[] , int b_len )//a b均为字符串
{
    fast_sort(a,0,a_len-1);//字符串a快排
    fast_sort(b,0,b_len-1);//字符串b快排

    int a_index,b_index;
    for( b_index = 0 , a_index = 0 ; b_index < b_len ; b_index++ )//b在a中找伙伴，所以b为外循环
    {
        while( a_index < a_len && a[a_index] < b[b_index] )//a,b均为增序
            a_index++;
        if( a_index >= a_len || a[a_index] > b[b_index] )
            return false;//b中任意一个元素轮询a后没找到匹配，则直接return false  无需再找下去了--降低复杂度
    }
    return true;
}

int main()
{
    int a_len,b_len;
    char* a;
    char* b;
    printf("请输入a数组长度\n");
    scanf("%d",&a_len);
    a = (char*)malloc(a_len*sizeof(char));

    printf("请输入b数组长度\n");
    scanf("%d",&b_len);
    b = (char*)malloc(b_len*sizeof(char));

    printf("请输入长字符串a元素：");
    //char ch;
    //while( ch = getchar() != '\n');
    scanf("%s",a);
    //while( ch = getchar() != '\n');
    printf("请输入短字符串b元素：");
    scanf("%s",b);
    printf("%d\n",string_contain(a,a_len,b,b_len));
    if(string_contain(a,a_len,b,b_len))
        printf("a包含b中所有元素！\n");
    else
        printf("a不包含b！\n");
    return 0;
}
