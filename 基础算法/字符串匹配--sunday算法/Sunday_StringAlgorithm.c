/*************************************************************************

Sunday Algorithm----һ�ּ򵥵��ַ���ģʽƥ���㷨

��KMP��BM�㷨������࣬�����ʱ�临�Ӷ�ΪO(��������*Ŀ�괮����)
���磺 Ŀ�괮 baaaabaaaabaaaabaaaa
       ģʽ�� aaaaa

Complexity---O(��������*Ŀ�괮����)
Author:tmw
date:2017-9-5

**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGSIZE 50

//��ʼ��������Ŀ�괮
int init( char **source , char **target )
{
    *source = (char*)malloc(STRINGSIZE*sizeof(char));
    *target = (char*)malloc(STRINGSIZE*sizeof(char));

    if( source == NULL || target == NULL )
    {
        printf("��ʼ���ڴ����ʧ�ܣ�\n");
        return 0;
    }

    memset(source,'\0',STRINGSIZE);
    memset(target,'\0',STRINGSIZE);//��ʼ�������char���ڴ�ռ�

    char ch;
    int i = 0;
    printf("����������Ԫ�أ�<��enter����>\n");
    while( ( ch = getchar() ) != '\n' )
    {
        (*source)[i] = ch;
        i++;
    }

    i = 0;
    printf("������Ŀ�������Ԫ�أ���enter����>\n");
    while( ( ch = getchar() ) != '\n' )
    {
        (*target)[i] = ch;
        i++;
    }

/*************************************
//    [�����Ƿ���������ֵ]
//    i = 0;
//    while( i < strlen(*source) )
//    {
//        printf("%c",(*source)[i]);
//        i++;
//    }
//    i = 0;
//    printf("\n");
//    while( i < strlen(*target) )
//    {
//        printf("%c",(*target)[i]);
//        i++;
//    }
**************************************/

    return 1;
}

//Ŀ�괮�Ƿ���tempԪ�أ����򷵻�temp��Ŀ�괮�е�λ�ã����򷵻�-1
int findIndex( char *target , char temp )
{
    if( strlen(target) == 0 )
    {
        printf("����-----Ŀ�괮Ϊ�գ�\n");
        return 0;
    }

    int i = 0;
    for( i = strlen(target)-1 ; i > 0 ; i-- )
    {
        if( target[i] == temp )
            return i;
    }
    return -1;
}

int Sunday( char *source , char *target )
{
    //��������
    int i = 0;
    int j = 0;
    int srclen = 0;
    int tarlen = 0;
    int index = 0;
    int temp;

    //������ʼ��
    srclen = strlen( source );
    tarlen = strlen( target );
    //��ʼ�����
    if( srclen == 0 )
    {
        printf("����------����Ϊ�գ�\n");
        return 0;
    }
    if( tarlen == 0 )
    {
        printf("����-----Ŀ�괮Ϊ�գ�\n");
        return 0;
    }

    //Sunday�㷨��Ҫ˼��
    while( i < srclen )
    {
        if( source[i] == target[j] )
        {
            i++;
            j++;
            if( j == tarlen )
            {
                printf("�ҵ�ƥ�䴮��λ��Ϊ[%d ~ %d]\n",i-tarlen+1,i);
                return 0;
            }
        }
        else
        {
            temp = tarlen + i - j;
            index = findIndex( target , source[temp] );
            if( index == -1 ) //������   Ŀ�괮�Һ�һ��Ԫ��û����Ŀ�괮ƥ��
            {
                i = temp + 1; //iָ������δ��ƥ��Ԫ�صĺ�һ���������Ƚ�
                j = 0; //Ŀ�괮����
            }
            else //�����е�tempλ���ϵ�Ԫ�أ���Ŀ�괮�г��ֹ���Ŀ�괮�Ӻ���ǰ������
            {
                i = temp - index;//�����±귵�����Ŀ�괮�ġ���ʼλ�á�---����������ƥ����ַ�����Ŀ�괮�ڶ�Ӧ��λ�ü���ƥ��
                j = 0;       //��ʱĿ�괮���������ڡ���ԡ�����ʼλ�á���ʼ�Ƚ�
            }
        }
    }
    printf("δ��ƥ�䣡...\n");
    return 0;
}



int main()
{
    char *source;
    char *target;

    init( &source , &target );
    Sunday( source , target );

    return 0;
}
