#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void sorting(struct node**,struct node*);
void insert(struct node**,int);
void del(struct node**);
void display(struct node*);
int main()
{
	struct node *top=NULL;
	struct node *sort=NULL;
	int ele,i;
	while(1)
	{
		printf("1.push element\n");
		printf("2.pop element\n");
		printf("3.display stack\n");
		printf("4.sorting\n");
		printf("enter your choice\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("enter the element\n");
				scanf("%d",& ele);
				insert(&top,ele);
				break;
			case 2:
				del(&top);
				break;
			case 3:
				display(top);
				break;
			case 4:
				sorting(&sort,top);
				break;
			default:
				printf("invalid option\n");
				return 0;
		}
	}
}
void insert(struct node **temp,int ele)
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=ele;
	t->next=*temp;//*temp and top are same
	*temp=t;
}
void del(struct node **top)
{
	struct node *head=*top;
	*top=(*top)->next;
	head->next=NULL;
}
void display(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;	
	}	
}
/*void sorting(struct node *top)
{
	struct node *ptr1=top;struct node *ptr2;
	int temp;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
		{
			if(ptr1->data > ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}ptr2=ptr2->next;
		}ptr1=ptr1->next;
	}
}*/
void sorting(struct node **sort,struct node *p)
{
	printf("1");
		while(p!=NULL)
		{printf("2");
			struct node *t=(struct node*)malloc(sizeof(struct node));
			t->data=p->data;t->next=NULL;
			if(*sort==NULL)
			{printf("3");
				t->next=*sort;
				*sort=t;
			}
			else
			{printf("4");
				struct node *q=*sort;
				if(t->data<((*sort)->data))
				{printf("5");
					while((t->data)< ((q->next)->data))                                                 
					{	printf("6");
							q=q->next;
					}printf("7");
						t->next=q->next;
						q->next=t;
				}
				else
				{
					t->next=*sort;
					*sort=t;
				}
			}
			p=p->next;
		}
}
