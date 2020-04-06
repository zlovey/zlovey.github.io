//字符串查找
//暴力匹配

#include <stdio.h>
#include <string.h>
int* ViolentMatch(char* t, char* p) //t为主串，p为模式串
{
	int i,j,k;
	i=0;j=0;k=0;
	int r[100];//存储匹配成功的首地址
	int tlen=strlen(t);//主串和模式串的长度
	int plen=strlen(p);
	while(i<tlen&&j<plen)
	{
		if(t[i]==p[j])
			i++;j++;
		else
		{
			j=0;//模式串从头开始匹配
			i=i-j+1;//主串从与模式串开始匹配的下一个字符重新开始
		}
		if(j==plen)//匹配成功
		{
			r[k]=i-j;//存入
			k++;
		}
		else r[k]=-1;
	}
	return r;
}
