class Solution {
public:
    bool check(int x,int y,int n)
    {
        return x>=0 && x<n && y>=0 && y<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        int cost=0;
        if(grid[0][0]==0)
        {
            q.push({0,0});
            grid[0][0]=1;
        }
        int r[8]={1,-1,0,0,1,-1,-1,1};
        int c[8]={0,0,1,-1,1,-1,1,-1};
        while(!q.empty())
        {
            int size=q.size();
             cost++;
            while(size>0)
            {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row==n-1 && col==n-1)
            {
                return cost;
            }
            for(int i=0;i<8;i++)
            {
                if(check(row+r[i],col+c[i],n) && grid[row+r[i]][col+c[i]]==0 )
                {
                    grid[row+r[i]][col+c[i]]=1;
                    q.push({row+r[i],col+c[i]});
                }
            }
            size--;
            }
           
        }
        return -1;
    }
};