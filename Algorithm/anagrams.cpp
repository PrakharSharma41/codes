#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
#define INF 2000000
#define MAX 1000000
#define LIM 1000

bool primearray[MAX];
//void calc_prime()
//{
//  memset (primes, true, sizeof (primes));
//  primes [0] = primes [1] = false;
//  int i,j;
//  for ( i = 2; i <= LIM; i++) {
//    if (primes [i]) {
//      for ( j = 2 * i; j < MAX; j += i)
//        primes [j] = false;
//    }
//  }
//}
void calc_primes () {
  memset (primearray, true, sizeof (primearray));
  primearray [0] = primearray [1] = false;
  for (int i = 2; i <= LIM; i++) {
    if (primearray[i]) {
      for (int j = 2 * i; j < MAX; j += i)
        primearray[j] = false;
    }
  }
}
int compara (const void *p, const void *q) {
  return *(int *) p - *(int *) q;
}
class PrimeAnagrams{
	private:
		vector<int>resp;
		int melhor;
		void find(string text,int pos,int size,string digit,int usados[])
		{
			int i,j,k,nums[3];string txt[3];
			if(pos==size){  // block to take number from different permutations
				for(i=0;i<size-2;i++){
					if(text[i+1]=='0') continue;
					txt[0]="";
					for(j=0;j<=i;j++)
					txt[0]+=text[j];
					for(j=i+1;j<size-1;j++){
						if(text[j+1]=='0') continue;
						txt[1]="";
						for(k=i+1;k<=j;k++)
						txt[1]+=text[k];
						txt[2]="";
						for(k=j+1;k<size;k++)
						txt[2]+=text[k];
			            nums [0] = atoi (txt [0].c_str ());
			            nums [1] = atoi (txt [1].c_str ());
			            nums [2] = atoi (txt [2].c_str ());
			            if (!primearray [nums [0]] || !primearray [nums [1]] || !primearray[nums [2]])
              				continue;
			            if (nums [0] * nums [1] * nums [2] >= melhor)
			              continue;
			            melhor = nums [0] * nums [1] * nums [2];
			            qsort (nums, 3, sizeof (int), compara);
			            resp.clear ();
			            for (int k = 0; k < 3; k++)
			              resp.push_back (nums [k]);
					}
				}
				return;
			}
			string ntext;
			// loop to create different permutations of string
			for(i=0;i<size;i++){
				if(usados[i]) continue;
				if(pos==0&&digit[i]=='0') continue;
				ntext=text+digit[i];
				usados[i]=1;
				find(ntext,pos+1,size,digit,usados);
				usados[i]=0;
			}
		}
	public:
		vector <int> primes (string anagram){
			string newstring="";
			int usados[10];
			melhor=INF;
			calc_primes();
			resp.clear();
			memset(usados,0,sizeof(usados));
			find(newstring,0,anagram.size(),anagram,usados);
			return resp;
		}	
};
int main()
{
	string s;
	cin>>s;
	PrimeAnagrams x;
	vector<int>k=x.primes(s);
	cout <<k[0]<<"\n"<<k[1]<<"\n"<<k[2]<<"\n";
}
