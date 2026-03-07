class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int maximum=1;
        sort(pairs.begin(),pairs.end());
        vector<int>dp(pairs.size(),1);
        for(int i=1;i<pairs.size();i++)
        {
           for(int j=0;j<i;j++)
           {
              if(pairs[i][0]>pairs[j][1])
              {
                  dp[i]=max(dp[i],dp[j]+1);
                  maximum=max(maximum,dp[i]);
              }
           }
        }
        return maximum;
    }
};