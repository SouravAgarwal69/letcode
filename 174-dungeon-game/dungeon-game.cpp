class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>>mat(m,vector<int>(n));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                {
                    mat[i][j]=dungeon[i][j]>0?1:abs(dungeon[i][j])+1;
                }
                else
                {
                    int right=j==n-1?INT_MAX:mat[i][j+1];
                    int down=i==m-1?INT_MAX:mat[i+1][j];
                    int val=min(right,down)-dungeon[i][j];
                    mat[i][j]=val>0?val:1;
                }
            }
        }
        return mat[0][0];
    }
};