class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long dp[nums.size()+1][2];
        dp[0][0]=0;
        dp[0][1]=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            dp[i+1][0]=max(dp[i][0],dp[i][1]+nums[i]);
            dp[i+1][1]=max(dp[i][1],dp[i][0]-nums[i]);
            ans=max(dp[i+1][0],dp[i+1][1]);
        }
        return ans;
    }
};