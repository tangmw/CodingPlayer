/*******************************************************************************************
������������
����һ���ַ�����Ҫ���ַ���ǰ��������ַ��Ƶ��ַ�����β�������磺
���ַ�����abcdef����ǰ3���ַ�'a'��'b'��'c'�Ƶ��ַ�����β������ôԭ��
��������ɡ�defabc������дһ������ʵ�ִ˹���

˼·����ͨ��������ת�ķ���ʵ��
step1:��ԭ�ַ����ֳ������֣�һ�������ַ���ǰ��ġ������ַ���X����һ�����ǳ���X��Y
step2:��X�������ַ���ת����������˵�ģ���"abc"��ת��"cba"����"def"��ת��"fed"
step3:�������ַ���ȫ����ת--����"cbafed"��ת��"defabc"����ʵ�����ַ���ǰ�������ַ��ƶ���β��

ʱ�临�Ӷ�ΪO(n)

Author:tmw
date:2017-11-29
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(x,y,t) (t=x,x=y,y=t)
void rotate(char* array , int low , int high )
{
    int temp;
    while(low<high)
    {
        swap(array[low],array[high],temp);
        low++;
        high--;
    }
}
void three_steps_rotate(char* array , int rotate_part , int array_len )
{
    rotate(array,0,rotate_part-1);
    rotate(array,rotate_part,array_len-1);
    rotate(array,0,array_len-1);
}

int main()
{
    printf("���Դ���!\n");
    char a1[] = "abcdefghigk";
    printf("ԭ�ַ���Ϊ��%s\n",a1);
    three_steps_rotate(a1,3,strlen(a1));
    printf("��ת����ַ���Ϊ��%s\n",a1);

    char a2[] = "zhongkeyuanjisuansuo";
    printf("ԭ�ַ���Ϊ��%s\n",a2);
    three_steps_rotate(a2,4,strlen(a2));
    printf("��ת����ַ���Ϊ��%s\n",a2);

    return 0;
}
