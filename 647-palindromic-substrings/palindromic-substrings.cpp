class Solution {
public:
    int dp[1000][1000];
    bool check(string &s,int i,int j)
    {
        if(i>j)
        {
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[i][j]=check(s,i+1,j-1);
        }
        return false;
    }
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        int total=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(check(s,i,j))
                {
                    total++;
                }
            }
        }
        return total;
    }
};
