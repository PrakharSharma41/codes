#include<stdio.h>
int main()
{
	long int result=1,a,b;
	scanf("%ld%ld",&a,&b);
	while(b>0)
	{
		if(b%2!=0)
		{
			result=(result*a)%10;
		}
		a=(a*a)%10;
		b/=2;
	}
	printf("%ld\n",result);
	return 0;
}

