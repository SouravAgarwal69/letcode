class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operation=0;
        stack<int>st;
        for(int i=0;i<nums.size();i++)
        {
           
            while(!st.empty() && st.top()>nums[i])
            {
                st.pop();
            }
             if(nums[i]==0)
            {
                continue;
            }
            if(st.empty() || st.top()<nums[i])
            {
                operation++;
                st.push(nums[i]);
            }
        }
        return operation;
    }
};