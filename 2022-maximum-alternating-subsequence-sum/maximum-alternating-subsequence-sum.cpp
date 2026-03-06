class Solution {
public:
    long long find(vector<int>&nums,vector<vector<long long>>&dp,int index,int flag)
    {
        if(index==nums.size())
        {
            return 0;
        }
        if(dp[index][flag]!=-1)
        {
            return dp[index][flag];
        }
        int value=flag==0?nums[index]:(-1)*nums[index];
        long long take=value+find(nums,dp,index+1,1-flag);
        long long skip=find(nums,dp,index+1,flag);
        return dp[index][flag]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
       return find(nums,dp,0,0);
    }
};