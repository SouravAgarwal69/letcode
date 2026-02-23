class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int>videoClips(time+1);
        for(int i=0;i<clips.size();i++)
        {
            int start=clips[i][0];
            int end=clips[i][1];
            if(start<=time)
            {
            videoClips[start]=max(videoClips[start],end);
            }
        }
        int totalClips=0,currEnd=0,maxEnd=0;
        for(int i=0;i<time+1;i++)
        {
            if(i>maxEnd)
            {
                return -1;
            }
            if(i>currEnd)
            {
                currEnd=maxEnd;
                totalClips++;
            }
            maxEnd=max(maxEnd,videoClips[i]);
        }
        return totalClips;
    }
};