class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                mp[j-i].push_back(mat[i][j]);
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            sort(it->second.begin(),it->second.end());
        }
        for(int i=mat.size()-1;i>=0;i--)
        {
            for(int j=mat[0].size()-1;j>=0;j--)
            {
                mat[i][j]=mp[j-i].back();
                mp[j-i].pop_back();
            }
        }
        return mat;
    }
};