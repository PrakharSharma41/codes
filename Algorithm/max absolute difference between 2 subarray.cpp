//         max absolute difference between 2 subarray from i to j and k to l
//               given that 1<=i<=j<k<=l<=n

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,n,i,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;long long int a[n],left[n+1][2],right[n+1][2],k=0;ans=0;
		for(i=0;i<n;i++)
			cin>>a[i];
		left[0][0] = a[0];
		left[0][1] = a[0];		
		for(i=1;i<n;i++)
		{
			left[i][0]=max(left[i-1][0],k)+a[i];
			left[i][1]=min(left[i-1][1],k)+a[i];
		}
		right[n-1][0] = a[n-1];
		right[n-1][1] = a[n-1];		
		for(i=n-2;i>=0;i--)
		{
			right[i][0]=max(right[i+1][0],k)+a[i];
			right[i][1]=min(right[i+1][1],k)+a[i];
		}
		for(i=0;i<n-1;i++)
		{
			
			ans=max(ans,abs(left[i][0]-right[i+1][1]));
			ans=max(ans,abs(left[i][1]-right[i+1][0]));
		}
		cout <<ans<<"\n";
	}
	return 0;
}
