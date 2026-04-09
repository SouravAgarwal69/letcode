class Solution {
public:
    int mod=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<pair<long long,long long>>>mat(m,vector<pair<long long,long long>>(n));
        mat[0][0].first=grid[0][0];
        mat[0][0].second=grid[0][0];
        for(int i=1;i<m;i++)
        {
            mat[i][0].first=mat[i-1][0].first*grid[i][0];
            mat[i][0].second=mat[i-1][0].second*grid[i][0];
        }
        for(int i=1;i<n;i++)
        {
            mat[0][i].first=mat[0][i-1].first*grid[0][i];
            mat[0][i].second=mat[0][i-1].second*grid[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                mat[i][j].first=max({mat[i-1][j].first*grid[i][j],mat[i-1][j].second*grid[i][j],mat[i][j-1].first*grid[i][j],mat[i][j-1].second*grid[i][j]});
                mat[i][j].second=min({mat[i-1][j].first*grid[i][j],mat[i-1][j].second*grid[i][j],mat[i][j-1].first*grid[i][j],mat[i][j-1].second*grid[i][j]});
            }
        }
        return mat[m-1][n-1].first<0?-1:(mat[m-1][n-1].first)%mod;
    }
};