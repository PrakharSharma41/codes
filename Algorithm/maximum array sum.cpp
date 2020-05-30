#include<stdio.h>
int maxValue(int a,int b,int c)
{
	if(a>=b&&a>=c)
	return a;
	else if(b>=a&&b>=c)
	return b;
	else
	return c;
}
int main()
{
	int n;
	scanf("%d",&n);int a[n],b[n],i,max;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	b[0]=a[0];max=a[0];
	if(a[1]>a[0])
		b[1]=a[1];
	else
		b[1]=a[0];
	max=b[1];
	for(i=2;i<n;i++)
	{
		b[i]=maxValue(a[i],max,(a[i]+b[i-2]));
		max=b[i];
	}
	printf("%d",max);
	return 0;
}

