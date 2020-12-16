#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
ll nCrevenoroddfinder(ll n,ll r)
{
    ll a=r;
    ll b=n-r;
    for(ll i=0;i<30;i++)
    {
        ll x=1<<i;
        if((x&a)&&(x&b))
        {
            return 0;//even
        }
    }
    return 1;//odd
}
 
// for calculating inverse
int modx(int x,int n)
{
    int result=1,M=1e9+7;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}
 
ll ncr(ll n, ll k) 
{ 
    ll res = 1;  
    if (k > n - k) 
        k = n - k; 
    for (ll i = 0; i < k; ++i) { 
        res*=(n-i);
		res /= (i + 1); 
    } 
  
    return res; 
} 
 
ll add(ll a,ll b,ll m){
	return ((a%m)+(b%m))%m;
}
 
ll sub(ll a,ll b,ll m){
	return ((a%m)-(b%m)+m)%m;
}
 
ll mul(ll a,ll b,ll m){
	return ((a%m)*(b%m))%m;
}
 
ll inverse(ll a,ll m){
	return modx(a,m-2);
}
 
ll power(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n%2==1)
		res=(res*x);
		x=x*x;
		n/=2;
	}
	return res;
}
 
 
ll gcd(ll a,ll b){
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
 
ll lcm(ll a,ll b){
	return (a*b)/(gcd(a,b));
}
 
 
bool isprime(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0)return false;
  }
  return true;
}
 
bool isperfect(ll n) {
  ll y = sqrt(n);
  if (n % y == 0 && y * y == n)return true;
  return false;
}
 
bool prime[10000000];
void seive() {
    for(ll i=1;i<10000000;i++)
    prime[i]=true;
	prime[1] = true;
	for (ll i = 2; i * i < 10000000; i++) {
		if (!prime[i])continue;
		for (ll j = i * i; j < 10000000; j += i) {
		  prime[j] = false;
		}
	
	}
}
// parameter format 1: l=-1 r=size-1
// parameter format 2: l=0 r=size
// parameter format 3: l=0 r=size-1
//all format works because all index appears once
int search(std::vector<int>& v, int l, int r, int key) 
{ 
    while (r - l >1) { 
        int m = l + (r - l) / 2; 
        if( v[m] <= key ) 
            l = m; 
        else
            r = m;     
    } 
  
    if( A[l] == key ) // as r-l>1 it is written so that function do not cause
    // problem with length 2
        return l; 
    if( A[r] == key ) 
        return r; 
    else
        return -1;   
} 
  

int32_t main(){
	fast
	ll t,n,i,j,m=1e9+7;
//	cin	>>t;
	t=1;
	while(t--){
		cin>>n;vector<ll>v(n);
		for(i=0;i<n;i++)
		cin>>v[i];
		cout<<seq(v)<<"\n";
	}
	return 0;
}
