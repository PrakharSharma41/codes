#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int front=-1,rear=-1;
int cqueue[SIZE];
void traverse();
void insert(int);
void del();
int main()
{
	int ch,ele;
	while(1)
	{
		printf("1.insert\n\n");
		printf("2.delete\n\n");
		printf("3.traverse\n\n");
		printf("4.quit\n\n");
		printf("enter your choice\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the element\n\n");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2:
				del();
				break;
			case 3:
				traverse();
				break;
			case 4:
				return 0;
			default:
				printf("invalid option\n\n");
		}
	}
	return 0;
}
void insert(int ele)
{
	if(SIZE==rear+1||front==rear+1)
	{
		printf("cicular queue is full\n\n");
		rear=-1;
	}
	else if(rear==-1&&front==-1)
	{
		rear=0;front=0;cqueue[rear]=ele;
	}
	else
	{
		rear++;
		cqueue[rear]=ele;
	}
}
void del()
{
	int ele;
	if(front==-1&&rear==-1)
	printf("circular queue is empty\n\n");
	else if(front==SIZE-1)
	{
		front=-1;ele=cqueue[front];
		//printf("abcd");
		printf("deleted element is %d\n\n",cqueue[front]);
	}
	else if(front==rear)
	{
	front=-1;rear=-1;
	}
	else
	{
		ele=cqueue[front];
		//printf("abcd");
		printf("deleted element is %d\n\n",cqueue[front]);
		front++;
	}
}
void traverse()
{
	int i;
	if(front==-1&&rear==-1)
	printf("queue is empty\n\n");
	else
	{
		for(i=front;i<=rear;i++)
		printf("%d\t\t",cqueue[i]);
	}
}
