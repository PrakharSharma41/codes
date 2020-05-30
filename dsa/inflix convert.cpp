#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void push(struct node **temp,int ele)
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=ele;
	t->next=*temp;
	*temp=t;
}
int pop(struct node **top)
{
	struct node *head=*top;
	*top=(*top)->next;
	head->next=NULL;
	return (head->data);
}
int prec(char x)
{
	switch(x)
	{
		case '?':	return 0;
		case '(':return 1;
		case '+':
		case '-':return 2;
		case '*':
		case '/':return 3;
	}
}
void convert(char inflix[],char postflix[])
{
	char temp,x;
	int j=0,i=0;
	struct node *top=NULL;
	push(&top,'?');
	while((temp=inflix[i++])!='\0')
	{
		//printf("2");
		if(temp=='(')
		push(&top,'(');
		else
		{
			
			if(isalnum(temp))
			postflix[j++]=temp;
			else
			{
				if(temp==')')
				{
					while(top->data!='(')
					postflix[j++]=pop(&top);
					pop(&top);
				}
				else
				{
					while(prec(temp)<=prec(top->data))
					postflix[j++]=pop(&top);
					push(&top,temp);
				}
			}
		}
		//printf("3");
	}	//printf("4");
	while(top->data!='?')
	postflix[j++]=pop(&top); 
}
int evaluate(char postflix[])
{
	struct node *top=NULL;
	int z,i=0,x,y;
	char temp;
	while(postflix[i]!='\0')
	{temp=postflix[i];
		if(isdigit(temp))
		{
			temp=temp-48;
			push(&top,temp);
		}
		else
		{
			x=pop(&top);
			y=pop(&top);
			switch(temp)
			{
				case '+':z=x+y;break;
				case '-':z=x-y;break;
				case '*':z=x*y;break;
				case '/':z=x/y;break;
			}push(&top,z);
		}i++;
	}
	return (pop(&top));
}
int main()
{
	int x;
	char inflix[30],postflix[30];
	printf("enter the inflix expression\n");
	gets(inflix);
	convert(inflix,postflix);
	printf("postflix expression is\n");
	puts(postflix);
	x=evaluate(postflix);
	printf("value of expression is %d\n",x);
	return 0;
}
