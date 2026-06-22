class Solution {
public:
    bool dfs(vector<bool>&visited,vector<bool>&path,vector<int>adj[],int node)
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
                else{
                   if(dfs(visited,path,adj,adj[node][i]))
                   {
                       return true;
                   }
                }
            }
            path[node]=false;
            return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<bool>visited(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
       vector<bool>path(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(dfs(visited,path,adj,i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};