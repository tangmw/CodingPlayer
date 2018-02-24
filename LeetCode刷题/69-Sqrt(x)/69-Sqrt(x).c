/**********************************************************************************************************

LeetCode----[easy] 69-sqrt(x)

Implement int sqrt(int x).
Compute and return the square root of x.

[Ans:]
Method1:µ÷ÓÃsqrt()

Author:tmw
date:2017-10-11

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int mySqrt(int x)
{
    if( x <= 0 )
        return 0;
    return (int)sqrt(x);
}
int main()
{
    int x;
    scanf("%d\n",x);
    mySqrt(x);
    return 0;
}
