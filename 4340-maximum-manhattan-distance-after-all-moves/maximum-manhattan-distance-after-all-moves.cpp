class Solution {
public:
    int maxDistance(string moves) {
        int x_move=0,y_move=0,k=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
            {
                x_move--;
            }
            else if(moves[i]=='D')
            {
                y_move--;
            }
            else if(moves[i]=='U')
            {
                y_move++;
            }
            else if(moves[i]=='R')
            {
                 x_move++;
            }
            else
            {
                k++;
            }
        }
        return abs(x_move)+abs(y_move)+k;
    }
};