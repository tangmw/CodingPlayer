#include <stdio.h>
#include <stdlib.h>

/**快速排序优化2--优化递归操作**/
//递归对性能是有一定影响的，快排在其尾部有两次递归操作，如果待排序的序列划分极端不平衡，
//递归深度将趋近于n，而不是平衡时的logn。这就不仅仅是速度快慢的问题了，栈的大小是有限的，
//每次递归调用都会耗费一定的栈空间，函数的参数越多，每次递归耗费的空间也越多，因此，减少
//递归会大大提高性能

//下面是用一次迭代来换取一次递归的代码，此代码主要对快排的递归部分修改，中轴元素的选取和
//排序部分代码沿用优化1方案的

int Three_choose_one_optimize_fastSort( int array[] , int low , int high )
{
    int mid = ( low + high ) / 2;
    int temp;
    if( array[low] > array[high] )
    {
        temp = array[low];
        array[low] = array[high];
        array[high] = temp;
    }
    if( array[mid] > array[high] )
    {
        temp = array[high];
        array[high] = array[mid];
        array[mid] = temp;
    }//以上，high位置的元素为三者中的最大
    if( array[low] < array[mid] )
    {
        temp = array[low];
        array[low] = array[mid];
        array[mid] = temp;
    }//以上，low位置的元素为三者中第二大元素

    int target = array[low];
    while( low < high )
    {
        while( low < high && array[high] > target )
            high--;
        array[low] = array[high];

        while( low < high && array[low] < target )
            low++;
        array[high] = array[low];
    }
    array[low] = target;
    return low;
}

void interate_replace_one_recursion_fastSort( int array[] , int low , int high )
{
    int index;
    while( low < high )//迭代换递归，这里从if换成while
    {
        index = Three_choose_one_optimize_fastSort(array,low,high);

        interate_replace_one_recursion_fastSort(array,low,index-1);
        low = index+1;
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
    for( i = 0 ; i < array_size ; i++ )
        scanf("%d",&array[i]);

    interate_replace_one_recursion_fastSort( array , 0 , array_size-1 );
    printf("快速排序经第二次优化后，数组元素顺序输出为：\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}

