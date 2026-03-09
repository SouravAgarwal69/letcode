class Solution {
public:
     int dp[101];
    int find(int index,int n,vector<int>&nums)
    {
        if(index>n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int take= nums[index]+find(index+2,n,nums);
        int skip= find(index+1,n,nums);
        return dp[index]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        memset(dp,-1,sizeof(dp));
        int case1=find(0,nums.size()-2,nums);
        memset(dp,-1,sizeof(dp));
        int case2=find(1,nums.size()-1,nums);
        return max(case1,case2);
    }
};