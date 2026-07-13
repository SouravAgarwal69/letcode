class Solution {
public:
    void dfs(vector<int>adj[],vector<bool>&visited,int node)
    {
        queue<int>q;
        q.push(node);
        visited[node]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                if(!visited[adj[node][i]])
                {
                    visited[adj[node][i]]=true;
                    q.push(adj[node][i]);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {
            return -1;
        }
        int cnt=0;
        vector<int>adj[n];
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(adj,visited,i);
            }
        }
        return cnt-1;
    }
};