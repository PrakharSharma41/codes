
//dp[n][m] represent binary string of length n with m consecutive ones at end
class Solution {
public:
    int countBinaryStrings(int n, int k) {
        
        vector<vector<int> >dp(n+1,vector<int>(k+1));
        dp[0][0]=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                dp[i+1][0]+=dp[i][j];
                if(j<k)
                dp[i+1][j+1]+=dp[i][j];
            }
        }
        int result=0;
        
        for(int j=0;j<=k;j++)
        {
        result+=dp[n][j];            
        }

        return result;
    }
};



