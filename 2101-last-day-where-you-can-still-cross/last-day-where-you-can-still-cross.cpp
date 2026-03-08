class Solution {
public:
    bool Check(int r,int c,int row,int col)
    {
        return r>=0 && r<row && c>=0 && c<col;
    }
    bool isPossible(int day,vector<vector<int>>&cells,int row,int col)
    {
        vector<vector<int>>mat(row,vector<int>(col,0));
       for(int i=0;i<day;i++)
       {
            mat[cells[i][0]-1][cells[i][1]-1]=1;
       }
         queue<pair<int,int>>q;
        for(int i=0;i<mat[0].size();i++)
        {
            if(mat[0][i]==0)
            {
                q.push(make_pair(0,i));
                mat[0][i]=1;
            }
        }
        int R[]={-1,1,0,0};
        int C[]={0,0,-1,1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r==row-1 )
            {
                return true;
            }
            for(int i=0;i<4;i++)
            {
               if(Check(r+R[i],c+C[i],row,col) && mat[r+R[i]][c+C[i]]==0)
               {
                    q.push(make_pair(r+R[i],c+C[i]));
                    mat[r+R[i]][c+C[i]]=1;
               }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int s=0,e=cells.size(),ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(mid,cells,row,col))
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