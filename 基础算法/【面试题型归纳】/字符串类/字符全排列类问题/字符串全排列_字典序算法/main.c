/*******************************************************************************************
������������
��ӡ�����ַ������������������

�ֵ��������㷨
��������ƫ��A��B,(a,b)��(a��,b��)���ڵѿ�����A��B�����ֵ�����Ϊ(a,b) �� (a��,b��) ���ҽ���a<a�� �� (a=a�� ��b��b��).
1����������������ȳ��ַ���������㿪ʼ�����Ƕ�Ӧ���ַ�����Ƚϣ����ȳ��ֽ�С�ַ����ַ����ֵ���С
2������������������ǵȳ��ַ���������ַ�һֱ��ȣ���϶��Ǹ��ַ������ֵ���С

���磺��abc������abcd������acde������adbc��
�ֵ����С��������Ϊ��"abc"����abcd������acde������adbc��

���ԣ�Ҫ������������ַ�����ȫ���У�������ֵ��������㷨���£�
�㷨��㣺�ҵ��ֵ�����С������1~n���硰12345��
step1:����������Ѱ�ַ����е�һ�γ��ֵݼ����е���λ�ַ�a[i];
step2:Ѱ��iλ�����ҵ��ַ��У���a[i]��������ַ�������С���ַ�����Ϊb[j];
step3:����a[i]��b[j]��
step4:�ѵ�i+1λ����󲿷ֵ��ַ���ת��ִ�д˲����i+1��n���ַ������������
�㷨�յ㣺�ҵ��ֵ�����������n~1���硰54321�����㷨����
********************************************************************************************/
/**�ֵ��������㷨ʵ��**/
/************************
Author:tmw
date:2017-11-12
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define swap(x,y,t) (t=x,x=y,y=t)
//�㷨��㣺��ͨ�����ҳ��Ѹ��ַ������ֵ�����С����
int first_ele_fast_sort( char* array , int low , int high )//ע��������ַ����Ŀ���  char
{
    int target = 0;
    target = array[low];//͵������ֱ���������еĵ�һ��Ԫ����Ϊ����Ԫ��

    while( low < high )
    {
        while( low < high && array[high] >= target  )
            high--;
        array[low] = array[high];//��ʱhighλ���ϵ�Ԫ��Ϊ������Ԫ��

        while( low < high && array[low] <= target   )
            low++;
        array[high] = array[low];//������targetֵ��Ԫ�طŵ��������highλ���ϣ���ô��ʱ,lowλ�ñ�Ϊ������
    }
    array[low] = target; //���ϣ�ʡȥ��������Ϊ���ڿӸ�ֵ��������ʱ�临�Ӷ�
    return low;
}
char* fast_sort( char* array , int low , int high )
{
    if( low < high )
    {
        int index;
        index = first_ele_fast_sort(array,low,high);
        fast_sort(array,low,index-1);
        fast_sort(array,index+1,high);
    }
    return array;
}

void reverse( char* array , int start , int end )
{
    while( start < end )
    {
        char temp;
        swap(array[start],array[end],temp);
        start++;
        end--;
    }
}

//�ֵ��������㷨----�ҵ��ȵ�ǰ�����ֵ����1��������
bool dictionary_sort( char* array , int array_len )
{
    //step1:����������Ѱ�ַ����е�һ�γ��ֵݼ����е���λ�ַ�a[i]
    int i = 0;
    int j = 0;
    for( i = array_len - 2 ; (i >= 0) && array[i] >= array[i+1] ; i-- );//��ʱiλ���ϵ�Ԫ��array[i]��ΪĿ��Ԫ��a

    if( i < 0 )//˵����ʱ�Ѿ�������ֵ�����
        return false;

    //step2:Ѱ��iλ�����ҵ��ַ��У���a[i]��������ַ�������С���ַ�����Ϊb[j];
    for( j = array_len-1 ; ( j > i ) && array[j] <= array[i] ; j-- );
    //forѭ���󣬾��ҵ��˵ڶ���Ŀ��Ԫ��b---array[j]

    //step3:����a[i]��b[j]
    char temp;
    swap(array[j],array[i],temp);

    //step4:�ѵ�i+1λ����󲿷ֵ��ַ���ת
    reverse(array,i+1,array_len-1);
    return true;
}

/**�ֵ���ȫ����--�ҳ������ַ������ֵ����С�����ҳ�ȫ����**/
void dictionary_full_sort(char* array , int array_len )
{
    int i = 1;
    array = fast_sort(array,0,array_len-1);//�ȿ��ţ��ҳ���С�ֵ�����
    printf("\tcase #%d \t%s\n",i,array);
    while(dictionary_sort(array,array_len))
        printf("\tcase #%d \t%s\n",++i,array);
}


int main()
{
    char array[] = "aaabb";
    printf("%s ��ȫ����Ϊ��\n",array);
    dictionary_full_sort(array,strlen(array));
    return 0;
}
