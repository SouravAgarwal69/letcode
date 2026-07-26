class Solution {
public:
    bool isValid(int row,int col,int m,int n)
    {
        return row>=0 && row<m && col>=0 && col<n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r[4]={0,0,-1,1};
        int c[4]={1,-1,0,0};
        int m=isWater.size(),n=isWater[0].size();
        vector<vector<int>>result(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j]==1)
                {
                    q.push({i,j});
                    result[i][j]=0;
                }
            }
        }
       while(!q.empty()) 
       {
           int size=q.size();
           
           int row=q.front().first,col=q.front().second;
           q.pop();
           for(int i=0;i<4;i++)
           {
              if(isValid(row+r[i],col+c[i],m,n) && result[row+r[i]][col+c[i]]==-1)
              {
                  q.push({row+r[i],col+c[i]});
                  result[row+r[i]][col+c[i]]=1+result[row][col];
              }
           }
       }
       return result;
    }
};