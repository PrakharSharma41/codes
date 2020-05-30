#include<stdio.h>
#include<string.h>
int lps(char str[],int i,int j);
int max(int x,int y);
int main()
{
	printf("Enter the String\n");char str[2000];
	scanf("%s",str);int i=0,j=strlen(str)-1;
	printf("Longest subsequence is %d\n",lps(str,i,j));
	return 0;
}
int max(int x,int y)
{
	return (x>y?x:y);                              //     0   1   2   3   4
}                                                 //    a   b   b   c   d
int lps(char str[],int i,int j)
{
	if(i==j)      // for odd length
	return 1;
	if(str[i]==str[j]&&i+1==j)    // for even length
	return 2;
	if(str[i]==str[j])
	return lps(str,i+1,j-1)+2;
	return max(lps(str,i+1,j),lps(str,i,j-1));
}
