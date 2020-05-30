#include<math.h>
#include<stdio.h>
int main()
{
    long long int n,i=0,x=0,k=1,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        while(pow(2,i)<=n)
        i++;
        x=pow(2,i);
		switch(x-n)
		{
			case 0:
				printf("%lld\n",k);
				break;
			default:
	    	    i-=1;
       			 x=pow(2,i);
        		while(x!=n)
        		{
          	  if(x<n)
          	  {
          	      i--;
          	      x+=pow(2,i);k++;
          	  }
          	  else 
          	 	 {
            	    i--;
            	    x-=pow(2,i);
        	    }
    	    }
	        printf("%lld\n",k);
	        break;
		}
		 i=0;k=1;x=0;
    }
    return 0;
}
