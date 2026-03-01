class Solution {
public:
    bool isPossible(vector<int>&nums,vector<int>&changeIndices,int givenTime)
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
        vector<pair<int,int>>vp(lastVisited.size());
        for(int i=0;i<lastVisited.size();i++)
        {
            vp[i].first=lastVisited[i];
            vp[i].second=i;
        }
        sort(vp.begin(),vp.end());
        int usedTime=0;
        for(int i=0;i<vp.size();i++)
        {
            int avlTime=vp[i].first;
            int index=vp[i].second;
            if(usedTime+nums[index]+1>avlTime)
            {
                return false;
            }
            usedTime+=nums[index]+1;
        }
        /*
        map<int,int>mp;
        for(int i=0;i<lastVisited.size();i++)
        {
            mp[lastVisited[i]]=i;
        }
        int usedTime=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int reqTime=nums[it->second];
            if(reqTime+1+usedTime>it->first)
            {
                return false;
            }
            usedTime+=reqTime+1;
        }*/
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int minTime=-1;
        int s=1,e=changeIndices.size();
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(nums,changeIndices,mid))
            {
                minTime=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return minTime;
    }
};