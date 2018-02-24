/*******************************************************************************************
【问题描述】
输入一个由数字组成的字符串，把它转换成整数并输出。

编写代码前，应结合题意考虑以下几点：
输入参数合法性验证
1）题目有说字符串由数字组成，但没说清楚数字之间是否有空格---（空格在这里视为非法字符）
2）输入是否为空串
特殊情况讨论
3）字符串的正负性
4）转换成整数后，是否会造成溢出

在实际考虑中，笔者曾想到过两种方法，一种是从前往后遍历还原整数，一种是从后往前遍历还原整数，
但是后来经过实际编程，笔者发现由于输入的字符串可能会有不定数目的空格，从后往前遍历公式会受
到空格的干扰而出错，笔者黔驴技穷也没法更好解决此问题的方式，处于代码的简洁易读，笔者推荐采
用从前往后遍历还原方法解决此类问题。

Author:tmw
date:2017-11-13
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <math.h>


///**从前往后遍历还原**/
int string2int_begin2end(char* array)
{
    //空串检查
    if(strlen(array) == 0)
        return 0;

    //正负性检查&&空格滤除
    int i = 0;
    while( array[i] == ' ' )//空格滤除
        i++;
    if(i==strlen(array)-1)
        return 0;//

    int signo = 1;//signo = 1表示负数
    if( array[i] == '+')
        signo = 0;//signo = 0表示正数
    i++;

    int number = 0;
    int sum = 0;
    while( array[i] != ' ' && i < strlen(array) )//滤除数字之间的空格，开始转换，转换中考虑溢出
    {
        number = array[i] - '0';
        if( ( signo == 0 && sum > INT_MAX/10 ) || ( sum > INT_MAX/10 && number >= INT_MAX%10 ) )//正数处理
        {
            sum = INT_MAX;
            break;
        }
        if( ( signo == 1 && sum > (unsigned)INT_MIN/10 ) || ( sum > (unsigned)INT_MIN/10 && number >= (unsigned)INT_MIN%10 ) )//负数处理
        {
            sum = INT_MIN;
            break;
        }

        sum = sum*10 + number;//为防止在这一步sum会溢出程序错误运算，需在这之前进行溢出检查
        i++;
    }
    return signo==0?sum:-sum;
}





int main()
{
    printf("代码测试\n");
    char a1[] = "";
    printf("%s转换成整数为:%d\n",a1,string2int_begin2end(a1));

    char a2[] = "   ";
    printf("%s转换成整数为:%d\n",a2,string2int_begin2end(a2));

    char a3[] = "  +452365  ";
    printf("%s转换成整数为:%d\n",a3,string2int_begin2end(a3));

    char a4[] = "   -2343 ";
    printf("%s转换成整数为:%d\n",a4,string2int_begin2end(a4));

    char a5[] = "  +10522545459 ";
    printf("%s转换成整数为:%d\n",a5,string2int_begin2end(a5));

    char a6[] = "  -10522545459 ";
    printf("%s转换成整数为:%d\n",a6,string2int_begin2end(a6));

    printf("INT_MAX = %d\n",INT_MAX);
    printf("INT_MIN = %d\n",INT_MIN);

    return 0;
}
