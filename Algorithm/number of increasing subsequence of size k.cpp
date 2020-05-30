#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n,sum=0,i,j,l,k;
	printf("enter the size of array and size of subsequence\n");
	scanf("%d%d",&n,&k);
	 int a[n]; int dp[n][n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
	dp[0][i]=1;        // subsequence of size 1
	for(l=1;l<k;l++)
	{
		for(i=1;i<n;i++)
		{
			dp[l][i]=0;
			for(j=l-1;j<i;j++)
				if(a[j]<a[i])
					dp[l][i]+=dp[l-1][j];
		}
	}
	for(i=k-1;i<n;i++)
		sum+=dp[k-1][i];     //   summing up the count of increasing subsequence
	printf("number is %d\n",sum);
	return 0;
}
