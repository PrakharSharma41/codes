#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	struct node *right;
	int data;
};
struct node *create(int);
void display(struct node*);
void display3(struct node*);
int main()
{
	struct node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->left->right=create(5);
	root->right->right=create(6);
	root->right->left=create(7);
	display(root);
	display3(root);
	return 0;
}
struct node *create(int d)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void display(struct node *curr)
{
	if(curr->left)
	display(curr->left);
	printf("%d",curr->data);
	if(curr->right)
	display(curr->right);
}
void display3(struct node *curr)
{
	if(curr->left)
	display3(curr->left);
	if(curr->right)
	display3(curr->right);
	printf("%d\n",curr->data);
}
