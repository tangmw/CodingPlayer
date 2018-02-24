/*******************************************************************************************
【问题描述】
给定一个字符串，判断这个字符串是否是回文

下面算法实现的是栈判断是否为回文
将元素一一进栈，然后出栈，比较进栈前后是否一致，一致则为回文，不一致则不是

时间复杂度为O(n)

Author:tmw
date:2017-11-13
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome_stack(char* array)
{
    //输入合法性判定
    if(strlen(array)==0 || array==NULL)
        return false;

    char* stack;
    stack = (char*)malloc((strlen(array)+1)*sizeof(char));

    int top = 0;
    for(top=0;top<strlen(array);top++)//入栈
        stack[top] = array[top];
    top--;//top始终指向栈顶

    char* after;
    after = (char*)malloc((strlen(array))*sizeof(char));//保存出栈后的字符串

    int i = 0;
    while(top>=0)
        after[i++] = stack[top--];//出栈
    after[i] = '\0';//注意！！字符串以\0结尾！否则会有乱码

    free(stack);//释放栈空间

    if(strcmp(array,after)==0)
        return true;//栈前栈后一样，是回文，返回1
    else
        return false;

}

int main()
{
    printf("测试程序\n");
    char a1[]="";
    printf("a1=%s\t%d\n",a1,isPalindrome_stack(a1));

    char a2[]="  ";
    printf("a2=%s\t%d\n",a2,isPalindrome_stack(a2));

    char a3[]="12321";
    printf("a3=%s\t%d\n",a3,isPalindrome_stack(a3));

    char a4[]="dafdf111";
    printf("a4=%s\t%d\n",a4,isPalindrome_stack(a4));

    char a5[]="ababadfsbba";
    printf("a5=%s\t%d\n",a5,isPalindrome_stack(a5));
    return 0;
}
