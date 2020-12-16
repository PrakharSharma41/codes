#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
ll tree[500000],lazy[500000],a[500000];
// lazy propogation

void update(int node,int s,int e,int l,int r,int val){
	if(lazy[node]!=0){
		tree[node]+=(e-s+1)*lazy[node];
		if(s!=e){
			lazy[2*node+1]+=lazy[node];
			lazy[2*node+2]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(s>r ||e<l||s>e)
	return ;
	if(s>=l && e<=r){
		tree[node]+=(e-s+1)*val;
		if(s!=e){
			lazy[2*node+1]+=val;
			lazy[2*node+2]+=val;
		}
		return ;
	}
	int m=(s+e)/2;
	update(2*node+1,s,m,l,r,val);
	update(2*node+2,m+1,e,l,r,val);
	tree[node]=tree[2*node+1]+tree[2*node+2];
}

//void update(int node,int start,int end,int value,int pos)
//{
//    if(start==end)
//    {
//        a[pos]=value;
//        if(value%2==0)
//        tree[node]=1;
//        else
//        tree[node]=0;
//    }
//    else
//    {
//        int mid=(start+end)/2;
//        if(pos>=start&&pos<=mid)
//        update(2*node+1,start,mid,value,pos);
//        else
//        update(2*node+2,mid+1,end,value,pos);
//        tree[node]=tree[2*node+1]+tree[2*node+2];
//    }
//}

int query(int node,int s,int e,int l,int r){
	if(lazy[node]!=0){
		tree[node]+=(e-s+1)*lazy[node];
		if(s!=e){
			lazy[2*node+1]+=lazy[node];
			lazy[2*node+2]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(s>r ||e<l||s>e)
	return 0;
	if(s>=l&&e<=r)
	return tree[node];
	int m=(s+e)/2;
	int left=query(2*node+1,s,m,l,r);
	int right=query(2*node+2,m+1,e,l,r);
	return left+right;	
		
}
void build(ll node, ll s,ll e){
	if(s==e){
		if(a[s]%2==0)
		tree[node]=1;
		else
		tree[node]=0;
	}
	else{
        int mid = (s + e) / 2;
        build(2*node+1, s, mid);
        build(2*node+2, mid+1, e);
        tree[node] = tree[2*node+1] + tree[2*node+2];	
		cout<<node<<" "<<tree[node]<<"\n";	
	}
}

int32_t main()
{
	int t,n,j,k;
	t=1;
//	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=0;i<n;i++)cin>>a[i];
		ll q;
		build(0,0,n-1);
		cin>>q;
		ll c,x,y,ans;
		while(q--){
			cin>>c>>x>>y;
			if(c==0)
			update(0,0,n-1,x-1,y);
			else{
				if(c==1)
				    ans=query(0,0,n-1,x-1,y-1);
				else
				    ans=(y-x+1)-query(0,0,n-1,x-1,y-1);
				cout<<ans<<"\n";				
			}

		}
	}
	return 0;
}
include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
ll tree[500000],lazy[500000],a[500000];

void update(int node,int start,int end,int value,int pos)
{
    if(start==end)
    {
        a[pos]=value;
        if(value%2==0)
        tree[node]=1;
        else
        tree[node]=0;
    }
    else
    {
        int mid=(start+end)/2;
        if(pos>=start&&pos<=mid)
        update(2*node,start,mid,value,pos);
        else
        update(2*node+1,mid+1,end,value,pos);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int query(int node,int s,int e,int l,int r){
	if(s>r ||e<l||s>e)
	return 0;
	if(s>=l&&e<=r)
	return tree[node];
	int m=(s+e)/2;
	int left=query(2*node,s,m,l,r);
	int right=query(2*node+1,m+1,e,l,r);
	return left+right;	
		
}
void build(ll node, ll s,ll e){
	if(s==e){
		if(a[s]%2==0)
		tree[node]=1;
		else
		tree[node]=0;
	}
	else{
        int mid = (s + e) / 2;
        build(2*node, s, mid);
        build(2*node+1, mid+1, e);
        tree[node] = tree[2*node] + tree[2*node+1];		
	}
}

int32_t main()
{
	int t,n,j,k;
	t=1;
//	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=0;i<n;i++)cin>>a[i];
		ll q;
		build(1,1,n);
		cin>>q;
		ll c,x,y,ans;
		while(q--){
			cin>>c>>x>>y;
			if(c==0)
			update(1,1,n,x,y);
			else{
				if(c==1)
				    ans=query(1,1,n,x,y);
				else
				    ans=(y-x+1)-query(1,1,n,x,y);
				cout<<ans<<"\n";				
			}

		}
	}
	return 0;
}
