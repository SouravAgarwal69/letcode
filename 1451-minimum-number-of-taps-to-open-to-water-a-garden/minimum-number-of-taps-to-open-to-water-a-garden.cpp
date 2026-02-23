class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>WaterRange(ranges.size()+1);
        for(int i=0;i<ranges.size();i++)
        {
            int s=max(0,i-ranges[i]);
            int e=min(n,i+ranges[i]);
            WaterRange[s]=max(WaterRange[s],e);
        }
        int tapes=0,currEnd=0,maxEnd=0;
        for(int i=0;i<n+1;i++)
        {
            if(i>maxEnd)
            {
                return -1;
            }
            if(i>currEnd)
            {
                tapes++;
                currEnd=maxEnd;
            }
            maxEnd=max(maxEnd,WaterRange[i]);
        }
        return tapes;
    }
};