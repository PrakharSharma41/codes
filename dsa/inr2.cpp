#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char name[10000],temp;
        scanf("%s",name);
        int n,m,j,k,i;
        scanf("%d%d",&n,&m);
        j=strlen(name);
        for(i=0;i<j;i++)
        {
            for(k=0;k<j-i;k++)
            {
            	char a='name[k]',b='name[k+1]';
                if(a>b)
                {
                    temp=a;
                    a=b;
                    b=temp;
                }
            }
        }
        printf("%s",name);printf("\n");
    }
return 0;
    
}
