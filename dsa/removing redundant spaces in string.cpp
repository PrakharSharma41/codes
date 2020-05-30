#include<stdio.h>
int main()
{
	char str[100];
	printf("enter your string\n");
	scanf("%[^\n]s",str);
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]==' '&&str[i+1]==' '||str[i]==' '&&str[i-1]==' ')
		{
			int k=i;
			while(str[k]!='\0')
			{
				str[k]=str[k+1];k++;
			}i--;
		}
		i++;
	}
	puts(str);
	return 0;
}
