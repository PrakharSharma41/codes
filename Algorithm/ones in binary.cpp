# include<stdio.h>
int main()
{
	int count=0,n;
	scanf("%d",&n);
	while(n)
	{
		n=n&(n-1);
		count++;
	}
	printf("no of ones are %d\n",count);
	return 0;
}






