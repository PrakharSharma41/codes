//#include<stdio.h>
//#include<stdlib.h>
//struct node{
//	struct node *right;
//	struct node *left;
//	int data;
//};
//struct node *create(int ele);
//void traverse(struct node *t);
//struct node *insert(struct node*,struct node*);
//struct node *search(struct node*,struct node**,int);
//struct node *del(struct node*,struct node*,int);
//void floor(struct node*,struct node*,int);
//struct node *findfloor(struct node *root,struct node **q,int ele);
//int main()
//{
//	struct node *root=NULL,*q=NULL;
//	int ch,val,ele,x;
//	while(1)
//	{
//		printf("1.insertion\n\n");
//		printf("2.searching\n\n");
//		printf("3.traverse\n\n");
//		printf("4.delete\n\n");
//		printf("5.floor of an element\n\n");
//		printf("6.exit\n\n");
//		printf("enter your choice:\n");
//		scanf("%d",&ch);
//		switch(ch)
//		{
//			case 1:
//				printf("enter the data\n\n");
//				scanf("%d",&ele);
//				root=insert(root,create(ele));
//				break;
//			case 2:
//				printf("enter the element to search:");
//				scanf("%d",&val);
//				
//				printf("\nelement found is %d\n",search(root,&q,val)->data);
//				printf("\nparent of element found is %d\n",q->data);
//				break;
//			case 3:
//				traverse(root);
//				break;
//			case 4:
//				printf("enter the element to delete\n");
//				scanf("%d",&ele);
//				root=del(root,q,ele);
//				break;
//			case 5:
//				printf("enter the element to find floor\n");
//				scanf("%d",&ele);
//				floor(root,q,ele);
//				break;
//			case 6:
//				return 0;
//			default:
//				printf("invalid option");		
//		}
//	}
//	return 0;
//}
//struct node *del(struct node *root,struct node *q,int ele)
//{
//	struct node *p=(struct node*)malloc(sizeof(struct node));
//	p=search(root,&q,ele);
//	if(p==NULL)
//	{
//		return NULL;
//	}	
//		//deleting node with zero child
//	if(p->left==NULL&&p->right==NULL)
//		{
//				if(p == q->left)
//				q->left=NULL;
//				else
//				q->right=NULL;
//			free(p);
//		}
//	else  
//		{
//			//deleting node with one child
//			if(p->left==NULL)
//			{
//				if(p == q->left)
//				q->left=p->right;
//				else
//				q->right=p->right;
//			}
//			if(p->right==NULL)
//			{
//				if(p == q->left)
//				q->left=p->left;
//				else
//				q->right=p->left;
//			}
//		//deleting node with two child
//			else
//			{
//				struct node *fp=p;
//				struct node *rp=p->right;
//				struct node *s=rp->left;
//				while(s!=NULL)
//				{
//					fp=rp;
//					rp=s;
//					s=rp->left;
//				}
//				if(fp!=p)
//				{
//					if(p==q->left)
//					q->left=rp;
//					else
//					q->right=rp;
//					rp->left=p->left;
//					fp->left=rp->right;
//					rp->right=p->right;
//				}
//				else
//				{
//					if(p==q->left)
//					q->left=rp;
//					else
//					q->right=rp;
//					rp->left=p->left;
//				}
//				free(p);
//			}
//		}
//	return root;
//}
//struct node *create(int ele)
//{
//	struct node *temp=(struct node*)malloc(sizeof(struct node));
//	temp->data=ele;
//	temp->left=NULL;
//	temp->right=NULL;
//	return temp;
//}
//struct node *insert(struct node *root,struct node *temp)
//{
//	if(root==NULL)
//	return temp;
//	else if((root->data)<(temp->data))
//	root->right = insert(root->right,temp);
//	else
//	root->left = insert(root->left,temp);
//	return root;
//}
//void traverse(struct node *t)
//{
//	if(t!=NULL)
//	{		
//	if(t->left)
//	traverse(t->left);
//	printf("%d\n",t->data);
//	if(t->right)
//	traverse(t->right);
//	}
//	else
//	printf("bst is now empty\n");
//}
//void floor(struct node *root,struct node *q,int ele)
//{
//		struct node *p=(struct node*)malloc(sizeof(struct node));
//	p=findfloor(root,&q,ele);
//	printf("floor is %d\n",q->data);
//}
//struct node *findfloor(struct node *root,struct node **q,int ele)
//{
//	*q=root;
//	while( root->data <ele&&((*q)->data<=ele))
//	{
//		*q=root;
//		if(root->data <ele)
//		root=root->right;
//		else
//		root=root->left;
//	}
//	if(root->data==ele)
//		*q=root;
//	else
//	return root;
//}
//struct node *search(struct node *root,struct node **q,int ele)
//{
//	*q=NULL;
//	while(root!=NULL&&root->data!=ele)
//	{
//		*q=root;
//		if(root->data <ele)
//		root=root->right;
//		else
//		root=root->left;
//	}
//	if(root==NULL)
//	return NULL;
//	else
//	return root;
//}
#include<stdio.h>
int main()
{
    int i,j,k=0,a[6][6],sum[16],max=-100;
    for(i=0;i<6;i++)
    for(j=0;j<6;j++)
    scanf("%d",&a[i][j]);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
          sum[k] = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1] + a[i+1][j] + 
          a[i+1][j+1] + a[i+1][j+2];
          if(max<sum[k])
          max=sum[k];
            k++;
        }
    }
    for(i=0;i<16;i++)
    printf("%d\t\t",sum[i]);
    printf("max is %d",max);
    return 0;
}

