class Solution {
public:
    int dp[101][2];
    int find(vector<int>&nums,int index,int flag)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index][flag]!=-1)
        {
            return dp[index][flag];
        }
        int take=nums[index]+find(nums,index+2,1);
        int skip=find(nums,index+1,0);
        return dp[index][flag]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,1);
    }
};