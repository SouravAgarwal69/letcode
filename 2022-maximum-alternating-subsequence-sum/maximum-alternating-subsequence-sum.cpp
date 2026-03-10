class Solution {
public:
    long long dp[100000][2];
    long long find(int index,vector<int>&nums,int flag)
    {
        if(index==nums.size())
        {
            return 0;
        }
       if(dp[index][flag]!=-1)
        {
            return dp[index][flag];
        }
        int value=flag==0?nums[index]:-nums[index];
        long long take=value+find(index+1,nums,1-flag);
        long long skip=find(index+1,nums,flag);
        return dp[index][flag]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(0,nums,0);
    }
};