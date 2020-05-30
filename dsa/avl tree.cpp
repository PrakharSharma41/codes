#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *right;
	struct node *left;
	int data;
	int height;
};
struct node *create(int ele);
void traverse(struct node *t);
struct node *insert(struct node*,struct node*);
struct node *right(struct node *root);
int max(int x,int y);
int height(struct node *root);
struct node *minnode(struct node *root);
struct node *del(struct node *root,int ele);
int main()
{
	struct node *root=NULL,*q=NULL;
	int ch,val,ele,x;
	while(1)
	{
		printf("1.insertion\n\n");
		printf("2.traverse\n\n");
		printf("3.exit\n\n");
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
				return 0;
			default:
				printf("invalid option");		
		}
	}
	return 0;
}
struct node *create(int ele)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=0;
	return temp;
}
int height(struct node *root)
{
	if(root==NULL)
	return -1;
	else
	return root->height;
}
int balance(struct node *root)
{
	if(root==NULL)
	return 0;
	else
	return (height(root->left)-height(root->right));
}
struct node *right(struct node *root)
{
	struct node *y=root->left;
	struct node *t=y->right;
	y->right=root;
	root->left=t;
	root->height=1+max(height(root->left),height(root->right));
	y->height=1+max(height(y->left),height(y->right));
	return y;
}
struct node *left(struct node *root)
{
	struct node *y=root->right;
	struct node *t=y->left;
	y->left=root;
	root->right=t;
	root->height=1+max(height(root->left),height(root->right));
	y->height=1+max(height(y->left),height(y->right));
	return y;
}
struct node *insert(struct node *root,struct node *temp)
{
	if(root==NULL)
	return temp;
	else if((root->data)<(temp->data))
	root->right = insert(root->right,temp);
	else
	root->left = insert(root->left,temp);
	root->height= 1+max(height(root->left),height(root->right));
	int x=balance(root);
	if( x>1 &&((temp->data) < ((root->left)->data)))
		return right(root);//left left case
	else if(x<-1 &&((temp->data) > ((root->right)->data)))
		return left(root);//right right case
	else if(x>1 &&((temp->data) > ((root->left)->data)))	
		{
			root->left=left(root->left);
			return right(root);//left right case	
		}
	else if(x<-1 &&((temp->data) < ((root->right)->data)))
	{
		root->right=right(root->right);
		return left(root);//right left case
	}
	return root;
}
void traverse(struct node *t)
{
	if(t->left)
	traverse(t->left);
	if(t->right)
	traverse(t->right);
	printf("%d\n",t->data);
}
int max(int x,int y)
{
	return ((x>y)?x:y);
}
struct node *del(struct node *root,int ele)
{
	if(ele<root->data)
	root=root->left;
	if(ele>root->data)
	root=root->right;
	else
	{
		if(root->left==NULL||root->right==NULL)
		{
			struct node *temp=root->left ? root->left:root->right;
			if(temp==NULL)
			{
				temp=root;
				root=NULL;
			}
			else
			*root=*temp;
			free(temp);
		}
		else
		{
			struct node *temp=minnode(root->right);
			root->data=temp->data;
			root->right=del(root->right,temp->data);
		}
	}
	root->height=1+max(height(root->left),height(root->right));
	int x=balance(root);
	if(x>1&&balance(root->left)>=0)
	return right(root);
	if(x>1&&balance(root->left)<0)
	{
		root->left=root->left=left(root->left);
		return right(root);
	}
	if(x<-1&&balance(root->right)<=0)
	return left(root);
	if(x<-1&&balance(root->right)>0)
	{
		root->right=right(root->left);
		return left(root);
	}
	return root;
}
struct node *minnode(struct node *root)
{
	struct node *curr=root;
	while(curr->left!=NULL)
	curr=curr->left;
	return curr;
}
