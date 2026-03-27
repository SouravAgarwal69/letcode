class Solution {
public:
    int countSubstrings(string s) {
        int total=0;
        vector<vector<bool>>dp(s.size()+1,vector<bool>(s.size()+1));
        for(int len=1;len<=s.size();len++)
        {
            for(int i=0;i+len-1<s.size();i++)
            {
                int j=i+len-1;
               if(len==1)
               {
                  dp[i][j]=true;
               }
               else if(len==2)
               {
                 dp[i][j]=(s[i]==s[j]);
               }
               else 
               {
                  dp[i][j]=s[i]==s[j] && dp[i+1][j-1];
               }
               if(dp[i][j])
               {
                  total++;
               }

            }
        }
        return total;
    }
};