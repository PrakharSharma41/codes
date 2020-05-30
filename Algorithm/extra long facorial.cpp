#include<stdio.h>
int main()
{
	int n;int arr[200]={0},carry=0,counter=0,i;
	scanf("%d",&n);arr[0]=1;
	while(n>1)
	{
		for(i=0;i<=counter;i++)
		{
			carry+=arr[i]*n;
			arr[i]=carry%10;
			carry/=10;
		}
		while(carry>0)
		{
			arr[++counter]=carry%10;
			carry/=10;
		}
		n--;
	}
	for(i=counter;i>=0;i--)
	printf("%d",arr[i]);
    return 0;
}

