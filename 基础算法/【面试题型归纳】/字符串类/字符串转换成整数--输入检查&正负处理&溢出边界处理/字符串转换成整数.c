/*******************************************************************************************
������������
����һ����������ɵ��ַ���������ת���������������

��д����ǰ��Ӧ������⿼�����¼��㣺
��������Ϸ�����֤
1����Ŀ��˵�ַ�����������ɣ���û˵�������֮���Ƿ��пո�---���ո���������Ϊ�Ƿ��ַ���
2�������Ƿ�Ϊ�մ�
�����������
3���ַ�����������
4��ת�����������Ƿ��������

��ʵ�ʿ����У��������뵽�����ַ�����һ���Ǵ�ǰ���������ԭ������һ���ǴӺ���ǰ������ԭ������
���Ǻ�������ʵ�ʱ�̣����߷�������������ַ������ܻ��в�����Ŀ�Ŀո񣬴Ӻ���ǰ������ʽ����
���ո�ĸ��Ŷ���������ǭ¿����Ҳû�����ý��������ķ�ʽ�����ڴ���ļ���׶��������Ƽ���
�ô�ǰ���������ԭ��������������⡣

Author:tmw
date:2017-11-13
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <math.h>


///**��ǰ���������ԭ**/
int string2int_begin2end(char* array)
{
    //�մ����
    if(strlen(array) == 0)
        return 0;

    //�����Լ��&&�ո��˳�
    int i = 0;
    while( array[i] == ' ' )//�ո��˳�
        i++;
    if(i==strlen(array)-1)
        return 0;//

    int signo = 1;//signo = 1��ʾ����
    if( array[i] == '+')
        signo = 0;//signo = 0��ʾ����
    i++;

    int number = 0;
    int sum = 0;
    while( array[i] != ' ' && i < strlen(array) )//�˳�����֮��Ŀո񣬿�ʼת����ת���п������
    {
        number = array[i] - '0';
        if( ( signo == 0 && sum > INT_MAX/10 ) || ( sum > INT_MAX/10 && number >= INT_MAX%10 ) )//��������
        {
            sum = INT_MAX;
            break;
        }
        if( ( signo == 1 && sum > (unsigned)INT_MIN/10 ) || ( sum > (unsigned)INT_MIN/10 && number >= (unsigned)INT_MIN%10 ) )//��������
        {
            sum = INT_MIN;
            break;
        }

        sum = sum*10 + number;//Ϊ��ֹ����һ��sum���������������㣬������֮ǰ����������
        i++;
    }
    return signo==0?sum:-sum;
}





int main()
{
    printf("�������\n");
    char a1[] = "";
    printf("%sת��������Ϊ:%d\n",a1,string2int_begin2end(a1));

    char a2[] = "   ";
    printf("%sת��������Ϊ:%d\n",a2,string2int_begin2end(a2));

    char a3[] = "  +452365  ";
    printf("%sת��������Ϊ:%d\n",a3,string2int_begin2end(a3));

    char a4[] = "   -2343 ";
    printf("%sת��������Ϊ:%d\n",a4,string2int_begin2end(a4));

    char a5[] = "  +10522545459 ";
    printf("%sת��������Ϊ:%d\n",a5,string2int_begin2end(a5));

    char a6[] = "  -10522545459 ";
    printf("%sת��������Ϊ:%d\n",a6,string2int_begin2end(a6));

    printf("INT_MAX = %d\n",INT_MAX);
    printf("INT_MIN = %d\n",INT_MIN);

    return 0;
}
