class Solution {
public:
    int find(vector<int>&nums,vector<int>&dp,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int skip=find(nums,dp,index+1);
        int stashed=nums[index]+find(nums,dp,index+2);
        return dp[index]=max(skip,stashed);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return find(nums,dp,0);
    }
};