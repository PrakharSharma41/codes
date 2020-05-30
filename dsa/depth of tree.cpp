#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *right;
	struct node *left;
	int data;
};
struct node *create(int ele);
void traverse(struct node *t);
struct node *insert(struct node*,struct node*);
int depth(struct node*,int);
int main()
{
	struct node *root=NULL,*q=NULL;
	int ch,val,ele,x;
	while(1)
	{
		printf("1.insertion\n\n");
		printf("2.traverse\n\n");
		printf("3.depth\n\n");
		printf("4.quit\n\n");
		printf("enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data\n\n");
				scanf("%d",&ele);
				root=insert(root,create(ele));
				break;
			case 2:
				traverse(root);
				break;
			case 3:
				printf("enter the data to find its depth\n");
				scanf("%d",&ele);
				printf("depth of %d is %d\n",ele,depth(root,ele));
				break;
			case 4:
				return 0;
			default:
				printf("invalid option");		
		}
	}
	return 0;
}
int depth(struct node *root,int ele)
{
	if(root==NULL||root->data==ele)
	return 0;
	else
	{
		int left=depth(root->left,ele);
		int right=depth(root->right,ele);
		if(left>right)
		return (left+1);
		else
		return (right+1);
	}
}
struct node *create(int ele)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node *insert(struct node *root,struct node *temp)
{
	if(root==NULL)
	return temp;
	else if((root->data)<(temp->data))
	root->right = insert(root->right,temp);
	else
	root->left = insert(root->left,temp);
	return root;
}
void traverse(struct node *t)
{
	if(t!=NULL)
	{		
	if(t->left)
	traverse(t->left);
	printf("%d\n",t->data);
	if(t->right)
	traverse(t->right);
	}
	else
	printf("bst is now empty\n");
}
