/***********************************************
【问题描述】
给定一个排好序的数组，查找某个数是否在这个数组中

解题思路：由于数组是有序的，因而可考虑二分查找，注意避免mid值溢出情况即可

Author:tmw
date:2018-2-23
************************************************/
#include <stdio.h>
#include <stdlib.h>

/**有序表的二分查找**/
int binary_search(int array[] , int array_number , int target_data )
{
    int left = 0;
    int right = array_number - 1;

    while(left<=right)
    {
        int mid = left + ( right - left ) / 2;

        if( target_data > array[mid] ) //目标值大于中间值，则说明在中间值以右查找--变更left值
            left = mid + 1;
        else if( target_data < array[mid]) //目标值小于中间值，说明在中间值以左查找--变更right值
            right = mid - 1;
        else
            return mid;
    }
    return -1; //没查找到则返回-1
}


int main()
{
    printf("测试代码\n");

    int array1[11] = {1,2,3,4,5,6,7,8,9,10};
    int array2[22] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200};

    int i;
    for(i=0;i<10;i++)
        printf("%d ",array1[i]);

    printf("\n");

    for(i=0;i<20;i++)
        printf("%d ",array2[i]);

    printf("\n");

    int ret1 = binary_search(array1,10,5);
    printf("%d \n",ret1);
    int ret2 = binary_search(array2,20,5);
    printf("%d \n",ret2);
    int ret3 = binary_search(array2,20,100);
    printf("%d \n",ret3);




    return 0;
}
