int maxi=0;
    // int solve(int n, int m, vector<vector<int>> mat, int i, int j)
    // {
    //     if(i>=n || j>=m)
    //     return 0;
        
    //     int right=solve(n,m,mat,i,j+1);
    //     int diag=solve(n,m,mat,i+1,j+1);
    //     int down=solve(n,m,mat,i+1,j);
        
    //     int ans;
    //     if(mat[i][j] == 1)
    //     {
    //         ans=1+min(right,min(diag,down));
    //         maxi=max(ans,maxi);
    //         return ans;
    //     }
    //     else
    //     return 0;
    // }
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        // int x= solve(n,m,mat,0,0);
        // return  maxi;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(mat[i][j]==1)
                {
                    dp[i][j]=1+min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j]));
                    maxi=max(dp[i][j],maxi);
                }
                else
                dp[i][j]=0;
            }
        }
        return maxi;
    }
