#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
int main()
{
	int num;
	printf("enter value of data");
	scanf("%d",&num);
	while(num!=2)
	{
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter the data");
		scanf("%d",&num);
		temp->data=num;
		temp->right = NULL;
		temp->left = NULL;
		if(root==NULL)
		{
			root =temp;
		}
		else
		{
			temp->right=root;
			root->left=temp;
			root=temp;
		}
	}
	struct node *temp=root;
	while(temp->right!=NULL)
	{
		printf("%d",temp->data);
	}
	return 0;
}
