// binary search in rotated array
// an sorted array is given while it is rotated by some position(unknown)
// see errichto's video
// leetcode week 3
// use array 4 5 6 7 8 9 1 2 3 to check
#include<iostream>
using namespace std;
int main()
{
	int low=0,high=n-1;
	int first=a[0];
	// target is value to search for in array
	while(low<high)
	{
		int mid=(low+high)/2;
		int value=a[mid];
		if(value==target)
		return mid;
		bool big=value>=first;
		bool targ=target>=first;
		if(big==targ)
		{
			if(target>value)
				low=mid+1;
			else
				high=mid-1;
		}
		else
		{
			if(big)
				low=mid+1;
			else
				high=mid-1;
		}
	}
		
	return -1;
}
