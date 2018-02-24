/**********************************************************************************************************

LeetCode----[easy] 2-ReverseInteger
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

[Ans:]
Complexity---O(n)
Method: using "/" and "%" cleverly
Author:tmw
date:2017-8-28

***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //head of INT_MIN && INT_MAX   INT_MIN = -INT_MAX-1(it is a expression)

int reverse(int x)
{
    int result = 0;
    int backNum = 0;

    while( x != 0 )
    {
        backNum = x % 10;
        if( result > (INT_MAX/10) ) //positive OverFlow
            return 0;
        if( result < (INT_MIN)/10 ) //negative OverFlow
            return 0;
        result = result*10 + backNum;
        x = x/10;
    }
    return result;
}

int main()
{
    int x = 0;
    int ans = 0;
    printf("Please input the number you wanna converse: ");
    scanf("%d",&x);
    ans = reverse(x);
    printf("The %d converse is %d\n",x,ans);
    return 0;
}
