/**********************************************************************************************************

LeetCode----[easy] 14-LongestCommonPrefix

Write a function to find the longest common prefix string amongst an array of strings.

[Ans:]
主要考察:字符串数组初始化、赋值、输出----指针与数组的转换
Author:tmw
date:2017-9-5

***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* fun  ---because it will return a character string not a character
char* longestCommonPrefix(char** strs, int strsSize)
{
    //第一步：在字符串数组中，找到长度最小的子串
    int lenMin = 0;
    int i = 0;
    int len = 0;


    char *sh;
    sh = (char*)malloc(1*sizeof(char));
    memset(sh,0,1);
    if( strsSize == 0 )
    {
        printf("字符串为空！\n");
        return sh;
    }

    lenMin = strlen(strs[0]); //先将长度最小赋给第一个字符串
    printf("%d\n",strlen(strs[0]));
    for( i = 1 ; i < strsSize ; i++ )
    {
        len = strlen(strs[i]);
        printf("%d\n",len);
        if( len < lenMin )
            lenMin = len;
    }//此时,lenMin就是字符串数组中字符串长度最小的值了
    printf("lenMin = %d\n",lenMin);

    //第二步：比较字符串数组中的每一个字符串在index位置上的字符，若相等，则index++，否则退出
    i = 0; //将i复位,避免重复申请内存，节约资源
    int j = 0;//j遍历字符串数组中的每一个字符串
    int index = 0;//记录字符串之间相同字符的下标
    char ch;//比较字符
    int flag = 0;//flag=1 终止匹配标识




    while( index <= lenMin )
    {
        ch = strs[0][index];
        j = 1; //j重置
        while( j < strsSize )//遍历每个字符串---返回每个串中最长公共前缀
        {
            while( ( j < strsSize ) && ( ch == strs[j][index] ) )//比较字符串数组中每一个字符串在index位置下的字符
                j++;
            if( j < strsSize )
            {
                if( index == 0 )
                {
                    printf("没有最长公共前缀匹配！\n");
                    return sh;
                }
                else
                {
                    flag = 1;//flag=1意味着不需要继续匹配了
                    break;
                }
            }
        }
        if( flag != 1 )
        {
           index++;
           printf("index = %d\n",index);
        }
        if( flag == 1 )
            break;
    }


    //第三步：将index位置之前的字符全部输出
    char *temp;
    temp = (char*)malloc( (index+1)*sizeof(char) );//index+1是为了给最后一位填\0，输出最后的匹配字符串
    i = 0;//将i复位
    for( i = 0 ; i < index ; i++ )
        temp[i] = strs[0][i];
    temp[i++] = '\0';//最后一位补上\0

    //最后一步：输出最大公共前缀字符串
    printf("字符串数组strs的最长公共前缀字符串为：%s",temp);
    return temp;

}

int main()
{

    int i = 0;

//    char strs[20][30];
//    memset(strs,0x00,sizeof(char)*400);//memset初始化二维数组
/********************************************************************************************************************************
下面的代码，将**strs转换为二维数组操作形式

先给**strs 的strs分配空间，它的下一级是*strs 因此sizeof(char*)，分配完后，就有空间来存储这些字符串了
再给*strs 的strs分配空间，它的下一级是字符了，因此sizeof(char)，分配完后，每一个位置下（需要for循环）的字符串就有空间存储了，
而*strs里的char字符本身就有存储，不需要申请

***********************************************************************************************************************************/
    char **strs;
    strs = malloc(5*sizeof(char *));
    int strsSize = 0;
    int j;
    for( j = 0 ; j < 3 ; j++ )
        strs[j] = malloc(30*sizeof(char));

    printf("请输入字符串个数：\n");
    scanf("%d",&strsSize);

    printf("请输入您的字符串\n");

    for( i = 0 ; i < strsSize ; i++ )
        scanf("%s",strs[i]);

/***********************************************************************

**strs转换成二维数组后，在函数调用的时候就可以以二维数组的形式调用了

*************************************************************************/
    longestCommonPrefix(strs,strsSize);
    return 0;
}
