class Solution {
public:
    void Bfs(vector<int>adj[],vector<bool>&visited,int node)
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
                    Bfs(adj,visited,adj[node][i]);
                }
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
                Bfs(adj,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};