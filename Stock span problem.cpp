class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>ans(n,1);
       stack<int>st;
       for(int i=n-1;i>=0;i--)
       {
           while(!st.empty() && price[st.top()]<price[i])
           {
               ans[st.top()]=abs(i-st.top());
               st.pop();
           }
           st.push(i);
       }
       //cout<<st.size()<<endl;
      while(!st.empty())
          {
              ans[st.top()]=abs(0-st.top())+1;
              st.pop();
          }
       return ans;
    }
};
