class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>TimeRanges(ranges.size()+1);
        for(int i=0;i<ranges.size();i++)
        {
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            TimeRanges[start]=max(TimeRanges[start],end);
        }
        int currEnd=0,maxEnd=0,tapes=0;
        for(int i=0;i<n+1;i++)
        {
            if(i>maxEnd)
            {
                return -1;
            }
            if(i>currEnd)
            {
                currEnd=maxEnd;
                tapes++;
            }
            maxEnd=max(maxEnd,TimeRanges[i]);
        }
        return tapes;
    }
};