class Solution {
public:
    bool dfs(int node,vector<int>&color,vector<vector<int>>&graph)
    {
          for(int i=0;i<graph[node].size();i++)
          {
             if(color[graph[node][i]]==-1)
             {
                 color[graph[node][i]]=1-color[node];
                 if(!dfs(graph[node][i],color,graph))
                 {
                    return false;
                 }
             }
             else if(color[node]==color[graph[node][i]])
             {
                return false;
             }
          }
          return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!dfs( i,color,graph))
                {
                   return false;
                }
            }
        }
        return true;
    }
};