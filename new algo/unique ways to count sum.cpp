// unique ways to count a sum x with n number of coins given

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//dp[i][j]=dp[i-1][j]+dp[i][j-a[i]] 
ll dp[2][1000001]; 
int main() {
    fast_io;
    ll n,m,x,i,j,k,q;
    cin >> n>>x;
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<2;i++)
	{
	    for(j=0;j<=x;j++)
	    {
	    	if(j==0)
	    	dp[i][j]=1;
	    	else
	    	dp[i][j]=0;
		}
	}
    for(i=0;i<n;i++)
    {
    	for(j=0;j<=x;j++)
    	{
    		if(j==0)
    		dp[0][j]=1;
    		else if(i==0)
    		{
    			if(j>=a[i])
    			dp[0][j]=dp[0][j-a[i]];
			}
			else
			{
				if(j>=a[i])
				dp[1][j]=(dp[0][j]+dp[1][j-a[i]])%mod;
				else
				dp[1][j]=dp[0][j];
			}
		}
		if(i!=0)
		{
			for(j=0;j<=x;j++)
			dp[0][j]=dp[1][j];			
		}
	}
	cout<<max(dp[0][x],dp[1][x]);
    return 0;
}

