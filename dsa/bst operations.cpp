#include<stdio.h>
#include<stdlib.h>
void insert(int);
void traverse(struct node*);
void del(int);
struct node
{
	int data;
	struct node* right;
	struct node* left;
};
struct node *root=NULL;
int main()
{	int ch,val,ele;
	while(1)
	{
		printf("1.insertion\n\n");
		printf("2.deletion\n\n");
		printf("3.traverse\n\n");
		printf("4.exit\n\n");
		printf("enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data\n\n");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2:
				printf("enter the element to delete:");
				scanf("%d",val);
				del(val);
				break;
			case 3:
				traverse(root);
				break;
			case 4:
				return 0;
			default:
				printf("invalid option");		
		}
	}
	return 0;
}
void insert(int ele)
{
	struct node *p,*t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=ele;
	t->left=NULL;
	t->right=NULL;
	p=root;
	if(root==NULL)
	root=t;
	else
	{
		struct node *curr;
		curr=root;
		while(curr)
		{
			p=curr;
			if(t->data>curr->data)
			curr=curr->right;
			else
			curr=curr->left;
		}
		if(t->data>p->data)
		p->right=t;
		else
		p->left=t;
	}
}
void traverse(struct node *t)
{
	if(t->left)
	traverse(t->left);
	printf("%d\n",t->data);
	if(t->right)
	traverse(t->right);
}
void del(int val)
{
	struct node *curr=root,*p;
	while(curr->data!=val)
	{
		p=curr;															
		if(val > curr->data)
		{
			curr=curr->right;
		}
		else
		{
		    curr=curr->left;
		}
	}//p=3000 curr=4000
	if(curr==p->right)
	{
		p->right=NULL;
	}
	else
	{
		p->left=NULL;
	}
	free(curr);
}

























