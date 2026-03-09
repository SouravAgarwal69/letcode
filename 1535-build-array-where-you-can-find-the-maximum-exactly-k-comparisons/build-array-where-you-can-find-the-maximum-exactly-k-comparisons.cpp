class Solution {
public:
    int dp[51][101][51];
    int mod =1e9+7;
    int fun(int n,int m,int k,int index,int maximum,int sc)
    {
        if(sc>k)
        {
            return 0;
        }
        if(index==n)
        {
            if(sc==k)
            {
                return 1;
            }
            return 0;
        }
        if( maximum!=-1 && dp[index][maximum][sc]!=-1)
        {
            return dp[index][maximum][sc];
        }
        int result=0;
        for(int i=1;i<=m;i++)
        {
            if(i>maximum)
            {
                result=(result+fun(n,m,k,index+1,i,sc+1)) % mod;
            }
            else
            {
                result=(result+fun(n,m,k,index+1,maximum,sc)) % mod;
            }
        }
        if(maximum!=-1)
        {
        return dp[index][maximum][sc]=result % mod;
        }
        return result % mod;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return fun(n,m,k,0,-1,0);
    }
};