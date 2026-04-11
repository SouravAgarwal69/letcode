class Solution {
public:
    int find1(vector<vector<int>>&fruits)
    {
        int total=0;
        for(int i=0;i<fruits.size();i++)
        {
            total+=fruits[i][i];
            fruits[i][i]=0;
        }
       return total;
    }
    int find2(vector<vector<int>>&fruits,int i,int j,vector<vector<int>>&dp)
    {
        int n=fruits.size();
        if(i==n-1 || j==n || i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int path1=find2(fruits,i+1,j-1,dp);
        int path2=find2(fruits,i+1,j,dp);
        int path3=find2(fruits,i+1,j+1,dp);
        return dp[i][j]=fruits[i][j]+max({path1,path2,path3});
    }
    int find3(vector<vector<int>>&fruits,int i,int j,vector<vector<int>>&dp)
    {
        int n=fruits.size();
        if(j==n-1 || i<j || i==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int path1=find3(fruits,i-1,j+1,dp);
        int path2=find3(fruits,i,j+1,dp);
        int path3=find3(fruits,i+1,j+1,dp);
        return dp[i][j]=fruits[i][j]+max({path1,path2,path3});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int child1=find1(fruits);
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        vector<vector<int>>dp2(n,vector<int>(n,-1));
        int child2=find2(fruits,0,n-1,dp1);
        int child3=find3(fruits,n-1,0,dp2);
        return child1+child2+child3;
    }
};