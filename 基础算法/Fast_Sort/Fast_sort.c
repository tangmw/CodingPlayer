/********************************************

FastSorting----full the dig and recursive
Complexity---O(nlogn)
Author:tmw
date:2017-8-23

*********************************************/

#include <stdio.h>
#include <stdlib.h>

void fastSort( int array[] , int l , int r )
{
    int key = 0;
    int i = 0;
    int j = 0;

    key = array[l]; // digging

    i = l;  // set i be the left index
    j = r;  // set j be the right index

    while( ( i < j ) )
    {
        //right first
        while( ( array[j] >= key ) && ( i < j ))
            j--;
        if( i < j )  // array[j] < key
        {
            array[i] = array[j]; //fill dig
            i++;
        }//then array[j] be the dig

        //left next
        while( ( array[i] < key ) && ( i < j ) )
            i++;
        if( i < j )
        {
            array[j] = array[i];
            j--;
        }
    }
    //break: j == i
    array[i] = key;

    //the i be the critical point
    //recursive
    if( l < r )  //recurse end condition
    {
        fastSort(array,l,i-1);
        fastSort(array,i+1,r);
    }
    else
        return;
}

int main()
{
    int *array;
    int array_len = 0;
    int i = 0;
    int k = 0;

    printf("Please input the length of array:");
    scanf("%d",&array_len);

    //malloc array according to input length
    array = malloc( array_len*sizeof( int ) );

    printf("Please input your array member [member must be integer] !\n");
    for(i = 0 ; i < array_len ; i++)
    {
        scanf("%d", &array[i] );
    }
    fastSort(array,0,array_len-1);

    //print the result array
    printf("Sorting result is:");
    for( k = 0 ; k < array_len ; k++ )
    {
        printf("%d  ",array[k]);
    }
    printf("\n");
    return 0;
}
