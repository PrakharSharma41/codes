#include<stdio.h>
void selection(int arr[10],int);
void insertion(int arr[10],int);
void bubble(int arr[10],int);
void quick(int arr[10],int,int);
int main()
{
	int arr[10],n,low,high;
	printf("enter the number of elements to put in array\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	selection(arr,n);
//	insertion(arr,n);
	low=0;high=n-1;
	quick(arr,low,high);
//	bubble(arr,n);
		for(int i=0;i<n;i++)
	printf("%d\t",arr[i]);
	return 0;
}
void display(int arr[10],int n)
{
	for(int i=0;i<n;i++)
	printf("%d\t",arr[i]);
	printf("\n");
}
void selection(int arr[10],int n)
{
	int a[100],k=0;
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
		//a[k]=pos;k++;
		temp=arr[i];
		arr[i]=arr[pos];
		arr[pos]=temp;
	}
for(int i=0;i<=k;i++)
printf("%d\t",a[i]);
}
void insertion(int arr[10],int n)
{
	int k=0,j=0;
/*	for(int i=1;i<n;i++)
	{
		int y=arr[i];
		for(j=0;j<=i-1;j++)
		{
			if(y<arr[j])
			{
				for(k=i;k>=j+1;k--)
				arr[k]=arr[k-1];
				arr[j]=y;break;
			}
		}
	}*/
	for(int i=1;i<n;i++)
	{
		int y=arr[i];
		j=i-1;
		while(j>=0&&y<arr[j])
		{
			arr[j+1]=arr[j];j--;
		}
		arr[j+1]=y;
	}
}
void bubble(int arr[10],int n)
{
	int temp=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	display(arr,n);
}
void quick(int arr[10],int low,int high)
{
	if(low>high)
	return;
	else
	{
	
		int last,temp=0,mid=(low+high)/2;
		temp=arr[mid];
		arr[mid]=arr[low];
		arr[low]=temp;
		last=low;
		for(int i=low+1;i<=high;i++)
		{
			if(arr[i]<arr[low])
			{
				last+=1;
				temp=arr[i];arr[i]=arr[last];arr[last]=temp;
			}
		}temp=0;
		temp=arr[low];
		arr[low]=arr[last];
		arr[last]=temp;
		quick(arr,low,last-1);
		quick(arr,last+1,high);
	}
}
/*int swap(int arr,int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;return arr;
}*/
