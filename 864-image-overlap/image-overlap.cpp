class Solution {
public:
    int countOverlap(vector<vector<int>>&img1,vector<vector<int>>&img2,int row_offSet,int col_offSet,int n)
    {
        int overlap=0;
        for(int i=0;i<img1.size();i++)
        {
            for(int j=0;j<img2.size();j++)
            {
                if(i+row_offSet<0 || i+row_offSet>=n || j+col_offSet<0 || j+col_offSet>=n)
                {
                    continue;
                }
                if(img1[i][j]==1 && img2[i+row_offSet][j+col_offSet]==1)
                {
                     overlap++;
                }
            }
        }
        return overlap;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int maxOverlaps=0;
        for(int row_offSet=-n+1;row_offSet<n;row_offSet++)
        {
            for(int col_offSet=-n+1;col_offSet<n;col_offSet++)
            {
              int  overlap=countOverlap(img1,img2,row_offSet,col_offSet,n);
                maxOverlaps=max(maxOverlaps,overlap);
            }
        }
        return maxOverlaps;
    }
};