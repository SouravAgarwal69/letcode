class Solution {
public:
    bool bfs(vector<int>adj[],vector<int>&color,int node)
    {
        queue<int>q;
        q.push(node);
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
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        vector<int>adj[graph.size()];
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!bfs(adj,color,i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};