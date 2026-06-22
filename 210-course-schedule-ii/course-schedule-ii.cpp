class Solution {
public:
    bool find(vector<int>adj[],stack<int>&st,vector<bool>&visited,vector<bool>&recursivePath,int node)
    {
           visited[node]=true;
           recursivePath[node]=true;
           for(int i=0;i<adj[node].size();i++)
           {
               if(visited[adj[node][i]])
               {
                if(recursivePath[adj[node][i]])
                {
                  return true;
                }
               }
               if(!visited[adj[node][i]])
               {
                  if(find(adj,st,visited,recursivePath,adj[node][i]))
                  {
                     return true;
                  }
               }
           }
           st.push(node);
           recursivePath[node]=false;
           return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>result;
        stack<int>st;
        vector<bool>visited(numCourses);
        vector<bool>recursivePath(numCourses);
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
               if(find(adj,st,visited,recursivePath,i))
               {
                  return {};
               }
            }
        }
        
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};