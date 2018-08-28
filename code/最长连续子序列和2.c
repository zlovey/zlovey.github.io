//最长连续子序列和
//分治O(nlogn)

#include <stdio.h>
int count(int left,int right);
int A[10000];//数组
int main()
{
	int sum,n;//最大值 
	scanf("%d",&n);
	for(int i=1;i<n+1;i++)//以1开头，可以保证后面分割的时候尽可能靠近中心
		scanf("%d",&A[i]);
	sum=count(1,n); 	
	printf("%d\n",sum);
 	return 0;
}

int count(int left,int right)  //仅记录left和right，将数组A设置为全局变量
{
	if(left==right)//长度为1时
		return A[left];//返回当前值
	int mid=(left+right)>>1;//计算中间分割点

	int i=count(mid+1,right);//右边部分
	int j=count(left,mid);//左边部分
	//（3）情况
	int temp=0,sum1=A[mid+1],sum2=A[mid];
	//sum1和sum2的起始值必须为左右两端不同的起始值，且注意相互对应！不能同时取中值，会导致重复取中值的错误！
	for(int k=mid+1;k<=right;k++)//取右边的最大值
	{
		temp+=A[k];
		if(temp>sum1)
			sum1=temp;
	}
	temp=0;
	for(int k=mid;k>=left;k--)//取左边的最大值
	{
		temp+=A[k];
		if(temp>sum2)
			sum2=temp;
	}
	temp=sum1+sum2;

	if(i>temp) temp= i;//直接进行比较即可，不用写max函数
	else if(j>temp) temp=j;
	return temp;
}