#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void convert(char inflix[],char postflix[]);
void precedence(char);
struct node{
	int data[50];
	int top;
};
int main()
{
	char infix[30],postfix[30];
	printf("enter the infix string\n");
	gets(infix);
	convert(infix,postfix);
	return 0;
}
void convert(char infix[30],char postfix[30])
{
	char temp,x;
	struct node s;
	int i,j=0;
	for(i=0;infix[i]!='\0';j++)
	{
		temp=infix[i];
		if(isalnum(temp))
		postfix[j++]=temp;
		else if(token=='(')
		push(&s,'(');
		else if(token==')')
		{
			while(x=pop(&s)!=')')
			postfix[j++]=x;
		}
		else
		{
			while(precedence(token)<precedence(top(&s)))
			{
				x=pop(&s);
				postfix[j++]=x;
			}
			push(&s,temp);
		}
	}
	while(!empty(&s))
	{
		x=pop(&s);
		postfix[j++]=x;
	}
	postfix[j]='\0';
}















