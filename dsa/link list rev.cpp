#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *link;
};
void insert(struct node*,int);
void del(struct node*);
void traverse(struct node*);
void swap(struct node*);
struct node* root=NULL;
int main()
{
	int ch,ele;
	while(1)
	{
	
		
		printf("1.insert\n\n");
		printf("2.delete\n\n");
		printf("3.traverse\n\n");
		printf("4.swap\n\n");
		printf("5.quit");
		printf("enter your choice \n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data\n\n");
				scanf("%d",&ele);
				insert(root,ele);
			//	printf("%d",root->data);
				break;
			case 2:
				del(root);
				break;
			case 3:
				traverse(root);
				break;
			case 4:
				swap(root);
				break;
			case 5:
				return 0;
			default:
				printf("enter valid option\n\n");
		}
	
	}
	return 0;
}
void insert(struct node *root,int ele)
{
	struct node * temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->link=NULL;
	if(root==NULL)
	root=temp;
	else
	{
		struct node *p=root;
		while(p->link!=NULL)
		p=p->link;
		p->link=temp;
	}//	traverse(root);	
}
void del(struct node *root)
{
	int pos,i=1;
	printf("enter  the location to delete\n\n");
	scanf("%d",&pos);
	struct node *q,*p=root;
	while(i<pos-1)
	{
		i++;
		p=p->link;
	}q=p->link;
	p->link=q->link;
	q->link=NULL;
	free(q);
}
void traverse(struct node *root)
{
	struct node *temp=root;
	while(temp!=NULL)
	{
		printf("%d\t\t",temp->data);
		temp=temp->link;
	}
}
void swap(struct node *root)
{
	struct node *temp,*p=root,*q=root;
	int i=1,j=1,loc;
	printf("enter the location\n\n");
	scanf("%d",&loc);
	while(i<loc)
	{
		p=p->link;i++;
	}
	while(j<loc-2)
	{
		q=q->link;j++;
	}
	temp=q->link;
	q->link=p;
	temp->link=p->link;
	p->link=temp;
}
