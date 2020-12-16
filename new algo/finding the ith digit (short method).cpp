#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

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

ll add(ll a,ll b,ll m){
	return ((a%m)+(b%m))%m;
}

ll sub(ll a,ll b,ll m){
	return ((a%m)-(b%m)+m)%m;
}

ll mul(ll a,ll b,ll m){
	return ((a%m)*(b%m))%m;
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

ll sum(ll a){
	ll sum=0;
	while(a>0){
		sum+=a%10;
		a/=10;
	}
	return sum;
}

int main(){
//	ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
	ll t,s,n,i,j;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<"enter the digit to find (1 based )\n";
		cin>>s;
		ll ans=(n/power(10,s-1))%10;
		cout<<ans<<"\n";
	}
	return 0;
}
