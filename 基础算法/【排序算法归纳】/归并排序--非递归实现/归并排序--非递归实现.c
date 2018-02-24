#include <stdio.h>
#include <stdlib.h>


void merge( int array[] , int left , int middle , int right )
{
    int left_len = middle - left;
    int right_len = right - middle - 1;
    int left_array[left_len];
    int right_array[right_len];
    int i,j,k;

    //单独摘出两个有序序列
    for( i = 0 ; i <= left_len ; i++ )
        left_array[i] = array[i+left];

    for( j = 0 ; j <= right_len ; j++)
        right_array[j] = array[j+middle+1];

    //将两个有序序列变成一个有序序列
    //注意：因为后面的排序函数一直是对array数组的递归，因此排序至始至终是对array数组进行，
    //array数组元素的位置变化必须体现在array数组里，不能用别的变量代替!!!
    k = left;
    i = 0;j = 0;
    while( i <= left_len && j <= right_len )
    {
        if( left_array[i] < right_array[j] )
            array[k++] = left_array[i++];
        else
            array[k++] = right_array[j++];
    }
    while( i <= left_len )
        array[k++] = left_array[i++];
    while( j <= right_len )
        array[k++] = right_array[j++];
}

void merge_sort_interate( int array[] , int array_len )
{
    int k;
    for( k = 1 ; k < array_len ; k = k*2 )//以2*k作为步进
    {
        int i = 1;
        //int j;
        while( i <= array_len-2*k+1 )
        {
            merge(array,i,i+k-1,i+2*k-1);
            i = i+2*k;
        }
        /**当array_len为奇数情况时，需要考虑最后一个单着的元素**/
        if( i < array_len-k+1 )//将最后一个元素与前偶数个归并好的元素最后归并成一个序列
            merge(array,i,i+k-1,array_len);
    }
}

int main()
{
    int *array;
    int i,array_size;
    printf("请输入数组元素的个数:\n");
    scanf("%d",&array_size);

    array = (int*)malloc(sizeof(int));
    printf("请输入 %d 个元素\n",array_size);
    for( i = 1 ; i <= array_size ; i++ )
        scanf("%d",&array[i]);

    merge_sort_interate( array ,array_size );
    printf("经归并排序后，数组元素顺序输出为：\n");
    for( i = 1 ; i <= array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}

