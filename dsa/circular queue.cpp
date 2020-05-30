#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
void insert(int);
void del(void);
void traverse(void);
int front=-1,rear=-1;
int cqueue[CAPACITY];
int main()
{	
	
	int ch;
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
				int ele;
				printf("enter the element:\n\n");
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
	if(front==rear+1||CAPACITY==rear+1)
	printf("queue is full");
	else if(front=-1&&rear==-1)
	{
		front=0;rear=0;
		cqueue[rear]=ele;
	}
	else if(rear==CAPACITY-1)
	{
		rear=0;cqueue[rear]=ele;
	}
	else
	{
		rear++;
		cqueue[rear]=ele;
	}
}
void del(void)
{
	int ele;
	if(front==-1&&rear==-1)
	printf("queue is empty");
	else if(front==CAPACITY-1)
	{
		ele=cqueue[front];
		front=0;
	}
	else if(front==rear)
	{
		ele=cqueue[front];
		front=-1;rear=-1;
	}
	else
	{
		ele=cqueue[front];
		front++;
	}
}
void traverse(void)
{
	int i;
	if(front==-1&&rear==-1)
	printf("queue is empty\n");
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\n\n",cqueue[i]);
		}
	}
}









