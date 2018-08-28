//最长公共子串
//动态规划

#include <stdio.h>
int LCS(int A[],int B[],int n,int m)//算法数组以1为开始计数
{
	int i,j;
	int L[100][100];//最长公共子序列长度数组
	int res=0;
	for(i=1;i<n;i++)
		for(j=1;j<m;j++)
		{
			if(i==0||j==0)
				L[i][j]=0;
			else if(A[i]==B[j])
			{
				L[i][j]=L[i-1][j-1]+1;
				res=max(L[i][j],res);
			}
		}
 	return L[n][m];
}
