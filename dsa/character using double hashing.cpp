#include<stdio.h>
#include<string.h>
#define SIZE 10
struct node{
	char arr[50];
};
struct node htable[SIZE];
void initial()
{
	for(int i=0;i<SIZE;i++)
	strcpy(htable[i].arr,"NULL");
}
void insert()
{
	char str[50];
	printf("enter the string to insert\n");
	scanf("%s",str);
	int i,j=strlen(str);
	int hash1=j%SIZE;;
	int index,hash2=7-(j%7);
	for( i=0;i<SIZE;i++)
	{
		index=hash1+i*hash2;
		if(!strcmp(htable[index].arr,"NULL"))
		{
			strcpy(htable[index].arr,str);
			break;
		}
	}
	if(i==SIZE)
	printf("array is full\n");
}
void search()
{
	char str[50];
	int i,ele;
	printf("enter the element to search\n");
	scanf("%s",str);
	for(i=0;i<SIZE;i++)
	{
		if(!strcmp(htable[i].arr,str))
		{
			printf("element is found\n");
			break;
		}
	}
	if(i==SIZE)
	printf("element not found\n");
}
void display()
{
		for(int i=0;i<SIZE;i++)
	printf("%s\t\t",htable[i].arr);
}
int main()
{
	initial();
	int ch;
	while(1)
	{
		printf("1.insert\n");
		printf("2.display\n");
		printf("3.search an element\n");
		printf("4.quit\n");
		printf("1.enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			insert();
			break;
			case 2:
			display();
			break;
			case 3:
			search();
			break;
			case 4:
			return 0;
		}
	}
	return 0;
}
