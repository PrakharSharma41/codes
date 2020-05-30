#include<stdio.h>
int main()
{
	int n,i=2,count=0;
	printf("enter the number to find prime factors\n");
	scanf("%d",&n);
	while(n%2==0)
	{
		n/=2;count++;
	}
	printf("number of times 2 is factor is %d\n",count);count=0;
	for(i=3;i*i<=n;i+=2)
	{count=0;
		if(n%i==0)
		{
			while(n%i==0)
			{
				n/=i;count++;;
			}
			printf("number of times %d is factor is %d\n",i,count);
		}
	}
	if(n>1)
	printf("%d is also factor\n",n);
	return 0;
}
