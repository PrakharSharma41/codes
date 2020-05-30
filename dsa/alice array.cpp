#include<stdio.h>
int main()
{
    long long int n,q;
    scanf("%d",&n);
    long long int a[n+1],i,x=0,b;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        x+=a[i];
    }
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld",&i);
        b=x-i;
        for(i=n;i>=0;i--)
        {
            if(b>a[i])
            b-=a[i];
            else
            {
                if(i%2!=0)
                {
                	printf("Alice\n");
                	break;
				}
                else
                {
                	printf("Bob\n");break;
				}
            }
        }
    }
    return 0;
}
