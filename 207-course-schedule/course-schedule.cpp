class Solution {
public:
    bool bfs(vector<int>&indegree,vector<int>adj[])
    {
        queue<int>q;
        int cnt=0;
        for(int i=0;i<indegree.size();i++)
        {
              if(indegree[i]==0)
              {
                 q.push(i);
                 cnt++;
              }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]]==0)
                {
                    q.push(adj[node][i]);
                    cnt++;
                }
            }
        }
        return cnt==indegree.size();
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses);
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        return bfs(indegree,adj);
    }
};