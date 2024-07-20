public:
    //Function to return the total number of possible unique BST. 
    int mod=1e9+7;
    // int solve(int N, vector<int>&dp){
    //     if(N==1)
    //     return 1;
    //     if(N==0)
    //     return 1;
    //     if(dp[N]!=-1)
    //     {
    //         return dp[N]%mod;
    //     }
    //     int ans=0;
    //     for(int i=1;i<=N;i++)
    //     {
    //          ans=(ans%mod+((1LL*solve(i-1,dp)%mod)*(1LL*solve(N-i,dp)%mod))%mod)%mod;
    //     }
    //     return dp[N]=ans%mod;
    // }
    int numTrees(int N) 
    {
        // Your code here
        vector<int>dp(N+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=N;i++)
        {
            
                int t=0;
                for(int j=1;j<=i;j++)
                {
                    t=((t%mod)+((1LL*dp[j-1]%mod)*(1LL*dp[i-j]%mod))%mod)%mod;
                }
            dp[i]=t%mod;
            
        }
        // return solve(N,dp)%mod;
        return dp[N];
        
    }
