class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size()+1,n=word2.size()+1;
        vector<vector<int>>mat(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                {
                    mat[i][j]=i+j;
                }
                else if(word1[i-1]==word2[j-1])
                {
                    mat[i][j]=mat[i-1][j-1];
                }
                else
                {
                    mat[i][j]=1+min({mat[i-1][j-1],mat[i][j-1],mat[i-1][j]});
                }
            }
        }
        return mat[m-1][n-1];
    }
};