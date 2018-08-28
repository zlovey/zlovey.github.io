//字符串查找
//KMP
//两个分开的函数
#include <stdio.h>
#include <string.h>
int* KMP(char* t, char* p) //t为主串，p为模式串
{
	int i,j,k;
	i=0;j=0;k=0;
	int r[100];//存储匹配成功的首地址
	int tlen=strlen(t);//主串和模式串的长度
	int plen=strlen(p);
	while(i<tlen&&j<plen)
	{
		if(j==-1||t[i]==p[j])//需要添加j==-1的情况，当next数组中的值为-1时，表示
			i++;j++;
		else
		{
			j=next[j];//模式串从next数组的记录值开始匹配
//i的位置不需要移动			i=i-j+1;//主串从与模式串开始匹配的下一个字符重新开始
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

void GetNext(char* p,int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  //遍历模式串
    {  
        //p[k]表示前缀，p[j]表示后缀  
        if (k == -1 || p[j] == p[k])   //k==-1为需要与首字符匹配的情况
        {  
            ++k;  //先++再赋值即为next，先赋值再++即为当前的前后缀最大公共元素长度
            ++j;  
            next[j] = k;  
        }  
        else 
            k = next[k];  //当前面有相同的字符而当前字符p[k]与p[j]不同时，可将k位置与j位置中间的字符视为空，将当前字符的next值赋为与next[k]相同。
    }  
}  