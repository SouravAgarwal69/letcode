class Solution {
public:
    bool check(int x,int y,int m,int n)
    {
        return x>=0 && x<m && y>=0 && y<n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r[4]={1,-1,0,0};
        int c[4]={0,0,1,-1};
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>>result(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        int diff=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==m-1 && col==n-1)
            {
                return diff;
            }
            for(int i=0;i<4;i++)
            {
                if(check(row+r[i],col+c[i],m,n))
                {
                    int minDiff=max(diff,abs(heights[row][col]-heights[row+r[i]][col+c[i]]));
                     if(result[row+r[i]][col+c[i]]>minDiff)
                     {
                        result[row+r[i]][col+c[i]]=minDiff;
                        pq.push({minDiff,{row+r[i],col+c[i]}});
                     }
                }
            }
        }
        return result[m-1][n-1];
    }
};