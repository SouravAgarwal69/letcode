class Solution {
public:
    int dp[501][501];
    int findminDistance(string &word1,string &word2,int m,int n)
    {
         if(m==0 || n==0)
         {
            return m+n;
         }
           if(dp[m][n]!=-1)
         {
            return dp[m][n];
         }
         if(word1[m-1]==word2[n-1])
         {
            return dp[m][n]=findminDistance(word1,word2,m-1,n-1);
         }
         int insert=1+findminDistance(word1,word2,m,n-1);
         int Delete=1+findminDistance(word1,word2,m-1,n);
         int Replace=1+findminDistance(word1,word2,m-1,n-1);
         return dp[m][n]=min({insert,Delete,Replace});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return findminDistance(word1,word2,word1.size(),word2.size());
    }
};