#include<stdio.h>
int main()
{
    long long int l,r,n,m,sum=0,f[1000],i;f[1]=1;f[2]=1;
    printf("asdas");
	for(i=3;i<=10002;i++)
    {
        if(i%2!=0)
        f[i]=3*f[i-2];
        else
        f[i]=2*f[i-1]-f[i-2]+2;
    }
    printf("%lld\n",f[99]);
    scanf("%lld%lld",&n,&m);
    while(n--)
    {
        sum=0;
        scanf("%lld%lld",&l,&r);
        for(i=l;i<=r;i++)
        sum=(sum%m+f[i]%m)%m;
        printf("%lld\n",sum);
    }
    return 0;
}
