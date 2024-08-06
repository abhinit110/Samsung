    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        priority_queue<pair<int,int>>q;
        int m_p=INT_MAX;
        int max_p=0;
        int ans=0;
        int buy_in=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            
            if(m_p<prices[i])
            {
                ans+=max_p-m_p;
                q.pop();
                max_p=prices[i];
                m_p=prices[i];
                buy_in=i;
                
            }
            else
            {
                // q.push({prices[i],i});
                max_p=max(max_p,prices[i]);
                if(m_p>prices[i])
                {
                    m_p=prices[i];
                    buy_in=i;
                }
            }
            
            // while(!q.empty()&&q.top().second>sell_in)
            // q.pop();
        }
        ans+=max_p-m_p;
        return ans;
    }
};
//////////////////////////////////////////////////////////

public:
    // int solve(vector<int>&price, int n, int in, int var)
    // {
    //     if(in>=n)
    //     return 0;
        
    //     if(var == 0)
    //     {
    //         return max(-price[in]+solve(price,n,in+1,1),solve(price,n,in+1,0));
    //     }
    //     else
    //     {
    //         return max(price[in]+solve(price,n,in+1,0),solve(price,n,in+1,1));
    //     }
    // }
    int stockBuyAndSell(int n, vector<int> &price) {
        // code here
        //return solve(prices,n,0,0);
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(j==0)
                dp[i][j]=max(-price[i]+dp[i+1][1],dp[i+1][0]);
                else
                dp[i][j]=max(price[i]+dp[i+1][0],dp[i+1][1]);
            }
        }
        //  for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=1;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0];
    }
