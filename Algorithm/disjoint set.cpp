#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int root (int Arr[ ] ,int i)   // path compression
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ; 
		i = Arr[ i ]; 
    }
    return i;
}

void unions(int Arr[],int size[],int A,int B)  // weighted union
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
        size[root_A]=0;
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
        size[root_B]=0;
    }
}

int main()
{
    int i,a,b,n,m;
    cin>>n>>m;
    int size[n+1],Arr[n+1];
        int temp[n+1],k=0;
    for(i=1;i<=n;i++)
    {
    	Arr[i]=i;
    	size[i]=1;
	}
    while(m--)
    {
        cin>>a>>b;
        unions(Arr,size,a,b);
        for(i=1;i<=n;i++)
        	temp[i]=size[i];
        sort(temp,temp+n+1);
        for(i=0;i<=n;i++)
        {
            if(temp[i]!=0&&temp[i]!=-1&&temp[i]<=n)
				cout<<temp[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

