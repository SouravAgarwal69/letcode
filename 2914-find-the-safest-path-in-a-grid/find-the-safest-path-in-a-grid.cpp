class Solution {
public:
     bool isValid(int row,int col,int n)
     {
        return row>=0 && row<n && col>=0 && col<n;
     }
     void findsfGrid(vector<vector<int>>&grid,vector<vector<int>>&sfGrid)
     {
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        int n=grid.size();
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push(make_pair(i,j));
                    sfGrid[i][j]=0;
                }
            }
        }
        int level=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(isValid(r+row[i],c+col[i],n) && sfGrid[r+row[i]][c+col[i]]==-1)
                {
                   q.push(make_pair(r+row[i],c+col[i]));
                   sfGrid[row[i]+r][col[i]+c]=level;
                }
            }
            }
            level++;
        }
     }
    bool isPossible(int sf,vector<vector<int>>&sfGrid)
    {
         int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        int n=sfGrid.size();
        if(sfGrid[0][0]<sf)
        {
            return false;
        }
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        queue<pair<int,int>>q;
        q.push(make_pair(0,0));
        visited[0][0]=true;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(isValid(r+row[i],c+col[i],n) && !visited[r+row[i]][c+col[i]] && sfGrid[r+row[i]][c+col[i]]>=sf)
                {
                    if(r+row[i]==n-1 && c+col[i]==n-1)
                    {
                        return true;
                    }
                    q.push(make_pair(r+row[i],c+col[i]));
                    visited[r+row[i]][c+col[i]]=true;
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>sfGrid(n,vector<int>(n,-1));
        findsfGrid(grid,sfGrid);
        int s=0,e=n;
        int ans=s;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(mid,sfGrid))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
};