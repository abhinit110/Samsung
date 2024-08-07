vector<int>bit;
    int n;
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first==b.first)
        return a.second < b.second;
        else
        return a.first > b.first;
    }
    void update(int val,int id)
    {
        while(id<=n)
        {
            bit[id]+=val;
            id+=(id & -id);
        }
    }
    int query(int id)
    {
        int ans=0;
        while(id>0)
        {
            ans+=bit[id];
            id-=(id & -id);
        }
        return ans;
    }
    vector<int> count_NGE(int m, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int>res;
        
        n=m;
        bit=vector<int>(n+1,0);
        vector<int>ans(n);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end(), comp);
        
        for(auto it:v)
        {
            int in=it.second +1;
            update(1,in);
            ans[in-1]=query(n)-query(in);
        }
        
        
        int l=queries;
        for(auto it:indices)
        res.push_back(ans[it]);
        return res;
         
       
    }
