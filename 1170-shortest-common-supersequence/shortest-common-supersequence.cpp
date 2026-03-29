class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans;
        int m=str1.size()+1,n=str2.size()+1;
        vector<vector<int>>mat(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                {
                    mat[i][j]=i+j;
                }
                else if(str1[i-1]==str2[j-1])
                {
                    mat[i][j]=1+mat[i-1][j-1];
                }
                else
                {
                    mat[i][j]=1+min(mat[i-1][j],mat[i][j-1]);
                }
            }
        }
        int i=m-1,j=n-1;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(mat[i-1][j]>mat[i][j-1])
            {
               ans.push_back(str2[j-1]);
               j--;
            }
            else
            {
                ans.push_back(str1[i-1]);
                i--;
            }
        }
        while(i>0)
        {
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0)
        {
            ans.push_back(str2[j-1]);
            j--;
        }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};