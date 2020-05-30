#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp;
	int ch,noc=0,nol=1;
	char prakhar[20];
	printf("enter the filename:");
	fp=fopen(prakhar,"r");
	if(fp==NULL)
	{
		printf("enter opening the file");
		return 0;
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		if(ch=='\n')
		nol++;
		noc++;
		ch=fgetc(fp);
	}
	if(noc>0)
	{
		printf("file%s,there are %d linesand %d characters",prakhar,nol,noc);
	}
	else
	printf("file is empty");
	fclose(fp);
	return 0;
}
