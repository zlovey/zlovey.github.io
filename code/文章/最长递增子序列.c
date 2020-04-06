//最长递增子序列
//动态规划O(n^2)

#include <stdio.h>
int main()
{
	int n;//最大值 
	int A[1000],L[1000]={1};//每个以自身作为末尾的最长递增子序列长度至少为1
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

	for(int j=0;j<n;j++)
		L[j]=1;

	for(int j=1;j<n;j++)//遍历，可以直接从第二个数开始，默认第一个数L数列为1
	{
		for(int i=0;i<j;i++)
		{
			if(A[i]<A[j]&&L[j]<L[i]+1)//注意第二个条件，取最大的L序列而过滤其他序列
				L[j]=L[i]+1;
		}
	}
	int max=0;
	for(int j=0;j<n;j++)
	{
		if(max<L[j])
			max=L[j];
	}
	printf("%d\n",max);
 	return 0;
}
