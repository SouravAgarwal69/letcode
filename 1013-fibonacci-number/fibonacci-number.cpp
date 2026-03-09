class Solution {
public:
    int dp[31];
    int find(int n)
    {
        if(n<2)
        {
            return n;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=find(n-1)+find(n-2);
    }
    int fib(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n);
    }
};