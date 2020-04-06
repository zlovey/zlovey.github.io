//4. Median of Two Sorted Arrays
// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// You may assume nums1 and nums2 cannot be both empty.
#include <stdio.h>

int nums1[2]={1,2};
int nums2[2]={3,4};
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);
int main()
{
	double me=findMedianSortedArrays(nums1,2,nums2  ,2);
	printf("%f\n",me); 
	return 0;
}
// //way1
// double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//     int s[10000];//合并两个数组O(m+n)不合题意
//     int i,j,k;
//     k=0;
//     for(i=0,j=0;i<nums1Size&&j<nums2Size;)
//     {
//     	if(nums1[i]<nums2[j])
//     	{
//     		s[k]=nums1[i];
//     		k++;i++;
//     	}
//     	else
//     	{
//     		s[k]=nums2[j];
//     		k++;j++;
//     	}
//     }
//     if(i==nums1Size)
//     {
//     	for(;j<nums2Size;j++,k++)
//     		s[k]=nums2[j];
//     }
//     else if(j==nums2Size)
//     {
//     	for(;i<nums1Size;i++,k++)
//     		s[k]=nums1[i];
//     }

//     for(k=0;k<(nums2Size+nums1Size);k++)
//     	printf("%d\n",s[k]);

//     printf("\n");

//     if((nums2Size+nums1Size)%2)//奇数取中间数
//     {
//     	return s[(nums2Size+nums1Size)/2];
//     }
//     else                  //偶数取中间两数平均数
//     	return (s[(nums2Size+nums1Size)/2-1]+s[(nums2Size+nums1Size)/2])/2;
// }



//way2  O(log(m+n))
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    //二分
    if((nums2Size+nums1Size)%2)//奇数取中间数
    {
    	return search(low,high,(nums2Size+nums1Size)/2);
    }
    else                  //偶数取中间两数平均数
    {
    	double t1=(double)search(low,high,(nums2Size+nums1Size)/2-1);
    	double t2=(double)search(low,high,(nums2Size+nums1Size)/2);
    	return (t1+t2)/2;
    } 
}


int search(int* nums1, int nums1Size, int* nums2, int nums2Size,int pos)//寻找合并后pos位置的值；pos为合并后需要寻找的位置
{
	int j,k;
	j=nums1Size/2;
	k=nums2Size;
	

	if (m > n) return findKth(nums2, nums1, pos);//保证s1比s2短
       if (m == 0) return nums2[pos - 1];
       if (pos == 1) return min(nums1[0], nums2[0]);
       int i = min(m, pos / 2), j = min(n, pos / 2);
       if (nums1[i - 1] > nums2[j - 1]) {
           return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), pos - j);
       } else {
           return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, pos - i);
       }

}









    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return (findKth(nums1, nums2, (m + n + 1) / 2) + findKth(nums1, nums2, (m + n + 2) / 2)) / 2.0;
    }
    int findKth(vector<int> nums1, vector<int> nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findKth(nums2, nums1, k);
        if (m == 0) return nums2[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);
        int i = min(m, k / 2), j = min(n, k / 2);
        if (nums1[i - 1] > nums2[j - 1]) {
            return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
        } else {
            return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
        }
        return 0;
    }