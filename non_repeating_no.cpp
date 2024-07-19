vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> ans;
        // Code here.
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[abs(nums[i])]*=-1; 
        }
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])]<0)
            ans.push_back(nums[i]);
        }
        return ans;
    }
