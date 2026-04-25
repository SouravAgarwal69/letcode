class Solution {
public:
    int countOverlap(vector<vector<int>>&img1,vector<vector<int>>&img2,int row,int col,int n)
    {
        int overlap=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+row>=n || i+row<0 || j+col>=n || j+col<0)
                {
                    continue;
                }
                if(img1[i][j]==1 && img2[i+row][j+col]==1)
                {
                     overlap++;
                }
            }
        }
        return overlap;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxOverlap=0,n=img1.size();
        for(int row_shift=-n+1;row_shift<n;row_shift++)
        {
            for(int col_shift=-n+1;col_shift<n;col_shift++)
            {
                int overlap=countOverlap(img1,img2,row_shift,col_shift,n);
                maxOverlap=max(maxOverlap,overlap);
            }
        }
        return maxOverlap;
    }
};