class Solution {
public:
    int dp[200][200];
    int solve(vector<vector<int>>&grid,int r,int c)
    {
        if(r==grid.size()-1 && c==grid[0].size()-1)
        {
              return grid[r][c];
        }
        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }
        else if(r==grid.size()-1)
        {
            return dp[r][c]=grid[r][c]+solve(grid,r,c+1);
        }
        else if(c==grid[0].size()-1)
        {
            return dp[r][c]=grid[r][c]+solve(grid,r+1,c);
        }
        else
        {
            return dp[r][c]=grid[r][c]+min(solve(grid,r+1,c),solve(grid,r,c+1));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0);
    }
};