/*******************************************************************************************
【问题描述】
给定一个字符串，判断这个字符串是否是回文

回文的特点在于对称性，针对这个性质，笔者想到的方法有:
1）两头到中间
2）中间到两头
3）recerse前后判断
4）栈

下面的算法实现的是两头到中间
头、尾指针分别指向字符串的首元素和尾元素，逐一比较，若有不同，
则返回false，程序退出。直到头尾指针指向同一个中间元素，算法终止

时间复杂度为O(n)

Author:tmw
date:2017-11-13
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome_edge2middle(char* array)
{
    //合法性检查
    if(strlen(array) == 0 || array==NULL)
        return false;

    int front = 0;
    int rear = strlen(array)-1;
    while( front < rear )
    {
        if(array[front] != array[rear])
        {
            return false;
            break;
        }
        front++;
        rear--;
    }
    return true;
}


int main()
{
    printf("测试程序\n");
    char a1[]="";
    printf("a1=%s\t%d\n",a1,isPalindrome_edge2middle(a1));

    char a2[]="  ";
    printf("a2=%s\t%d\n",a2,isPalindrome_edge2middle(a2));

    char a3[]="12321";
    printf("a1=%s\t%d\n",a3,isPalindrome_edge2middle(a3));

    char a4[]="dafdf";
    printf("a1=%s\t%d\n",a4,isPalindrome_edge2middle(a4));

    char a5[]="abababba";
    printf("a1=%s\t%d\n",a5,isPalindrome_edge2middle(a5));


    return 0;
}
