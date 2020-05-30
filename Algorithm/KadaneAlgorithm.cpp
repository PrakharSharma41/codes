											// MAXIMUM SUM OF SUBARRAY(CONTINUOUS ELEMENTS)
#include<stdio.h>
int maximum(int a,int b);
int main()
{
	int i,n,max=-9999999,val=-9999999;
	printf("Enter size of array\n");
	scanf("%d",&n);int a[n],dp[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);dp[0]=a[0];val=a[0],max=dp[0];
	printf("0-->%d\n",dp[0]);
	for(i=1;i<n;i++)
	{
		dp[i]=maximum(dp[i-1],0)+a[i];             // O(N)  SPACE COMPLEXITY
		printf("%d-->%d\n",i,dp[i]);
		max=maximum(dp[i],max);
		printf("max is %d\n",max);
	}
//		for(i=1;i<n;i++)					// O(1) SPACE COMPLEXITY
//	{
//		val=maximum(val,0)+a[i];
//		max=maximum(max,val);
//	}
	printf("Maximum sum is %d\n",max);
	return 0;
}
int maximum(int a,int b)
{
	return (a>b? a:b);
}
