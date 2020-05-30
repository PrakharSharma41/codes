#include<stdio.h>
struct node {
	struct node *right;
	struct node *left;
	int data;
};
struct node *root=NULL;
void insert(int);
void traverse();
int main()
{
	while(1)
	{
		int ch,ele;
		printf("1.insert\n\n");
		printf("2.traverse\n\n");
		printf("3.quit\n\n");
		printf("enter your choice\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2:
				traverse();
				break;
			case 3:
				return 0;
			default:
				printf("enter valid option\n\n");
		}
	}
	return 0;
}
void insert(int ele)
{
	struct node *temp;
	temp->right=NULL;
	temp->left=NULL;
	temp->data=ele;
	if(root==NULL)
	root=temp;
	else
	{
		struct node *p=root;
		while(p->right!=NULL)
		p=p->right;
		p->right=temp;
		temp->left=p;
	}
}
void traverse()
{
	struct node *temp=root;
	while(temp->right!=NULL)
	{
	printf("%d\t\t",temp->data);temp=temp->right;
	}
}
