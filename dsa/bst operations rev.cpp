#include<stdio.h>
#include<stdlib.h>
void insert(int);
void traverse(struct node*);
void traverses(struct node*);
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
		printf("3.display tree 1\n\n");
		printf("4.display tree 2\n\n");
		printf("5.exit\n\n");
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
				traverses(root);
				break;
			case 5:
				return 0;
			default:
				printf("invalid option");		
		}
	}
	return 0;
}
void insert(int ele)
{
	struct node *t,*p;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=ele;t->left=NULL;t->right=NULL;//t->data is not giving error-it is a doubt
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
void del(int n)
{
	struct node *curr,*p;
	curr=root;
	while(curr->data!=n)
	{
		p=curr;
		if(n>curr->data)
		curr=curr->right;
		else
		curr=curr->left;
	}
	if(curr->right==NULL&&curr->left==NULL)
	{
		if(curr=p->right)
		p->right=NULL;
		else
		p->left=NULL;
	}
	else if(curr->left!=NULL&&curr->right==NULL)
	{
		struct node *t1=curr->left,*t2=curr->left;
		if(t2->right!=NULL)
		{
			while(t2->right!=NULL)
			{
				t1=t2;
				t2=t2->right;
			}
			p->right=t2;
			t2->left=curr->left;
			t1->right=NULL;
			free(curr);
		}
		else
		p->right=t2;
		free(curr);
	}
	else if(curr->right!=NULL&&curr->left==NULL)
	{
		struct node *t1=curr->right,*t2=curr->right;
		if(t2->left!=NULL)
		{
			while(t2->left!=NULL)
			{
				t1=t2;
				t2=t2->left;
			}
			p->left=t2;
			t2->right=curr->right;
			t1->left=NULL;
			free(curr);
		}
		else
		p->left=t2;
		free(curr);
	}	
}
void traverse(struct node *t)
{
	if(t->left)
	traverse(t->left);                          // inorder traversal
	printf("%d\t\t",t->data);
	if(t->right)
	traverse(t->right);
}
void traverses(struct node *t)
{
	printf("%d\t\t",t->data);
	if(t->left)                                //preorder traversal
	traverses(t->left);
	if(t->right)
	traverses(t->right);
}
















