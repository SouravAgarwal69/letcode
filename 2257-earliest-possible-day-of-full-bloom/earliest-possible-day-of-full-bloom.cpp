class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int maxBloom=0;
        vector<int>index(plantTime.size());
        iota(index.begin(),index.end(),0);
        sort(index.begin(),index.end(),[&](int i,int j)
        {
              return growTime[i]>growTime[j];
        }
        );
        int plantDays=0;
        for(int i=0;i<growTime.size();i++)
        {
            plantDays+=plantTime[index[i]];
           int growDay=plantDays+growTime[index[i]];
            maxBloom=max(maxBloom,growDay);
        }
        return maxBloom;
    }
};