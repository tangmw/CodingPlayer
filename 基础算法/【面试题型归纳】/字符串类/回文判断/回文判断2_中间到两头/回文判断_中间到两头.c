/*******************************************************************************************
������������
����һ���ַ������ж�����ַ����Ƿ��ǻ���

������㷨ʵ�ֵ����м䵽��ͷ
���ȶ��ַ�����������Ϸ��Լ��
������Ϸ���ǰ���£����ַ������в���
1����Ϊż����ʱ����ʼ�Ƚϵ��м���Ϊ(��+β)/2��(��+β)/2+1;
2����Ϊ������ʱ����ʼ�Ƚϵ��м���Ϊ(��+β)/2-1��(��+β)/2+1

ʱ�临�Ӷ�ΪO(n)

Author:tmw
date:2017-11-13
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome_middle2edge(char* array)
{
    //�ַ����Ϸ��Լ��
    if(array==NULL || strlen(array)==0)
        return false;

    //�����ж�
    if(strlen(array)%2!=0)//˵��Ϊ������
    {
        int front = (strlen(array)-1)/2-1;//�±��0��ʼ
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
        int front = (strlen(array)-1)/2;//�±��0��ʼ
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
    printf("���Գ���\n");
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
