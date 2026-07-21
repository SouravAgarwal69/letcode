class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v=points.size();
        vector<pair<int,int>>adj[v];
        for(int i=0;i<v;i++)
        {
            for(int j=i+1;j<v;j++)
            {
                int x1=points[i][0],y1=points[i][1],x2=points[j][0],y2=points[j][1];
                int dist=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        } 
        vector<bool>visited(v,false);
        int totalCost=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(visited[node])
            {
                continue;
            }
            visited[node]=true;
            totalCost+=dist;
            for(int i=0;i<adj[node].size();i++)
            {
                int neigh=adj[node][i].second;
                int wt=adj[node][i].first;
                if(!visited[neigh])
                {
                    pq.push({wt,neigh});
                }
            }
        }
        return totalCost;
    }
};