class Solution {
public:
     int find(vector<int>&nums,int index,vector<int>&dp)
     {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int smashed=nums[index]+find(nums,index+2,dp);
        int skip=find(nums,index+1,dp);
        return dp[index]=max(smashed,skip);
     }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return find(nums,0,dp);
    }
};