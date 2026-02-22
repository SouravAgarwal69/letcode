class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>temp(n+1);
        for(int i=0;i<ranges.size();i++)
        {
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            temp[left]=max(temp[left],right);
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
            maxEnd=max(maxEnd,temp[i]);
        }
        return tapes;
    }
};