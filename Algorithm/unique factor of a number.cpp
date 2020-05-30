#include<iostream>
using namespace std;
int factor(int n,int m)  // calculate unique factor of a number
{
	int t=0;
	while(m*m<=n)
	{
		if(n%m==0)
		t+=factor(n/m,m);
		m++;
	}
	return t+1;
}
int main()
{
	int n;
	cin>>n;
	cout <<factor(n,2)-1;
	return 0;
}
