class Solution {
public:
    int n;
    vector<int>min_bit;
    vector<int>max_bit;

    void update(int val,int id,vector<int>&bit)
    {
        while(id<=n)
        {
            bit[id]+=val;
            id+=(id & -id);
        }
    }
     
    int query(int id,vector<int>&bit)
    {
        int ans=0;
        while(id>0)
        {
            ans+=bit[id];
            id-=(id & -id);
        }
        return ans;
    }
    int numTeams(vector<int>& rating) {
        n=rating.size();
        min_bit=vector<int>(n+1,0);
        max_bit=vector<int>(n+1,0);
        vector<pair<int,int>>v1;
        vector<pair<int,int>>v2;
        for(int i=0;i<n;i++)
        {
            v1.push_back({rating[i],i});
            v2.push_back({rating[i],i});
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(), greater<pair<int,int>>());
        vector<int>mini(n,0);
        vector<int>maxi(n,0);
        for(auto it:v1)
        {
            update(1,it.second+1,min_bit);
            mini[it.second]=(query(n,min_bit)-query(it.second+1,min_bit));
        }
        cout<<query(n,min_bit)<<endl;
        for(auto it:v2)
        {
            update(1,it.second+1,max_bit);
            maxi[it.second]=(query(n,max_bit)-query(it.second+1,max_bit));
        }
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(rating[i]>rating[j])
                {
                    ans+=mini[j];
                }
                
                if(rating[i]<rating[j])
                ans+=maxi[j];
            }
        }
        return ans;



    }
};
