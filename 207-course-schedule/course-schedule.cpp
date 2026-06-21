class Solution {
public:
    bool detectCycle(int node,vector<int>adj[],vector<bool>&visited,vector<bool>&path)
    {
        visited[node]=true;
        path[node]=true;
        for(int i=0;i<adj[node].size();i++)
        {
            if(visited[adj[node][i]])
            {
                if(path[adj[node][i]])
                {
                    return true;
                }
            }
            else
            {
                if(detectCycle(adj[node][i],adj,visited,path))
                {
                    return true;
                }
            }
        }
        path[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<int>adj[V];
        vector<bool>visited(V);
        vector<bool>path(V);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<V;i++)
        {
              if(!visited[i] && detectCycle(i,adj,visited,path))
              {
                 return false;
              }
        }
        return true;
    }
};