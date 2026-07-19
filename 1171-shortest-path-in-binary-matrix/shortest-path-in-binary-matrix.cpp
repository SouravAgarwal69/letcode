class Solution {
public:
    bool check(int r,int c,int n)
    {
        return r>=0 && r<n && c>=0 && c<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row[8]={-1,1,-1,1,-1,1,0,0};
        int col[8]={0,0,-1,1,1,-1,1,-1};
        int n=grid.size();
        queue<pair<int,int>>q;
        if(grid[0][0]==0)
        {
        q.push({0,0});
        }
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size>0)
            {
                int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r==n-1 && c==n-1)
            {
                return level+1;
            }
            for(int i=0;i<8;i++)
            {
                if(  check(r+row[i],c+col[i],n) && grid[r+row[i]][c+col[i]]==0)
                {
                    
                        q.push({r+row[i],c+col[i]});
                        grid[r+row[i]][c+col[i]]=1;
                }
            }
            size--;
            }
            level++;
        }
        return -1;
    }
};