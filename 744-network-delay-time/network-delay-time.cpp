class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        vector<int>result(n+1,INT_MAX);
        result[k]=0;
        while(!q.empty())
        {
            int node=q.top().second;
            int time=q.top().first;
            q.pop();
            if(result[node]<time)
            {
                continue;
            }
            for(int i=0;i<adj[node].size();i++)
            {
                int neigh=adj[node][i].first;
                int wt=adj[node][i].second;
                if(wt+time<result[neigh])
                {
                    result[neigh]=wt+time;
                    q.push({wt+time,neigh});
                }
            }
        }
        int maxDelay=INT_MIN;
        for(int i=1;i<result.size();i++)
        {
            maxDelay=max(maxDelay,result[i]);
        }
        return maxDelay==INT_MAX?-1:maxDelay;
    }
};