class Solution {
public:
    bool detectCycle(vector<int>adj[],stack<int>&st,vector<bool>&visited,vector<bool>&path,int node)
    {
            visited[node]=true;
            path[node]=true;
            for(int i=0;i<adj[node].size();i++)
            {
                if(!visited[adj[node][i]])
                {
                if(detectCycle(adj,st,visited,path,adj[node][i]))
                {
                    return true;
                }
                }
                else if(path[adj[node][i]])
                {
                    return true;
                }

            }
        path[node]=false;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>result;
        stack<int>st;
        vector<bool>visited(n);
        vector<bool>path(n);
        vector<int>adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i] && detectCycle(adj,st,visited,path,i))
            {
                return {};
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