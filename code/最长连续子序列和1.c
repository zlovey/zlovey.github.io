//最长连续子序列和
//简单遍历O(n^2)

#include <stdio.h>

int main()
{
	 int sum,n;//最大值 
	 int A[10000];//数组
	 int tag1,tag2;
	 while(scanf("%d",&n)||n!=0)
	 {
	 	for(int i=0;i<n;i++)
	 		scanf("%d",&A[i]);
	 	sum=A[0];
	 	for(int i=0;i<n;i++)
	 	{
	 		int temp=0;
	 		for(int j=i;j<n;j++)
	 		{
	 			temp+=A[j];
	 			if(sum<temp)
	 			{
	 				sum=temp;
	 				tag1=i;
	 				tag2=j;
	 			}	
	 		}
	 	}
		printf("%d %d %d\n",sum,tag1,tag2);
	}
 	return 0;
}