class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v=points.size();
        vector<pair<int,int>>adj[v];
        vector<bool>visited(v,0);
        int minCost=0;
        for(int i=0;i<v;i++)
        {
            for(int j=i+1;j<v;j++)
            {
                int x1=points[i][0],y1=points[i][1],x2=points[j][0],y2=points[j][1];
                int dist=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(visited[node])
            {
                continue;
            }
            visited[node]=true;
            minCost+=cost;
            for(int i=0;i<adj[node].size();i++)
            {
                pq.push({adj[node][i].second,adj[node][i].first});
            }
        }
        return minCost;
    }
};