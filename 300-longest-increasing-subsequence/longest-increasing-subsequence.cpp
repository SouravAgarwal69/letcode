class Solution {
public:
    int dp[2500][2500];
    int findLength(vector<int>&nums,int index,int prev)
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
        if(prev==-1 || nums[prev]<nums[index])
        {
            take=1+findLength(nums,index+1,index);
        }
        int skip=findLength(nums,index+1,prev);
        if(prev!=-1)
        {
            return dp[index][prev]=max(take,skip);
        }
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return findLength(nums,0,-1);
    }
};