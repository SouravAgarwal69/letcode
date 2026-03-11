class Solution {
public:
    int dp[1000][1000];
    int find(vector<vector<int>>&pairs,int index,int prev)
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
        if(prev==-1 ||pairs[index][0]>pairs[prev][1])
        {
            take=1+find(pairs,index+1,index);
        }
        int skip=find(pairs,index+1,prev);
        if(prev!=-1)
        {
            return dp[index][prev]=max(take,skip);
        }
        return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        return find(pairs,0,-1);
    }
};