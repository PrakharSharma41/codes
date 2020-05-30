#include<iostream>
#include <bits/stdc++.h> 
#include<map>
using namespace std;

int main()
{
	int t,i,n,x,y;
//	cin>>t;
//	while(t--)
//	{
		cin >>n >>x >>y;int a[n],b[n],count=0,maxv,x1=x,y1=y;
		multimap<int,int> one,two;
	//	char cv;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		for(i=0;i<n;i++)
		{
			one.insert(pair <int, int> (a[i],b[i]));
			two.insert(pair <int, int> (b[i], a[i]));
	//		one[a[i]]=b[i];
	//		two[b[i]]=a[i];
		}
	
		multimap<int, int>::reverse_iterator itr;
		for(itr = two.rbegin(); itr != two.rend(); itr++)
		{
	
			if(((itr->first) > (itr->second))&&y1>0)
			{
				count+=(itr->first);y1--;
				
			}
			else if(((itr->first) > (itr->second))&&y1<=0)
			{
				count+=itr->second;x1--;
			}
			else if(((itr->first) < (itr->second))&&x1>0)
			{
				count+=itr->second;x1--;
			}
			else
			{
				count+=itr->first;y1--;
			}
		}
//		cout <<"count is "<<count<<endl;
		maxv=count;count=0;
	//	
		for(itr = one.rbegin(); itr != one.rend(); itr++)
		{
			if(((itr->first) > (itr->second))&&x>0)
			{
				count+=itr->first;x--;
			}
			else if(((itr->first) > (itr->second))&&x<=0)
			{
				count+=itr->second;y--;
			}
			else if(((itr->first) < (itr->second))&&y>0)
			{
				count+=itr->second;y--;
			}
			else
			{
				count+=itr->first;x--;
			}
		}
		maxv=maxv>count?maxv:count;
		cout <<maxv<<"\n";		
//	}
	return 0;
}
