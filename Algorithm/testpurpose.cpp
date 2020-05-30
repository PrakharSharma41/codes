#include<stdio.h>
#define m 1000001
long long int a[m];
int main()
{
    int i,t,n;
    a[1]=0;a[2]=0;a[3]=1;
    for(i=4;i<m;i++)
    {
    	a[i]=a[i-1]+(i-2)*(i-2);
	}
	    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}

