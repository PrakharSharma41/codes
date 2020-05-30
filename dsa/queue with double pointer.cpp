#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
	int data;
	struct node *next;
};
void display(struct node *head);
void insert(struct node **front,struct node **rear,int d);
int del(struct node **front,struct node **rear);
bool isEmpty(struct node *front);
void sorting(struct node*);
int main()
{
	struct node *front=NULL,*rear=NULL;
	int ch,ele,x;
	while(1)
	{
		printf("1.insert the element\n");
		printf("2.delete the topmost element\n");
		printf("3.display the queue\n");
		printf("4.sorting\n");
		printf("5.quit");
		printf("enter your choice\n.");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data.\n");
				scanf("%d",&ele);
				insert(&front,&rear,ele);
				break;
			case 2:
				x=del(&front,&rear);
				printf("deleted element is %d\n",x);
				break;
			case 3:
				display(front);
				break;
			case 4:
				sorting(front);
				break;
			case 5:
				return 0;
		}
	}
return 0;
}
void sorting(struct node *top)
{
	struct node *ptr1=top;struct node *ptr2;
	int temp;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
		{
			if(ptr1->data > ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}ptr2=ptr2->next;
		}ptr1=ptr1->next;
	}
}
void insert(struct node **front,struct node **rear,int d)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;temp->next=NULL;
	if((*front)==NULL)
		*front=*rear=temp;
	else
	{
		(*rear)->next=temp;
		*rear=temp;
		temp->next=NULL;
	}
}
bool isEmpty(struct node *front)
{
	if((front)==NULL)
	return true;
	else
	return false;
}
int del(struct node **front,struct node **rear)
{
	int d;
	struct node *temp=*front;
	if(isEmpty(*front))
	return -99;
	else
	{
		*front= (*front)->next;
		d=temp->data;
		free(temp);
		return d;
	}
}
void display(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}
}
