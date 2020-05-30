#include<stdio.h>
#define CAPACITY 5
void push(int);
int pop(void);
void peek(void);
int isfull(void);
int isempty(void);
void traverse(void);
int stack[CAPACITY];
int top=-1;
int main()
{
	int ch;
	int item;
	while(1)
	{
		printf("1.push \n");
		printf("2.pop\n");
		printf("3.peek\n");
		printf("4.traverse\n");
		printf("5.quit");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the element");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				traverse();
				break;
			case 5:
				return 0;
				break;
			default:
				printf("invalid option");
		}
	}
	return 0;
}
void push(int item)
{
	if(isfull())
	printf("stack is full");
	else
	{
		top++;
		stack[top]=item;
		printf("%d is pushed",stack[top]);
	}
}
int pop()
{
	if(isempty())
	return 0;
	else
	{
		printf("%d is poped",stack[top--]);
		return top;
	}
}
void peek()
{
	if(isempty())
	printf("stack is underflow");
	else
	{
		printf("%d is peek element",stack[top]);
	}
}
void traverse()
{
	int i;
	if(isempty())
	printf("stack is underflow");
	else
	{
		for(i=0;i<=top;i++)
		printf("%d\n",stack[i]);
	}
}
int isfull()
{
	if(top==CAPACITY-1)
	return 1;
	else
	return 0;
}
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}











