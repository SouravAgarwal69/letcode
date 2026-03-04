class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1);
        dp[1]=nums[0];
        for(int i=2;i<dp.size();i++)
        {
            int skip=dp[i-1];
            int stashed=nums[i-1]+dp[i-2];
            dp[i]=max(skip,stashed);
        }
        return dp[dp.size()-1];
    }
};