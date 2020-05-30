#include<stdio.h>
struct node{
    int x,b[500],c[500];
};
int main()
{
    int i,n,j,k=0;
    scanf("%d",&n);
    struct node a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",a[i].x);
        for(j=0;j<a[i].x;j++)
        {
            scanf("%d ",&a[i].b[j]);
            if(a[i].b[j]<2)
            {
                a[i].c[k]=a[i].b[j];k++;
            }
            else if(2<=a[i].b[j]<=3)
            {
                a[i].c[k]=a[i].b[j];k++;
            }
            else if(3<=a[i].b[j]<7)
            {
                a[i].c[k]=a[i].b[j];k++;
            }
            else
            {
                a[i].c[k]=a[i].b[j];k++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<a[i].x;j++)
        {
            printf("%d",a[i].c[j]);
        }
        printf("\n");
    }
    return 0;
}
