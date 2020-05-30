#include<stdio.h>
int main()
{
	FILE *fp;
	char feedback[10];
	fp=fopen("COMMENTS.TXT","w");
	if(fp==NULL)
	{
		printf("fo=ile not open");
		return 0;
	}
	printf("provide feedback:");
	gets(feedback);
	fflush(stdin);
	
	fclose(fp);
	return 0;
}
