class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size()));
        for(int L=2;L<=s.size();L++)
        {
           for(int i=0;i+L-1<s.size();i++)
           {
                 int j=i+L-1;
                 if(s[i]==s[j])
                 {
                    dp[i][j]=dp[i+1][j-1];
                 }
                 else
                 {
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                 }
           }
        }
        return dp[0][s.size()-1];
    }
};