#include<stdio.h>
int main()
{
    int n,m,i,q,j,one,two;
    scanf("%d%d%d",&n,&m,&q); int a[n+1][m+1],input[n+1][m+1],k,l,sum;
    printf("%d %d %d \n",n,m,q);
    int maxleft=1,minright=m,maxup=1,mindown=n,left=1,right=m,up=1,down=n;;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&input[i][j]);
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(j==1)
            a[i][j]=input[i][j];
            else
            a[i][j]=a[i][j-1]+input[i][j];
        }
    }

    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
        {
			if(i!=1)
            a[i][j]+=a[i-1][j];
        }
    }
	
	while(q--)
	{
		sum=0;
		scanf("%d",&one);
		if(one==1)
		{
			scanf("%d%d",&k,&l);
			left=left+k;right=right+k;
			up=up+l;down=down+l;
			maxleft = maxleft > left ? maxleft : left;
			maxup = maxup > up ? maxup : up;
			minright=minright < right ? minright : right;
			mindown=mindown < down ? mindown : down;
			printf("maxleft->%d minright->%d maxup->%d mindown->%d\n",maxleft,minright,maxup,mindown);			
		}
		else
		{		
			if((maxleft>minright)||(maxup>mindown))
			printf("0\n");
			else
			{
				int p = a[mindown][maxleft-1],q=a[maxup-1][minright],r=a[maxup-1][maxleft-1];
				if(maxleft==1||maxup==1)
				r=0;       ///  r =  a[maxup-1][maxleft-1]
				if(maxleft==1)
				p=0;  ///      p = a[mindown][maxleft-1]
				if(maxup==1)
				q=0;  ///     q=    a[maxup-1][minright]
				sum=a[mindown][minright]-p-q+r;
				printf("%d\n",sum);
			}
		}
	}
    return 0;
}






