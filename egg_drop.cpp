int solve(int n, int k, vector<vector<int>>&dp)
    {
        if(k==0 || k==1)
        return k;
        
        if(n==1)
        return k;
        
        int mi=INT_MAX,x,res;
        if(dp[n][k]!=-1)
        return dp[n][k];
        for(x=1;x<=k;x++)
        {
            res=max(solve(n-1,x-1,dp), solve(n,k-x,dp));
            mi=min(res,mi);
        }
        return dp[n][k]=mi+1;
    }
    
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
