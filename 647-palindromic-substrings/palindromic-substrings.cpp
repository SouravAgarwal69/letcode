class Solution {
public:
   int dp[1000][1000];
    bool isPallindrome(string &s,int i,int j)
    {
        if(i>=j)
        {
            return true;
        }
       if(dp[i][j]!=-1)
       {
          return dp[i][j];
       }
        if(s[i]==s[j])
        {
         return dp[i][j]=isPallindrome(s,i+1,j-1);
        }
        return dp[i][j]=false;
    }
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        int total=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(isPallindrome(s,i,j))
                {
                    total++;
                }
            }
        }
        return total;
    }
};