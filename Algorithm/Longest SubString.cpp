#include<stdio.h>
#include<string.h>
int main()
{
	char str[10000];
	printf("Enter the string\n");
	scanf("%s",str);
	int i,j=strlen(str),low,high,max=0;
	for(i=1;i<j;i++)
	{
		low=i-1;high=i;
		while(low>=0&&high<j&&str[low]==str[high])
		{
			if(high-low+1>max)
			max=high-low+1;
			low--;
			high++;
		}
		low=i-1;high=i+1;
		while(low>=0&&high<j&&str[low]==str[high])
		{
			if(high-low+1>max)
			max=high-low+1;
			low--;
			high++;
		}
	}
	printf("Longest length palindrome substring is %d\n",max);
	return 0;
}
