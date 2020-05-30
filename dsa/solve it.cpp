#include<stdio.h>
void main()
{
    long long int n,i,q,j;
    scanf("%lld",&n);
    long long int a[n];
    for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
    scanf("%lld",&q);
    long long int b[q];
    for(i=0;i<q;i++)
    scanf("%lld",&b[i]);
    for(i=0;i<q;i++)
    {
        long long int x=0,flag=0;
        for(j=0;j<n;j++)
        {
            if(b[i]==a[j])
            {
               x++;flag=1;
            }
        }
        if(flag==1)
        printf("%lld\n",x);
        else
        printf("NOT PRESENT\n");
    }
}
