class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int taps=0;
        vector<int>result(n+1);
        for(int i=0;i<n+1;i++)
        {
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            result[left]=max(result[left],right);
        }
        int startEnd=0,maxEnd=0;
        for(int i=0;i<result.size();i++)
        {
            if(i>maxEnd)
            {
                return -1;
            }
            if(i>startEnd)
            {
                startEnd=maxEnd;
                taps++;
            }
            maxEnd=max(maxEnd,result[i]);
        }
        return taps;
    }
};