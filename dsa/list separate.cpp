#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void create(struct node**,int);
void display(struct node*);
void separate(struct node*,struct node*,struct node*);
void del(struct node*,int);
int main()
{
	struct node *head=NULL,*odd=NULL,*even=NULL;
	int ch,d,n;
	while(1)
	{
		printf("1.enter the data\n");
		printf("2.display the list\n");
		printf("3.separate\n");
		printf("4.delete\n");
		printf("5.quit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the element\n");
				scanf("%d",&d);
				create(&head,d);break;
			case 2:
				display(head);break;
			case 3:
				separate(head,even,odd);
				break;
			case 4:
				printf("enter the element to delete\n\n");
				scanf("%d",&n);
				del(head,n);
				break;
			case 5:
				return 0;
			default:
				printf("enter valid option\n");
		}
	}
	return 0;
}
void del(struct node *header,int n)
{
	struct node *t=NULL;
	while(header->next->data!=n)
	{
		header=header->next;
	}
	header->next=t;
	t=t->next;
	header->next=t;
}
void create(struct node **header,int d)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=d;
	if(*header==NULL)
	t->next=NULL;
	else
	t->next=*header;
	*header=t;
}
void display(struct node *header)
{
	while(header!=NULL)
	{
		printf("%d\t\t",header->data);
		header=header->next;
	}printf("\n");
}
void separate(struct node *header,struct node *even,struct node *odd)
{
	while(header!=NULL)
	{
		if(header->data%2==0)
		create(&even,header->data);
		else
		create(&odd,header->data);
		header=header->next;
	}display(even);
	printf("\n");
	display(odd);printf("\n");
}

