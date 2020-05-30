#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,c,x;
    cin >>n>>c;
    int value[n],weight[n];
    map<float,int> point;
    map<float, int>::iterator itr; 
	for(i=0;i<n;i++)
    {
        cin >>value[i];
    }
    for(i=0;i<n;i++)
    {
        cin >>weight[i];
    }
    for(i=0;i<n;i++)
    	point.insert(pair<float,int>(float(value[i])/weight[i],i));

//     for (itr = point.begin(); itr != point.end(); ++itr) { 
//        cout << '\t' << itr->first 
//             << '\t' << itr->second << '\n'; 
//    } 
long int total=0;
std::map<float, int>::reverse_iterator ritr = point.rbegin();
    while(ritr!=point.rend())
    {
    	if(weight[ritr->second]<=c)
    	{
    		c-=weight[ritr->second];
			total+=value[ritr->second];
		}
		if(c<=0)
		break;
		ritr++;
	}
	cout<<total;
    return 0;
}
