#include<stdio.h>
void insertion(int arr[10],int,int);
int main()
{
	int arr[10],n;
	printf("enter the number of elements to put in array\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	insertion(arr,n,0);
	insertion(arr,n,1);	
	for(int i=0;i<n;i++)
	printf("%d\t",arr[i]);
	return 0;
}
void insertion(int arr[10],int n,int i)
{
	int j=0;
	if(i==0)
	{
		for(i=2;i<n;i+=2)
	{
		int y=arr[i];
		j=i-2;
		while(j>=0&&y>arr[j])
		{
			arr[j+2]=arr[j];j-=2;
		}
		arr[j+2]=y;
	}
	}
	else
	{
		for(i=3;i<n;i+=2)
	{
		int y=arr[i];
		j=i-2;
		while(j>=0&&y<arr[j])
		{
			arr[j+2]=arr[j];j-=2;
		}
		arr[j+2]=y;
	}
	}
}
