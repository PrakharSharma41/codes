#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
struct node{
	int data;
	struct node *link;
};
int top=-1;
struct node *root;
void push(int);
void pop();
void peek();
void traverse();
int main()
{
	int ch,i,ele;
	while(1)
	{
		printf("1.push \n");
		printf("2.pop\n");
		printf("3.peek\n");
		printf("4.traverse\n");
		printf("5.quit\n\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the element");
				scanf("%d",&ele);
				push(ele);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				traverse();
				break;
			case 5:
				return 0;
				break;
			default:
				printf("invalid option\n\n");
		}
	}
	return 0;
}
void push(int ele)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->link=root;
	root=temp;
}
void pop()
{
	struct node *temp;
	temp=root;
	if(root=NULL)
	printf("stack is empty\n\n");
	else
	{
	root=root->link;
	temp->link=NULL;
	free(temp);
	}
}
void peek()
{
	struct node *temp=root;
	printf("peek element is %d\n\n",temp->data);
}
void traverse()
{
	struct node *temp=root;
	if(root==NULL)
	printf("stack is empty\n\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d\t\t",temp->data);
			temp=temp->link;			
		}
	}
}





