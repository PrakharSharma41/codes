//https://www.quora.com/What-is-the-approach-for-solving-GSS1-and-GSS3-on-SPOJ-using-segment-trees
 // code to find max sum in a range using segment trees
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxisum[200000];
int sum[200000];
int maxlsum[200000];
int maxrsum[200000];
int a[50000];
// 0 for left 1 for right 2 for both
void sets(int node,int val)
{
	sum[node]=val;maxrsum[node]=val;maxlsum[node]=val;maxisum[node]=val;
}
void calc(int node)
{
	
	sum[node]=sum[2*node]+sum[2*node+1];
	maxlsum[node]=max(sum[2*node]+maxlsum[2*node+1],maxlsum[2*node]);
	maxrsum[node]=max(maxrsum[2*node+1],sum[2*node+1]+maxrsum[2*node]);
	maxisum[node]=max(max(maxisum[2*node],maxisum[2*node+1]),maxrsum[2*node]+maxlsum[2*node+1]);
}

void build(int node,int start,int end,int a[])
{
	if(start==end)
	sets(node,a[start]);
	else
	{
		int mid=(start+end)/2;
		build(2*node,start,mid,a);
		build(2*node+1,mid+1,end,a);
		calc(node);
	}
}
void update(int node,int start,int end,int idx,int a[],int value)
{
	if(start==end)
	{
		a[idx]=value;
		sets(node,value);
	}
	else
	{
		int mid=(start+end)/2;
		if(idx<mid)
		update(2*node,start,mid,idx,a,value);
		else
		update(2*node+1,mid+1,end,idx,a,value);
		calc(node);
	}
}

void query_rec(int node,int start,int end,int l,int r,vector<int>& nodes)
{
    if(start>r || end<l)
        return ;
	if(l<=start&&r>=end)
	nodes.push_back(node);
	else
	{
		int mid=(start+end)/2;
//		if(mid>=l&&start<=r)
		query_rec(2*node,start,mid,l,r,nodes);
//		if(r>=mid&&l<=end)
		query_rec(2*node+1,mid+1,end,l,r,nodes);
	}
}

int query(int l,int r,int n)
{
	vector<int> nodes;
	query_rec(1,1,n,l,r,nodes);
	int z=nodes.size(),res=-2e9,t=-2e9;
	for(int i=0;i<z;i++)
	{
		res=max(res,maxisum[nodes[i]]);
		res=max(res,t+maxlsum[nodes[i]]);
		t=max(t+sum[nodes[i]],maxrsum[nodes[i]]);
	}
	return res;
}

int32_t main()
{
    int i,n,q,x,y;
//    cout<<"asda\n";
    cin>>n;

    for(i=1;i<=n;i++)
    cin>>a[i];
    // char c;
    build(1,1,n,a);
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        cout<<query(x,y,n)<<"\n";
    }
    return 0;
}

