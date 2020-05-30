#include<stdio.h>
#include<math.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int a[n],b[n],i,x=0,k;
    for( i=0;i<n;i++)
    {
         scanf("%lld",&a[i]);
    }
    for(i=0;i<n;i++)
    {
    	         if(a[i]%(sqrt(a[i])==0))
        {
             b[i] = a[i]/(sqrt(a[i]));
             x+=b[i];
        }
         else
         {
             k=a[i];
             k--;
            while(a[i]%(sqrt(k)!=0))
            k--;
            b[i]=a[i]/k;
            x+=b[i];
         }
	}
    printf("%lld",x);
    return 0;
}
