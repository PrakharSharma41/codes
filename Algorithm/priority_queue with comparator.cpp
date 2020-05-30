#include<iostream>
using namespace std;

#include<bits/stdc++.h>
#define int long long
class compare{
	public:
	bool operator()(pair<int,pair<int,int> >p1,pair<int,pair<int,int> >p2)
	{

		if(p1.first>p2.first)
		return false;
		else if(p1.first==p2.first)
		{
			if(p1.second.first<p2.second.first)
			return false;
			else
			return true;	
		}
		else
		return true;	
	} 	
};


int32_t main()
{

	int i,t,n,k,l,r,z;
	cin>>t;
	
	while(t--)
	{
		cin>>n;int a[n+1]={0};
    	priority_queue <pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > > ,compare> mp; 
		if(n%2==0)
		{
			a[n/2]=1;
			mp.push(make_pair(n/2,make_pair(n/2+1,n)));
			mp.push(make_pair(n/2-1,make_pair(1,n/2-1)));
			
		}
		
		else
		{
			a[n/2+1]=1;
			mp.push(make_pair(n/2,make_pair(n/2+2,n)));
			mp.push(make_pair(n/2,make_pair(1,n/2)));
			
		}
		for(int i=2;i<=n;i++)
		{
			if(!mp.empty())
			{
				l=mp.top().second.first;
				r=mp.top().second.second;		
				mp.pop();	
			}
			else
				break;
			if((r-l+1)%2==0)
			{
				a[(l+r-1)/2]=i;z=(l+r-1)/2;
				if(r-z>0)
					mp.push(make_pair(r-z,make_pair(z+1,r)));
				if(z-l>0)
					mp.push(make_pair(z-l,make_pair(l,z-1)));							
			}
			else
			{
				a[(l+r)/2]=i;z=(l+r)/2;
				if(r-z>0)
				mp.push(make_pair(r-z,make_pair(z+1,r)));
				if(z-l>0)
				mp.push(make_pair(z-l,make_pair(l,z-1)));
			}
		}
		for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
		cout<<"\n";
	}
	return 0;
}

