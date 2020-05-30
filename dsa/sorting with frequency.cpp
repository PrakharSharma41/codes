#include<stdio.h>
void selection(int arr[10],int);
int main()
{
	int arr[10],n,low,high;
	printf("enter the number of elements to put in array\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	selection(arr,n);
	
	return 0;
}
void selection(int arr[10],int n)
{
	int c[100],k=0;
	int pos,temp;
	for(int i=0;i<n;i++)
	{
		int y=arr[i],pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(y>arr[j])
			{
				y=arr[j];
				pos=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[pos];
		arr[pos]=temp;
	}
		for(int i=0;i<n;i++)
	printf("%d\t\t",arr[i]);
	printf("\n\n");
		for(int i=0;i<n;i++)
	{
		temp=0;pos=0;
		while(arr[pos]<=i)
		{
			if(arr[pos]==i)
			temp++;
			pos++;
		}
		c[i]=temp;
	}
	for(int i=0;i<n;i++)
	printf("%d\t\t",c[i]);
}
