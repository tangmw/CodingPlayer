/*************************************************************************

Sunday Algorithm----一种简单的字符串模式匹配算法

比KMP和BM算法简单了许多，它最坏的时间复杂度为O(主串长度*目标串长度)
比如： 目标串 baaaabaaaabaaaabaaaa
       模式串 aaaaa

Complexity---O(主串长度*目标串长度)
Author:tmw
date:2017-9-5

**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGSIZE 50

//初始化主串和目标串
int init( char **source , char **target )
{
    *source = (char*)malloc(STRINGSIZE*sizeof(char));
    *target = (char*)malloc(STRINGSIZE*sizeof(char));

    if( source == NULL || target == NULL )
    {
        printf("初始化内存分配失败！\n");
        return 0;
    }

    memset(source,'\0',STRINGSIZE);
    memset(target,'\0',STRINGSIZE);//初始化分配的char型内存空间

    char ch;
    int i = 0;
    printf("请输入主串元素，<以enter结束>\n");
    while( ( ch = getchar() ) != '\n' )
    {
        (*source)[i] = ch;
        i++;
    }

    i = 0;
    printf("请输入目标检索串元素，以enter结束>\n");
    while( ( ch = getchar() ) != '\n' )
    {
        (*target)[i] = ch;
        i++;
    }

/*************************************
//    [测试是否能正常赋值]
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

//目标串是否有temp元素，是则返回temp在目标串中的位置，否则返回-1
int findIndex( char *target , char temp )
{
    if( strlen(target) == 0 )
    {
        printf("错误！-----目标串为空！\n");
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
    //变量定义
    int i = 0;
    int j = 0;
    int srclen = 0;
    int tarlen = 0;
    int index = 0;
    int temp;

    //变量初始化
    srclen = strlen( source );
    tarlen = strlen( target );
    //初始化检查
    if( srclen == 0 )
    {
        printf("错误！------主串为空！\n");
        return 0;
    }
    if( tarlen == 0 )
    {
        printf("错误！-----目标串为空！\n");
        return 0;
    }

    //Sunday算法主要思想
    while( i < srclen )
    {
        if( source[i] == target[j] )
        {
            i++;
            j++;
            if( j == tarlen )
            {
                printf("找到匹配串！位置为[%d ~ %d]\n",i-tarlen+1,i);
                return 0;
            }
        }
        else
        {
            temp = tarlen + i - j;
            index = findIndex( target , source[temp] );
            if( index == -1 ) //主串中   目标串右后一个元素没有与目标串匹配
            {
                i = temp + 1; //i指向主串未被匹配元素的后一个，继续比较
                j = 0; //目标串回溯
            }
            else //主串中的temp位置上的元素，在目标串中出现过（目标串从后往前遍历）
            {
                i = temp - index;//主串下标返回相对目标串的“起始位置”---即让主串中匹配的字符能与目标串在对应的位置继续匹配
                j = 0;       //此时目标串与主串都在“相对”“起始位置”开始比较
            }
        }
    }
    printf("未能匹配！...\n");
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
