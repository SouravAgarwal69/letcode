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
       int skip=find(s+1,e,nums,dp);
       int stashed=nums[s]+find(s+2,e,nums,dp);
       return dp[s]=max(skip,stashed);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        return max(find(0,nums.size()-2,nums,dp1),find(1,nums.size()-1,nums,dp2));
    }
};