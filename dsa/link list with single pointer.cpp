#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *link;
	int data;
};
struct node *create(struct node*,int);
void display(struct node*);
struct node *root=NULL;
int main()
{
	int ch;
	while(1)
	{
		int ele;
		printf("1.insert\n");
		printf("2.display\n");
		printf("3.quit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the element\n");
				scanf("%d",&ele);
				root=create(root,ele);
				break;
			case 2:
				display(root);
				break;
			case 3:
				return 0;
		}
	}
	return 0;
}
struct node *create(struct node *r,int d)
{
	struct node *temp=root;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->link=NULL;
	if(root==NULL)
	r=temp;
	else
	{
		struct node *p=r;
		while(p->link!=NULL)
		p=p->link;
		p->link=temp;
	}return r;
}
void display(struct node *temp)
{
	
		while(temp!=NULL)
		{
			printf("%d\t\t",temp->data);
			temp=temp->link;
		}
}
