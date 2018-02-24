/***********************************************
������������
����һ�����������һ���������������в���һ�������������ǵĺ�����������
���Ǹ�����������ж�����ĺ͵���������������������һ�Լ��ɡ�

�ⷨ����
�������������ģ����Կ��ǰ������ų�����ģ�����������ĺ󣬱��кü��ַ���
�����ҵ���͵��ڸ�����������������
����������ص��Ƽ�����бƵķ������㷨���£�
�㷨׼�����ÿ������򣬽���������������
step1:�趨�����α�begin��end,�ֱ�ָ�������ͷ��β
step2:���ĳһʱ�̣�array[begin]+array[end]>sum����begin������end--,��Сarray[begin]+array[end]��ֵ
step3:���ĳһʱ�̣�array[begin]+array[end]<sum����end������begin++,����array[begin]+array[end]��ֵ
�㷨��������array[begin]+array[end]==sumʱ������array[begin]��array[end]��ֵ���㷨��������begin==end
��array[begin]+array[end]!=sum��˵��������û�к�Ϊsum�������������ش���

Author:tmw
date:2017-11-19
************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t)

//��������Ԫ��ѡȡ--����ȡ����ģ��
int median3(int *array , int low , int high )
{
    int mid = ( low + high ) / 2;
    int temp;
    if( array[high] < array[mid] )
        swap( array[high] , array[mid] , temp );
    if( array[high] < array[low] )
        swap( array[high] , array[low] , temp );
    //���ϣ���֤array[high]Ϊ�����е����ֵ
    if( array[low] < array[mid] )
        swap( array[low] , array[mid] , temp );
    //���ϣ���֤array[low]Ϊ�����е��м�ֵ
    return array[low];
}
//һ�ο���
int fast_sort_using_median3(int *array , int low , int high )
{
    array[low] = median3(array,low,high);

    int target = array[low];//����Ԫ�ر���

    while( low < high )
    {
        while( low < high && array[high] >= target  )
            high--;
        array[low] = array[high];

        while( low < high && array[low] <= target   )
            low++;
        array[high] = array[low];
    }
    array[low] = target;
    return low;
}
//����Ԫ�ؿ���
int* fast_sort_all(int *array , int low , int high)
{
    if( low < high )
    {
        int mid_index;
        mid_index = fast_sort_using_median3(array,low,high);
        fast_sort_all(array,0,mid_index-1);
        fast_sort_all(array,mid_index+1,high);
    }
    return array;
}

//����б����㷨
void TowSum_Sort_and_Aproach(int *array , int array_len , int sum )
{
    int begin = 0;
    int end = array_len - 1;
    array = fast_sort_all(array,0,array_len - 1);//�����������������

    while( begin < end )
    {
        if( array[begin] + array[end] == sum )
        {
            printf("%d + %d = %d\n",array[begin],array[end],sum);
            //begin++;
            //end--;
            break;//���Ҫ���������������������������ԣ��򽫴�breakע�⣬��begin++;end--��ע
        }
        else
        {
            if( array[begin] + array[end] > sum )//array[begin]+array[end]>sum����begin������end--
                end--;
            else//array[begin]+array[end]<sum����end������begin++
                begin++;
        }
    }
    if(begin == end)
        printf("������û�к�Ϊ %d ��������\n",sum);
}


int main()
{
    printf("���Դ���\n");
    int i;
    int sum = 15;

    int a[12] = {1,2,4,5,7,11,54,3,8,6,10,13};
    for(i=0;i<12;i++)
        printf("%d ",a[i]);
    printf("\n");
    TowSum_Sort_and_Aproach(a,12,sum);

    int b[15] = {3,4,2,10,5,0,12,13,8,9,16,17,20,1,6};
    for(i=0;i<15;i++)
        printf("%d ",b[i]);
    printf("\n");
    TowSum_Sort_and_Aproach(b,15,sum);

    return 0;
}

