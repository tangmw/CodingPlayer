/**********************************************************************************************************

LeetCode----[easy] 13-RomantoInteger

Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

[Ans:]
Method: switch/case ; learn the roman rules...
Author:tmw
date:2017-8-30

***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanchange(char ch) //define the key exchange number first
{
    switch(ch)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int romanToInt(char* s)
{
    int len = 0;
    int i = 0;
    int before = 0;
    int next = 0;
    int result = 0;

    len = strlen(s);
    if( len == 0 )
        return 0;   //s is empty

    while( s[i] != '\0')
    {
        before = romanchange( s[i] );
        next = romanchange( s[i+1] );

        if( before < next )
        {
            result = result + next - before;
            i = i + 2;
        }
        else
        {
            result = result + before;
            i = i + 1;
        }

    }
    return result;
}



int main()
{
    char s[20];
    int result = 0;
    printf("Please input your Roman number:\n");
    scanf("%s",s);
    result = romanToInt(s);
    printf("The Roman number '%s' to Int number is %d\n",s,result);
    return 0;
}
