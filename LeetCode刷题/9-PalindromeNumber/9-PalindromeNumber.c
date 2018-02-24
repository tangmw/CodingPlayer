/**********************************************************************************************************

LeetCode----[easy] 9-PalindromeNumber

Determine whether an integer is a palindrome. Do this without extra space.

[Ans:]
Complexity---O(n)
Method: using "/" and "%" cleverly
Author:tmw
date:2017-8-28

***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //bool type function
#include <math.h>  //pow(x,y) x^y

////method 1 ----apply for a new buffer
//bool isPalindrome(int x)
//{
//    int i = 0;
//    int j = 0;
//    char *temp;
//    int y = 0;
//    int k = 0;
//    int backNum = 0;
//    int index = 0;
//
//    y = x;
//    while( x != 0)
//    {
//        x = x/10;
//        i++;
//    }
//
//    printf("lenth i = %d\n",i);
//    temp = malloc( i*sizeof(char) );
//    while( j<i )
//    {
//        backNum = y%10;
//        index = i-j-1;
//        temp[index] = backNum;
//        j++;
//        y = y/10;
//        printf("temp[%d] = %d\n",index,backNum);
//    }
//
//    while( ( temp[k] == temp[j-k-1] ) && ( k < j ) )
//    {
//        k++;
//    }
//    printf("k = %d\n",k);
//    printf("j = %d\n",j);
//    if( k < j )
//    {
//        return false;
//        free(temp);
//    }
//
//    else
//    {
//        return true;
//        free(temp);
//    }
//
//}

//method 2---- not apply for a new buffer
bool isPalindrome(int x)
{
    int left = 0;
    int right = 0;
    int len = 0;
    int i = 0;
    int y=x/10;

    len++;
    while( y != 0 )
    {
        len++;
        y = y/10;
    }

    while( ( left == right ) && ( x/10 != 0 ) )
    {
        left = x * pow( 10 , ( -( len - i - 1 ) ) );
        right = x%10;
        x = x - left*pow( 10 , len - i - 1 ) - right;
        x = x/10;
        len--;
        i++;
    }
    if( left != right )
        return false;
    else
        return true;

}


int main()
{
    int x;
    int key = 0;
    printf("Please input the number x :");
    scanf("%d",&x);
    key = isPalindrome(x);
    if( key == false )
        printf("It is not a Palindrome!\n");
    else
        printf("It is a Palindrome!\n");
    return 0;
}
