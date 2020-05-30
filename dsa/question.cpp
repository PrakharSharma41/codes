#include<stdio.h>
int main()
{
	int arr[100],k;
	for(int i=0;i<10;i++)
	scanf("%d",&arr[i]);
	for(int i=1;i<10;i++)
	{
		int y=arr[i];k=i;
		if(y<0)
		{
			for(k=i;arr[k-1]>0;k--)
			arr[k]=arr[k-1];
			arr[k]=y;
		}
	}
		for(int i=0;i<10;i++)
	printf("%d\t",arr[i]);
	return 0;
}
