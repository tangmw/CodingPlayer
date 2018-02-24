/*******************************************************************************************
【问题描述】
给定一个字符串，判断这个字符串是否是回文

下面的算法实现的是中间到两头
首先对字符串进行输入合法性检查
在输入合法的前提下，对字符串进行操作
1）当为偶数串时，起始比较的中间数为(首+尾)/2和(首+尾)/2+1;
2）当为奇数串时，起始比较的中间数为(首+尾)/2-1和(首+尾)/2+1

时间复杂度为O(n)

Author:tmw
date:2017-11-13
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome_middle2edge(char* array)
{
    //字符串合法性检查
    if(array==NULL || strlen(array)==0)
        return false;

    //分类判断
    if(strlen(array)%2!=0)//说明为奇数串
    {
        int front = (strlen(array)-1)/2-1;//下标从0开始
        int rear = (strlen(array)-1)/2+1;
        while(front>=0)
        {
            if(array[front]!=array[rear])
                return false;
            front--;
            rear++;
        }
    }
    else
    {
        int front = (strlen(array)-1)/2;//下标从0开始
        int rear = (strlen(array)-1)/2+1;
        while(front>=0)
        {
            if(array[front]!=array[rear])
                return false;
            front--;
            rear++;
        }
    }
    return true;
}

int main()
{
    printf("测试程序\n");
    char a1[]="";
    printf("a1=%s\t%d\n",a1,isPalindrome_middle2edge(a1));

    char a2[]="  ";
    printf("a2=%s\t%d\n",a2,isPalindrome_middle2edge(a2));

    char a3[]="12321";
    printf("a1=%s\t%d\n",a3,isPalindrome_middle2edge(a3));

    char a4[]="dafdf";
    printf("a1=%s\t%d\n",a4,isPalindrome_middle2edge(a4));

    char a5[]="abababba";
    printf("a1=%s\t%d\n",a5,isPalindrome_middle2edge(a5));


    return 0;
}
