class Solution {
public:
    bool isPossible(int givenTime,vector<int>&nums,vector<int>&changeIndices)
    {
        vector<int>lastVisited(nums.size(),-1);
        for(int i=0;i<givenTime;i++)
        {
            lastVisited[changeIndices[i]-1]=i+1;
        }
        for(int i=0;i<lastVisited.size();i++)
        {
            if(lastVisited[i]==-1)
            {
                return false;
            }
        }
        map<int,int>mp;
        for(int i=0;i<lastVisited.size();i++)
        {
            mp[lastVisited[i]]=i;
        }
        int usedTime=0;
         for(auto it=mp.begin();it!=mp.end();it++)
         {
            int reqTime=it->first;
            int index=it->second;
            if(nums[index]+1+usedTime>reqTime)
            {
                return false;
            }
            usedTime+=nums[index]+1;
         }
         return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int earliestTime=0;
        for(int time=1;time<=changeIndices.size();time++)
        {
            if(isPossible(time,nums,changeIndices))
            {
                return time;
            }
        }
        return -1;
    }
};