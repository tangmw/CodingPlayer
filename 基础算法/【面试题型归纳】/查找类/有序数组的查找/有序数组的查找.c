/***********************************************
������������
����һ���ź�������飬����ĳ�����Ƿ������������

����˼·����������������ģ�����ɿ��Ƕ��ֲ��ң�ע�����midֵ����������

Author:tmw
date:2018-2-23
************************************************/
#include <stdio.h>
#include <stdlib.h>

/**�����Ķ��ֲ���**/
int binary_search(int array[] , int array_number , int target_data )
{
    int left = 0;
    int right = array_number - 1;

    while(left<=right)
    {
        int mid = left + ( right - left ) / 2;

        if( target_data > array[mid] ) //Ŀ��ֵ�����м�ֵ����˵�����м�ֵ���Ҳ���--���leftֵ
            left = mid + 1;
        else if( target_data < array[mid]) //Ŀ��ֵС���м�ֵ��˵�����м�ֵ�������--���rightֵ
            right = mid - 1;
        else
            return mid;
    }
    return -1; //û���ҵ��򷵻�-1
}


int main()
{
    printf("���Դ���\n");

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
