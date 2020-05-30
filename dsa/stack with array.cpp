#include<stdio.h>
struct node{
	int data[10];
	int copy[10];
	int top;
};
void display(struct node);
void insert(struct node*,int);
void del(struct node*);
void create(struct node*);
void sorting(struct node*);
int main()
{
	int ch,ele;
	struct node s;
	s.top=-1;
//	create(&s);
	printf("\n%d",s.top);
	while(1)
	{
		printf("1.insert\n");
		printf("2.delete\n");
		printf("3.display\n");
		printf("4.sorting\n");
		printf("5.quit\n");
		printf("enter your choice\n.");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the element\n");
				scanf("%d",&ele);
				insert(&s,ele);
				break;
			case 2:
				del(&s);
				break;
			case 3:
				display(s);
				break;
			case 4:
			//	printf("1\n");
				sorting(&s);
				break;
			case 5:
				return 0;
		}
	}
}
void sorting(struct node *s)
{
//printf("2\n");
	int temp,i,j;
	for(i=0;i<=s->top;i++)
	{//printf("3\n");
		for(j=0;j< s->top-i;j++)
		{
			if(s->data[j] > s->data[j+1])
			{
				temp=s->data[j];
				s->data[j]=s->data[j+1];
				s->data[j+1]=temp;
			}
		}
	}
}
/*void create(struct node *s)
{
	s->top=-1;
	printf("%d",s->top);
}*/
void insert(struct node *s,int ele)
{
	if(s->top==9)
	printf("stack overflow\n");
	else
	{
		s->data[++(s->top)]=ele;
	}
	
}
void del(struct node *s)
{
	if(s->top==-1)
	printf("stack underflow\n");
	else
	{
		(s->top)--;
	}
}
void display(struct node s)
{
	int i=0;
//	printf("%d\n",s.top);
	while(i!=s.top)
	{
		printf("%d\n",s.data[i]);
		i++;
	}printf("%d\n",s.data[i]);
}
