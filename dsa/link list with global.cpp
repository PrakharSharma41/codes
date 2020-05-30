#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *link;
	int data;
};
void create(int);
void display();
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
				create(ele);
				break;
			case 2:
				display();
				break;
			case 3:
				return 0;
		}
	}
	return 0;
}
void create(int d)
{
	struct node *temp=root;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->link=NULL;
	if(root==NULL)
	root=temp;
	else
	{
		struct node *p=root;
		while(p->link!=NULL)
		p=p->link;
		p->link=temp;
	}
}
void display()
{struct node *temp=root;
	if(root==NULL)
	printf("empty");
	else
	{
		while(temp!=NULL)
		{
			printf("%d\t\t",temp->data);
			temp=temp->link;
		}
	}
}
