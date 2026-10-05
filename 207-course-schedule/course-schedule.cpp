class Solution {
public:
    bool dfs(int node,vector<int>adj[],vector<bool>&visited,vector<bool>&path)
    {
        if(visited[node])
        {
           if(path[node])
           {
              return true;
           }
        }
        else
        {
             visited[node]=true;
             path[node]=true;
             for(int i=0;i<adj[node].size();i++)
             {
                 if(dfs(adj[node][i],adj,visited,path))
                 {
                    return true;
                 }
             }
        }
        path[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool>visited(n);
        vector<bool>path(n);
        for(int i=0;i<n;i++)
        {
             if(!visited[i] && dfs(i,adj,visited,path))
             {
                return false;
             }
        }
        return true;
    }
};