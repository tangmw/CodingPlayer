/*******************************************************************************************
������������
���������ַ���a��b��һ��һ�̣���ο����ж϶��ַ���b������Ԫ�ض��ڳ��ַ���a�У�
��������ַ����е�Ԫ�ض�Ϊ��д��ĸ
����
1) a = ��ABCD��,b = ��DBA��,����true
2) a = "ABCD",b = "AAD",����true
3) a = "ABCD",b = "BCE",����false
********************************************************************************************/

/************************
Author:tmw
date:2017-11-6
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
����һ������+����
step 1: ��a��bʹ�ÿ��ų�Ϊ�������У����Ӷ�o(nlogn)
step 2: b��Ԫ����aƥ�䣬ƥ��ɹ��򷵻�false,���Ӷ�O(m+n)

ps:���������ֱ��ƥ�䣬�������в����������ÿһ��ƥ�䶼Ҫ��a�������һ�Σ����Ӷ�O(n*m)
**/
int first_ele_fast_sort( char array[] , int low , int high )//ע��������ַ����Ŀ���  char
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
void fast_sort( char array[] , int low , int high )
{
    if( low < high )
    {
        int index;
        index = first_ele_fast_sort(array,low,high);
        fast_sort(array,low,index-1);
        fast_sort(array,index+1,high);
    }
}
bool string_contain( char a[] , int a_len , char b[] , int b_len )//a b��Ϊ�ַ���
{
    fast_sort(a,0,a_len-1);//�ַ���a����
    fast_sort(b,0,b_len-1);//�ַ���b����

    int a_index,b_index;
    for( b_index = 0 , a_index = 0 ; b_index < b_len ; b_index++ )//b��a���һ�飬����bΪ��ѭ��
    {
        while( a_index < a_len && a[a_index] < b[b_index] )//a,b��Ϊ����
            a_index++;
        if( a_index >= a_len || a[a_index] > b[b_index] )
            return false;//b������һ��Ԫ����ѯa��û�ҵ�ƥ�䣬��ֱ��return false  ����������ȥ��--���͸��Ӷ�
    }
    return true;
}

int main()
{
    int a_len,b_len;
    char* a;
    char* b;
    printf("������a���鳤��\n");
    scanf("%d",&a_len);
    a = (char*)malloc(a_len*sizeof(char));

    printf("������b���鳤��\n");
    scanf("%d",&b_len);
    b = (char*)malloc(b_len*sizeof(char));

    printf("�����볤�ַ���aԪ�أ�");
    //char ch;
    //while( ch = getchar() != '\n');
    scanf("%s",a);
    //while( ch = getchar() != '\n');
    printf("��������ַ���bԪ�أ�");
    scanf("%s",b);
    printf("%d\n",string_contain(a,a_len,b,b_len));
    if(string_contain(a,a_len,b,b_len))
        printf("a����b������Ԫ�أ�\n");
    else
        printf("a������b��\n");
    return 0;
}
