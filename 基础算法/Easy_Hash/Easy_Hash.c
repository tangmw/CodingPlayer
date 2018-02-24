/********************************************

Easy Hash----take remainder as index
Complexity---O(n)
Author:tmw
date:2017-8-25

*********************************************/

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
    printf("number %d in hash position is %d\n",number,position);
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
         //printf("%d in hashLink[%d], and it's position is %d\n",num,index,i);
         return i;
     }
     else
     {

         printf("The number %d is not exit in array!\n",num);
         return 0;
     }

     return 0;
 }

int main()
{
    int array_len = 0;
    int i = 0;
    int num = 0;
    int key = 0;

    printf("Please input array size!\n");
    scanf("%d",&array_len);

    int *nums;
    nums = malloc( array_len*sizeof(int) );
    printf("Please input the array elements:\n");
    for( i = 0 ; i < array_len ; i++ )
        scanf("%d",&nums[i]);

    init();
    hashInseart(nums,array_len);

    printf("Please input the num you wanna find..\n");
    scanf("%d",&num);

    key = hashFind(num);
    printf("The num you input is in hash %d position",key);
    return 0;
}
