#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void heapify(vector<int>& v,int i,int n )
{
	int left=2*i+1;
	int largest,right=2*i+2;
	if(left<n&&v[left]>v[i])
	largest=left;
	else
        largest = i;
    if(right < n and v[right] > v[largest] )
	    largest = right;
    if(largest != i )
    {
       swap (v[i] , v[largest]);
       heapify(v, largest,n);
	}
}

void build_heap(vector<int>& v)
{
	for(int i=v.size()/2;i>=0;i--)
	heapify(v,i,v.size());
}

void deleted(vector<int>& v)
{
	v[0]=v[v.size()-1];
	heapify(v,0,v.size()-1);
}

void insert(vector<int>&v,int val)
{
	v.push_back(-1);  // considering all greater than zero are inserted
	v[v.size()-1]=val;int i=v.size()-1;
	
//	heapify(v,(i-1)/2,v.size());
	while(i>0&&v[(i-1)/2]<v[i])
	{
		swap(v[i],v[(i-1)/2]);
		i=(i-1)/2;
	}
}

void display(vector<int>& v)
{
	for(int i=0;i<v.size();i++)
	cout <<v[i]<<"\n";
}
int main()
{
	vector<int> v;
	v.push_back(1);v.push_back(4);v.push_back(7);v.push_back(8);
	v.push_back(3);v.push_back(100);
	build_heap(v);
	display(v);
	insert(v,10);
	cout <<"new array is "<<"\n";
	display(v);
	deleted(v);
	cout <<"new array is "<<"\n";
	display(v);
	return 0;
}
