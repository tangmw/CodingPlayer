#include <stdio.h>
#include <stdlib.h>

/**���������Ż�2--�Ż��ݹ����**/
//�ݹ����������һ��Ӱ��ģ���������β�������εݹ�������������������л��ּ��˲�ƽ�⣬
//�ݹ���Ƚ�������n��������ƽ��ʱ��logn����Ͳ��������ٶȿ����������ˣ�ջ�Ĵ�С�����޵ģ�
//ÿ�εݹ���ö���ķ�һ����ջ�ռ䣬�����Ĳ���Խ�࣬ÿ�εݹ�ķѵĿռ�ҲԽ�࣬��ˣ�����
//�ݹ�����������

//��������һ�ε�������ȡһ�εݹ�Ĵ��룬�˴�����Ҫ�Կ��ŵĵݹ鲿���޸ģ�����Ԫ�ص�ѡȡ��
//���򲿷ִ��������Ż�1������

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
    }//���ϣ�highλ�õ�Ԫ��Ϊ�����е����
    if( array[low] < array[mid] )
    {
        temp = array[low];
        array[low] = array[mid];
        array[mid] = temp;
    }//���ϣ�lowλ�õ�Ԫ��Ϊ�����еڶ���Ԫ��

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
    while( low < high )//�������ݹ飬�����if����while
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
    printf("����������Ԫ�صĸ���:\n");
    scanf("%d",&array_size);

    array = (int*)malloc(sizeof(int));
    printf("������ %d ��Ԫ��\n",array_size);
    for( i = 0 ; i < array_size ; i++ )
        scanf("%d",&array[i]);

    interate_replace_one_recursion_fastSort( array , 0 , array_size-1 );
    printf("�������򾭵ڶ����Ż�������Ԫ��˳�����Ϊ��\n");
    for( i = 0 ; i < array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}

