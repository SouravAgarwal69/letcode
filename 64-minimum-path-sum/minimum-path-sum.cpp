class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>>mat(r,vector<int>(c));
        mat[0][0]=grid[0][0];
        for(int i=1;i<r;i++)
        {
            mat[i][0]=mat[i-1][0]+grid[i][0];
        }
        for(int j=1;j<c;j++)
        {
            mat[0][j]=mat[0][j-1]+grid[0][j];
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                mat[i][j]=grid[i][j]+min(mat[i-1][j],mat[i][j-1]);
            }
        }
        return mat[r-1][c-1];
    }
};