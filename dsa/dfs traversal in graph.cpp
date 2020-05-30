#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define waiting 2
#define visited 3
#define max 100
int n,adj[max][max],stack[max],top=-1,state[max];
void dfs(int v);
int isempty();
void dfs_traversal();
void pushstack(int n);
int popstack();
void create_graph();
int main()
{
	create_graph();
	dfs_traversal();
	return 0;
}
void dfs_traversal()
{
	int v;
	for(v=0;v<max;v++)
	state[v]=initial;
	printf("enter the start vertex for graph\n");
	scanf("%d",&v);
	dfs(v);
}
void dfs(int v)
{
	int i;
	pushstack(v);
	state[v]=waiting;
	while(!isempty())
	{
		int ele=popstack();
		printf("%d\t",ele);
		state[ele]=visited;
		for(i=0;i<max;i++)
		{
			if(adj[ele][i]==1&&state[i]==initial)
			{
				pushstack(i);
				state[i]=waiting;
			}
		}
	}
}
void pushstack(int n)
{
	if(top==max-1)
	printf("stack is full\n");
		top++;
		stack[top]=n;
}
int popstack()
{
	int item;
	if(top==-1)
	{
		printf("stack is empty\n");
		exit(1);
	}
		item=stack[top];
		top--;
	return item;
}
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
void create_graph()
{
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	int maxedge=n*(n-1),origin,destination;
	for(int i=1;i<=maxedge;i++)
	{
		printf("enter the origin and destiantion vertices\n");
		scanf("%d%d",&origin,&destination);
		if(origin==-1&&destination==-1)
		break;
		else
		{
			adj[origin][destination]=1;
			adj[destination][origin]=1;       
		}
	}
}
