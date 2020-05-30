#include<stdio.h>
int main()
{
	int t,i,pos,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);long int a[n],sum=0,count=0;
		for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
			{
				pos=i;count++;
			}
			if(a[i]<a[i-1])
			{
				pos=i;count++;
			}
		}
		long long int y=n-pos,x=pos-count;x--;
		sum+=(y*(y+1))/2+1;sum+=(x*(x+1))/2+1;
		if(count==1)
		{
			sum+=(y*(y+1))/2;
			sum+=(x*(x+1))/2;
		}
		printf("%ld\n",sum);
	}
	return 0;
}
