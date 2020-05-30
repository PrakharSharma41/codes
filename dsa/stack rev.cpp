#include<stdio.h>
#define CAPACITY 5
void insert(int);
int pop();
int isfull();
int isempty();
void peek();
int top=-1,stack[CAPACITY];
int main()
{
	int ele,i,ch;
	while(1)
	{
		printf("1.insert\n\n");
		printf("2.pop\n\n");
		printf("3.peek\n\n");
		printf("4.quit\n\n");
		printf("enter ur choice\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the element\n\n");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				return 0;
			default:
				printf("enter valid option\n\n");
		}
	return 0;
}
void insert(int ele)
{
	if(isfull())
	printf("stack is full\n\n");
	else
	{
		top++;
		stack[top]=ele;
	}
} 
int pop()
{
	if(isempty)
	printf("stack is empty\n\n");
	else
	{
		return stack[top--];
	}
}
void peek()
{
	printf("%d\n\n",stack[top]);
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
