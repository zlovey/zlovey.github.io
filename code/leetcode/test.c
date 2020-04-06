//二分搜索(已排序)

s[]
int search(int low,int high,int num)
{
	int mid=(high-low)/2
	if(s[mid]<num)
	{
		low=mid+1;
	}
	else
	{
		high=mid-1;
	}
	search(low,high,num);

}