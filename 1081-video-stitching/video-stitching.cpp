class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int>timeRange(time+1);
        for(int i=0;i<clips.size();i++)
        {
            int start=clips[i][0];
            int end=min(time,clips[i][1]);
            if(start<=time)
            {
            timeRange[start]=max(timeRange[start],end);
            }
        }
        int clip=0,currEnd=0,maxEnd=0;
        for(int i=0;i<time+1;i++)
        {
            if(i>maxEnd)
            {
                return -1;
            }
            if(i>currEnd)
            {
                clip++;
                currEnd=maxEnd;
            }
            maxEnd=max(maxEnd,timeRange[i]);
        }
        return clip;
    }
};