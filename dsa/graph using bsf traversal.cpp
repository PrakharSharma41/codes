#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define waiting 2
#define visited 3
#define max 100
int n,adj[max][max],queue[max],front=-1,rear=-1,state[max];
void bfs(int v);
int isempty();
void bfs_traversal();
void insertqueue(int n);
int deletequeue();
void create_graph();
int main()
{
	create_graph();
	bfs_traversal();
	return 0;
}
void bfs_traversal()
{
	int v;
	for(v=0;v<max;v++)
	state[v]=initial;
	printf("enter the start vertex for graph\n");
	scanf("%d",&v);
	bfs(v);
}
void bfs(int v)
{
	int i;
	insertqueue(v);
	//state[v]=waiting;
	while(!isempty())
	{
		int ele=deletequeue();
		printf("%d\t",ele);
		state[ele]=visited;
		for(i=0;i<max;i++)
		{
			if(adj[ele][i]==1&&state[i]==initial)
			{
				insertqueue(i);
				state[i]=waiting;
			}
		}
	}
}
void insertqueue(int n)
{
	if(rear==max-1)
	printf("queue is full\n");
	else
	{
		if(front==-1)
		front++;
		rear++;
		queue[rear]=n;
	}
}
int deletequeue()
{
	int item;
	if(front==-1||front>rear)
	{
		printf("queue is empty\n");
		exit(1);
	}
		item=queue[front];
		front++;
	return item;
}
int isempty()
{
	if(front==-1||front>rear)
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
			//adj[destination][origin]=1;
		}
	}
}
