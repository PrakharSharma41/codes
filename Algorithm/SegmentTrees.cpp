//  code to find minimum in a range

#include<iostream>
using namespace std;
void build(int node,int start,int end,int a[],int tree[])
{
    if(start==end)
    tree[node]=a[start];
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid,a,tree);
        build(2*node+1,mid+1,end,a,tree);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

void update(int node,int start,int end,int a[],int tree[],int value,int pos)
{
    if(start==end)
    {
        a[pos]=value;
        tree[node]=value;
    }
    else
    {
        int mid=(start+end)/2;
        if(pos>=start&&pos<=mid)
        update(2*node,start,mid,a,tree,value,pos);
        else
        update(2*node+1,mid+1,end,a,tree,value,pos);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

int query(int node,int start,int end,int l,int r,int a[],int tree[])
{
    if(start>r || end<l)
        return 100005;
    if(start>=l&&end<=r)
        return tree[node];    
    else
    {
        int mid=(start+end)/2;
        int p1=query(2*node,start,mid,l,r,a,tree);
        int p2=query(2*node+1,mid+1,end,l,r,a,tree);
        return min(p1,p2);
    }
}

int main()
{
    int i,n,q,x,y;
    cin>>n>>q;
    int tree[2000005],a[100005];
    for(i=1;i<=n;i++)
    cin>>a[i];
    // char c;
    build(1,1,n,a,tree);
    while(q--)
    {
        char c;
        cin>>c>>x>>y;
        if(c=='q')
        cout<<query(1,1,n,x,y,a,tree)<<"\n";
        else
        update(1,1,n,a,tree,y,x);
    }
    return 0;
}

