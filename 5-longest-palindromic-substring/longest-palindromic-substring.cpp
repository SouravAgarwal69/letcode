class Solution {
public:
   int dp[1000][1000];
    bool solve(int i,int j,string &s)
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
            return dp[i][j]=solve(i+1,j-1,s);
        }
        return dp[i][j]=false;
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
       int startIndex=0,len=0;
       for(int i=0;i<s.size();i++)
       {
          for(int j=i;j<s.size();j++)
          {
              if(solve(i,j,s) && len<j-i+1)
              {
                startIndex=i;
                len=j-i+1;
              }
          }
       }
       return s.substr(startIndex,len);
    }
};