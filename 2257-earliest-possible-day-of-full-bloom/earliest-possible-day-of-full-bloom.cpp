class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>vp;
        for(int i=0;i<plantTime.size();i++)
        {
            vp.push_back(make_pair(growTime[i],plantTime[i]));
        }
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        int maxBloomDays=0,prevPlantTime=0;
        for(int i=0;i<vp.size();i++)
        {
            int CurrplantTime=prevPlantTime+vp[i].second;
            int CurrgrowTime=vp[i].first;
            maxBloomDays=max(maxBloomDays,CurrplantTime+CurrgrowTime);
            prevPlantTime=CurrplantTime;
        }
           return maxBloomDays;
    }
};