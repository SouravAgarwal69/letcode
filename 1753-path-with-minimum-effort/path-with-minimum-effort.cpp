class Solution {
public:
    bool check(int x,int y,int m,int n)
    {
        return x>=0 && x<m && y>=0 && y<n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r[4]={0,0,-1,1};
        int c[4]={1,-1,0,0};
        int m=heights.size(),n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
         result[0][0]=0;
        while(!pq.empty())
        {
            int effort=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                if(check(row+r[i],col+c[i],m,n))
                {
                    int minEffort=max(abs(heights[row][col]-heights[row+r[i]][col+c[i]]),effort);
                    if(result[row+r[i]][col+c[i]]>minEffort)
                    {
                        result[row+r[i]][col+c[i]]=minEffort;
                        pq.push({minEffort,{row+r[i],col+c[i]}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};