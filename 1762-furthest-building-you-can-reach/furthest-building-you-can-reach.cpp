class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>maxQ;
        for(int i=0;i<heights.size()-1;i++)
        {
            int diff=heights[i+1]-heights[i];
            if(diff<=0)
            {
                continue;
            }
            if(diff>bricks && ladders==0)
            {
                return i;
            }
            else if(diff<=bricks)
            {
                bricks-=diff;
                maxQ.push(diff);
            }
            else if(ladders>0)
           {
               if(!maxQ.empty() && diff<maxQ.top())
               {
                 bricks+=maxQ.top();
                 maxQ.pop();
                 bricks-=diff;
                 maxQ.push(diff);
               }
               ladders--;
           }
        }
        return heights.size()-1;
    }
};