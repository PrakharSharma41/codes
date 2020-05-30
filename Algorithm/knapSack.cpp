// A Dynamic Programming based solution for 0-1 Knapsack problem 
#include<bits/stdc++.h>
 using namespace std; 
int max(int a, int b) { return (a > b)? a : b; } 
  
// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
   for(int i =0;i<=W;i++)
  {
  	for(int j=0;j<=W;j++)
  		cout <<K[i][j]<<" ";
	  cout<<"\n";
  }
   return K[n][W]; 
} 
  
int main() 
{ 
    int val[] = {10,2,1,3}; 
    int wt[] = {10,5,10,10}; 
    int  W = 20; 
    int n = sizeof(val)/sizeof(val[0]); 
    knapSack(W, wt, val, n);
//    printf("%d", knapSack(W, wt, val, n)); 
    return 0; 
} 
