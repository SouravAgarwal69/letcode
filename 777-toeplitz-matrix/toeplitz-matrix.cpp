class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int,int>mp;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(mp.find(j-i)!=mp.end())
                {
                    if(mp[j-i]!=matrix[i][j])
                    {
                        return false;
                    }
                }
                else
                    {
                        mp[j-i]=matrix[i][j];
                    }
            }
        }
        return true;
    }
};