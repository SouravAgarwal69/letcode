class Solution {
public:
    int dp[1000][1000];
    int find(int idx1,int idx2,string &text1,string &text2)
    {
        if(idx1==text1.size() || idx2==text2.size())
        {
            return 0;
        }
        if(dp[idx1][idx2]!=-1)
        {
            return dp[idx1][idx2];
        }
        int result=0;
        if(text1[idx1]==text2[idx2])
        {
           result=1+find(idx1+1,idx2+1,text1,text2);
        }
        else{
            result=max(find(idx1+1,idx2,text1,text2),find(idx1,idx2+1,text1,text2));
        }
        return dp[idx1][idx2]=result;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,text1,text2);
    }
};