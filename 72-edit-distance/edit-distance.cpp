class Solution {
public:
    int dp[501][501];
    int operation (string &word1,string &word2,int i,int j)
    {
        if(i==word1.size())
        {
            return word2.size()-j;
        }
        if(j==word2.size())
        {
            return word1.size()-i;
        }
        if(word1[i]==word2[j])
        {
            return operation(word1,word2,i+1,j+1);
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int insert=1+operation(word1,word2,i,j+1);
        int Delete=1+operation(word1,word2,i+1,j);
        int replace=1+operation(word1,word2,i+1,j+1);
        return  dp[i][j]=min({insert,Delete,replace});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return operation(word1,word2,0,0);
    }
};