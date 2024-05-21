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
