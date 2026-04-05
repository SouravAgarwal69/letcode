class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>>mat(m,vector<int>(n));
        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }
        mat[0][0]=1;
        for(int row=1;row<m;row++)
        {
            mat[row][0]=obstacleGrid[row][0]==1?0:mat[row-1][0];
        }
        for(int col=1;col<n;col++)
        {
            mat[0][col]=obstacleGrid[0][col]==1?0:mat[0][col-1];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                { 
                  mat[i][j]=0; 
                }
                else
                {
                    mat[i][j]=mat[i-1][j]+mat[i][j-1];
                }
            }
        }
        return mat[m-1][n-1];
    }
};