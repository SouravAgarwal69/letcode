class Solution {
public:
     bool isPossible(vector<int>&time,int totalTrips,long long GivenTime)
     {
        long long trips=0;
        for(int i=0;i<time.size();i++)
        {
            trips+=GivenTime/time[i];
            if(trips>=totalTrips)
            {
                return true;
            }
        }
       return trips>=totalTrips;
     }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s=*min_element(time.begin(),time.end());
        long long e=1LL**min_element(time.begin(),time.end())*totalTrips;
        long long ans=e;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
            if(isPossible(time,totalTrips,mid))
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