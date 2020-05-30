#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
	int data;
	struct node *next;
};
void display(struct node *front,struct node *rear);
void insert(struct node **front,struct node **rear,int d);
int del(struct node **front,struct node **rear);
bool isEmpty(struct node *front);
int main()
{
	struct node *front=NULL,*rear=NULL;
	int ch,ele,x;
	while(1)
	{
		printf("1.insert the element\n");
		printf("2.delete the topmost element\n");
		printf("3.display the queue\n");
		printf("4.quit");
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
				display(front,rear);
				break;
			case 4:
				return 0;
		}
	}
return 0;
}
void insert(struct node **front,struct node **rear,int d)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;temp->next=NULL;
	if(isEmpty(*front))
		*front=*rear=temp;
	else
	{
		(*rear)->next=temp;
		*rear=temp;
		(*rear)->next=*front;
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
		d=temp->data;
		*front= (temp)->next;
		(*rear)->next=*front;
		free(temp);
		return d;
	}
}
void display(struct node *f,struct node *r)
{
	while(f!=r)
	{
		printf("%d\n",f->data);
		f=f->next;
	}printf("%d\n",f->data);
}
