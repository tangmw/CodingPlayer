/**********************************************************************************************************

LeetCode----[easy] 20-ValidParentheses

Given a string containing just the characters '('��')'��'{'��'}'��'['and']',determine if the input string is valid

The brackets must close in the correct order.'()' and '[]{}()<>�� are right but '{]'is not

[Ans:]
Method:Stack
Author:tmw
date:2017-9-6

***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//bool����֧�ſ�
#include <string.h>

//�������ջ�ķ���
//��һ��������ջ�ṹ����ʼ��ջ������д����ջ��ջ�Ӻ���

#define StackSize 100

/*SqStack*/
typedef struct SQSTACK_NODE
{
    char data[StackSize];
    int top;
}SqStack;

//initial
SqStack* StackInit()
{
    SqStack *s;
    //int i = 0;
    s = (SqStack*)malloc(StackSize*sizeof(SqStack));

    if( !s )
        printf("The memory malloc failed!\n");
    else
        s->top = -1;
    return s;
}
//judge weather empty or not
bool StackIsEmpty( SqStack *s )
{
    if( s->top == -1 )
        return true;
    else
        return false;
}

void Push( SqStack *s , char e ) //put e into the Stack
{
    if( s->top == StackSize-1 )
    {
        printf("Stack is full!\n");
        exit(0);
    }
    //printf("s->top=%d\n",s->top);
    s->top = s->top+1;
    s->data[s->top] = e;
    //PrintStack(s);
}

char Pop( SqStack *s )
{
    char e;
    if( ! StackIsEmpty(s) )
    {
        e = s->data[s->top];
        s->top--;
    }
    else
    {
        printf("Stack is empty, can not Pop element!\n");
    }
    return e;
}

bool isValid( char *s )
{
    int i = 0;
    int len = strlen(s);

    SqStack *St;
    St = StackInit();

    //�ж�ǰ�ж�s�Ƿ�Ϊ��
    if( len == 0 )
    {
        printf("�ж��ַ���Ϊ�գ��޷��ж���\n");
        return 0;
    }

    for( i = 0 ; i < len-1 ; i++ )
    {
        if( ( s[i] == '(') || ( s[i] == '[') || ( s[i] == '{' ) || ( s[i] == '<') )
            Push(St,s[i]);
        else if( StackIsEmpty(St) )
        {
            printf("�ǶԳ��ַ���\n");
            return false;
        }
        else
        {
            if( s[i] == ']' && !StackIsEmpty(St) )
            {
                if( St->data[St->top] == '[')
                    Pop(St);
                else
                {
                    printf("�ǶԳ��ַ���\n");
                    return false;
                }
            }

            if( s[i] == ')' && !StackIsEmpty(St) )
            {
                if( St->data[St->top] == '(')
                    Pop(St);
                else
                {
                    printf("�ǶԳ��ַ���\n");
                    return false;
                }
            }

            if( s[i] == '}' && !StackIsEmpty(St) )
            {
                if( St->data[St->top] == '{')
                    Pop(St);
                else
                {
                    printf("�ǶԳ��ַ���\n");
                    return false;
                }
            }

            if( s[i] == '>' && !StackIsEmpty(St) )
            {
                if( St->data[St->top] == '<')
                    Pop(St);
                else
                {
                    printf("�ǶԳ��ַ���\n");
                    return false;
                }
            }
        }
    }
    if( StackIsEmpty(St) )
    {
        printf("�ǶԳ��ַ���\n");
        return true;
    }

    else
    {
        printf("�ǶԳ��ַ���\n");
        return false;
    }
}


int main()
{
    char *s;
    int i = 0;

    s = malloc(50*sizeof(char));
    memset(s,'\0',50);

    printf("�����������ַ�����\n");
    while( ( s[i] = getchar() ) != '\n' )
    {
        ungetc(s[i],stdin);
        scanf("%c",&s[i]);
        i++;
    }
    isValid(s);
    return 0;
}
