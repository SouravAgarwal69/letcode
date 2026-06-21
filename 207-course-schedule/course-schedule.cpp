class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses);
        queue<int>q;
          int cntCourse=0;
           
        for(int i=0;i<prerequisites.size();i++)
        {
              indegree[prerequisites[i][0]]++;
              adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

       for(int i=0;i<numCourses;i++)
       {
          if(indegree[i]==0)
          {
            q.push(i);
            cntCourse++;
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
                   cntCourse++;
                   q.push(adj[node][i]);
               }
           }
       }
       return cntCourse==numCourses;
    }
};