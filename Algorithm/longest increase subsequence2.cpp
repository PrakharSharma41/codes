//        longest increasing subsequence in NLOGN

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
    return r; 
} 
int main()
{
    int n,i,j,x;
    cin>>n;vector<int>v;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    vector<int>tail(n,0);
    tail[0]=v[0];int length=1;
    for(int i=1;i<n;i++)
    {
        if(v[i]<tail[0])
        tail[0]=v[i];
        else if(v[i]>tail[length-1])
        tail[length++]=v[i];
        else
        {
            int k=upper_bound(tail.begin(),tail.begin()+length,v[i])-tail.begin();
            if(k>0)
            {
                if(tail[k-1]==v[i])
                k--;
            }
        // tail[CeilIndex(tail, -1, length - 1, v[i])]=v[i];
        tail[k]=v[i];
        }
    }
    cout<<length<<"\n";

    return 0;
}
