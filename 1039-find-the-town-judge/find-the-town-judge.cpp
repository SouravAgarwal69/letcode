class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>degree(n);
        for(int i=0;i<trust.size();i++)
        {
            degree[trust[i][0]-1]--;
            degree[trust[i][1]-1]++;
        }
        for(int i=0;i<n;i++)
        {
            if(degree[i]==n-1)
            {
                return i+1;
            }
        }
        return -1;
    }
};