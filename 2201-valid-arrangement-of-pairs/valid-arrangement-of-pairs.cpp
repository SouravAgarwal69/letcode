class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&mp,vector<int>&path)
    {
        while(!mp[node].empty())
        {
            int val=mp[node].back();
            mp[node].pop_back();
            dfs(val,mp,path);
        }   
        path.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<vector<int>>result;
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indeg,outdeg;
        for(int i=0;i<pairs.size();i++)
        {
            adj[pairs[i][0]].push_back(pairs[i][1]);
            outdeg[pairs[i][0]]++;
            indeg[pairs[i][1]]++;
        }
        int startNode=pairs[0][0];
        for(auto it=adj.begin();it!=adj.end();it++)
        {
            int val=it->first;
            if(outdeg[val]-indeg[val]==1)
            {
                startNode=val;
                break;
            }
        }
        vector<int>path;
        dfs(startNode,adj,path);
        reverse(path.begin(),path.end());
        for(int i=1;i<path.size();i++)
        {
            result.push_back({path[i-1],path[i]});
        }
        return result;
    }
};