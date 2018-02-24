/***************************

//���Ա��ʽ��9+(3-1)*3+10/2
//��׺ת��׺�����931-3*+102/+
//���Ľ������char�ͽ�ջÿ��ֻ�ܶ���һ���ַ�������(������10��Ϊ�Ӵ���ջ������1 0)
//Author:tmw
//date:2017-9-1

*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define StackSize 30

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

void PrintStack( SqStack *s)
{
    int i = 0;

    while( i <= s->top )
    {
        printf("%c",s->data[i]);
        i++;
    }
    printf("\n");
}

/*************************************************************************************
�����main()��������Ϊcheckջ�ܷ����������Ĳ��Ժ���

//int main()
//{
//    char element;
//    int i = 0;
//    SqStack *s;
//
//    printf("Stack check---\n");
//    s = StackInit();
//
//    printf("Please input elements into the Stack!\n");
//    //getchar();
//    while( ( s->data[i] = getchar() ) != '\n' )
//    {
//        ungetc(s->data[i],stdin);//ungetc�ǰ���������һ�������ͻ�������
//        scanf("%c",&element);
//        Push(s,element);
//        i++;
//    }
//    //Pop(s);//put \n out of stack
//    printf("s->top=%d\n",s->top);
//    PrintStack(s);
//    printf("Next step will Pop the top number!\n");
//
//    Pop(s);
//    PrintStack(s);
//    return 0;
//}
*******************************************************************************************/

/***************************
//��׺���ʽת��׺���ʽ
*****************************/
char*  PostfixExpression(char *c, int lenth)
{
    SqStack *s;
    s = StackInit();   //ջ������������ķ��ţ������ֵĻ���ֱ�Ӵ�ӡ

    int i = 0;
    int j = 0;

    //int e;

    char* temp;//temp��������������ĺ�׺���ʽ��������������������
    temp = malloc(lenth*sizeof(char));
    memset(temp,'\0',lenth); //��ʼ��temp

    while( c[i] != '\0' )
    {
        if( c[i] >= '0' && c[i] <= '9' )
        {
            temp[j] = c[i];
            printf("%c",temp[j]);
            j++;
            i++;
        }
        else
        {
            if( ( c[i] == '(' ) || ( ( ( s->data[s->top] == '+' ) || ( s->data[s->top] == '-' ) ) && ( ( c[i] == '*') || ( c[i] == '/' ) ) ) )
            {
                Push(s,c[i]);
                i++;
            }

            else if( c[i] == ')' )
            {
                while( s->data[s->top] != '(' )
                {
                    temp[j] = Pop(s);
                    printf("%c",temp[j]);
                    j++;
                }
                Pop(s);//��������(��ȡ��������������temp��
                i++;
            }
            else if( ( ( s->data[s->top] == '*' ) || ( s->data[s->top] == '/' ) ) && ( ( c[i] == '+') || ( c[i] == '-' ) ) )
            {
                while( !StackIsEmpty(s) )
                {
                    temp[j] = Pop(s);
                    printf("%c",temp[j]);
                    j++;
                }
            }
            else
            {
                Push(s,c[i]);
                i++;
            }
        }

        if( i == lenth )
        {
            while( !StackIsEmpty(s) )
            {
                temp[j] = Pop(s);
                printf("%c",temp[j]);
                j++;
            }
        }

    }
    printf("\n");
    printf("The result is %s\n",temp);
    return temp;
}

/***************************
//��׺���ʽ������
*****************************/
void PostfixExpCompute( char *temp , int tempLen )
{
    SqStack *s;
    s = StackInit();
    int i = 0;
    int result = 0;
    int ans = 0;

    for( i = 0 ; i < tempLen ; i++ )
    {
        if( temp[i] >= '0' && temp[i] <= '9' )
        {
            temp[i] = temp[i]-'0';//char תint
            Push(s,temp[i]);
            printf("s->data[%d] = %d\n",s->top,s->data[s->top]);
        }
        else
        {
            switch (temp[i])
            {
                case '+':
                    result = s->data[s->top-1] + s->data[s->top];
                    printf("%d+%d ans is %d\n",s->data[s->top-1],s->data[s->top],result);
                    ans = Pop(s);
                    ans = Pop(s);
                    break;
                case '-':
                    result = s->data[s->top-1] - s->data[s->top];
                    printf("%d-%d ans is %d\n",s->data[s->top-1],s->data[s->top],result);
                    ans = Pop(s);
                    ans = Pop(s);
                    break;
                case '*':
                    result = s->data[s->top-1] * s->data[s->top];
                    printf("%d*%d ans is %d\n",s->data[s->top-1],s->data[s->top],result);
                    ans = Pop(s);
                    ans = Pop(s);
                    break;
                case '/':
                    result = s->data[s->top-1] / s->data[s->top];
                    printf("%d/%d ans is %d\n",s->data[s->top-1],s->data[s->top],result);
                    ans = Pop(s);
                    ans = Pop(s);
                    break;
                default:break;
            }
            Push(s,result);
        }
    }
    ans = Pop(s);
    printf("The final compute answer is %d\n",ans);
}

int main()
{
    char *temp;
    int i = 0;
    printf("Please input your biaodashi!\n");
    char *c = (char *)malloc(20*sizeof(char));
    memset(c,'\0',20);//��ʼ��c�ַ�������

    while( ( c[i] = getchar() ) != '\n' )
    {
        ungetc(c[i],stdin);//ungetc�ǰ���������һ�������ͻ�������
        scanf("%c",&c[i]);
        i++;
    }
    printf("length_c = %d\n",i);
    temp = PostfixExpression(c,i);
    PostfixExpCompute(temp,i);
    return 0;
}



