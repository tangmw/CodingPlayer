/*******************************************************************************************
������������
����һ���ַ������ж�����ַ����Ƿ��ǻ���

���ĵ��ص����ڶԳ��ԣ����������ʣ������뵽�ķ�����:
1����ͷ���м�
2���м䵽��ͷ
3��recerseǰ���ж�
4��ջ

������㷨ʵ�ֵ�����ͷ���м�
ͷ��βָ��ֱ�ָ���ַ�������Ԫ�غ�βԪ�أ���һ�Ƚϣ����в�ͬ��
�򷵻�false�������˳���ֱ��ͷβָ��ָ��ͬһ���м�Ԫ�أ��㷨��ֹ

ʱ�临�Ӷ�ΪO(n)

Author:tmw
date:2017-11-13
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome_edge2middle(char* array)
{
    //�Ϸ��Լ��
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
    printf("���Գ���\n");
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
