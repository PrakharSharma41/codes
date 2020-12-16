//    lowest common ancestor in a tree for any 2 nodes u and v.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5;
vector<int> adj[N];
int arr[N];
int depth[N];
int parent[N];

void dfs(int u,int f,int d)
{
	parent[u]=f;
	depth[u]=d;
	for(auto it:adj[u])
	{
		if(it!=f)
		dfs(it,u,d+1);
	}
}

int solve(int a,int b)
{
	while(a!=b)
	{
		if(depth[a]>depth[b])
		{
			a=parent[a];
		}
		else
		{			
			b=parent[b];
		}
	}
	return a;
}

int32_t main()
{
//	ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
	int t,n,q,i,x,y,a,b;
	cin>>t;
	while(t--)
	{
		cin >> n >> q;
		for (i = 1; i <= n; i++) {
//		  cin >> arr[i];
		  adj[i].clear();
		}
		for(i=1;i<n;i++)
		{
		  cin >> x >> y;
		  adj[x].push_back(y);
		  adj[y].push_back(x);
		}
		dfs(1,-1,0);
		while(q--)
		{
			  cin >> a >> b;
			  cout << solve(a, b) << "\n";			
		}
	}
	
	return 0;
}



