#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char ch[50];
	struct node *next;
};
void insert(struct node**);
void display(struct node*);
void del(struct node**,int);
int main()
{
	struct node *top=NULL;
//	char str[50];
	char *ptr;
	int ch,pos;
	while(1)
	{
		printf("1.enter the string\n");
		printf("2.display\n");
		printf("3.delete an element\n");
		printf("4.quit.\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert(&top);
				break;
			case 2:
				display(top);
				break;
			case 3:
				printf("enter the position");
				scanf("%d",&pos);
				del(&top,pos);
				break;
			case 4:
				return 0;
		}
	}
	return 0;
}
void insert(struct node **top)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
		scanf("%s",temp->ch);
	temp->next=NULL;
	if(*top==NULL)
	{
		*top=temp;
		//puts(temp->ch);
	}
	else
	{printf("1");
		struct node *p=*top;
		while(p->next!=NULL)
			{
				printf("2.");
				p=p->next;
			}printf("2.");
		p->next=temp;
		printf("2");
	}
}
void display(struct node *top)
{
	struct node *temp=top;
	while(temp!=NULL)
	{
		printf("%s\n",temp->ch);
		temp=temp->next;
	}
}
void del(struct node **top,int pos)
{
	struct node *temp=*top,*q;
	int i=1;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}q=temp->next;
	temp->next=q->next;
	free(q);
}
