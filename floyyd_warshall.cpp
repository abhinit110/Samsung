class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dp){
	    
	   
	    int n=dp.size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(dp[i][j]==-1)
	            dp[i][j]=10000;
	        }
	    }
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(dp[i][j]>=10000)
	            dp[i][j]=-1;
	        }
	    }
	}
};
