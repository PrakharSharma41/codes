#include<bits/stdc++.h>
using namespace std;
int recursion(int start,int end,int x,int a[]);
int main()
{
	int i=0,n;
	cout << "Enter size of array\n";
	cin >> n;
	int x,a[n+1],start=1,end=n,flag=0,mid;
	for(i=1;i<=n;i++)
	cin >> a[i];
	cout << "enter value to find";
	cin >> x;
	flag=recursion(start,end,x,a);
//	while(start<=end)
//	{
//	    mid=(start+end)/2;
//		if(a[mid]> x)
//			end-=1;
//		else if(a[mid]< x)
//			start+=1;
//		else
//		{
//			flag=1;break;
//		}
//	}
	if(flag==1)
	cout << "number has been found at "<<mid;
	return 0;
}
int recursion(int start,int end,int x,int a[]){
	int mid=(start+end)/2;
	if(start==end)
	return 0;
	if(a[mid]> x)
		recursion(start,(end-1),x,a);
	else if(a[mid]< x)
		recursion((start+1),end,x,a);
	else
	{
		return 1;
	}	
}



















