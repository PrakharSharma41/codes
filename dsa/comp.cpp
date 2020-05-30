#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        long long int a[n],i,count=1;
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
        {
            if(a[i+1]>a[i])
            a[i+1]=a[i];
            else
            count++;
        }
        printf("%lld\n",count);
    }
    return 0;
}
