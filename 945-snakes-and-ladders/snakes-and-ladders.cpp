class Solution {
public:
    pair<int,int>find(int val,int n)
    {
        int bottom_row=(val-1)/n;
        int top_row=(n-1)-bottom_row;
        int col=(val-1)%n;
        if(bottom_row%2!=0)
        {
            col=(n-1)-col;
        }
        return {top_row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        queue<int>q;
        q.push(1);
        visited[n-1][0]=true;
        int DiceRoll=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
            int val=q.front();
            q.pop();
            if(val==n*n)
            {
                return DiceRoll;
            }
            for(int k=1;k<=6;k++)
            {
                if(val+k>n*n)
                {
                    break;
                }
                pair<int,int>cordinate=find(val+k,n);
                int row=cordinate.first;
                int col=cordinate.second;
                if(visited[row][col])
                {
                    continue;
                }
                visited[row][col]=true;
                if(board[row][col]==-1)
                {
                    q.push(val+k);
                }
                else{
                     q.push(board[row][col]);
                }
            }
           }
           DiceRoll++;
        }
        return -1;
    }
};