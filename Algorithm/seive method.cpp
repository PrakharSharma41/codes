#include<stdio.h>
#include<math.h>
int main()
{
	int k,i,j,a[100],n;
	printf("enter the number of elements of matrix:\n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		a[i]=i;
	for(k=2;k<sqrt(n);k++)
		{
			while(2*k<n)
			{
				a[2*k]=1;k++;
			}
		}
	for(i=0;i<n;i++)
	{
		if(a[i]!=1&&a[i]!=0)
		printf("%d\t\t",a[i]);
	}
	return 0;
}

