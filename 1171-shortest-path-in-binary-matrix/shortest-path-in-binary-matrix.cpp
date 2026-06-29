class Solution {
public:
    bool valid(int r,int c,int n)
    {
        return r>=0 && r<n && c>=0 && c<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int,int>>q;
        q.push({0,0});
        if(grid[n-1][n-1]==1 || grid[0][0]==1)
        {
            return -1;
        }
        int level=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size>0)
            {
              pair<int,int>pq=q.front();
              q.pop();
              int row=pq.first;
              int col=pq.second;
              if(row==n-1 && col==n-1)
              {
                   return level;
              }
              for(int i=0;i<directions.size();i++)
              {
                    int r=row+directions[i].first;
                    int c=col+directions[i].second;
                  if(valid(r,c,n) && grid[r][c]==0)
                  {
                      grid[r][c]=1;
                      q.push({r,c});
                  }
              }
              size--;
            }
            level++;
        }
        return -1;
    }
};