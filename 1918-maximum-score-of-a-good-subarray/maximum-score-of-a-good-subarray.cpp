class Solution {
public:
    void findNSE(vector<int>&nums,vector<int>&NSE)
    {
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                NSE[i]=nums.size();
            }
           else
           {
              NSE[i]=st.top();
           }
           st.push(i);
        }
    }
    void findPSE(vector<int>&nums,vector<int>&PSE)
    {
         stack<int>st;
         for(int i=0;i<nums.size();i++)
         {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                PSE[i]=-1;
            }
            else
            {
                PSE[i]=st.top();
            }
            st.push(i);
         }
    }
    int maximumScore(vector<int>& nums, int k) {
        int score=0;
        vector<int>NSE(nums.size());
        vector<int>PSE(nums.size());
        findNSE(nums,NSE);
        findPSE(nums,PSE);
        for(int i=0;i<nums.size();i++)
        {
            if(PSE[i]<k && NSE[i]>k)
            {
                score=max(score,(NSE[i]-PSE[i]-1)*nums[i]);
            }
        }
        return score;
    }
};