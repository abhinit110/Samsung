vector<int> factorial(int N){
        vector<int>ans;
        int carry = 0;
        ans.push_back(1);
        for(int i=2;i<=N;i++)
        {
            for(int j=0;j<ans.size();j++)
            {
                int t=ans[j]*i+carry;
                ans[j]=t%10;
                carry=t/10;
            }
            while(carry)
            {
                ans.push_back(carry%10);
                carry/=10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
