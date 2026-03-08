class Solution {
public:
    bool isPossible(int givenSpeed,vector<int>&dist,double hr)
    {
        double time=0;
        for(int i=0;i<dist.size();i++)
        {
            if(i==dist.size()-1)
            {
                time+=((double)dist[i]/givenSpeed);
            }
            else
            {
            time+=ceil(((double)dist[i]/givenSpeed));
            }
            if(time>hr)
            {
                return false;
            }
        }
        return time<=hr;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s=1,e=1e9;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(mid,dist,hour))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};