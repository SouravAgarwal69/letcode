class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int row=text1.size()+1,col=text2.size()+1;
        vector<vector<int>>mat(row+1,vector<int>(col+1));
        for(int i=0;i<row;i++)
        {
            mat[i][0]=0;
        }
        for(int i=0;i<col;i++)
        {
            mat[0][col]=0;
        }
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    mat[i][j]=1+mat[i-1][j-1];
                }
                else
                {
                    mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
                }
            }
        }
        return mat[row-1][col-1];
    }
};