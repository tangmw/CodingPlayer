/*******************************************************************************************
【问题描述】
给定一个字符串，要求将字符串前面的若干字符移到字符串的尾部。例如：
将字符串“abcdef”的前3个字符'a'、'b'和'c'移到字符串的尾部，那么原字
符串将变成“defabc”，请写一个函数实现此功能

思路：可通过三步翻转的方法实现
step1:将原字符串分成两部分，一部分是字符串前面的“若干字符”X，另一部分是除了X的Y
step2:将X的所有字符翻转，即上面所说的，将"abc"翻转成"cba"，将"def"翻转成"fed"
step3:将整个字符串全部翻转--即将"cbafed"翻转成"defabc"。即实现了字符串前面若干字符移动到尾部

时间复杂度为O(n)

Author:tmw
date:2017-11-29
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(x,y,t) (t=x,x=y,y=t)
void rotate(char* array , int low , int high )
{
    int temp;
    while(low<high)
    {
        swap(array[low],array[high],temp);
        low++;
        high--;
    }
}
void three_steps_rotate(char* array , int rotate_part , int array_len )
{
    rotate(array,0,rotate_part-1);
    rotate(array,rotate_part,array_len-1);
    rotate(array,0,array_len-1);
}

int main()
{
    printf("测试代码!\n");
    char a1[] = "abcdefghigk";
    printf("原字符串为：%s\n",a1);
    three_steps_rotate(a1,3,strlen(a1));
    printf("旋转后的字符串为：%s\n",a1);

    char a2[] = "zhongkeyuanjisuansuo";
    printf("原字符串为：%s\n",a2);
    three_steps_rotate(a2,4,strlen(a2));
    printf("旋转后的字符串为：%s\n",a2);

    return 0;
}
