class Solution {
public:
    void bfs(vector<int>adj[],vector<bool>&visited,int node)
    {
        queue<int>q;
        q.push(node);
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
                bfs(adj,visited,i);
            }
        }
        return cnt;
    }
};