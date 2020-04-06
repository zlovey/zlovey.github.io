//最长连续子序列和
//动态规划O(n)

#include <stdio.h>
int main()
{
	int n;//最大值 
	int A[1000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	int sum=0;
	int temp=0;
	for(int i=0;i<n;i++)//遍历
	{
		temp+=A[i];//从数组开始计算
		if(temp>sum)//若取得更大的值则替换
			sum=temp;
		else if(temp<0)//一旦有小于零的序列则将temp置为0
			temp=0;
	}
	printf("%d\n",sum);
 	return 0;
}
