#include<stdio.h>
int main()
{
	int a[100],n,y,first,last,middle;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter the number to search\n");
	scanf("%d",&y);
	
   first = 0;
   last = n - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (a[middle] < y)
         first = middle + 1;    
      else if (a[middle] == y) {
         printf("present", y);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      printf("not present\n", y);
	return 0;
}
