class Solution {
public:
    bool valid(int r,int c,int m,int n)
    {
        return r>=0 && r<m && c>=0 && c<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int r[4]={0,0,1,-1};
        int c[4]={1,-1,0,0};
        queue<pair<int,int>>q;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int minutes=0;
      
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    if(valid(row+r[i],col+c[i],m,n) && grid[row+r[i]][col+c[i]]==1)
                    {
                           q.push({row+r[i],col+c[i]});
                           grid[row+r[i]][col+c[i]]=2;
                    }
                }
            }
              minutes++;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return max(0,minutes-1);
    }
};