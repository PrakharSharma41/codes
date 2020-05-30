#include<stdio.h>
int main()
{
	long long int p,n,count=0;
	scanf("%lld",&n);
	double res=n;
	for(p=2;p*p<=n;p++)
	{
//		count++;
		if(n%p==0)
		{
			while(n%p==0)//to remove the powers of p and making sure only prime factors are calculated
			{
				n/=p;//count++;
			}
			res=res*(1.0-1.0/(double)p);
		}
	}
	if(n>1)
	res=res*(1.0-1.0/(double)n);
	printf("%lld",(long long int)res);
//	printf("count is %d\n",count);
	return 0;
}
