#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int *next;
};
void insert(int);
void traverse();
void del(int);
struct node *root=NULL;
int main()
{
//	struct node *root=NULL;
	int ch,n;
	while(1)
	{
		printf("1.insert\n\n");
		printf("2.delete\n\n");
		printf("3.traverse\n\n");
		printf("4.delete\n\n");
		printf("5.quit\n\n");
		printf("enter your choice\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data\n\n");
				scanf("%d",&n);
				insert(n);
				break;
			case 2:
				printf("enter the element to delete\n\n");
				scanf("%d",&n);
				del(n);
				break;
			case 3:
				traverse();
				break;
			case 4:
				return 0;
		}
	}
	return 0;
}
void insert(int n)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;temp->next=NULL;
	if(root==NULL)
	root=temp;
	else
	{
		struct node *p=root;
		while(p->next!=NULL)
		p=p->next;
		p->next=temp;
	}
}
void traverse()
{
	struct node *temp=root;
	while(temp->next!=NULL)
	{
		printf("%d\t\t",temp->data);
		temp=temp->next;
	}
}
void del(int n)
{
	struct node *temp=root,*p;
	while(temp->data!=n)
	{
		p=temp;
		temp=temp->next;
	}
	p->next=temp->next;
	temp->next=NULL;
}
