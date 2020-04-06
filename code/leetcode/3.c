#include<stdio.h>

char s[8]="bbbbbbb";


int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
	int left=0;//left mark
	int len=0;//length
	int b[256];//ascll counts
	for(int i=0;i<256;i++)
		b[i]=0;
	for(int i=0;s[i]!=NULL;i++)
	{
		if(b[s[i]]==0||b[s[i]]<=left)
			len=max(len,i-left+1);
		else
			left=b[s[i]];
		b[s[i]]=i+1;
	}
	 // int left,len;//主串中左边标记和最长子串长度
  //   int T[256]={0};//ASCII码一共有256位并初始化
  //   int i;
  //   for(left=0,len=0,i=0;s[i]!=NULL;i++)
  //   {
  //       if(T[s[i]]==0||T[s[i]]<=left)
  //       {
  //           len=max(len,i-left+1);
  //       }
  //       else
  //       {
  //           left=T[s[i]];
  //       }
  //       T[s[i]]=i+1;
  //   }
	printf("%d\n",len);
	return 0;
}
