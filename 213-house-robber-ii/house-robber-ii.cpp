class Solution {
public:
     int recursion(vector<int>&nums,int index,int e,vector<int>&dp)
     {
        if(index>e)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int skip=recursion(nums,index+1,e,dp);
        int take=nums[index]+recursion(nums,index+2,e,dp);
        return dp[index]=max(skip,take);
     }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
       return max(recursion(nums,0,nums.size()-2,dp1),recursion(nums,1,nums.size()-1,dp2));
    }
};