
/*#include<stdio.h>
int *bubble(int *p,int i)
{
	*(p+i)=99;
	return p;
}
int main()
{
	int arr[10],n,i,*p;
	p=arr;
	printf("enter number of elements\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	i=0;
	p=bubble(arr,i);
	for(int i=0;i<n;i++)
	printf("%d\t",arr[i]);
	return 0;
}*/
#include<stdio.h>
int *bubble(int *p,int i,int n,int k)
{
	int temp;
	if(i>=n-k+1)
	{
	return p;
	}
	else
	{
		if((*(p+i))<(*(p+i-1)))
		{
			temp = *(p+i);
			*(p+i) = *(p+i-1);
			*(p+i-1) = temp;	
		}
		i++;
		bubble(p,i,n,k);
	}	
	//return p;
}
int main()
{
	int arr[10],n,i,*p;
	p=arr;
	printf("enter number of elements\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(int k=1;k<n;k++)
	{
		i=1;
		p=bubble(arr,i,n,k);
	}
	for(int i=0;i<n;i++)
	printf("%d\t",*(p+i));
	return 0;
}
