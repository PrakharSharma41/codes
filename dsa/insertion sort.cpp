#include<stdio.h>
int main()
{
	int n,arr[100];
	printf("enter the number of element\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(int i=1;i<n;i++)
	{
		int y=arr[i];
		for(int j=0;j<i;j++)
		{
			if(y<arr[j])
			{
				for(int k=i;k>j;k--)
				arr[k]=arr[k-1];
				arr[j]=y;
			}
		}
	}
	for(int i=0;i<n;i++)
	printf("%d",arr[i]);
	return 0;
}
