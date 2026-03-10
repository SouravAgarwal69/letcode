class Solution {
public:
   int dp[101];
    int find(int s,int e,vector<int>&nums)
    {
        if(s>e)
        {
            return 0;
        }
        if(dp[s]!=-1)
        {
            return dp[s];
        }
        int take=nums[s]+find(s+2,e,nums);
        int skip=find(s+1,e,nums);
        return dp[s]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        if(nums.size()==1)
        {
            return nums[0];
        }
        int case1=find(0,nums.size()-2,nums);
         memset(dp,-1,sizeof(dp));
        int case2=find(1,nums.size()-1,nums);
        return max(case1,case2);
    }
};