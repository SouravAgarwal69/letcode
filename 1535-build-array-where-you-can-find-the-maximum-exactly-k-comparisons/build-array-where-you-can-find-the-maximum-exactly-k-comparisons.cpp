class Solution {
public:
    int mod=1e9+7;
    int dp[50][51][101];
    int find(int n,int m,int k,int index,int maximum,int sc)
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
         int result=0;
         if(dp[index][sc][maximum]!=-1)
         {
            return dp[index][sc][maximum];
         }
          for(int i=1;i<=m;i++)
          {
              if(i>maximum)
              {
                result=(result+find(n,m,k,index+1,i,sc+1))%mod;
              }
              else
              {
                  result=(result+find(n,m,k,index+1,maximum,sc))%mod;
              }
          }
          return dp[index][sc][maximum]=result%mod;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
       return find(n,m,k,0,0,0)%mod;
    }
};