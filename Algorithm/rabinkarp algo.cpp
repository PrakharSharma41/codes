#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;

int add(int a,int b)
{
	if(a+b>=mod)
	return a+b-mod;
	return a+b;
}
int sub(int a,int b)
{
	if(a-b<0)
	return a-b+mod;
	return a-b;
}
int mul(int a,int b)
{
	return (int)(1ll*a*b%mod);
}
void prec(int n,int hash[],int p[],char s[])
{
	p[0]=1;int z=26;
	hash[0]=s[0];
	for(int i=1;i<=n;i++)
	p[i]=mul(p[i-1],z);
	for(int i=1;i<=n;i++)
	hash[i]=add(mul(hash[i-1],z),s[i]);
}
int get(int l,int r,int hash[],int p[])
{
	int res=hash[r];
	if(l!=0)
	res=sub(res,mul(hash[l-1],p[r-l+1]));
	return res;
}
int32_t main()
{
	char s[100005];
	int hash[100005];
	int p[100005];

	int t,n,ans,len1,len2;
	cin>>t;
	while(t--)
	{
//		string s;
		cin>>s;
		n=strlen(s);
		prec(n,hash,p,s);ans=0;
		for(int len=2;len<=n-2;len+=2)
		{
			len1=len/2;
			len2=(n-len)/2;
			if(get(0,len1-1,hash,p)!=get(len1,len-1,hash,p))
				continue;
			if(get(len,len+len2-1,hash,p)!=get(len+len2,n-1,hash,p))
				continue;
			ans++;
		}
		cout<<ans<<"\n";		
	}
	return 0;
}
