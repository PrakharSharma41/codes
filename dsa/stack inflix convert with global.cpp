#include<stdio.h>
#include<ctype.h>
#include<string.h>
char stack[20];
int top=-1;
int pre(char x)
{
	if(x=='(')
	return 0;
	if(x=='+'||x=='-')
	return 1;
	if(x=='*'||x=='/')
	return 2;
}
void push(char x)
{
	stack[++top]=x;
}
char pop()
{
	if(top==-1)
	return -1;
	else
	return stack[top--];
}
int main()
{
	char postflix[20];                                 /*replace postflix with inflix*/
	char *inflix,x;
	printf("enter the inflix expression\n");
	gets(postflix);
	inflix=postflix;
	while(*inflix!='\0')
	{
		if(isalnum(*inflix))
			printf("%c",*inflix);
		else if(*inflix=='(')
		push(*inflix);
		else if(*inflix==')')
		{
			while((x=pop())!='(')
			printf("%c",x);
		}
		else
		{
			while(pre(stack[top])>=pre(*inflix))
			printf("%c",pop());
			push(*inflix);
		}
		inflix++;
	}
	while(top!=-1)
	printf("%c",pop());
	return 0;
}
