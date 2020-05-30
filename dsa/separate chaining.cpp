#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	char str[50];
	struct node *link;
};
struct node *chain[3];
void initial()
{
	for(int i=0;i<3;i++)
	chain[i]=NULL;
}
int insert(int value,char *ptr)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof (struct node));
	newnode->data=value;
	strcpy(newnode->str,ptr);
	newnode->link=NULL;
	int key=value%3;
	if(chain[key]==NULL)
	chain[key]=newnode;
	else
	{
		struct node *temp=chain[key];
		while(temp->link)
			temp=temp->link;
		temp->link=newnode;
	}
}
int print(int  collision)
{
	int i;
	for(i=0;i<3;i++)
	{
		struct node *temp=chain[i];
		//printf("%d\n",temp->data);
		while(temp)
		{
			collision++;
			printf("%d\t\t",temp->data);
						printf("%s\t\t",temp->str);
			temp=temp->link;
		}
		collision--;
		printf("\n");
	}
	return (collision);
}
int main()
{
	char str[50];
	initial();
	int collision=0;
	scanf("%s",str);
	insert(7,str);
	scanf("%s",str);
	insert(6,str);
	scanf("%s",str);
	insert(3,str);
	scanf("%s",str);
	insert(10,str);
	scanf("%s",str);
	insert(4,str);
	scanf("%s",str);
	insert(5,str);
	collision=print(collision);
	printf("number of collisions are %d",collision);
	return 0;
}
