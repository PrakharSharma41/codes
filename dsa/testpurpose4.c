#include<stdio.h>
int main()
{
    long long int i,n,x,new,max=-11111;
    scanf("%lld",&n);long long int a[n];
    for(i=0;i<n;i++)
    {
    	scanf("%lld",&a[i]);
    	if(max<a[i])
    	max=a[i];
	}
    x=a[0]%2==0?a[0]/2:((a[0]/2)+1);
   // printf("%lld\n",x);x=1859;
    while(1)
    {
//    	printf("hello\n");
        int flag=1;new=x;
       // printf("new is %lld\n",new);
        for(i=0;i<n;i++)
        {
            new=2*new-a[i];new=new%1000000000000000000;
            //printf("%lld-->",new);
            if(new<=0)
            {
            //	printf(" breaking value is %lld\n",a[i]);
                flag=0;break;
            }
        }
        if(flag==1)
        {
            printf("%lld\n",x);
            break;
        }
        x++;
    }
    return 0;
}

