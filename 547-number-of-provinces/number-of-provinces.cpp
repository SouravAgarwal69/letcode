class Solution {
public:
    void dfs(vector<int>adj[],vector<bool>&visited,int node)
    {
        visited[node]=true;
        for(int i=0;i<adj[node].size();i++)
        {
            if(!visited[adj[node][i]])
            {
                dfs(adj,visited,adj[node][i]);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(isConnected.size());
        vector<int>adj[n];
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(adj,visited,i);
            }
        }
        return cnt;
    }
};