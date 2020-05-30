#include<stdio.h>
int sum(int x);
int main()
{
	int n,x,y;
	printf("enter the first number\n");
	scanf("%d",&x);
	printf("enter the second number\n");
	scanf("%d",&y);
	int a[y+1],i,j;
	for(i=2;i<y+1;i++)
	a[i]=1;
	a[0]=0;a[1]=0;
	for(i=2;i*i<=y;i++)
	{
		if(a[i]==1)
		{
			for(j=i*2;j<=y;j+=i)
			a[j]=0;
		} 
	}
	for(i=0;i<y+1;i++)
	if(a[i]==1&&i>x)
	{
		int z=sum(i);
	//	printf("%d\t\t",z);
		if(a[z]==1)
		{
			//printf("true\t\t");
			printf("%d\t",i);
		}
	}
	return 0;
}
int sum(int x){
	int count=0;
	while(x>0)
	{
		int rem=x%10;
		count+=rem;
		x/=10;
	}
	//printf("%d\t\t",count);
	return count;
}
