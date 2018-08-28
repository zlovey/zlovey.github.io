//最长公共子序列
//动态规划

#include <stdio.h>
int LCS(int A[],int B[],int n,int m)//算法数组以1为开始计数
{
	int i,j;
	int L[100][100];//最长公共子序列长度数组
	for(i=0;i<n;i++)
	{
		L[i][0]=0;//当i=0或j=0时长度为0
		L[0][i]=0;
	}
	for(i=1;i<n;i++)
		for(j=1;j<m;j++)
		{
			if(A[i]==B[j])
				L[i][j]=L[i-1][j-1]+1;
			else
				L[i][j]=max(L[i][j-1],L[i-1][j]);
		}
 	return L[n][m];
}
