class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<adj[i].size();j++)
           {
               indegree[adj[i][j]]++;
           }
        }
        int cnt=0;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                cnt++;
                q.push(i);
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
       return cnt==n;
    }
};