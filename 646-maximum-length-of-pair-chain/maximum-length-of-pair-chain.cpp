class Solution {
public:
    int find(vector<vector<int>>&pairs,int index,int prev,vector<vector<int>>&dp)
    {
        if(index==pairs.size())
        {
            return 0;
        }
        if(prev!=-1 && dp[index][prev]!=-1)
        {
            return dp[index][prev];
        }
        int take=0;
        if(prev==-1 || pairs[prev][1]<pairs[index][0])
        {
           take=1+find(pairs,index+1,index,dp);
        }
        int skip=find(pairs,index+1,prev,dp);
        if(prev!=-1)
        {
            return dp[index][prev]=max(take,skip);
        }
        return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
      sort(pairs.begin(),pairs.end());
      int n=pairs.size();
      vector<vector<int>>dp(n,vector<int>(n,-1));
       return find(pairs,0,-1,dp);
    }
};