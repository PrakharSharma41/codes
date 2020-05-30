#include<stdio.h>
#include<string.h>
int max(int x,int y);
int main()
{
	printf("Enter the String\n");char value[100];
	scanf("%s",value);int i=0,len=strlen(value);int str[100][100];
	for(i=0;i<len;i++)
	str[i][i]=1;
	for(int c=2;c<=len;c++)               // use string : abdcb to understand
	{
		for(i=0;i<len-c+1;i++)
		{
			int j=i+c-1;
			if(value[i]==value[j]&&c==2)
			str[i][j]=2;
			else if(value[i]==value[j])
			str[i][j]=str[i+1][j-1]+2;
			else
			str[i][j]=max(str[i+1][j],str[i][j-1]);
		}
	}
	printf("Longest palandromic subsequence is %d\n",str[0][len-1]);
//	printf("Longest palandromic subsequence is %d\n",str[1][3]);
//	printf("Longest palandromic subsequence is %d\n",str[3][2]);
//	printf("Longest palandromic subsequence is %d\n",str[90][2]);
	return 0;
}
int max(int x,int y)
{
	return (x>y)?x:y;                              
}
