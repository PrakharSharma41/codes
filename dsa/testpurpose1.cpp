#include<stdio.h>
int main()
{
	long long int n,q,i,j;
	scanf("%lld",&n);long long int x,y,a[n],count=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
//		if(a[i]<min)
//		min=a[i];
	}
	int min=3;
    long long int b[min+1];
	for(i=2;i<=min;i++)
	{
		int flag=0;
		for(j=0;j<n;j++)
		{
			if(a[j]%i!=0)
			{
				flag=1;break;
			}
		}
		if(flag==0)
		{
			count+=i;
			b[i]=1;
		}
	}
	count+=1;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		if(x>min)
		printf("0\n");
		if(min>y)
		{
			for(i=y+1;i<=min;i++)
			{
				if(b[i]==1)
				count-=i;
			}
		}
		if(min>=x&&min<=y)
		{
			for(i=x-1;i>0;i--)
			{
				if(b[i]==1)
				count-=i;
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}
