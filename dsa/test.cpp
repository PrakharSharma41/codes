
#include<stdio.h>
int main()
{
    int t,a[1000001],n,i,j,count,value;
    scanf("%d",&t);
	for(i=2;i<1000001;i++)
    a[i]=i;
	a[0]=0;a[1]=0;
	for(i=2;i*i<1000001;i++)
	{
	    value=0;
		if(a[i]==i)
		{
			for(j=i*2;j<=1000001;j+=i)
        {
    			if(a[j]==j)
		    	{
		    	    a[j]=i;
		    	    value++;
		    	}
        }
        a[i]=value+1;
		}
	}
	for(int i=2;i<100;i++)
	printf("%d-->%d\t\t",a[i]);
    while(t--)
    {
        count=0;
        scanf("%d",&n);
        if(n==2)
        printf("500000\n");
        else
        {
	     printf("%d\n",a[n]);
        }
    }
	return 0;
}
