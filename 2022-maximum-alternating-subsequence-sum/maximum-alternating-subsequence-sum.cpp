class Solution {
public:
    long long findMax(vector<int>&nums,int flag,int index,vector<vector<long long>>&dp)
    {
        if(index==nums.size())
        {
            return 0;
        }
       if(dp[index][flag]!=-1)
       {
          return dp[index][flag];
       }
       long long value=flag==1?(-1)*nums[index]:nums[index];
        long long take=value+findMax(nums,1-flag,index+1,dp);
        long long skip=findMax(nums,flag,index+1,dp);
        return dp[index][flag]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
        return findMax(nums,0,0,dp);
    }
};