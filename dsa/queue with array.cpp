#include<stdio.h>
struct node{
	int data[10];
	int front;
	int rear;
};
void display(struct node);
void insert(struct node*,int);
int del(struct node*);
void create(struct node*);
//void sorting(struct node*);
int binary(struct node,int);
void decimal(struct node,int);
int main()
{
	int ch,ele,i,x,n;
	struct node s ;struct node y;
//	s.top=-1;
//	create(&s);
//	printf("\n%d",s.top);
s.rear=-1;s.front=-1;
	while(1)
	{
		printf("1.insert\n");
		printf("2.delete\n");
		printf("3.display\n");
	//	printf("4.sorting\n");
		printf("5.binary\n");
		printf("6.binary display\n");
		printf("7.quit\n");
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
				 n=del(&s);
				printf("deleted element is %d\n",n);
				break;
			case 3:
				display(s);
				break;
			/*case 4:
			//	printf("1\n");
				sorting(&s);
				break;*/
			case 5:
				for(i=0;i<=s.rear;i++)
				{
					x=binary(s,s.data[i]);
					insert(&y,x);
				}
				break;
			case 6:
				display(y);
			case 7:
				return 0;
		}
	}
}
int del(struct node *s)
{
	if((s->front)==(s->rear))
	printf("string is empty");
	else
		return s->data[++(s->front)];	
}
void insert(struct node *s,int ele)
{
	if(s->rear==10)
	printf("queue is overflow\n");
	else
	{
		s->data[++(s->rear)]=ele;
	}
}
void display(struct node s)
{
	int i=0;
	while(i!=s.rear)
	{
		printf("%d\n",s.data[i]);
		i++;
	}printf("%d\n",s.data[i]);
}
int binary(struct node s,int num)
{
	//printf("1\n");
	int rem,bn=0,temp=1;
		while(num!=0)
		{
			rem=num%2;
			num/=2;
			bn=bn+temp*rem;
			temp=temp*10;
		}
		return (bn);
}
