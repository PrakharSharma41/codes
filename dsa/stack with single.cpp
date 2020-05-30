#include<stdio.h>
#include<stdlib.h>
void insert(struct node*,int);
void del(struct node*);
void display(struct node*);
struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;
int main()
{
	int ele,i;
	while(1)
	{
		printf("1.push element\n");
		printf("2.pop element\n");
		printf("3.display stack\n");
		printf("4.quit");
		printf("enter your choice\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("enter the element\n");
				scanf("%d",& ele);
				insert(top,ele);
				break;
			case 2:
				del(top);
				break;
			case 3:
				display(top);
				break;
			case 4:
				return 0;
			default:
				printf("enter the valid option\n");
		}
	}
}
void insert(struct node *temp,int ele)
{
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=top;
	top=temp;
}
void del(struct node *head)
{
	top=top->next;
	head->next=NULL;
}
void display(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;	
	}	
}
