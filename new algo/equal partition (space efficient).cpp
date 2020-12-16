    int equalPartition(int n, int arr[])
    {
        int i,j,sum=0;
        for(i=0;i<n;i++)
        sum+=arr[i];
        int dp[sum+2],pos[sum+2];
        

        for(j=0;j<=sum;j++)
        dp[j]=0,pos[j]=-1;
        
        dp[0]=1;
        
        for(i=0;i<n;i++){
            for(j=1;j<=sum;j++){
                if((arr[i]<=j) && (dp[j-arr[i]]>0) && (pos[j-arr[i]]!=i) ){
                    dp[j]=1;pos[j]=i;
                }
            }
        }
        
        if((sum%2==0) && (dp[sum/2]==1))
        return 1;
        return 0;
    }

