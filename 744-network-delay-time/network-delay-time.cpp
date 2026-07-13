class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>Time(n+1,INT_MAX);
        vector<pair<int,int>>adj[n+1];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        Time[k]=0;
        pq.push({0,k});
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({w,v});
        }
        while(!pq.empty())
        {
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                int wt=adj[node][i].first;
                int neigh=adj[node][i].second;
                if(dist+wt<Time[neigh])
                {
                    Time[neigh]=dist+wt;
                    pq.push({wt+dist,neigh});
                }
            }
        }
        int result=0;
        for(int i=1;i<n+1;i++)
        {
           if(Time[i]==INT_MAX)
           {
              return -1;
           }
           result=max(result,Time[i]);
        }
        return result==INT_MAX?-1:result;
    }
};