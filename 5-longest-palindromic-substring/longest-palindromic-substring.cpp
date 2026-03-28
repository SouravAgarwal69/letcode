class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size()));
        int index=0,maxlen=0;
        for(int len=1;len<=s.size();len++)
        {
           for(int i=0;i+len-1<s.size();i++)
           {
               int j=len+i-1;
               if(len==1)
               {
                  dp[i][j]=true;
               }
               else if(len==2)
               {
                  dp[i][j]=s[i]==s[j];
               }
               else
               {
                 dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
               }
           if(dp[i][j] && maxlen<len)
           {
             maxlen=len;
             index=i;
           }
           }
        }
        return s.substr(index,maxlen);
    }
};