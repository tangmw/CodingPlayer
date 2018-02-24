/*******************************************************************************************
������������
����һ���ַ������ж�����ַ����Ƿ��ǻ���

�����㷨ʵ�ֵ���ջ�ж��Ƿ�Ϊ����
��Ԫ��һһ��ջ��Ȼ���ջ���ȽϽ�ջǰ���Ƿ�һ�£�һ����Ϊ���ģ���һ������

ʱ�临�Ӷ�ΪO(n)

Author:tmw
date:2017-11-13
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome_stack(char* array)
{
    //����Ϸ����ж�
    if(strlen(array)==0 || array==NULL)
        return false;

    char* stack;
    stack = (char*)malloc((strlen(array)+1)*sizeof(char));

    int top = 0;
    for(top=0;top<strlen(array);top++)//��ջ
        stack[top] = array[top];
    top--;//topʼ��ָ��ջ��

    char* after;
    after = (char*)malloc((strlen(array))*sizeof(char));//�����ջ����ַ���

    int i = 0;
    while(top>=0)
        after[i++] = stack[top--];//��ջ
    after[i] = '\0';//ע�⣡���ַ�����\0��β�������������

    free(stack);//�ͷ�ջ�ռ�

    if(strcmp(array,after)==0)
        return true;//ջǰջ��һ�����ǻ��ģ�����1
    else
        return false;

}

int main()
{
    printf("���Գ���\n");
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
