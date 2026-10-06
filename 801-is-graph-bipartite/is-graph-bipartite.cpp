class Solution {
public:
    bool bfs(vector<int>adj[],int value,vector<int>&color)
    {
         queue<int>q;
         q.push(value);
         while(!q.empty())
         {
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                if(color[adj[node][i]]==-1)
                {
                    color[adj[node][i]]=1-color[node];
                    q.push(adj[node][i]);
                }
                else if(color[adj[node][i]]==color[node])
                {
                    return true;
                }
            }
         }
         return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(bfs(adj,i,color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};