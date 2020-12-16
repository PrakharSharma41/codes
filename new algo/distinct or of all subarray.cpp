#include<iostream>
#include<bits/stdc++.h>
//#include<unordered_set>
using namespace std;
#define ll long long

// if number of elements are greater than 62 than or is not pairwise distinct

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll l,r,x,m,d,t,n,i,j,ans,k,b=0,c=0,rem,val;
	cin>>t;
	while(t--)
	{
		cin>>n;
	 	ll a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		unordered_set<ll> s;
		for(i=0; i<n; i++)
		{
			x=a[i];
			s.insert(x);
			for( j=i-1; j>=(max(b,i-62)); j--)
			{
				x= a[j] | x;
				s.insert(x);
			}
		}
		val=s.size();
		if(val==(n*(n+1))/2)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}

