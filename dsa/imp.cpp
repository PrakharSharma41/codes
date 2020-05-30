#include<stdio.h>
int prime(int);
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i=0,flag=1;
        char str[500];
        scanf("%s",str);
        while(str[i]!='\0')
        {
            int flag=1;
            flag=prime((int)(str[i]));
            if(flag==1)
            printf("%c",str[i]);
            else
            {
                while(flag==0)
                {
                    flag=prime(((int)(str[i])-1));
                }
                if(flag==1)
                printf("%c",str[i]-1);
            }i++;
        }
    }
    return 0;
}
int prime(int k)
{
            int j=2,flag=1;
            for(j=2;j<k;j++)
            {
                if(k%j==0)
                {
                    flag=0;break;
                }
                else
                flag=1;
            }
            return flag;
}
