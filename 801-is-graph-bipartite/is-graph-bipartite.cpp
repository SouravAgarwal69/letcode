class Solution {
public:
    bool dfs(vector<int>adj[],vector<int>&color,int node)
    {
        for(int i=0;i<adj[node].size();i++)
        {
            if(color[adj[node][i]]==-1)
            {
                color[adj[node][i]]=1-color[node];
                if(!dfs(adj,color,adj[node][i]))
                {
                    return false;
                }
            }
            else if(color[node]==color[adj[node][i]])
            {
                return false;
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
                if(!dfs(adj,color,i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};