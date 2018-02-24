/***********************************************
【问题描述】
有一个长度为2n的数组{a1,a2,a3,...an,b1,b2,b3,...,bn},希望排序后变成{a1,b1,a2,b2,...,an,bn}，
请考虑有没有时间复杂度为O(n)，空间复杂度为O(1)的解法

位置置换法已经很聪明很厉害了，它拥有了“先知”的能力，将时间复杂度降到了O(n)，空间复杂度主要浪费在
用另外一个数组转存了结果，那么有没有一种方法不需要用其他数组空间转存直接在原数组中进行操作，使它
的空间复杂度降到O(1)呢？答案是有的！

在位置置换法的前提下，我们知道了当前数组中任意元素经“洗牌”后将放置的位置，以数组[a1,a2,a3,a4,b1,b2,b3,b4]
为例，设定下标从1开始存起，则各元素的下标走向为：
1->2->4->8->7->5->1
3->6->3
这竟然是个圈！！这让笔者想到了在树结构中，寻找祖先的一个很重要的find函数！
那么问题就变成了：
如何从表达式(2*i)%(2*n+1)中找到在这2*n个数中，存在多少个圈？以及各个圈的首个位置呢？
假设在已知圈首个位置的前提下，实现此算法的名字为CycleLeader()

高能预警！！接下来引入一个非常重要的神级公式：
若2*n = 3^k-1，则它有k个圈，且每个圈头部的起始位置分别是：1,3,9,...,3^(k-1)

这里牵涉到的数学逻辑不多说了，详细参考july《编程之法》P62-67

但是，如果我们的n不满足上面的式子，又该如何找每个圈的头部元素位置和有多少个圈呢？则采用分治法
先让一部分的长度满足上述结论：若2*m=3^k-1，则恰好有k个圈，且每个圈头部的起始位置分别是：1,3,9,...,3^(k-1)
。其中m<n，这m个元素往神级公式上靠，剩下的n-m个元素单独计算
如此分法，原始数组对应的下标如下：
1,2,3,...,m,m+1,m+2,...,n,n+1,n+2,...,n+m,n+m+1,...,2*n-1,2*n，由于神级结论是要凑2*m个数的，而原始数组又是a1~an,b1~bn,因此
a1~am对应的是b1~bm，所以转化成数组下标就是需要先将n+1,n+2,...,n+m位置的元素和m+1,m+2,...,n位置的元素交换，使得
1,2,3,...,m和n+1,n+2,...,n+m对应的a1~am，b1~bm元素凑成满足神级公式的2*m，即实现一个字符串的旋转操作

而在之前的算法积累中，有一种3步反转法可以实现复杂度为O(n)的字符串旋转操作
即：
step1:将原字符串分成两部分，一部分是字符串前面的“若干字符”X，另一部分是除了X的Y
step2:将X的所有字符翻转，即将"abc"翻转成"cba"，将"def"翻转成"fed"
step3:将整个字符串全部翻转--即将"cbafed"翻转成"defabc"。即实现了字符串前面若干字符移动到尾部

如此，便将2*n中满足神级结论的2*m个元素的圈数和圈首位置解决，接下来就继续利用神级公式，把问题规模一步步减小，最终完全解决


完美洗牌算法步骤如下：
输入：数组array[1,...,2*n]
step1:找到最大满足2*m=3^k-1的m，为保证m最大，用数学表达式约束：3^k<=2*n<3^(k-1)
step2:将1,2,3,...,m,m+1,m+2,...,n,n+1,n+2,...,n+m,n+m+1,...,2*n-1,2*n中的m+1,m+2,...,n与n+1,n+2,...,n+m进行3步翻转，即将m+1,m+2,...,n右移m位
step3:对这2m长度的数组，它有k个圈，每个圈的起始位置为1,3，...3^(k-1)，使用CycleLeader()算法，先将满足神级公式的2m个元素归位
step4:对array数组后面的m+1,m+2,...,n,n+m+1,...,2*n-1,2*n继续使用此算法，走step1,2,3，每次数组完成2*m个元素的归位

完美洗牌算法完成后，数组变成[b1,a1,b2,a2,...,bn,an]，再用两两交换--时间复杂度同样为O(n)形成最终的[a1,b1,a2,b2,...,an,bn]

时间复杂度O(n),空间复杂度O(1)----完美！
Author:tmw
date:2017-11-28
************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,t) (t=x,x=y,y=t)

/**沿着圈找元素的下一个位置**/
//因为n可能不满足神级公式，因此(2*i)%(2*n+1)中的除数需要传参
void CycleLeader(int* array , int leader_position , int mod )
{
    int from = leader_position;
    int temp;
    for(from = (leader_position*2)%mod;from!=leader_position;from = (2*from)%mod )
        swap(array[leader_position],array[from],temp);
    //每次，将圈首位置作为待交换区，分别与(2*from)%mod位置上的元素做交换
}
/**3步翻转算法**/
void rotate(int* array , int low , int high )
{
    int temp;
    while(low<high)
    {
        swap(array[low],array[high],temp);
        low++;
        high--;
    }
}
void three_steps_rotate(int* array , int rotate_num , int array_len )
{
    rotate(array,1,array_len-rotate_num);//前部分翻转
    rotate(array,array_len-rotate_num+1,array_len);//后部分翻转
    rotate(array,1,array_len);//整体翻转
}

void perfect_shuffle( int* array , int n )
{
    while(n>1)
    {
        /*第一步：寻找最大满足2*m=3^k-1的m：用数学表达式约束：3^k<=2*n<3^(k-1)*/
        int k,m;
        for(k=0,m=1;(2*n/m)>=3;k++,m=m*3);
        m = m/2; //找到了k和m

        /*第二步：将m+1,m+2,...,n与n+1,n+2,...,n+m进行3步翻转,向右移m位*/
        three_steps_rotate(array+m,m,n);//向右移m位，总共有n个元素：n+m-n-1+n-m+1=n

        /*第三步：对这2m长度的数组，它有k个圈，每个圈的起始位置为1,3，...3^(k-1)，使用CycleLeader()算法*/
        int i,leader_position;
        for(i=1,leader_position=1;i<=k;i++,leader_position = leader_position*3)
            CycleLeader(array,leader_position,2*m+1);

        /*第四步：对array数组后面的m+1,m+2,...,n,n+m+1,...,2*n-1,2*n继续使用此算法*/
        array = array + 2*m;//array指针右移
        n = n-m;
    }
    //n==1
    int t = array[1];
    array[1] = array[2];
    array[2] = t;
}

int main()
{
    printf("测试程序!\n");
    int i;

    int array[11] ={0,1,2,3,4,5,11,22,33,44,55};//数组元素从1号位置开始起效
    printf("原数组为：");
    for(i=1;i<11;i++)
        printf("%d ",array[i]);
    printf("\n");

    perfect_shuffle(array,5);

    printf("洗牌后的数组为：");
    for(i=1;i<11;i++)
        printf("%d ",array[i]);
    printf("\n");

    return 0;
}
