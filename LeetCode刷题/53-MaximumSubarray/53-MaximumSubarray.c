/**********************************************************************************************************

LeetCode----[easy] 53-MaximumSubarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

[Ans:] http://www.cnblogs.com/boring09/p/4252780.html
Method:
������һ����̬�滮�� ��̬�滮���ο���http://www.cnblogs.com/boring09/p/4252780.html
                                         http://www.cnblogs.com/bourbon/archive/2011/08/23/2151044.html
��sum[i]��ʾ��i��ʼ������Ӵ��ͣ����е��ƹ�ʽ��sum[i] = max{A[i], A[i] + sum[i+1]}
��Ϊ����ʽֻ�õ��˺�һ������ڱ���ʵ�ֵ�ʱ����Խ���״̬ѹ������һ����������
ʱ�临�Ӷ�O(n)

������˼·��
1������ֲ����ֵsum��ȫ�����ֵmaxSum����ʼֵ��Ϊ�����һ��ֵ
2���ֲ����ֵ���������ڣ��ж���ǰԪ��ֵ�ܷ������֮ǰԪ�ع��ɵļ��ϣ�����
    a������ǰԪ��ֵС�ڽ���Ԫ�ط���֮ǰԪ�ع��ɵļ���֮��ĺ�ֵ���򽫴�Ԫ�ؼ��뼯�ϣ��ֲ����ֵ����Ϊ�¼���֮��
    b������ǰԪ��ֵ���ڽ���Ԫ�ط���֮ǰԪ�ع��ɵļ���֮��ĺ�ֵ���򽫾ֲ����ֵ����Ϊ��ǰԪ��ֵ������֮ǰ�ļ��ϣ�
    ��Ϊ�ӵ�ǰԪ�ؿ�ʼ�ļ��ϡ�
3��ȫ�����ֵʼ�ռ�¼�ֲ����ֵ�仯�����ֵ������������մ�

��������������������
1��������λ��0����������˳��ݼӺ󣬺�ֵ�����ֵ
2��������λ��1����������˳��ݼӺ󣬺�ֵ��ǰ�������ֵ����Ϊ����������������ֵ�Ÿ��£�
......
n��ֱ���������������һ��λ��numSize-1 ����ֵ��ǰnumSize�ֵ����ֵ�����������մ�

�������������η���
1�����Ƚ���ֳ�����A[l..m]��A[m+1..r]������m=(l+r)/2�����ֱ���ݹ���������������Ӵ��ͣ�������Ϊleft��right
2��A[l..r]�������Ӵ��Ϳ��ܳ��������ߣ���left�������߿��ܳ������Ұ�ߣ���right���������ܳ����ں����������ĵط�
3�����շ���һ�����м�������ɨ�������ֵ��

��ô������η�����Ҫ�������� ��С�˷���һ��ɨ�跶Χ

ʱ�临�Ӷ�O(nlogn)

Author:tmw
date:2017-9-18~9-21

***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/******************************************
������һ����̬�滮��----���Ӷ�O(n)
*******************************************/
//int max( int a , int b )
//{
//    a = (b > a ? b : a);
//    return a;
//}
//
//int maxSubArray(int* nums, int numsSize)
//{
//    int sum = nums[0];
//    int maxSum = sum;
//    int index = 0;
//    int index_mark = 0;
//    int temp;
//
//    /***�����㷨�ĺ���****/
//    for( index = 1 ; index < numsSize ; index++ )
//    {
//        sum = max( nums[index] , sum + nums[index] );
//        temp = maxSum;//��¼maxSum�仯ǰ��ֵ
//        maxSum = max( sum , maxSum );
//        if( temp != maxSum )//��¼��maxSumΪ���ʱ����λ���ֵ��±�
//            index_mark++;
//    }
//
//    /***���´��������ҵ���maxSum����λ�����±���ҳ���ΪmaxSum������Ԫ�ز���ӡ****/
//    index_mark--;
//    int j = index_mark;
//    int sum1 = 0;
//    while( sum1 != maxSum )
//    {
//        sum1 = sum1 + nums[j];
//        j++;
//    }
//    j--;
//    printf("the answer array index range is [%d-%d]\n",index_mark,j);
//    printf("the specific answer is: -----  ");
//    for(index = index_mark ; index <= j ; index++ )
//        printf("%d ",nums[index]);
//    printf("\n");
//    return maxSum;
//}
/******************************************
��������������������----���Ӷ�O(n^2)
*******************************************/
//int maxSubArray(int* nums, int numsSize)
//{
//    int max = INT_MIN;
//    int i,j,sum;
//
//    for( i = 0 ; i < numsSize ; i++ )
//    {
//        sum = 0;
//        for( j = i ; j < numsSize ; j++)
//        {
//            sum = nums[j] + sum;
//            if( sum > max )
//                max = sum;
//        }
//        printf("��%d�����ֵΪ:%d \n",i,max);
//    }
//    return max;
//}

/******************************************
�������������η���----���Ӷ�O(nlogn))
*******************************************/
int max( int a , int b )
{
    a = (b > a ? b : a);
    return a;
}
//������η��Ӻ���
int dividConquer( int *nums , int l , int r )
{
    int middle,left,right;//�洢���С���ֵ�ı���
    int m;//�м�ֵ���±�
    int i,j,temp,result;

    if( l == r )
        return nums[l];//ȷ�����α߽�

    m = ( l + r ) / 2;
    middle = nums[m];
    left = dividConquer( nums , l , m );
    right = dividConquer( nums , m+1 , r );

    //���middle��ֵ���Կ���һ�����ϰ����̲���ֵ����ֵ��
    //���ݹ���е�r = l+1ʱ��middle��¼��ֵ��ֻ������ֵ�����µ�����ֵ��Ҫô��ԭλ��m�ϵ�ֵ��Ҫô������ֵ�ĺ�ֵ������ȡֻ�������������µ����ֵ��
    //���Կ����жϣ���������ֵ�Ӵ������������ֵ�ʱ��middle��¼����Ҫô����ԭλ��m�ϵ�ֵ�����֧�����Ұ�֧�ĺ�ֵ��Ҫô������ԭλ��m�µ�ֵ���������֧���Ұ�֧���ص����ֵ
    //����ע�⣬middle��������������ֵ����Ϊ�����������ѭ����ʱ�򣬷��ص�ֵ��
    //1������mλ���µ�ֵ
    //2��mλ���µ�ֵ�����֧���Ұ�֧�ĺ�ֵ
    //3��mλ���µ�ֵ�����Ұ�֧�ܺ�ֵ
    //��������µ����ֵ����֮middle��ֵ�ǰ���mλ���µ�ֵ������ֵ��������𰸿����ǲ�����mλ���µ�ֵ�����������֧���ֵҲ�������ҷ�֧���ֵ�����
    //result = max( max(left , right ) , middle );�����������ֵҪô����mλ���µ�ֵ��Ҫô������mλ���µ�ֵ��ȡ��߻��ұߣ���һ���¡�
    for( i = m-1 , temp = middle ; i >= l ; i-- )
    {
        temp = nums[i] + temp;
        middle = max( temp , middle );
    }

    for( j = m+1 , temp = middle ; j <= r ; j++ )
    {
        temp = nums[j] + temp;
        middle = max( temp , middle );
    }

    result = max( max(left , right ) , middle );
    return result;
}

int maxSubArray(int* nums, int numsSize)
{
    return dividConquer( nums , 0 , numsSize - 1 );;
}

int main()
{
    printf("���Դ���!\n");
    int i;

    int a1[8] = {1,-2,3,10,-4,7,2,-5};
    int result1 = maxSubArray(a1,8);
    printf("ԭ����Ϊ��");
    for(i = 0 ; i < 8 ; i++ )
        printf("%d ",a1[i]);
    printf("����������Ϊ %d\n",result1);

    int a2[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int result2 = maxSubArray(a2,9);
    printf("ԭ����Ϊ��");
    for(i = 0 ; i < 9 ; i++ )
        printf("%d ",a2[i]);
    printf("����������Ϊ %d\n",result2);

    return 0;
}
