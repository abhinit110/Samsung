// User function Template for C++

class Solution {
  public:
    int kadane(vector<int>&a)
    {
        int n=a.size();
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            ans=max(ans,sum);
            if(sum<0)
            sum=0;
        }
        return ans;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int ans=INT_MIN;
        for(int i=0;i<C;i++)
        {
            vector<int>a(R,0);
            for(int j=i;j<C;j++)
            {
                for(int k=0;k<R;k++)
                a[k]+=(M[k][j]);
                ans=max(ans,kadane(a));
            }
            //cout<<"i= "<<i<<" ans= "<<ans<<endl;
        }
        return ans;
    }
};
