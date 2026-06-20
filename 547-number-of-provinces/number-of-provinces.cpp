class Solution {
public:
    void Dfs(vector<int>adj[],vector<bool>&visited,int cnt,int node)
    {
        visited[node]=true;
        for(int i=0;i<adj[node].size();i++)
        {
            if(!visited[adj[node][i]])
            {
                Dfs(adj,visited,cnt,adj[node][i]);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        int V=isConnected.size();
        vector<int>adj[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool>visited(V);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                Dfs(adj,visited,cnt,i);
                cnt++;
            }
        }
        return cnt;
    }
};