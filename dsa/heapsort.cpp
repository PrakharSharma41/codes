#include<stdio.h>
void build(int *ptr,int);
void adjust(int *ptr,int);
int main()
{
	int i,n;
	printf("enter the size of array\n");
	scanf("%d",&n);
	int a[n],*ptr=a;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	build(a,n);
	adjust(a,n);
	//to print array
	for(i=0;i<n;i++)
	printf("%d\t\t",a[i]);
	return 0;
}
void build(int *ptr,int n)
{
	int i,y,s,f;
	for(i=1;i<n;i++)
	{
		y=*(ptr+i);
		s=i;
		f=(s-1)/2;
		while(y>*(ptr+f)&&s>0)
		{
			*(ptr+s)=*(ptr+f);
			s=f;
			f=(s-1)/2;
		}
		*(ptr+s)=y;
	}
}
void adjust(int *ptr,int n)
{
	int i,x;
	for(i=n-1;i>=0;i--)
	{
		if((*ptr)>(*(ptr+i)))
		{
			x=*(ptr+i);
			*(ptr+i)=*(ptr);
			*ptr=x;
		}
		build(ptr,i);
	}
}
