#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;//global variable
struct node *create(struct node*);
struct node *display(struct node*);
struct node *del(struct node*);
struct node *insert(struct node*);
int main()
{
	start=create(start);
	printf("link list created");
	start=display(start);
	start=del(start);
	start=display(start);
	start=insert(start);
	start=display(start);
	return 0;	
}
struct node *create(struct node*)
{
	int num;
	struct node *newnode;
	printf("enter the value of num");
	scanf("%d",&num);
	while(num!=1)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=num;
		if(start==NULL)
		{
			start=newnode;
			newnode->next=NULL;
		}
		else
		{
			newnode->next=start;
			start=newnode;
		}
		printf("enter value of num");
		scanf("%d",&num);
	}
	return start;
}
struct node *display(struct node *start)
{
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}	
	return start;
	
}
struct node *del(struct node *start)
{
	struct node *p;
	p=start;
	struct node *q=start;
	int loc;
	printf("enter the location:");
	scanf("%d",&loc);
	
		int i=1;
		while(i<loc-1)
		{
			p=p->next;
			i++;
		}	
		q=p->next;
		p->next=q->next;
		q->next=NULL;
		free(q);
		return start;
}
struct node *insert(struct node *start)
{
	struct node *p=NULL;
	struct node *temp=start;
	int loc;
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter data of new node:");
	scanf("%d",&p->data);
	p->next=NULL;
	printf("enter location to add new node");
	scanf("%d",&loc);
	int i=1;
	while(i<loc)
	{
		i++;
		temp=temp->next;
	}
	p->next=temp->next;
	temp->next=p;
	return start;
	
}




























