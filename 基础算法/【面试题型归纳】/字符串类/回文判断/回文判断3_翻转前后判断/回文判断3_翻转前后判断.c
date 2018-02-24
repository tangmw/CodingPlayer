/*******************************************************************************************
【问题描述】
给定一个字符串，判断这个字符串是否是回文

下面算法实现的是翻转前后判断是否为回文
通过调用reverse函数，将原字符串翻转后与翻转前的字符串进行比较，如果相同，则是回文，反之不是

时间复杂度为O(n)

Author:tmw
date:2017-11-13
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define swap(x,y,t) (t=x,x=y,y=t)
bool isPalindrome_reverse(char* array)
{
    //输入合法性检查
    if(strlen(array)==0 || array==NULL)
        return false;
    char* temp;
    temp = (char*)malloc((strlen(array)+1)*sizeof(char));
    strcpy(temp,array);//char* strcpy(char* des,const char* source)

    int front = 0;
    int rear = strlen(array)-1;
    while( front < rear )
    {
        char temp1;
        swap(array[front],array[rear],temp1);
        front++;
        rear--;
    }
    if(strcmp(array,temp)==0)
        return true;
    else
        return false;
}

int main()
{
    printf("测试程序\n");
    char a1[]="";
    printf("a1=%s\t%d\n",a1,isPalindrome_reverse(a1));

    char a2[]="  ";
    printf("a2=%s\t%d\n",a2,isPalindrome_reverse(a2));

    char a3[]="12321";
    printf("a3=%s\t%d\n",a3,isPalindrome_reverse(a3));

    char a4[]="dafdf111";
    printf("a4=%s\t%d\n",a4,isPalindrome_reverse(a4));

    char a5[]="ababadfsbba";
    printf("a5=%s\t%d\n",a5,isPalindrome_reverse(a5));
    return 0;
}
