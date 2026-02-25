class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int>ArrivalTime(dist.size());
        for(int i=0;i<speed.size();i++)
        {
            ArrivalTime[i]=ceil((float)dist[i]/speed[i]);
        }
        sort(ArrivalTime.begin(),ArrivalTime.end());
        int currentTime=0,eliminate=0;
        for(int i=0;i<dist.size();i++)
        {
            if(currentTime>=ArrivalTime[i])
            {
                return eliminate;
            }
            currentTime++;
            eliminate++;
        }
        return eliminate;
    }
};