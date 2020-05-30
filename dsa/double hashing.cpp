#include<stdio.h>
#define SIZE 10
int htable[SIZE];
void initial()
{
	for(int i=0;i<SIZE;i++)
	htable[i]=0;
}
void display()
{
	for(int i=0;i<SIZE;i++)
	printf("%d\t\t",htable[i]);
}
void search()
{
	int i,ele;
	printf("enter the element to search\n");
	scanf("%d",&ele);
	for(i=0;i<SIZE;i++)
	{
		if(htable[i]==ele)
		{
			printf("element is found\n");
			break;
		}
	}
	if(i==SIZE)
	printf("element not found\n");
}
void insert()
{
	int i,data,index;
	printf("enter the data to insert\n");
	scanf("%d",&data);
	int hash1=data%SIZE;
	int hash2=7-(data%7);
	for( i=0;i<SIZE;i++)
	{
		index=hash1+i*hash2;
		if(htable[index]==0)
		{
			htable[index]=data;;
			break;
		}
	}
	if(i==SIZE)
	printf("array is full\n");
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
