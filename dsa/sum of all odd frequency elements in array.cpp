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
	int i,flag=0;
	int a[100],x=1,z=0;
	int pos,temp;
	for( i=0;i<n;i++)
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
		if(i>=1)
		{
			if(arr[i]==arr[i-1])
			x++;
			else
			{
				if((x%2)!=0&&i!=n-1)
				{
					z+=x*arr[i-1];x=1;
				}
				else if((x%2)==0&&i!=n-1)
					x=1;
					else 
					{
					z=z+arr[i]+arr[i-1];flag=1;	
					}
			}
		}
	}
	if((x%2)!=0&&flag==0)
		z+=x*arr[i-1];
printf("\n\t\t\t\t\t\t\t\t%d\t\n",z);
}
