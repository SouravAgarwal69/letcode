class Solution {
public:
    bool dfs(vector<int>adj[],stack<int>&st,vector<bool>&visited,int node,vector<bool>&path)
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
            else if(!visited[adj[node][i]])
            {
                if(dfs(adj,st,visited,adj[node][i],path))
                {
                    return true;
                }
            }
        }
        st.push(node);
        path[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        stack<int>st;
        vector<bool>visited(numCourses);
        vector<bool>path(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(dfs(adj,st,visited,i,path))
                {
                    return false;
                }
            }
        }
        return st.size()==numCourses;
    }
};