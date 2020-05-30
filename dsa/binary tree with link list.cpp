#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *right;
	struct node *left;
};
void insert(struct node **root,int ele);
void display2(struct node*);
void display3(struct node*);
void display1(struct node*);
int main()
{
	struct node *root=NULL;
	int ch,ele;
	while(1)
	{
		printf("1.insert node\n");
		printf("2.display tree in inorder\n");
		printf("3.display tree in preorder\n");
		printf("4.display tree in postorder\n");
		printf("5.quit\n");
		printf("enter your choice\n");
		scanf("%d",&ele);
		switch(ele)
		{
			case 1:
				printf("enter the data of node\n");
				scanf("%d",&ch);
				insert(&root,ch);
			//	printf("%d",root->data);
				break;
			case 2:
				//printf("%d",root->data);
				display1(root);
				break;
			case 3:
				display2(root);
				break;
			case 4:
				display3(root);
				break;
			case 5:
				return 0;
			default:
				printf("enter valid option\n");
		}
	}
	return 0;
}
void insert(struct node **root,int ele)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->right=NULL;temp->left=NULL;
	if(*root==NULL)
	*root=temp;
	else
	{
		struct node *curr=*root,*p=*root;
		while(curr)
		{
			p=curr;
			if(temp->data>curr->data)
			curr=curr->right;
			else
			curr=curr->left;
		}
		if(temp->data>p->data)
		p->right=temp;
		else
		p->left=temp;
	}
//	display(root);
}
void display1(struct node *curr)
{
	if(curr->left)
		display1(curr->left);
		printf("%d\n",curr->data);
	if(curr->right)
		display1(curr->right);
}
void display2(struct node *curr)
{
	printf("%d\n",curr->data);
	if(curr->left)
	display2(curr->left);
	if(curr->right)
	display2(curr->right);
}
void display3(struct node *curr)
{
	if(curr->left)
	display3(curr->left);
	if(curr->right)
	display3(curr->right);
	printf("%d\n",curr->data);
}
