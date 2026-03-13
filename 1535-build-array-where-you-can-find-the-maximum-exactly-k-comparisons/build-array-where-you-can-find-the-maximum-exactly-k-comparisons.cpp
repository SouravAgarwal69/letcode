class Solution {
public:
    int dp[50][101][51];
    int mod=1e9+7;
    int solve(int n,int m,int k,int maximum,int sc,int index)
    {
        if(index==n)
        {
            if(sc==k)
            {
                return 1;
            }
            return 0;
        }
        if(maximum!=-1 && dp[index][maximum][sc]!=-1)
        {
            return dp[index][maximum][sc];
        }
          long long ans=0;
        for(int i=1;i<=m;i++)
        {
            if(i>maximum)
            {
                ans=(ans+solve(n,m,k,i,sc+1,index+1))%mod;
            }
            else
            {
                ans=(ans+solve(n,m,k,maximum,sc,index+1))%mod;
            }
        }
        if(maximum!=-1)
        {
        return dp[index][maximum][sc]=ans;
        }
        return ans;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,m,k,-1,0,0);
    }
};