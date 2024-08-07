vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty()) left[i]=-1;
            else
            {
                while(!st.empty() && arr[i] < arr[st.top()])
                {
                    st.pop();
                }
                left[i]=st.empty()?-1:st.top();
            }
            st.push(i);
        }
        stack<int>st1;
        for(int i=n-1;i>=0;i--)
        {
            if(st1.empty()) right[i]=n;
            else
            {
                while(!st1.empty() && arr[i] <= arr[st1.top()])
                {
                    st1.pop();
                }
                right[i]=st1.empty()?n:st1.top();
            }
            st1.push(i);
        }
