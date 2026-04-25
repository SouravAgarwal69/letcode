class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rw[]={-1,1,0,0};
        int cl[]={0,0,-1,1};
        int m=grid.size(),n=grid[0].size();
        queue<vector<int>>q;
        bool visited[m][n][k+1];
        memset(visited,false,sizeof(visited));
        q.push({0,0,k});
        int steps=0;
        while(!q.empty())
        {
            int size=q.size();
           while(size--)
           {
           vector<int>temp=q.front();
           q.pop();
           int r=temp[0],c=temp[1],obstacle=temp[2];
           if(r==m-1 && c==n-1)
           {
                return steps;
           }
           for(int i=0;i<4;i++)
           {
              if(r+rw[i]<0 || r+rw[i]>=m || c+cl[i]<0 || c+cl[i]>=n)
              {
                  continue;
              }
              if(grid[r+rw[i]][c+cl[i]]==0 && !visited[r+rw[i]][c+cl[i]][obstacle])
              {
                  q.push({r+rw[i],c+cl[i],obstacle});
                  visited[r+rw[i]][c+cl[i]][obstacle]=true;
              }
              if(grid[r+rw[i]][c+cl[i]]==1 && obstacle>0 && !visited[r+rw[i]][c+cl[i]][obstacle-1])
              {
                   q.push({r+rw[i],c+cl[i],obstacle-1});
                   visited[r+rw[i]][c+cl[i]][obstacle-1]=true;
              }
           }
           }
           steps++;
        }
        return -1;
    }
};