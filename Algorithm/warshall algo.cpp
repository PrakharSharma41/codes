#include<stdio.h>
#include<stdlib.h>
#define INF 9999
void printsolution(struct graph*);
void floydwarshall(struct graph*);
struct graph{
	int v;
	int e;
	int **adj;
};
int main()
{
	int i,j;
	struct graph *g;
	int mat[4][4]={{0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}};
	g=(struct graph*)malloc(sizeof(struct graph));
	g->v=4;g->e=4;
	g->adj=(int**)malloc((g->v)*(g->v)*sizeof(int));
	for(i=0;i<g->v;i++)
	for(j=0;j<g->v;j++)
	**(g->adj+i*g->v+j)=mat[i][j];
	printsolution(g);
	floydwarshall(g);
	printsolution(g);
	return 0;
}
void printsolution(struct graph *g)
{
	int i,j;
	for(i=0;i<g->v;i++)
	{
		for(j=0;j<g->v;j++)
		{
			if(**(g->adj+i*g->v+j)==INF)
			printf("%7s","INF");
			else
			printf("%7d",**(g->adj+i*g->v+j));
			printf("\n");
		}
	}
}
void warshall(struct graph *g)
{
	int i,j,k,dist[g->v][g->v];
	for(i=0;i<g->v;i++)
	for(j=0;j<g->v;j++)
	dist[i][j]=**(g->adj+i*g->v+j);
	for(k=0;k<g->v;k++)
	{
		for(i=0;i<g->v;i++)
		{
			for(j=0;j<g->v;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	for(i=0;i<g->v;i++)
	for(j=0;j<g->v;j++)
	**(g->adj+i*g->v+j)=dist[i][j];
}
