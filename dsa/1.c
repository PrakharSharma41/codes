#include<stdlib.h>
#include<stdio.h>
struct node{
	int data;
	struct node *link;
};
void create(struct node**,int);
void length(struct node*,int);
void display(struct node*);
void sort(struct node*);
void main()
{
int n,count,x;
struct node *head=NULL;
	while(1)
	{
		printf("enter the data\n");
		scanf("%d",&x);
		if(x<0)
			break;
		else
			create(&head,x);
	}
	display(head);
	printf("enter the value of n\n");
	scanf("%d",&n);
	length(head,n);
	display(head);
	printf("1");
	sort(head);
	printf("2");
}
void create(struct node **header,int x)
{
struct node *t=(struct node*)malloc(sizeof(struct node));
t->data=x;
	if(*header==NULL)
		t->link=NULL;
	else
	t->link=*header;
	*header=t;
}
void length(struct node *header,int n)
{
struct node *a=header,*p=header,*q;
	int loc,i=1,count=1,z,j=1;
	while(header!=NULL)
	{
		count++;
		header=header->link;
	}
	loc=count/2;
	z=count-n;
	while(j<=z-1)
	{
		a=a->link;j++;
	}
	printf("nth node from end is %d\n",a->data);
	while(i<loc-1)
	{
		p=p->link;i++;
   }
	q=p->link;
	printf("middle element is %d\n",q->data);
	p->link=q->link;
	q->link=NULL;
	free(q);
}	
void display(struct node *header)
{
	while(header!=NULL)
	{
		printf("%d\t\t",header->data);
		header=header->link;
	}
}
void sort(struct node *header)
{int x;
	printf("3");
	struct node *prev=(struct node*)malloc(sizeof(struct node));
	prev->data=header->data;
	prev->link=NULL;
	while(header->link!=NULL)
	{printf("4");
		header=header->link;
		printf("9");
		if((header->data)<(prev->data))
			{header->data=x;
				printf("8");
				create(&prev,x);
			}
		else
		{printf("7");
			struct node *last=prev;
			while(last->data < header->data)
				last=last->link;
			last->link=header;last=last->link;
			last->link=NULL;		
		}	printf("6");
	}printf("5");
		printf("sorted list is:\n");
	display(prev);
}	
	
	
	
	
	
	
	
	
	

