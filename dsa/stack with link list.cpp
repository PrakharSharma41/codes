#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void traverse(void);
struct node
{
	int data;
	struct node* link;
};
struct node *top=NULL;
int main()
{
	while(1)
	{
		printf("1.insert\n");
		printf("2.pop\n");
		printf("3.traverse\n");
		printf("4.exit\n");
		int ch,item;
		printf("enter your choice:");	
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data:");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				pop();
				break;
			case 3:
				traverse();
				break;
			case 4:
				return 0;
			default:
				printf("invalid option");
		}
	}
	return 0;
}

void push(int item)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof (struct node*));
	temp->data=item;
	temp->link=top;
	top=temp;
}
void pop()
{
	struct node *temp;
	if(temp==NULL)
	printf("stack is empty");
	else
	{
		struct node *temp=top;
		printf("element  to delete is %d",temp->data);
		top=top->link;
		temp->link=NULL;
		free(temp);
	}
}
void traverse(void)
{
	struct node *temp;
	if(top==NULL)
	printf("stack is empty");
	else
	{
		temp=top;
		while(temp!=NULL)
		{
			printf("%d\t\n",temp->data);
			temp=temp->link;
		}
	}
}
