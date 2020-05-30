#include<stdio.h>
#include<string.h>
void lsa(char pattern[],int prefArray[],int);
void kmp(char pattern[],char str[],int prefArray[]);
int main()
{
	char pattern[100000],str[100000];
	scanf("%s",pattern);
	scanf("%s",str);
	int i,j=strlen(pattern);int prefArray[j+1];
	lsa(pattern,prefArray,j);
	for(i=0;i<j;i++)
	printf("%d\t\t",prefArray[i]);
	kmp(pattern,str,prefArray);
	return 0;
}
void kmp(char pattern[],char str[],int prefArray[])
{
	int count=0,j=0,i,m=strlen(pattern),length=strlen(str);
	for(i=0;i<length;i++)
	{

		if(str[i]==pattern[j]&&j>=0)
		j++;
		else if(j==m)
		{
			count++;j=prefArray[j-1]+1;i--;
		}
		else
		{
			if(j>0)
			{
				j=prefArray[j-1]+1;
				i--;
			}
			else
			j=0;
		}
	}
	if(j==m)
	count++;
	printf("%d\n",count);
}
void lsa(char pattern[],int prefArray[],int j)              // making longest subsequence array
{
	int i,length=0;                      // length can also be considered as index
	prefArray[0]=-1;
	for(i=1;i<j;i++)
	{
		if(pattern[i]==pattern[length]&&length!=-1){
			prefArray[i]=length;
			length++;
		}
		else
		{
			if(length!=0)
			{
				length=0;
				i--;
			}
			else
			prefArray[i]=-1;
		}
	}
}
