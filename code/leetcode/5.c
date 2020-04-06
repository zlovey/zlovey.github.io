//5. Longest Palindromic Substring
//根据回文定义正向遍历=逆向遍历

#include<stdio.h>
#include<string.h>


char* Reverse(char* s);
int main()
{
	char s[1000]="abcbaba";

	for(int i=0;i<strlen(s);i++)
	{
		str
	}
	char *p=Reverse(s);
	if(strcmp(s,p)==0)
		return 1;
	else return 0;
}
// char* longestPalindrome(char* s) {
    
// }

char* Reverse(char* s){
	int n=strlen(s);
	char t[1000]={0};
	int j=n-1;
	for(int i=0;i<n;i++)
	{
		t[j-i]=s[i];
	}
	// printf("%s\n",t);
	return t;
}