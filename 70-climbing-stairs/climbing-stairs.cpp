class Solution {
public:
    int dp[46];
    int calculate(int n,int start)
    {
          if(start==n)
        {
            return 1;
        }
        if(start>n)
        {
            return 0;
        }
        if(dp[start]!=-1)
        {
            return dp[start];
        }
        return dp[start]=calculate(n,start+1)+calculate(n,start+2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return calculate(n,0);
    }
};