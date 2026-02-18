class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        int prev=neededTime[0];
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]==colors[i-1])
            {
                time+=min(neededTime[i],prev);
                prev=max(neededTime[i],prev);
            }
            else
            {
                prev=neededTime[i];
            }
        }
        return time;
    }
};