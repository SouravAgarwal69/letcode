class Solution {
public:
    int find(int s,int e,vector<int>&nums,vector<int>&dp)
    {
        if(s>e)
        {
            return 0;
        }
        if(dp[s]!=-1)
        {
            return dp[s];
        }
        int take=nums[s]+find(s+2,e,nums,dp);
        int skip=find(s+1,e,nums,dp);
        return dp[s]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        vector<int>dp1(nums.size(),-1);
        int case1=find(0,n-2,nums,dp1);
           vector<int>dp2(nums.size(),-1);
        int case2=find(1,n-1,nums,dp2);
        return max(case1,case2);
    }
};