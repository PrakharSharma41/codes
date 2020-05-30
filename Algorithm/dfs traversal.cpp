#include <bits/stdc++.h>
#include<iostream>
#include<vector>

vector<int>conju[100];

// dfs traversal
int dfs(int u,int f){depth[u]=depth[f]+1;size[u]=1;
	for (int i=0;i<conj[u].size();++i){
		if ((v=conj[u][i])==f)continue;
		size[u]+=dfs(v,u);
	}det[u]=size[u]-depth[u];return size[u];
}
int main(){

	scanf("%d%d",&n,&k);
	for (int i=1;i<n;++i){    // edge from u to v and from v to u
		scanf("%d%d",&u,&v);conj[u].push_back(v);conj[v].push_back(u);
	}dfs(1,0);
	return 0;
}
