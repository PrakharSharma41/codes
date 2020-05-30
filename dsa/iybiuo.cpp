#include<stdio.h>
int main()
{
    int n,i,a[100],b[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d%d",&a[i],b[i]);
    for(i=0;i<n;i++)
    {
        if(b[i]%a[i]==0)
        printf("Yes\n");
        else
        printf("No");
    }
    return 0;
}
