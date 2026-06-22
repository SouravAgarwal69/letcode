class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>result;
        vector<int>indegree(numCourses);
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                result.push_back(i);
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
                    result.push_back(adj[node][i]);
                    q.push(adj[node][i]);
                }
            }
        }
        return result.size()==numCourses;
    }
};