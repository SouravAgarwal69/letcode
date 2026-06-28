class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>result(n+1,INT_MAX);
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        result[k]=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int times=pq.top().first;
            pq.pop();
            if(times>result[node])
            {
                continue;
            }
            for(int i=0;i<adj[node].size();i++)
            {
                 int neigh=adj[node][i].first;
                 int wt=adj[node][i].second;
                 if(times+wt<result[neigh])
                 {
                    result[neigh]=times+wt;
                    pq.push({times+wt,neigh});
                 }
            }
        }
        int DelayTime=INT_MIN;;
        for(int i=1;i<n+1;i++)
        {
            DelayTime=max(DelayTime,result[i]);
        }
        return DelayTime==INT_MAX?-1:DelayTime;
    }
};