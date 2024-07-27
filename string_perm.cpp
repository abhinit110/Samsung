 int n;
    vector<string>ans;
    void solve(string s, int in)
    {
        if(in == n)
        {ans.push_back({s});
        return;}
        
        
        for(int i=in;i<n;i++)
        {
            string w=s;
            char ch=w[in];
            w[in]=w[i];
            w[i]=ch;
            
            solve(w,in+1);
        }
    }
    vector<string> permutation(string s)
    {
        //Your code here
        vector<string>res;
        n=s.length();
        solve(s,0);
        for(auto it:ans)
        res.push_back(it);
        sort(res.begin(),res.end());
        return res;
    }
