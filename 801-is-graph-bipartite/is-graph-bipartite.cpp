class Solution {
public:
    bool bfs(int node,vector<int>&color,vector<vector<int>>&graph)
    {
         queue<int>q;
         q.push(node);
         while(!q.empty())
         {
            int node=q.front();
            q.pop();
            for(int i=0;i<graph[node].size();i++)
            {
                if(color[graph[node][i]]==color[node])
                {
                    return false;
                }
                else if(color[graph[node][i]]==-1)
                {
                    color[graph[node][i]]=1-color[node];
                    q.push(graph[node][i]);
                }
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
                if(!bfs( i,color,graph))
                {
                   return false;
                }
            }
        }
        return true;
    }
};