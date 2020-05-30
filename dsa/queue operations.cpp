#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
void insert(void);
void del(void);
void traverse(void);
int front=0,rear=0;
int queue[CAPACITY];
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
				insert();
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
void insert(void)
{
	int ele;
	if(rear==CAPACITY)
	printf("queue is full\n\n");
	else
	{
		printf("enter the element\n\n");
		scanf("%d",&ele);
		queue[rear]=ele;
		rear++;
	}
}
void del(void)
{
	//printf("%d",rear);
	int i;
	if(front==rear)
	printf("queue is empty\n\n");
	else
	printf("deleted item is %d\n\n",queue[front]);
	for(i=0;i<rear-1;i++)
	{
		queue[i]=queue[i+1];
		rear--;
	}
}
void traverse(void)
{
	int i;
	if(front==rear)
	printf("queue is empty\n\n");
	else
	for(i=front;i<rear;i++)
	printf("%d\n",queue[i]);
}









