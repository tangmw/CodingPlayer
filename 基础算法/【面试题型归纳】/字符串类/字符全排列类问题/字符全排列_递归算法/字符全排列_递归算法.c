/*******************************************************************************************
������������
��ӡ�����ַ������������������
����
1) �����ַ�����abc�������ӡ������ȫ������ʽ��
abc acb bac bca cab cba

ע�⣺д�㷨ʱҪ���ǵ�����ͬԪ�ص������
�����ַ�����aab��������ȫ���д�ӡӦ��Ϊ aab aba baa

���ԣ���Ƶ��㷨Ӧ�ö����������������
********************************************************************************************/

/************************
Author:tmw
date:2017-11-9
************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**�ݹ��㷨ʵ��**/
//#define swap(x,y,t) (t=x,x=y,y=t)---�궨�巽��
void swap( char* array , int i , int j ) //---����ʵ�δ��ݷ���
{
    char temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
bool can_swap( char *array , int i , int left );
void char_all_permutate(char array[] , int left , int right )
{
    int i;
    if( left == right )
        printf("\t %s\n",array);

    for( i = left ; i <= right ; i++ )
    {
        if(can_swap(array,left,i))
        {
            swap(array,i,left);
            //��iλ���Ժ��Ԫ�ؽ���ȫ����,��˵ݹ�
            char_all_permutate(array,left+1,right);
            //������һ���ͬʱ�ָ���һ�����������Է�i���Ӻ󣬽����һ��swapʱ���ֺ�֮ǰ��ͬ��Ԫ�ص����ˣ���ӡ��ͬ�������
            //---����ʵ����iλ��Ԫ�����������Ĺ���
            swap(array,i,left);
        }
    }
}
//�����Ӻ�������ʵ�ֶ��ַ������ȫ���У������������Ԫ�������ظ���Ԫ�أ���ȫ�����㷨��ʧЧ
//��Ϊ���㷨û�ж�Ԫ���������ֺ��ٽ�������ˣ��Ż����㷨�ĵ����ڣ��Ż�swap����swap����һ��Ԫ�����ص��ж�

//Ԫ�ط��ظ�������true���ɽ���
bool can_swap( char *array , int left , int i )
{
    //����i��ʼλ����left��������жϴ�����������Ԫ���Ƿ���Ҫ����ʱӦ����i=left�����
    int kk = left;
    for( kk = left ; kk < i ; kk++)
        if( array[kk] == array[i] && i != kk )
            return false;
    return true;
}


int main()
{
    char array[] = "aaabb";
    printf(" %s ��ȫ����Ϊ��\n",array);
    char_all_permutate(array,0,strlen(array)-1);
    return 0;
}
