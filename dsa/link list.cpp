#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
struct node *create(struct node*);
struct node *display(struct node*);
int main()
{
	int ch;
	while(1)
	{
		
		printf("1.insert\n\n");
		printf("2.display\n\n");
		printf("3.quit\n\n");
		printf("enter your choice:\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				start=create(start);
				break;
			case 2:
				start=display(start);
				break;
			case 3:
				return 0;
			default:
				printf("invalid option");		
		}
	}
	return 0;
}
struct node *create(struct node *start)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	printf("enter the data");
	scanf("%d",&temp->data);
	if(start==NULL)
	{
		temp->link=NULL;
		start=temp;
	}
	else
	{
		temp->link=start;
		start=temp;
	}
	return start;
}
struct node *display(struct node *start)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	if(start==NULL)
	printf("link list is empty");
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("%d\t\t",temp->data);
			temp=temp->link;
		}
	}
	return start;
}













