class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        int maximum=1;
        for(int j=1;j<nums.size();j++)
        {
            for(int i=0;i<j;i++)
            {
                if(nums[j]>nums[i])
                {
                dp[j]=max(dp[j],dp[i]+1);
                }
            }
            maximum=max(maximum,dp[j]);
        }
        return maximum;
    }
};