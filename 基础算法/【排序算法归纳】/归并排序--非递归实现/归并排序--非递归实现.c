#include <stdio.h>
#include <stdlib.h>


void merge( int array[] , int left , int middle , int right )
{
    int left_len = middle - left;
    int right_len = right - middle - 1;
    int left_array[left_len];
    int right_array[right_len];
    int i,j,k;

    //����ժ��������������
    for( i = 0 ; i <= left_len ; i++ )
        left_array[i] = array[i+left];

    for( j = 0 ; j <= right_len ; j++)
        right_array[j] = array[j+middle+1];

    //�������������б��һ����������
    //ע�⣺��Ϊ�����������һֱ�Ƕ�array����ĵݹ飬���������ʼ�����Ƕ�array������У�
    //array����Ԫ�ص�λ�ñ仯����������array����������ñ�ı�������!!!
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
    for( k = 1 ; k < array_len ; k = k*2 )//��2*k��Ϊ����
    {
        int i = 1;
        //int j;
        while( i <= array_len-2*k+1 )
        {
            merge(array,i,i+k-1,i+2*k-1);
            i = i+2*k;
        }
        /**��array_lenΪ�������ʱ����Ҫ�������һ�����ŵ�Ԫ��**/
        if( i < array_len-k+1 )//�����һ��Ԫ����ǰż�����鲢�õ�Ԫ�����鲢��һ������
            merge(array,i,i+k-1,array_len);
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
    for( i = 1 ; i <= array_size ; i++ )
        scanf("%d",&array[i]);

    merge_sort_interate( array ,array_size );
    printf("���鲢���������Ԫ��˳�����Ϊ��\n");
    for( i = 1 ; i <= array_size ; i++ )
        printf("%d ",array[i]);
    return 0;
}

