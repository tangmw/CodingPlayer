/**********************************************************************************************************

LeetCode----[easy] 1-TwoSum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

[Ans:]
Complexity---O(n)
Method: easy hash method
Author:tmw
date:2017-8-25

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define hashsize 10
typedef struct hashNode
{
    int num;
    struct hashNode *next;
}hashNode;
struct hashNode hashLink[hashsize];


/*initial hashList*/
void init()
{
    int i = 0;
    for( i = 0 ; i < hashsize ; i++ )
    {
        hashLink[i].num = i;
        hashLink[i].next = NULL;
    }
}

/*hash function:: find the position in hashLink*/
int hash( int number )
{
    int position = 0;
    position = number % hashsize;  //set remainder as the serial number
    //printf("number %d in hash position is %d\n",number,position);
    return position;
}
 /*insert number in hashList*/
void hashInseart( int array[] , int numsSize )
 {
     int i = 0;
     int j;
     int temp = 0;
     int num = 0;
     hashNode *p;

     for( i = 0 ; i < numsSize ; i++ )
     {
         j = 0;
         temp = array[i];
         num = hash(temp);
         while( hashLink[j].num != num )
             j++;

         p = (struct hashNode *)malloc(sizeof(struct hashNode));
         if( p == NULL )
         {
             printf("memory allocate wrong!\n");
             return;
         }

         p->num = temp;
         //head inseart method
         p->next = hashLink[j].next;
         hashLink[j].next = p;
     }
 }

 int hashFind( int num )
 {
     int index = 0;
     int i = 0;
     index = hash(num);

     hashNode *find;

     find = hashLink[index].next;

     while( ( find->num != num ) && ( find != NULL ) )
     {
         find = find->next;
         i++;
     }
     if( find->num == num )
     {
         //printf("The number %d is in the array!\n",find->num);
         return num;
     }
     else
     {

         printf("The number %d is not exit in array!\n",num);
         return 0;
     }

     //return 0;
 }

int twoSum(int array[], int numsSize, int target)
{
    int i = 0;
    int j;
    int key = 0;
    int findData = 0;
    int *temp;

    temp = malloc( numsSize*sizeof(int) );
    for( j = 0 ; j < numsSize ; j++ )
        temp[j] = array[j];

    hashInseart(array,numsSize);
    while( i < numsSize )
    {
        j = 0;
        findData = target - temp[i];
        key = hashFind(findData);
        if( key == findData )
        {
            while( temp[j] != key )
                j++;
            printf("Target %d= %d+%d , so the final answer is [%d,%d]\n",target,temp[i],temp[j],i,j);
            return 0;
        }
        else
            i++;
    }
    printf("Sorry,there is no answer...\n");
    return 0;
}


int main()
{
    int i = 0;
    int *testArray;
    int array_len = 0;
    int target = 0;
    init();

    printf("Please input your array length:\n");
    scanf("%d",&array_len);

    testArray = malloc( array_len*sizeof(int) );
    printf("Please input your array elements:\n");
    for( i = 0 ; i < array_len ; i++ )
    {
        scanf("%d", &testArray[i]);
    }

    printf("Please input your target number:\n");
    scanf("%d",&target);

    twoSum(testArray,array_len,target);
    return 0;
}
