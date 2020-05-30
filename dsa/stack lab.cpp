#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(struct node*,int);
void pop(struct node*);
int isempty(struct node*);
void display(struct node*);
void main()
{
	int ch;
	while(1)
	{
		printf("enter the data\n");
		scanf("%d",&ch);
		if(ch<0)
			break;
		else
			push(top,ch);
	}
	if(isempty(top))
	{
		display(top);
		pop(top);
		display(top);
	}
}
int isempty(struct node* top)
{
	if(top==NULL)
	return 0;
	else
	return 1;
	}
void push(struct node *temp,int n)
{
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=top;
	top=temp;
}
void pop(struct node *head)
{
	top=top->next;
	head->next=NULL;
}
void display(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
}
	
	
	
