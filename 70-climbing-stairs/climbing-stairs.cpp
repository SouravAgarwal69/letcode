class Solution {
public:
    int fun(int s,int target,vector<int>&dp)
    {
        if(s==target)
       {
           return 1;
       }
       if(s>target)
       {
          return 0;
       }
       if(dp[s]!=-1)
       {
          return dp[s];
       }
       return dp[s]=fun(s+1,target,dp)+fun(s+2,target,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fun(0,n,dp);
    }
};