/***********************************************
������������
��һ��m��n�еĶ�ά�����У�ÿһ�ж����մ����ҵ�����˳�����У�
ÿһ�ж����մ��ϵ��µ�����˳�����С�������������һ����ά�����
һ�������������һ���������ж��������Ƿ��и�����key�����������
����ʾ��ά���飬����ÿһ��ÿһ�ж����������������������в�
����6���򷵻�true�����������5���򷵻�false


1   2   8   9
2   4   9   12
4   7   10  13
6   8   11  15


���ⷨ����λ��
���������к��ж������Ķ�ά��������Ͼ��󣬸��ݾ����ص㣬�ɰ����·�����⣺
1�����Ƚ���㶨λ����ά�����һ�����һ�е�Ԫ�أ��Ӹ�Ԫ�ؿ�ʼ����
2��������Ԫ�ر�key���������ߣ����ǵ����ģ�
3��������Ԫ�ر�keyС���������ߣ����ǵ����ģ�

�÷�����ʱ�临�Ӷ�ΪO(m+n)������m��n�ֱ�Ϊ��ά������к���

Author:tmw
date:2018-2-23
************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 4
#define COL 4

bool PositionMethod_of_YangMartrix(int array[][COL],int key)
{
    //��ʼ�����в���
    int i = 0;
    int j = COL-1;
    int val = array[i][j];  //valֵΪ���λ�ã�ָ���һ�����һ�е�Ԫ��

    while(1)
    {
        if( val < key && i < ROW - 1) //keyֵ����˵��Ӧ��������----i��--ע��i��Խ��
            val = array[++i][j]; //����valֵ

        else if( val > key && j > 0)//keyֵ��С��˵��Ӧ��������----jֵ��--ע��j��Խ��
            val = array[i][--j];

        else if( val == key )
            return true;

        else
            return false;
    }
}





int main()
{
    printf("���Դ���\n");

    int array[][4] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};

    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",array[i][j]);
        printf("\n");
    }

    int res1 = PositionMethod_of_YangMartrix(array,6);
    int res2 = PositionMethod_of_YangMartrix(array,5);

    printf("\n");

    printf("%d \n",res1);
    printf("%d \n",res2);


    return 0;
}
