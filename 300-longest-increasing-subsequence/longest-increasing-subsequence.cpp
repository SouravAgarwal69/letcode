class Solution {
public:
    int find(vector<int>&nums,int index,int prev,vector<vector<int>>&dp)
    {
        if(index==nums.size())
        {
            return 0;
        }
        if(prev!=-1 && dp[index][prev]!=-1)
        {
            return dp[index][prev];
        }
        int take=0;
        if(prev==-1 || nums[index]>nums[prev])
        {
         take=1+find(nums,index+1,index,dp);
        }
        int skip=find(nums,index+1,prev,dp);
        if(prev!=-1)
        {
        return dp[index][prev]=max(skip,take);
        }
        return max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return find(nums,0,-1,dp);
    }
};